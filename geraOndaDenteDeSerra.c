
#include <stdio.h>
#include <stdlib.h>

#include "projeto2.h"
#include "wavfile.h"

void geraOndaDenteDeSerra (double* dados, int n_amostras, int taxa, double freq, int ascendente)
{
    //double* dados: vetor de dados.
    //int n_amostras: número de amostras no vetor.
    //int taxa: taxa de amostragem do sinal.
    //double freq: frequência da onda.
    //int ascendente: se for igual a 0, a onda é descendente, do contrário, a onda é ascendente.

    float aux, periodo_sinal = taxa/freq;
    int i;

    //Periodo do Sinal e seu intervalo:
    //printf("Periodo: %f\nIntervalo: [%d,%d]\n", periodo_sinal, (int)periodo_sinal, (int)periodo_sinal+1);

    aux = (freq/taxa)*2;
    for(i=1; i<n_amostras; i++)
    {
        dados[i] = dados[i-1] + aux;

        if(dados[i] >= 1)
            dados[i] = dados[i-1] + aux - 2*ascendente;
    }

}
