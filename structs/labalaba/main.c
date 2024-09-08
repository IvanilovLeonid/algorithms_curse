#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#define M 100
#define L 81
#define FCLR while(getc(file_from)!='\n');

struct book{
    char name[L], author[L];
    int price, pages;
    struct{
        char name_pub[L], city[L];
        int year;
    }publishing_house;
};

void n_to_0(char *s) {
    for (; *s && *s != '\n'; s++);
    *s = '\0';
}

int input_num_float(float min, float max, FILE *file_from) {
    float k = 0.0;
    int c;
    do {
        c = fscanf(file_from, "%f", &k);
        FCLR;
    } while (k < min || k > max || !c);
    return k;
}

int input_num(int min, int max, FILE *file_from) {
    int k = 0, c;
    do {
        c = fscanf(file_from, "%i", &k);
        FCLR;
    } while (k < min || k > max || !c);
    return k;
}

void input_str(char s[], FILE *file_from) {
    do {
        fgets(s, L, file_from);
    } while (strcmp(s, "") == 0);
    n_to_0(s);
}


int input_structs(struct book arr[]) {
    FILE *file_from;
    char filename_in[L];
    puts("Input name of file with data: ");
    gets(filename_in);
    if (!(file_from = fopen(filename_in, "r"))) {
        puts("File not found. ");
    }
    
    
    int k, i, c;
    time_t t;
    time(&t);
    struct tm *today = localtime(&t);
    int year = today->tm_year + 1900;
    c = fscanf(file_from, "%i", &k);
    if (c != 1) {
        puts("File is empty. ");
    }
    struct book *it;
    for (it = arr; it < arr + k; it++)
    {
        input_str(it->name, file_from);
        it->price = input_num_float(100.0, 50000.0, file_from);
        it->pages = input_num(5, 5000, file_from);
        input_str(it->author, file_from);
        it->publishing_house.year = input_num(1450, year, file_from);
        input_str(it->publishing_house.name_pub, file_from);
        input_str(it->publishing_house.city, file_from);
    }
    fclose(file_from);
    return k;
}

void output(struct book arr[], int k) {
    struct book *it;
    int j;
    for (it = arr, j = 1; it < arr + k, j <= k; it++, j++) {
        printf("Книга #%i \n", j);
        printf("Название: %s\n", it->name);
        printf("Цена: %i\n", it->price);
        printf("Число страниц: %i\n", it->pages);
        printf("Автор: %s\n", it->author);
        printf("Издательство: \n  Год издания: %i\n  Назвние издания: %s\n  Город: %s\n", it->publishing_house.year, it->publishing_house.name_pub, it->publishing_house.city);
        time_t start_time = time(NULL); // получаем текущее время
        while (difftime(time(NULL), start_time) < 2) {
            // ожидаем, пока не пройдет 10 секунд
        }

    }
}
//
//void find_cities(struct book arr[], int k){
//    int i, j, kf = 0;
//    char cities[M][L];
//    for(i = 0; i < k; i++){
//        int isUnique = 1;
//        for(j = 0; j < k && isUnique == 1; j++){
//            if (strcmp(arr[i].publishing_house.city, cities[j]) == 0){
//                isUnique = 0;
//            }
//        }
//        if (isUnique == 1){
//            strcpy(cities[kf++], arr[i].publishing_house.city);
//        }
//    }
//    
//    printf("\n");
//    
// 
//    int counter[kf];
//    for (i = 0; i < kf; i++){
//        int k1 = 0;
//        char names[k][L];
//        counter[i] = 0;
//        for(j = 0; j < k; j++){
//            if(strcmp(cities[i], arr[j].publishing_house.city) == 0){
//                int isUnique = 1;
//                for(int m = 0; m < k && isUnique == 1; m++){
//                    if(strcmp(arr[j].publishing_house.name_pub, names[m]) == 0){
//                        isUnique = 0;
//                    }
//                }
//                if (isUnique == 1){
//                    strcpy(names[k1++], arr[j].publishing_house.name_pub);
//                    counter[i]+=1;
//                }
//                
//            }
//        }
//        
//        
//    }
//    int maxx = 0;
//    for (int h = 0; h < kf; h++){
//        if(counter[h] > maxx){
//            maxx = counter[h];
//        }
//    }
//    for(int h = 0; h < kf; h++){
//        if(counter[h] == maxx)
//            printf("город с максимальным числом чит издательств %s\n", cities[h]);
//    }
//}
//
//

int main(void) {
    struct book arr[M];
    int n;
    n = input_structs(arr);
    output(arr, n);
//    find_cities(arr, n);
    return 0;
}


