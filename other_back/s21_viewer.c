#include "s21_viewer.h"


// вопорс про указатель . про 112 строчку.  хочу 2016г в пизду. а лучше вообще 15 и все нахуй бросить и заняться чем то полезным 
int main() {
    data_t obj = {0};
    index_f = 0;
    index_v = 0;
    s21_count_v_f("/Users/grandpat/3D_Viever_C/obj/cub.obj", &obj);
    s21_read("/Users/grandpat/3D_Viever_C/obj/cub.obj", &obj);
    for (int i = 0; i < 12; i++) {
        // printf("vertex%lf,\n",obj.vertexes[i]);
        printf("facet-s %u,\n",obj.facets[i]); 
    }
    return 0;
}

int s21_count_v_f(char* file_name, data_t *obj) { // открыли и посчитали, сколько нам потребуется памяти
    FILE *text;
    char ch[255] = { 0 };
    int y = strlen(ch); //длина строки
    int result = 0;

    if ((text = fopen(file_name, "r")) != NULL) {
        while ((fgets(ch, 255, text)) != NULL) { // считываем построчно
            if (ch[y - 1] == '\n') {
                ch[--y] = 0;
            }
            else if (ch[0] == 'v' && ch[1] == ' ') { //vertex
                obj->count_vert++;
            }
            else if (ch[0] == 'f' && ch[1] == ' ') { // facets
                obj->count_facets += s21_space_for_Fsupp(ch);
            }
        }
        fclose(text);
    }
    if(obj->count_vert < 3) {
        result = 1;
    }
    return result;
}

int s21_space_for_Fsupp(char *ch) {
    int i = 3;
    int space_count = 1;
    
    while(ch[i] != '\n' && ch[i] != EOF) {
        if (ch[i] == ' ') {
            space_count++;
            }
            i++;
        }
    return space_count;
}

void s21_read(char* file_name, data_t *obj) {
    FILE *text;
    char* ch = malloc(sizeof(char) * 255);
    int index = 0;
    int i = 0;
    obj->vertexes = malloc((obj->count_vert * 3 * sizeof(double) + 1));
    obj->facets = malloc((obj->count_facets * 6 * sizeof(unsigned int) + 1));

        if ((text = fopen(file_name, "r")) != NULL) {
            while((fgets(ch, 255, text)) != NULL) { // считываем построчно
                if (ch[0] == 'v' && ch[1] == ' ') {
                    sscanf(ch, "v %lf %lf %lf", &obj->vertexes[index_v],\
                    &obj->vertexes[index_v++], &obj->vertexes[index_v++]);
                    index_v++;
                    // printf("%lf,%lf,%lf\n", &obj->vertexes[i],&obj->vertexes[i++], &obj->vertexes[i++]);
                    i++;
                    // printf("%d\n",index);
                }
                else if (ch[0] == 'f' && ch[1] == ' ') {
                    s21_Fconnect(&obj, ch);
                    for (int i = 0; i < 3; i++) {
                    // printf("vertex%lf,\n",obj->vertexes[i]);
                    // printf("fas%d,\n",obj->facets[i]); 
                    }
                    
                }
            }
        }
    free(obj->vertexes);
    free(obj->facets);
    free(ch);
}

void s21_Fconnect(data_t **obj, char *ch) {
    
    int closure_val = 0; // для замыкания полигона
    // unsigned int f = 0;
    for (unsigned int i = 0; i < strlen(ch); i++) {
        // unsigned int number_val = 0; // порядковый номер записанного числа
        long int double_val = 0; // для дублирования чисел
        if (ch[i] == ' ' && s21_digit_supp(ch[++i])) {
            // number_val++;
            char str[10] = {'\0'};
            while (s21_digit_supp(ch[i])) {
                int j = 0;
                str[j] = ch[i];
                // printf("str-%s\n", str);
                i++;
                j++;
            }
            char * pEnd;
            double_val = strtol(str, &pEnd, 10);
            (**obj).facets[index_f] = double_val;
            printf("%u", (**obj).facets[index_f]);
            for (int i = 0; i < index_f; i++) {
                printf("che ne tak %u", (**obj).facets[i]);
            }
            // if (number_val == 1) {
            //     closure_val = obj->facets[f];
            //     f++;
            // }
            // if (number_val != 1) {
            //     obj->facets[++f] = double_val;
            //     f++;
            // }
        }
    }
    // (**obj).facets[f++] = closure_val;
}


// void s21_Fconnect(data_t *obj, char *ch) {
    
//     int closure_val = 0; // для замыкания полигона
//     // unsigned int f = 0;
//     for (unsigned int i = 0; i < strlen(ch); i++) {
//         // unsigned int number_val = 0; // порядковый номер записанного числа
//         long int double_val = 0; // для дублирования чисел
//         if (ch[i] == ' ' && s21_digit_supp(ch[++i])) {
//             // number_val++;
//             char str[10] = {'\0'};
//             while (s21_digit_supp(ch[i])) {
//                 int j = 0;
//                 str[j] = ch[i];
//                 // printf("str-%s\n", str);
//                 i++;
//                 j++;
//             }
//             char * pEnd;
//             double_val = strtol(str, &pEnd, 10);
//             (*obj).facets[index_f] = double_val;
//             printf("%u", (*obj).facets[index_f]);
//             for (int i = 0; i < index_f; i++) {
//                 printf("che ne tak %u", (*obj).facets[i]);
//             }
//         }
//     }
// }

int s21_digit_supp(char ind) {
    int result = 0;
        if (ind >= '0' && ind <= '9') {
            result = 1;
            }
    return result;
}