#ifndef SRC_S21_VIEWER_H_
#define SRC_S21_VIEWER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <../3DWieve/scene.h>

typedef struct DATA {
    unsigned int count_vert; // количество v
    unsigned int count_facets; // количество f
    double *vertexes; // хранятся в, цифры
    unsigned int *facets; // массив, в нем полигоны, эфки 122331
} data_t;


////parser
//unsigned int index_f;
//unsigned int index_v;
int s21_count_v_f(char* file_name, data_t *obj);
void s21_read(char* file_name, data_t *obj, unsigned int index_f, unsigned int index_v);
int s21_digit_supp(char ind);
int s21_space_for_Fsupp(char *ch);
unsigned int s21_Fconnect(data_t *obj, char *ch, unsigned int index_f);

#endif  // SRC_S21_VIEWER_H_
