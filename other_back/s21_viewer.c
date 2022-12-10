#include "s21_viewer.h"

// int main() {
//     data_t obj = {0};
//     index_f = 0;
//     index_v = 0;
//     s21_count_v_f("/Users/grandpat/3D_Viever_C/obj/cub.obj", &obj);
//     s21_read("/Users/grandpat/3D_Viever_C/obj/cub.obj", &obj);
//         // printf("\n");
//     for (int i = 0; i < index_f; i++) {
//         printf("vertex%lf,\n",obj.vertexes[i]);
//         printf("%u",obj.facets[i]);
//     }
//     free(obj.vertexes);
//     free(obj.facets);
//     return 0;
// }

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
    obj->vertexes = malloc((obj->count_vert * 3 * sizeof(double) + 1));
    obj->facets = malloc((obj->count_facets * 6 * sizeof(unsigned int) + 1));

        if ((text = fopen(file_name, "r")) != NULL) {
            while((fgets(ch, 255, text)) != NULL) { // считываем построчно
                if (ch[0] == 'v' && ch[1] == ' ') {
                    index_v += 2;
                    sscanf(ch, "v %lf %lf %lf", &obj->vertexes[index_v-2],\
                    &obj->vertexes[index_v-1], &obj->vertexes[index_v]);
                    index_v++;
                }
                else if (ch[0] == 'f' && ch[1] == ' ') {
                    s21_Fconnect(&obj, ch);
                }
            }
        }
    free(ch);
}

void s21_Fconnect(data_t **obj, char *ch) {
    
    int closure_val = '\0'; // для замыкания полигона
    int i_flag = 0; // порядковый номер записанного числа
    for (unsigned int i = 0; i < strlen(ch); i++) {
        long int val = 0; // для дублирования чисел
        if (ch[i] == ' ' && s21_digit_supp(ch[++i])) {
            ++i_flag;
            char str[10] = {'\0'};
            while (s21_digit_supp(ch[i])) {
                int j = 0;
                str[j] = ch[i];
                i++;
                j++;
            }
            char * pEnd;
            val = strtol(str, &pEnd, 10);
            (**obj).facets[index_f] = val;

            if (i_flag == 1) {
                // printf("end%d|", index_f);
                closure_val = val;
                ++index_f;                
            }
            if (i_flag != 1) {
                // printf("dubl%d|", index_f);
                (**obj).facets[++index_f] = val;
                ++index_f;
                
            }
        }
    }
    (**obj).facets[index_f-1] = closure_val;

    // printf("\n");
}

int s21_digit_supp(char ind) {
    int result = 0;
        if (ind >= '0' && ind <= '9') {
            result = 1;
            }
    return result;
}