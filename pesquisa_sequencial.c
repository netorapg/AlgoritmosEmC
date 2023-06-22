#include <stdio.h>
#include <string.h>

#define MAX 20

struct pessoa
{
   char nome[30];
   int idade;
};

int busca_seq(char str_aux[30], int n_cad, struct pessoa cadastro[]);

int main()
{
   struct pessoa cadastro[MAX];
   int n_cad;
   char str_aux[30];
   int i = 0;

   char nomes[20][30] = {
      "Armenia", "Basilio", "Cirilla", "Desuite", "EmilioEstevez", "Ferdinando", "Gertrudes", "Herminia", "Iconoclasta",
      "Joconda", "Kensington", "Laurette", "Merilu", "Normandia", "Obadias", "Persefone", "Romualdo", "Sorento",
      "Tuilia", "Veruka"
   };
   int idades[20] = {
      25, 32, 28, 30, 35, 39, 41, 46, 53, 54, 55, 63, 64, 72, 76, 81, 87, 90, 98, 99
   };

   for (i = 0; i < 20; i++)
   {
      strcpy(cadastro[i].nome, nomes[i]);
      cadastro[i].idade = idades[i];
   }

   n_cad = i;

   // Imprimindo o vetor de structs preenchido
   for (i = 0; i < 20; i++)
   {
      printf("Nome: %s, Idade: %d\n", cadastro[i].nome, cadastro[i].idade);
   }

   printf("ncad: %d\n", n_cad);

   int posicao = busca_seq("Gertrudes", n_cad, cadastro);
   if (posicao != -1) {
      printf("Nome encontrado na posição %d\n", posicao);
   } else {
      printf("Nome não encontrado\n");
   }

   return 0;
}

int busca_seq(char str_aux[30], int n_cad, struct pessoa cadastro[])
{
   int i, pos = -1;

   for (i = 0; i < n_cad; i++)
   {
      if (strcmp(str_aux, cadastro[i].nome) == 0)
         pos = i;
   }
   return (pos);
}

