#include <check.h>

#include "s21_viewer.h"

START_TEST(test_1) {
  data_t obj = {'\0'};
  char file_path[30] = "obj/cub.obj";
  s21_count_v_f(file_path, &obj);
  s21_read(file_path, &obj);
  double vertex[24] = {1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000,
                       1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000,
                       -1.000000, -1.000000, 1.000000,  1.000000,  -0.999999,
                       0.999999,  1.000000,  1.000001,  -1.000000, 1.000000,
                       1.000000,  -1.000000, 1.000000,  -1.000000};
  for (int i = 0; i < 24; i++) {
    ck_assert_double_eq_tol(obj.vertexes[i], vertex[i], 1);
  }
  free(obj.facets);
  free(obj.vertexes);
}
END_TEST

START_TEST(test_2) {
  data_t obj;
  char file_path[30] = "obj/cub.obj";
  s21_count_v_f(file_path, &obj);
  s21_read(file_path, &obj);
  int indices_1[] = {1, 2, 2, 3, 3, 1, 7, 6, 6, 5, 5, 7, 4, 5, 5, 1, 1, 4,
                     5, 6, 6, 2, 2, 5, 2, 6, 6, 7, 7, 2, 0, 3, 3, 7, 7, 0,
                     0, 1, 1, 3, 3, 0, 4, 7, 7, 5, 5, 4, 0, 4, 4, 1, 1, 0,
                     1, 5, 5, 2, 2, 1, 3, 2, 2, 7, 7, 3, 4, 0, 0, 7, 7, 4};
  for (size_t i = 0; i < 72; i++) {
    ck_assert_int_eq(obj.facets[i], indices_1[i]);
  }
  free(obj.facets);
  free(obj.vertexes);
}
END_TEST

START_TEST(test_8) {
  data_t obj = {'\0'};
  char file_path[30] = "obj/cub.obj";
  s21_count_v_f(file_path, &obj);
  ck_assert_int_eq(obj.count_facets, 36);
  // free(obj.count_facets);
}

START_TEST(test_9) {
  data_t obj = {'\0'};
  char file_path[30] = "obj/cub.obj";
  s21_count_v_f(file_path, &obj);
  ck_assert_int_eq(obj.count_vert, 8);
  // free(obj.count_vert);
}

START_TEST(test_3) {
  data_t obj = {'\0'};
  char file_path[30] = "obj/cub.obj";
  s21_count_v_f(file_path, &obj);
  s21_read(file_path, &obj);
  s21_moveX(&obj.vertexes, 0.9, obj.count_vert * 3);
  double vertex_1[] = {1.900000,  -1.000000, -1.000000, 1.900000,  -1.000000,
                       1.000000,  -0.100000, -1.000000, 1.000000,  -0.100000,
                       -1.000000, -1.000000, 1.900000,  1.000000,  -0.999999,
                       1.899999,  1.000000,  1.000001,  -0.100000, 1.000000,
                       1.000000,  -0.100000, 1.000000,  -1.000000};
  for (size_t i = 0; i < 24; i++) {
    // printf("%lf,", obj.vertexes[i]);
    ck_assert_int_eq(obj.vertexes[i], vertex_1[i]);
  }
  free(obj.facets);
  free(obj.vertexes);
}
END_TEST

START_TEST(test_4) {
  data_t obj = {'\0'};
  char file_path[30] = "obj/cub.obj";
  s21_count_v_f(file_path, &obj);
  s21_read(file_path, &obj);
  // s21_moveX(&obj.vertexes, 0.9, obj.count_vert * 3);
  s21_moveY(&obj.vertexes, -1.4, obj.count_vert * 3);
  double vertex_1[] = {1.000000,  -2.400000, -1.000000, 1.000000,  -2.400000,
                       1.000000,  -1.000000, -2.400000, 1.000000,  -1.000000,
                       -2.400000, -1.000000, 1.000000,  -0.400000, -0.999999,
                       0.999999,  -0.400000, 1.000001,  -1.000000, -0.400000,
                       1.000000,  -1.000000, -0.400000, -1.000000};
  for (size_t i = 0; i < 24; i++) {
    // printf("%lf,", obj.vertexes[i]);
    ck_assert_int_eq(obj.vertexes[i], vertex_1[i]);
  }
  free(obj.facets);
  free(obj.vertexes);
}
END_TEST

