#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_8510413922011297063);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4280803739659174345);
void car_H_mod_fun(double *state, double *out_6904337138715130404);
void car_f_fun(double *state, double dt, double *out_8171731221525875871);
void car_F_fun(double *state, double dt, double *out_371263271310610131);
void car_h_25(double *state, double *unused, double *out_283920167104337104);
void car_H_25(double *state, double *unused, double *out_6638715109809756372);
void car_h_24(double *state, double *unused, double *out_3148110347797342465);
void car_H_24(double *state, double *unused, double *out_7035360414163615867);
void car_h_30(double *state, double *unused, double *out_1986868367660494242);
void car_H_30(double *state, double *unused, double *out_4120382151302507745);
void car_h_26(double *state, double *unused, double *out_7033675044779982200);
void car_H_26(double *state, double *unused, double *out_8066525645025739020);
void car_h_27(double *state, double *unused, double *out_4046310608617749603);
void car_H_27(double *state, double *unused, double *out_1896788080118564528);
void car_h_29(double *state, double *unused, double *out_3834962042136299582);
void car_H_29(double *state, double *unused, double *out_3610150806988115561);
void car_h_28(double *state, double *unused, double *out_5630877064939523228);
void car_H_28(double *state, double *unused, double *out_8692549824057646135);
void car_h_31(double *state, double *unused, double *out_7597352483649712081);
void car_H_31(double *state, double *unused, double *out_6608069147932795944);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}