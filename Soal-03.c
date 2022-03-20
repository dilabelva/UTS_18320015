/*Soal          : 03
Nama/NIM        : Atadila Belva Ganya / 18320015
Jurusan         : Teknik Biomedis'20
Kelas           : K-01
Waktu pengerjaan: Minggu, 20 Maret 2022 9.56 WIB
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX_STRING 200

int main(){
    float r = 20*pow(10, 3), c = 183015*pow(10,-12), vin = 5;
    float vt = 0;
    char keadaan[MAX_STRING];
    //asumsikan V0 = 0 V, sehingga persamaan vt = vin (1-e^(-t/rc))
    //saat t>0, mula-mula akan terjadi keadaan transient dan setelahnya menjadi steady state/tunak

    printf("Pada detik keberapa, Anda ingin meninjau keadaan (t<0/t>0)? ");
    scanf("%s", keadaan);

    //deklarasi sama = 1 menunjukkan keadaan != "tunak"
    int sama = 1;
    sama = strcmpi(keadaan, "t>0");
    float t = 0;
    if(sama == 0){
        printf("Keadaan mula-mula akan transient, kemudian menjadi tunak (steady state) saat t>0,\nmaka dengan membatasi t pada 0<t<0.025 s, v(t) = ");
        for(t=0; t<0.025; t+=0.0001){
            vt = vin*(1-exp(-t/(r*c)));
            printf("%lf, ", vt);
        }
        printf("\n");
    }
    else{ //t<0
        vt = vin;
        printf("Saat t<0, v(t) = vin = %.0lf Volt\n", vt);
    }

    return 0;
}
