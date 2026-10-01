#include <stdio.h>

int main() {
    char msg[20];
    int chave;
    int i = 0, tam = 0;
    int f1 = 1, f2 = 1, f3;

    printf("Digite a palavra: ");
    scanf("%s", msg);

    printf("Digite o SHIFT: ");
    scanf("%d", &chave);

    while (msg[tam] != '\0') {
        tam++;
    }

    for (i = 0; i < tam; i++) {
        int seq;

        if (i == 0 || i == 1) {
            seq = 1;
        } else {
            f3 = f1 + f2;
            seq = f3;
            f1 = f2;
            f2 = f3;
        }

        int deslocamento = chave + seq;

        if (msg[i] >= 'a' && msg[i] <= 'z') {
            int temp = msg[i] - 'a' + deslocamento;

            while (temp >= 26) {
                temp = temp - 26;
            }

            msg[i] = 'a' + temp;
        }
    }

    printf("\nPalavra criptografada: %s\n", msg);

  
    FILE *arq = fopen("resultado_criptografia.txt", "w");
    if (arq != NULL) {
        fprintf(arq, "Palavra codificada: %s| SHIFT: %d | Tipo: 3 | Letras: %d\n", msg, chave, tam);
        fclose(arq);
        printf("Arquivo 'resultado_criptografia.txt' gerado com sucesso!\n");
    }

    return 0;
}
