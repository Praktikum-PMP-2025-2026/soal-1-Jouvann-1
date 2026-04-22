/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2 - Data Manipulation and External Files
 *   Hari dan Tanggal    : Rabu, 22 April 2026
 *   Nama (NIM)          : Joe Steven Hardy (13224065)
 *   Nama File           : soal1.c
 *   Deskripsi           : Menerima Input Jumlah Data, dan deretan nilai data, output SUM, AVG, MAX, dan IDX dari deret data tersebut
 */ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void hitungData(double data[], int jumlah, double *sum, double *avg, double *max, double *idx){
    int i = 0;
    *sum = 0;
    *max = data[0];
    *idx = 0;

    while (i < jumlah){
        *sum += data[i];

        if (data[i] > *max){
            *max = data[i];
            *idx = i;
        }

        i++;

        if (i == jumlah){
            break;
        }
    }

    *avg = *sum / jumlah;

    printf("SUM %.2f\n", *sum);
    printf("AVG %.2f\n", *avg);
    printf("MAX %.2f\n", *max);
    printf("IDX %.2f", *idx);
}

int main(){
    double data[100];
    double sum, avg, max, idx;
    int jumlah;
    int counter = 0;
    char input[100];
    char *token;

    //scanf("%[^\n]", &input);
    fgets(input, 100, stdin);
    printf("%s\n", input);

    token = strtok(input, " ");

    while (token!= NULL){
        if (counter < 1){
            jumlah = atoi(token);
            counter++;
        }
        else {
            data[counter-1] = atof(token);
            counter++;
        }
        token = strtok(NULL, " ");
    }

    // printf("counter : %.2f\n", jumlah);
    // for (int i = 0; i< jumlah; i++){
    //     printf(" %.2f\n", data[i]);
    // }

    hitungData(data, jumlah, &sum, &avg, &max, &idx);
    

    return 0;
}
