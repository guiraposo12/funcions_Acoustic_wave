#include <stdio.h>
#include <stdlib.h>

#include "projeto2.h"
#include "wavfile.h"

void tremoloDenteDeSerra (double* dados, int n_amostras, int tam_ciclo)
{
    //double* dados: vetor de dados.
    //int n_amostras: número de amostras no vetor.
    //int tam_ciclo: número de amostras em um ciclo.

    int i, aux=0;
    float* volume;
    float num = 1.0/(tam_ciclo-1);

    volume = (float*) malloc (sizeof (float) * n_amostras);

    for(i=0; i<n_amostras; i++)
    volume[i]=0;

    for(i=0; i<n_amostras; i++)
    {
        if( i<n_amostras/4 || (i>=n_amostras/2 && i<3*n_amostras/4) )
        {
            volume[i] = num*aux;
            dados[i] = dados[i]*num*aux;
            //printf("dados[%d]: %f; volume[%d] %f\n", i, dados[i],i ,volume[i]);
        }

        else
        {
            volume[i] = num*aux*(-1);
            dados[i]= dados[i]*volume[i];
            //printf("dados[%d]: %f; volume[%d] %f\n", i, dados[i],i ,volume[i]);
        }

        aux++;

        if(volume[i]==1 || volume[i]==-1)
        aux=0;

    }

    free(volume);//desaloca o vetor para nao ocupar espaco

}
