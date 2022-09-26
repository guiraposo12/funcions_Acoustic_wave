#include <stdio.h>
#include <stdlib.h>

#include "projeto2.h"
#include "wavfile.h"

void mudaGanho (double* dados, int n_amostras, double ganho)
{
    //double* dados: vetor de dados.
    //int n_amostras: número de amostras no vetor.
    //double ganho: modificador do ganho.

    int i;
    for(i=0; i<n_amostras; i++)
    dados[i] = ganho*dados[i];
}
