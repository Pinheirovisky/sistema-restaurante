#include <stdio.h>

#define CUSTO_FIXO 6
#define PRECO_KG 18
#define LARGURA_FAIXA 100
#define DESCONTO_FAIXA 0.1
#define DESCONTO_MAX 0.5

float calculaValorDevido(float peso, float custo_fixo, float preco_kg, float largura_faixa, float desconto_faixa, float desconto_max)
{
  float valorFinal = custo_fixo;
  float soma;
  int contador = 1;
  float numFaixa;

  if (peso > 100)
  {
    peso = peso - 100;
    // Numero de vezes que a largura esta presente dentro do peso do prato:
    numFaixa = peso / LARGURA_FAIXA;

    if (numFaixa <= 0)
      numFaixa == 1;

    // O programa vai rodar o número de vezes que a faixa existe dentro do peso do prato:
    while (numFaixa > 0)
    {
      // Caso atinja o desconto máximo,
      if (((float)contador / 10) == desconto_max)
      {
        soma += ((peso * 18) / 1000) * desconto_max;
      }
      else
      {
        // Soma com o próprio multiplicador "i"
        soma += peso ;
      }
      contador++;
      numFaixa--;
    }
  }

  return valorFinal + ((peso * 18) / 1000);
}

int main()
{

  float peso, precoFinal;

  printf("Olá! Informe o peso do prato do cliente: ");
  scanf("%f", &peso);

  precoFinal = calculaValorDevido(peso, CUSTO_FIXO, PRECO_KG, LARGURA_FAIXA, DESCONTO_FAIXA, DESCONTO_MAX);

  printf("O Preco final do prato eh R$%.2f\n", precoFinal);

  return 0;
}