START_TEST(test_5) {
  data_t obj = {'\0'};
  char file_path[30] = "obj/cub.obj";
  s21_count_v_f(file_path, &obj);
  s21_read(file_path, &obj);
  s21_moveZ(&obj.vertexes, 2.3, obj.count_vert * 3);
  double vertex_1[] = {1.000000,  -1.000000, 1.300000,  1.000000,  -1.000000,
                       3.300000,  -1.000000, -1.000000, 3.300000,  -1.000000,
                       -1.000000, 1.300000,  1.000000,  1.000000,  1.300001,
                       0.999999,  1.000000,  3.300001,  -1.000000, 1.000000,
                       3.300000,  -1.000000, 1.000000,  1.300000};
  for (size_t i = 0; i < 24; i++) {
    // printf("%lf,", obj.vertexes[i]);
    ck_assert_int_eq(obj.vertexes[i], vertex_1[i]);
  }
  free(obj.facets);
  free(obj.vertexes);
}
END_TEST

START_TEST(test_6) {
  data_t obj = {'\0'};
  char file_path[30] = "obj/cub.obj";
  s21_count_v_f(file_path, &obj);
  s21_read(file_path, &obj);
  s21_scale(&obj.vertexes, 2.3, obj.count_vert * 3);
  double vertex_1[] = {2.300000,  -2.300000, -2.300000, 2.300000,  -2.300000,
                       2.300000,  -2.300000, -2.300000, 2.300000,  -2.300000,
                       -2.300000, -2.300000, 2.300000,  2.300000,  -2.299998,
                       2.299998,  2.300000,  2.300002,  -2.300000, 2.300000,
                       2.300000,  -2.300000, 2.300000,  -2.300000};
  for (size_t i = 0; i < 24; i++) {
    // printf("%lf,", obj.vertexes[i]);
    ck_assert_int_eq(obj.vertexes[i], vertex_1[i]);
  }
  free(obj.facets);
  free(obj.vertexes);
}
END_TEST

START_TEST(test_7) {
  data_t obj = {'\0'};
  char file_path[30] = "obj/cub.obj";
  s21_count_v_f(file_path, &obj);
  s21_read(file_path, &obj);
  s21_rotate(&obj.vertexes, 'x', 1.1, obj.count_vert * 3);
  s21_rotate(&obj.vertexes, 'y', 1.1, obj.count_vert * 3);
  s21_rotate(&obj.vertexes, 'z', 1.1, obj.count_vert * 3);
  double vertex_1[] = {-0.727887, -0.465364, -1.501205, 1.227345, -0.553322,
                       -1.089706, 0.815846,  -1.361819, 0.692709, -1.139386,
                       -1.273860, 0.281210,  -0.815845, 1.361819, -0.692708,
                       1.139387,  1.273860,  -0.281209, 0.727887, 0.465364,
                       1.501205,  -1.227345, 0.553322,  1.089706};
  for (size_t i = 0; i < 24; i++) {
    // printf("%lf,", obj.vertexes[i]);
    ck_assert_int_eq(obj.vertexes[i], vertex_1[i]);
  }
  free(obj.facets);
  free(obj.vertexes);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_1);
  tcase_add_test(tc1_1, test_2);
  tcase_add_test(tc1_1, test_3);
  tcase_add_test(tc1_1, test_4);
  tcase_add_test(tc1_1, test_5);
  tcase_add_test(tc1_1, test_6);
  tcase_add_test(tc1_1, test_7);
  tcase_add_test(tc1_1, test_8);
  tcase_add_test(tc1_1, test_9);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}