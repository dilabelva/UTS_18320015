/*Soal          : 02
Nama/NIM        : Atadila Belva Ganya / 18320015
Jurusan         : Teknik Biomedis'20
Kelas           : K-01
Waktu pengerjaan: Sabtu, 19 Maret 2022 16.00 WIB
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STRING 200
#define MAX_LEN 255

int main(){
    //opening file eksternal "tegangan.txt" dengan pointer fp untuk dibaca
    FILE *fp = fopen("tegangan.txt", "r");

    //deklarasi variabel yang berkaitan dengan pengoperasian file
	char buffer[MAX_STRING];
	char* token;
	float tegangan[MAX_LEN];
	int i = 0;

    //membaca data pada file eksternal kemudian menyimpan datanya dalam array float tegangan[MAX_LEN]
    while(fgets(buffer, MAX_LEN, fp)) {
        token = strtok(buffer, ",");
		tegangan[i] = atof(token);
		token = strtok(NULL, "\n");
		i++;
	}

	//deklarasi variabel yang digunakan untuk pengolahan data file secara matematika
	float e = 16.02, mo = 0.9109, c = 2.9979, dalam_akar = 0;
	float m = 0, v = 0;

	//pengolahan data file hingga didapatkan m dan v
	for (i=0; i<10; i++){
        m = ((tegangan[i]*e)+(mo*pow(c,2)))/(pow(c,2));
        dalam_akar = 1 - (pow(mo,2)/pow(m,2));
        v = c * pow(dalam_akar,0.5);
        //print output untuk setiap data tegangan
        printf("Untuk tegangan %.1lf x 10^6 V, didapatkan m = %.3lf x 10^-30 kg and v = %.3lf X 10^8 m/s.\n", tegangan[i], m, v);
	}

	fclose(fp);

	return;
}
