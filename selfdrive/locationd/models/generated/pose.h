#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_4640888545343984264);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8995415760930999757);
void pose_H_mod_fun(double *state, double *out_5774323429540918077);
void pose_f_fun(double *state, double dt, double *out_7338345877331788808);
void pose_F_fun(double *state, double dt, double *out_5312483910149324978);
void pose_h_4(double *state, double *unused, double *out_4643980062039690148);
void pose_H_4(double *state, double *unused, double *out_2425981454432306690);
void pose_h_10(double *state, double *unused, double *out_5661069393973278441);
void pose_H_10(double *state, double *unused, double *out_6368917634896469223);
void pose_h_13(double *state, double *unused, double *out_829426422309673114);
void pose_H_13(double *state, double *unused, double *out_8410131410960543997);
void pose_h_14(double *state, double *unused, double *out_158537382404063139);
void pose_H_14(double *state, double *unused, double *out_6389222310771791219);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}