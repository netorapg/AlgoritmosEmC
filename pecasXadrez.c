#include <stdio.h>

int main() {
int tabuleiro[8][8] = {
{1, 3, 0, 5, 4, 0, 2, 1},
{1, 0, 1, 0, 0, 1, 0, 0},
{0, 0, 0, 0, 1, 0, 6, 0},
{1, 0, 0, 1, 1, 0, 0, 1},
{0, 1, 0, 4, 0, 0, 1, 0},
{0, 0, 3, 1, 0, 0, 1, 1},
{1, 0, 6, 6, 0, 0, 1, 0},
{1, 0, 5, 0, 1, 1, 0, 6}
};
int i, j, peoes = 0, bispos = 0, cavalos = 0, torres = 0, rainhas = 0, reis = 0;

for (i = 0; i < 8; i++) {
for (j = 0; j < 8; j++) {
switch (tabuleiro[i][j]) {
case 1:
peoes++;
break;
case 2:
cavalos++;
break;
case 3:
torres++;
break;
case 4:
bispos++;
break;
case 5:
reis++;
break;
case 6:
rainhas++;
break;
}
}
}
printf("Peoes: %d\n", peoes);
printf("Bispos: %d\n", bispos);
printf("Cavalos: %d\n", cavalos);
printf("Torres: %d\n", torres);
printf("Rainhas: %d\n", rainhas);
printf("Reis: %d\n", reis);
return 0;

}