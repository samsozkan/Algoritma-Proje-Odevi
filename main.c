#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

const char matrix_bigram_strings[10][3] ={"th", "he", "in", "er", "an", "en", "ch", "de", "ei", "te"};

const char matrix_trigram_strings[10][4]={"the", "and", "ing", "ent", "ion", "der", "sch", "ich", "nde", "die"};

const char languages[2][8]={"english", "german"};

//Ingilizce dilinin frekans degerleri
 const float frequency_eng[20]={ 2.71, 2.33, 2.03, 1.78, 1.61, 1.13, 0.01, 0.01, 0.01, 0.01, 1.81, 0.73, 0.72, 0.42, 0.42, 0.01, 0.01, 0.01, 0.01, 0.01 };
 //Almanca dilinin frekans degerleri
 const float frequency_germ[20]={ 0.01, 0.89, 1.71, 3.90, 1.07, 3.61, 2.36, 2.31, 1.98, 1.98, 0.01, 0.01, 0.01, 0.01, 0.01, 1.04, 0.76, 0.75, 0.72, 0.62 };


float calculated_frequencies[20];
float distances [2]={0,0};


void filter_str(char str[]);
void tolower_str (char str[]); //Metnin tamamen kucuk harflere donusturuldugu fonksiyon
void harf_hesaplama (char str[]); //Metnin harf sayisinin hesaplandigi fonksiyon
void calculate_frequencies_bi(char str[]);
void calculate_frequencies_tri(char str[]);
void calculate_distances();
void detect_lang();

float harf_sayisi = 0; //Harf sayisinin tutuldugu degisken

int main()
{
    char metin[10000];
    printf("Metin giriniz: ");
    gets(metin);
    filter_str(metin);
    tolower_str(metin);
    harf_hesaplama(metin);
    calculate_frequencies_bi(metin);
    calculate_frequencies_tri(metin);
    calculate_distances();
    detect_lang();

	return 0;
}

void filter_str(char str[]){

    for (int i = 0; i < strlen(str); i++)
        str[i] = ( (str[i] >= 'a') && (str[i] <= 'z') ) ? str[i] //Karakterin [a,z] araliginda olup olmadigi kontrol edilir
               : ( (str[i] >= 'A') && (str[i] <= 'Z') ) ? str[i] //Karakterin [A,Z] araliginda olup olmadigi kontrol edilir
               : (str[i] == 32) ? str[i] //Karakterin bosluk karakteri olup olmadigi kontrol edilir
               : 32; //32 degeri bosluk karakterinin ASCII tablosundaki decimal karsiligidir

}

void tolower_str (char str[]){

    for (int i = 0; str[i] != '\0'; i++) //Sonlandirici karakter gorulene kadar dongu calisir
        if (str[i] >= 'A')
            if (str[i] <= 'Z')
                str[i] = tolower(str[i]); //[A-Z] araliginda olan karakter, kucuk harfe donusturulur

    printf("\nMetin guncellendi: ");
    puts(str);

}

//Bu fonksiyon metin filtrelendikten sonra cagrilmalidir
void harf_hesaplama(char str[]) {

    for (int i = 0; i < strlen(str); i++)
        if (str[i] != 32)
            harf_sayisi++; //Karakter, bosluk karakteri degilse harf sayisi bir artar
        else
            continue;

}

void calculate_frequencies_bi(char str[]){

    int bigram_sayisi[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //Aranilan bigramlarin metinde gecme sayilarinin tutuldugu dizi

    /* Metindeki i ve ++i indisli karakterler ile bigram dizisinin a. elemaninin 0 ve 1 indisli karakterleri eslesirse
    aranilan bigram metinde bulunmustur. Bu kosul her saglandiginda bigram_sayisi dizisindeki a indisli eleman bir arttirilir */

    for (int a = 0; a < 10; a++)
        for (int i = 0; i < strlen(str) - 1; i++)
            if ((str[i] == matrix_bigram_strings[a][0]) && (str[++i] == matrix_bigram_strings[a][1]))
                bigram_sayisi[a]++;
            else
                continue;

    /* Hesaplanan bigram sayilari, metindeki harf miktarinin yarisina bolunur ve 100 ile carpilarak frekans degerleri
    elde edilir. Bu degerler calculated_frequencies dizisine sirasiyla yerlestirilir */

    for (int a = 0; a < 10; a++)
        calculated_frequencies[a] = (bigram_sayisi[a] / (harf_sayisi / 2)) * 100;

    //Bigramlar ve frekans degerleri ekrana bastirilir
    printf("\nBigram frekanslari hesaplandi: ");
    for (int i = 0; i < 10; i++)
        printf("\n%s: %.2f ", matrix_bigram_strings[i], calculated_frequencies[i]);

}

void calculate_frequencies_tri(char str[]){

    int trigram_sayisi[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //Aranilan trigramlarin metinde gecme sayilarinin tutuldugu dizi


    /* Metindeki i, i+1 ve i+2 indisli karakterler ile trigram dizisinin a. elemaninin 0,1 ve 2 indisli karakterleri eslesirse
    aranilan trigram metinde bulunmustur. Bu kosul her saglandiginda trigram_sayisi dizisindeki a indisli eleman bir arttirilir */

    for (int a = 0; a < 10; a++)
        for (int i = 0; i < strlen(str); i++)
            if ((str[i] == matrix_trigram_strings[a][0]) && (str[i+1] == matrix_trigram_strings[a][1]) && (str[i+2] == matrix_trigram_strings[a][2]))
                trigram_sayisi[a]++;
            else
                continue;


    /* Hesaplanan trigram sayilari, metindeki harf miktarinin ucte birine bolunur ve 100 ile carpilarak frekans degerleri
    elde edilir. Bu degerler calculated_frequencies dizisine 10.indisten baslayarak sirasiyla yerlestirilir */

    for (int i = 10; i < 20; i++)
    calculated_frequencies[i] = (trigram_sayisi[i-10] / (harf_sayisi / 3)) * 100;

    //Trigramlar ve frekans degerleri ekrana bastirilir
    printf("\n\nTrigram frekanslari hesaplandi: ");
    for (int i = 0; i < 10; i++)
        printf("\n%s: %.2f ", matrix_trigram_strings[i], calculated_frequencies[i+10]);
}

void calculate_distances(){

    int oklit_eng = 0; //Frekanslar ile Ingilizce dilinin frekanslari arasindaki oklit uzakligi
    int oklit_germ = 0; //Frekanslar ile Almanca dilinin frekanslari arasindaki oklit uzakligi

    /* Oklit uzakligi hesaplanirken, metinden elde edilen frekanslar ile dilin frekanslari arasindaki
    farkin kareleri toplanir ve karekok icine alinir */

    for (int i = 0; i < 20; i++) {
    oklit_eng += pow(calculated_frequencies[i] - frequency_eng[i], 2);
    oklit_germ += pow(calculated_frequencies[i] - frequency_germ[i], 2);
    }

    oklit_eng = sqrt(oklit_eng);
    oklit_germ = sqrt(oklit_germ);

    //Hesaplanan oklit uzakliklari distances dizisine yerlestirilir
    distances[0] = oklit_eng;
    distances[1] = oklit_germ;
}

void detect_lang(){

    //Metin, hesaplanan oklit uzakligi daha kucuk olan dilde yazilmistir
    if (distances[0] < distances[1])
        printf("\n\nSonuc: Girilen metin Ingilizce'dir. (%s)\n", languages[0]);
    else
        printf("\n\nSonuc: Girilen metin Almanca'dir. (%s)\n", languages[1]);

}
