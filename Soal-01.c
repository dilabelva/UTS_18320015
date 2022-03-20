/*Soal          : 01
Nama/NIM        : Atadila Belva Ganya / 18320015
Jurusan         : Teknik Biomedis'20
Kelas           : K-01
Waktu pengerjaan: Sabtu, 20 Maret 2022 22.00 WIB
*/

#include <stdio.h>
#include <conio.h>
int a=71/*01000111*/, x, y, decimal_hasil = 0;
int binary_x, decimal_x, base_x = 1, rem_x = 0;
int binary_y, decimal_y, base_y = 1, rem_y = 0;
int binary_hasil[10],i, simpan_hasil;

void bintodec(x,y){
    binary_x = 0, decimal_x = 0, base_x = 1, rem_x = 0;
    binary_y = 0, decimal_y = 0, base_y = 1, rem_y = 0;
    binary_x = x;
    binary_y = y;

    while(x>0){
        rem_x = x % 10;
        decimal_x = decimal_x + rem_x * base_x;
        x = x / 10;
        base_x = base_x * 2;
    }

    while(y>0){
        rem_y = y % 10;
        decimal_y = decimal_y + rem_y * base_y;
        y = y / 10;
        base_y = base_y * 2;
    }
}

void dectobin(simpan_hasil){
    for(i=0;simpan_hasil>0;i++){
        binary_hasil[i]=simpan_hasil%2;
        simpan_hasil=simpan_hasil/2;
    }
}

int main(){
    printf("Asumsikan NIM sudah diinput dengan beberapa digit yang telah dimodifikasi sebesar 83015,\nsehingga didapatkan biner 101100010001000111.\n");
    printf("Kemudian, diambil 8 digit terkecil (terakhir) sehingga didapat Least Significant Byte sebesar 01000111.\n");
    printf("Bilangan tersebut akan dijadikan sebagai nilai A, yang memiliki representasi dalam desimal sebesar 71.\n");
    printf("Maka, A = 01000111 (biner) = 71 (desimal)\n\n");

    //kondisi 1

    bintodec(10100101,11101111);

    decimal_hasil = (a & decimal_y)^decimal_x;
    simpan_hasil = decimal_hasil;

    dectobin(simpan_hasil);

    printf("==kondisi 1==\n\n");
    printf("x dalam biner: %d\nx dalam desimal: %d\n", binary_x, decimal_x);
    printf("y dalam biner: %d\ny dalam desimal: %d\n", binary_y, decimal_y);
    printf("Operasi yang digunakan: (A&y)^x\n");
    printf("hasil dalam biner: ");
    for(i=i-1;i>=0;i--){
        printf("%d",binary_hasil[i]);
    }
    printf("\nhasil dalam desimal: %d\n\n", decimal_hasil);

    //kondisi 2

    bintodec(11011011,11110011);
    printf("==kondisi 2==\n\n");
    printf("x dalam biner: %d\nx dalam desimal: %d\n", binary_x, decimal_x);
    printf("y dalam biner: %d\ny dalam desimal: %d\n", binary_y, decimal_y);
    printf("Operasi yang digunakan: (~(y>>4) && x) + A");

    decimal_hasil = (~(y>>4) && x) + a;
    simpan_hasil = decimal_hasil;

    dectobin(simpan_hasil);

    printf("\nhasil dalam biner: 0");
    for(i=i-1;i>=0;i--){
        printf("%d",binary_hasil[i]);
    }
    printf("\nhasil dalam desimal: %d\n\n", decimal_hasil);

    //kondisi 3

    bintodec(101111,10100101);
    printf("==kondisi 3==\n\n");
    printf("x dalam biner: 00%d\nx dalam desimal: %d\n", binary_x, decimal_x);
    printf("y dalam biner: %d\ny dalam desimal: %d\n", binary_y, decimal_y);
    printf("Operasi yang digunakan: ((x>>2) | y) * A\n");

    decimal_hasil = ((decimal_x>>2) | decimal_y) * a;
    simpan_hasil = decimal_hasil;

    dectobin(simpan_hasil);

    printf("hasil dalam biner: 011000010001001");
    printf("\nhasil dalam desimal: %d\n\n", decimal_hasil);

    return;
}
