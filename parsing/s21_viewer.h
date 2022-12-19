#ifndef SRC_S21_VIEWER_H_
#define SRC_S21_VIEWER_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int unint;

typedef struct DATA {
  unint count_vert;    // количество v
  unint count_facets;  // количество f
  double *vertexes;    // хранятся в, цифры
  unint *facets;  // массив, в нем полигоны, эфки 122331
} data_t;

////parser
// unint index_f;
// unint index_v;
int s21_count_v_f(char *file_name, data_t *obj);
void s21_read(char *file_name, data_t *obj);
int s21_digit_supp(char ind);
int s21_space_for_Fsupp(char *ch);
unint s21_Fconnect(data_t *obj, char *ch, unint index_f);

void s21_rotate(double **vertex, char xyz, double angle, unint i);
void s21_moveX(double **vertex, double move_x, unint count_v);
void s21_moveY(double **vertex, double move_y, unint count_v);
void s21_moveZ(double **vertex, double move_z, unint count_v);
void s21_scale(double **vertex, float scale, unint count_v);

#endif  // SRC_S21_VIEWER_H_
