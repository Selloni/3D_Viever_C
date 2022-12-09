#include "s21_viewer.h"

//int main() {
// data_t obj;
// // FILE* f = fopen("/Users/myrebean/C8_3DViewer_v1.0-0/src/test.obj", "r");
// // s21_count_v(f, &obj);
// s21_count_v_f("/Users/grandpat/3D_Viever_C/obj/cub.obj", &obj);
// s21_read("/Users/grandpat/3D_Viever_C/obj/cub.obj", &obj);
// // s21_digits("/Users/myrebean/C8_3DViewer_v1.0-0/src/test.obj", &obj);
////   for (int i = 0; i != obj.count_vert; ++i) {
////     printf("%lf ", obj.vertexes[i]);
////   }
//}

int s21_count_v_f(char* file_name, data_t *obj) { // открыли и посчитали, сколько нам потребуется памяти
    FILE *text;
    char ch[255] = { 0 };
    int y = strlen(ch); //длина строки
    int result = 1;

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
        result = 0;
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

    obj->vertexes = malloc(obj->count_vert * 3 * sizeof(double));
    obj->facets = malloc(obj->count_facets * 6 * sizeof(unsigned int));

        if ((text = fopen(file_name, "r")) != NULL) {
            // while((fgets(ch, 255, text)) != NULL) { // считываем построчно
                fgets(ch, 255, text);
                int i = 0;
                // if (ch[0] == 'v' && ch[1] == ' ')
                    ch += 2;
                    sscanf(ch, "%lf", &obj->vertexes[i++]);
                    printf("%lf", obj->vertexes[0]);
                    ch += 9;
                    sscanf(ch, "%lf", &obj->vertexes[i++]);
                    printf("%lf", obj->vertexes[1]);
                    ch += 10;
                    sscanf(ch, "%lf", &obj->vertexes[i++]);
                    printf("%lf", obj->vertexes[2]);
                    // sscanf(ch, "v %lf %lf %lf", &obj->vertexes[0], &obj->vertexes[1], &obj->vertexes[2]); // почему-то записывает, ток 6/8 строк в кубе
                //printf("%lf %lf %lf\n", obj->vertexes[0], obj->vertexes[1], obj->vertexes[2]);
                // if (ch[0] == 'f' && ch[1] == ' ')
                //     s21_Fconnect(obj, ch);
            //}
        }
    free(obj->vertexes);
    free(obj->facets);
    free(ch);
}

void s21_Fconnect(data_t *obj, char *ch) {
    unsigned int double_val = 0; // для дублирования чисел
    unsigned int closure_val = 0; // для замыкания полигона
    unsigned int number_val = 0; // порядковый номер записанного числа
    unsigned int f = 0;

    for (unsigned int i = 0; i < strlen(ch); i++) {
        if (ch[i] == ' ' && s21_digit_supp(ch[i+1])) {
            number_val++;
            char *str = &ch[i];
            while (s21_digit_supp(ch[i])) {
                i++;
                str++;
                str = &ch[i];
            }
            double_val = atoi(str);
            obj->facets[f] = double_val;

            if (number_val == 1) {
                closure_val = obj->facets[f];
                f++;
            }

            if (number_val != 1) {
                obj->facets[++f] = double_val;
                f++;
            }
        }
    }
    obj->facets[f++] = closure_val;
}

int s21_digit_supp(char ind) {
    int result = 0;
        if (ind >= '0' && ind <= '9') {
            result = 1;
            }
    return result;
}
