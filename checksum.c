#include<stdio.h>
#include "projeto2.h"
#include "wavfile.h"
#define N 8

unsigned char checksum (double* dados, int n_amostras){
/*      Parâmetros: double* dados: vetor de dados.
        int n_amostras: número de amostras no vetor.
        Valor de retorno: o checksum calculado.             */

    int i = 0;
    double *recebe_dados = (double*) malloc (sizeof (double) * n_amostras);


    ///Recebe as amostras em um vetor para moldar os valores///
     for(i=0; i<n_amostras; i++)
     {
        recebe_dados[i] = dados[i]*255;

            if(recebe_dados[i]<0)
            recebe_dados[i] = recebe_dados[i]*(-1);

        ///Faz o arredontamento///
            if((recebe_dados[i] - (int)recebe_dados[i]) > 0.5)
                recebe_dados[i] = (int)recebe_dados[i]+1;
            else
                recebe_dados[i] = (int)recebe_dados[i];
     }

        int j = 0,
        flag = 0,
        Checksum = 0,
        vetor_soma[N],
        vetor_binario[N];
    ///Transforma todos os valores de amostras em um único vetor de binário///
        i = 0;
        for (i = 0; i < n_amostras; i++){
            ///Conversão da amostra [i] para binário///
            j = 0;
            for (j = 0; j <= 7; j++) {
                if (recebe_dados[i] == 1.0){
                    vetor_binario[j] = 1;
                    recebe_dados[i] = 0;
                }
                else if (recebe_dados[i] == 0)
                    vetor_binario[j] = 0;

                else{
                vetor_binario[j] = (int)recebe_dados[i]%2;
                recebe_dados[i]/=2;
                }
            }
        ///Separa em 2 vetores com o binário das amostras para a comparação usando op. bit-a-bit///
            if (flag == 0){
                j = 0;
                flag = 1;
                for (j = 0; j <= 7; j++){
                    if (vetor_binario[j] != 1)
                        vetor_soma[j] = 0;

                    else
                        vetor_soma[j] = 1;
                }
            }
            else
            {
                j = 0;
                flag = 1;
                for (j = 0; j <= 7; j++)
                    vetor_soma[j] = vetor_binario[j] ^ vetor_soma[j];
            }
        }

        ///converte o vetor binario para um inteiro///
        j = 0;
        for (j = 0; j <= 7; j++){
            if (vetor_soma[j] == 1)
                Checksum += 1<<j;
        }

    free(recebe_dados);
return Checksum;
}
