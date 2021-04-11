#include <stdio.h>

#define CUSTO_FIXO 6
#define PRECO_KG 18
#define LARGURA_FAIXA 80
#define DESCONTO_FAIXA 0.05
#define DESCONTO_MAX 0.6

float calculaValorDevido(float peso, float custo_fixo, float preco_kg, float largura_faixa, float desconto_faixa, float desconto_max)
{
  float parcelaPeso = largura_faixa, soma = 0;
  // Inicialmente usa o próprio peso:
  float parcelaSemDesconto = (preco_kg * peso) / 1000;
  int i = 1, jaCalculou = 0;

  if (peso > largura_faixa)
  {
    // Retira a primeira faixa, para não aplicar o desconto errado:
    peso -= largura_faixa;
    // Usa a largura da faixa, pq o peso é maior:
    parcelaSemDesconto = (preco_kg * largura_faixa) / 1000;

    while (!jaCalculou)
    {
      // Ex: largura faixa é 100, e o peso é 130. Entao precisamos pegar esse 30 em vez de 100.
      if ((LARGURA_FAIXA * i) > peso)
      {
        parcelaPeso = LARGURA_FAIXA - ((LARGURA_FAIXA * i) - peso);
      }
      else
      {
        parcelaPeso = largura_faixa;
      }

      // Preço por quilo atual, com valor máximo o valor da faixa:
      parcelaPeso = (preco_kg * parcelaPeso) / 1000;

      // Caso tenha atingido o desconto máximo, então não aplica mais o desconto por faixa:
      if (i * desconto_faixa > desconto_max)
      {
        soma += parcelaPeso * (1 - desconto_max);
      }
      else
      {
        // Soma, já aplicando o desconto:
        soma += parcelaPeso * (1 - (desconto_faixa * i));
      }

      i++;

      // Se no próximo ciclo a diferença entre o peso e a faixa atual for maior que a própria faixa,
      // significa que já foi englobado todo o valor:
      if (((LARGURA_FAIXA * i) - peso) >= largura_faixa)
        jaCalculou = 1;
    }
  }

  return custo_fixo + parcelaSemDesconto + soma;
}

float calculaValorDevidoConvencial(float peso, float custo_fixo, float preco_kg)
{
  return custo_fixo + (preco_kg * peso / 1000);
}

int main()
{

  float peso, precoFinal, eConvencional;

  printf("Olá! Informe o peso do prato do cliente: ");
  scanf("%f", &peso);

  // precoFinal = calculaValorDevidoConvencial(peso, CUSTO_FIXO, PRECO_KG);
  precoFinal = calculaValorDevido(peso, CUSTO_FIXO, PRECO_KG, LARGURA_FAIXA, DESCONTO_FAIXA, DESCONTO_MAX);

  printf("O Preco final do prato eh R$%.2f\n", precoFinal);

  return 0;
}