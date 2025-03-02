#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.13.2                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4640888545343984264) {
   out_4640888545343984264[0] = delta_x[0] + nom_x[0];
   out_4640888545343984264[1] = delta_x[1] + nom_x[1];
   out_4640888545343984264[2] = delta_x[2] + nom_x[2];
   out_4640888545343984264[3] = delta_x[3] + nom_x[3];
   out_4640888545343984264[4] = delta_x[4] + nom_x[4];
   out_4640888545343984264[5] = delta_x[5] + nom_x[5];
   out_4640888545343984264[6] = delta_x[6] + nom_x[6];
   out_4640888545343984264[7] = delta_x[7] + nom_x[7];
   out_4640888545343984264[8] = delta_x[8] + nom_x[8];
   out_4640888545343984264[9] = delta_x[9] + nom_x[9];
   out_4640888545343984264[10] = delta_x[10] + nom_x[10];
   out_4640888545343984264[11] = delta_x[11] + nom_x[11];
   out_4640888545343984264[12] = delta_x[12] + nom_x[12];
   out_4640888545343984264[13] = delta_x[13] + nom_x[13];
   out_4640888545343984264[14] = delta_x[14] + nom_x[14];
   out_4640888545343984264[15] = delta_x[15] + nom_x[15];
   out_4640888545343984264[16] = delta_x[16] + nom_x[16];
   out_4640888545343984264[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8995415760930999757) {
   out_8995415760930999757[0] = -nom_x[0] + true_x[0];
   out_8995415760930999757[1] = -nom_x[1] + true_x[1];
   out_8995415760930999757[2] = -nom_x[2] + true_x[2];
   out_8995415760930999757[3] = -nom_x[3] + true_x[3];
   out_8995415760930999757[4] = -nom_x[4] + true_x[4];
   out_8995415760930999757[5] = -nom_x[5] + true_x[5];
   out_8995415760930999757[6] = -nom_x[6] + true_x[6];
   out_8995415760930999757[7] = -nom_x[7] + true_x[7];
   out_8995415760930999757[8] = -nom_x[8] + true_x[8];
   out_8995415760930999757[9] = -nom_x[9] + true_x[9];
   out_8995415760930999757[10] = -nom_x[10] + true_x[10];
   out_8995415760930999757[11] = -nom_x[11] + true_x[11];
   out_8995415760930999757[12] = -nom_x[12] + true_x[12];
   out_8995415760930999757[13] = -nom_x[13] + true_x[13];
   out_8995415760930999757[14] = -nom_x[14] + true_x[14];
   out_8995415760930999757[15] = -nom_x[15] + true_x[15];
   out_8995415760930999757[16] = -nom_x[16] + true_x[16];
   out_8995415760930999757[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5774323429540918077) {
   out_5774323429540918077[0] = 1.0;
   out_5774323429540918077[1] = 0.0;
   out_5774323429540918077[2] = 0.0;
   out_5774323429540918077[3] = 0.0;
   out_5774323429540918077[4] = 0.0;
   out_5774323429540918077[5] = 0.0;
   out_5774323429540918077[6] = 0.0;
   out_5774323429540918077[7] = 0.0;
   out_5774323429540918077[8] = 0.0;
   out_5774323429540918077[9] = 0.0;
   out_5774323429540918077[10] = 0.0;
   out_5774323429540918077[11] = 0.0;
   out_5774323429540918077[12] = 0.0;
   out_5774323429540918077[13] = 0.0;
   out_5774323429540918077[14] = 0.0;
   out_5774323429540918077[15] = 0.0;
   out_5774323429540918077[16] = 0.0;
   out_5774323429540918077[17] = 0.0;
   out_5774323429540918077[18] = 0.0;
   out_5774323429540918077[19] = 1.0;
   out_5774323429540918077[20] = 0.0;
   out_5774323429540918077[21] = 0.0;
   out_5774323429540918077[22] = 0.0;
   out_5774323429540918077[23] = 0.0;
   out_5774323429540918077[24] = 0.0;
   out_5774323429540918077[25] = 0.0;
   out_5774323429540918077[26] = 0.0;
   out_5774323429540918077[27] = 0.0;
   out_5774323429540918077[28] = 0.0;
   out_5774323429540918077[29] = 0.0;
   out_5774323429540918077[30] = 0.0;
   out_5774323429540918077[31] = 0.0;
   out_5774323429540918077[32] = 0.0;
   out_5774323429540918077[33] = 0.0;
   out_5774323429540918077[34] = 0.0;
   out_5774323429540918077[35] = 0.0;
   out_5774323429540918077[36] = 0.0;
   out_5774323429540918077[37] = 0.0;
   out_5774323429540918077[38] = 1.0;
   out_5774323429540918077[39] = 0.0;
   out_5774323429540918077[40] = 0.0;
   out_5774323429540918077[41] = 0.0;
   out_5774323429540918077[42] = 0.0;
   out_5774323429540918077[43] = 0.0;
   out_5774323429540918077[44] = 0.0;
   out_5774323429540918077[45] = 0.0;
   out_5774323429540918077[46] = 0.0;
   out_5774323429540918077[47] = 0.0;
   out_5774323429540918077[48] = 0.0;
   out_5774323429540918077[49] = 0.0;
   out_5774323429540918077[50] = 0.0;
   out_5774323429540918077[51] = 0.0;
   out_5774323429540918077[52] = 0.0;
   out_5774323429540918077[53] = 0.0;
   out_5774323429540918077[54] = 0.0;
   out_5774323429540918077[55] = 0.0;
   out_5774323429540918077[56] = 0.0;
   out_5774323429540918077[57] = 1.0;
   out_5774323429540918077[58] = 0.0;
   out_5774323429540918077[59] = 0.0;
   out_5774323429540918077[60] = 0.0;
   out_5774323429540918077[61] = 0.0;
   out_5774323429540918077[62] = 0.0;
   out_5774323429540918077[63] = 0.0;
   out_5774323429540918077[64] = 0.0;
   out_5774323429540918077[65] = 0.0;
   out_5774323429540918077[66] = 0.0;
   out_5774323429540918077[67] = 0.0;
   out_5774323429540918077[68] = 0.0;
   out_5774323429540918077[69] = 0.0;
   out_5774323429540918077[70] = 0.0;
   out_5774323429540918077[71] = 0.0;
   out_5774323429540918077[72] = 0.0;
   out_5774323429540918077[73] = 0.0;
   out_5774323429540918077[74] = 0.0;
   out_5774323429540918077[75] = 0.0;
   out_5774323429540918077[76] = 1.0;
   out_5774323429540918077[77] = 0.0;
   out_5774323429540918077[78] = 0.0;
   out_5774323429540918077[79] = 0.0;
   out_5774323429540918077[80] = 0.0;
   out_5774323429540918077[81] = 0.0;
   out_5774323429540918077[82] = 0.0;
   out_5774323429540918077[83] = 0.0;
   out_5774323429540918077[84] = 0.0;
   out_5774323429540918077[85] = 0.0;
   out_5774323429540918077[86] = 0.0;
   out_5774323429540918077[87] = 0.0;
   out_5774323429540918077[88] = 0.0;
   out_5774323429540918077[89] = 0.0;
   out_5774323429540918077[90] = 0.0;
   out_5774323429540918077[91] = 0.0;
   out_5774323429540918077[92] = 0.0;
   out_5774323429540918077[93] = 0.0;
   out_5774323429540918077[94] = 0.0;
   out_5774323429540918077[95] = 1.0;
   out_5774323429540918077[96] = 0.0;
   out_5774323429540918077[97] = 0.0;
   out_5774323429540918077[98] = 0.0;
   out_5774323429540918077[99] = 0.0;
   out_5774323429540918077[100] = 0.0;
   out_5774323429540918077[101] = 0.0;
   out_5774323429540918077[102] = 0.0;
   out_5774323429540918077[103] = 0.0;
   out_5774323429540918077[104] = 0.0;
   out_5774323429540918077[105] = 0.0;
   out_5774323429540918077[106] = 0.0;
   out_5774323429540918077[107] = 0.0;
   out_5774323429540918077[108] = 0.0;
   out_5774323429540918077[109] = 0.0;
   out_5774323429540918077[110] = 0.0;
   out_5774323429540918077[111] = 0.0;
   out_5774323429540918077[112] = 0.0;
   out_5774323429540918077[113] = 0.0;
   out_5774323429540918077[114] = 1.0;
   out_5774323429540918077[115] = 0.0;
   out_5774323429540918077[116] = 0.0;
   out_5774323429540918077[117] = 0.0;
   out_5774323429540918077[118] = 0.0;
   out_5774323429540918077[119] = 0.0;
   out_5774323429540918077[120] = 0.0;
   out_5774323429540918077[121] = 0.0;
   out_5774323429540918077[122] = 0.0;
   out_5774323429540918077[123] = 0.0;
   out_5774323429540918077[124] = 0.0;
   out_5774323429540918077[125] = 0.0;
   out_5774323429540918077[126] = 0.0;
   out_5774323429540918077[127] = 0.0;
   out_5774323429540918077[128] = 0.0;
   out_5774323429540918077[129] = 0.0;
   out_5774323429540918077[130] = 0.0;
   out_5774323429540918077[131] = 0.0;
   out_5774323429540918077[132] = 0.0;
   out_5774323429540918077[133] = 1.0;
   out_5774323429540918077[134] = 0.0;
   out_5774323429540918077[135] = 0.0;
   out_5774323429540918077[136] = 0.0;
   out_5774323429540918077[137] = 0.0;
   out_5774323429540918077[138] = 0.0;
   out_5774323429540918077[139] = 0.0;
   out_5774323429540918077[140] = 0.0;
   out_5774323429540918077[141] = 0.0;
   out_5774323429540918077[142] = 0.0;
   out_5774323429540918077[143] = 0.0;
   out_5774323429540918077[144] = 0.0;
   out_5774323429540918077[145] = 0.0;
   out_5774323429540918077[146] = 0.0;
   out_5774323429540918077[147] = 0.0;
   out_5774323429540918077[148] = 0.0;
   out_5774323429540918077[149] = 0.0;
   out_5774323429540918077[150] = 0.0;
   out_5774323429540918077[151] = 0.0;
   out_5774323429540918077[152] = 1.0;
   out_5774323429540918077[153] = 0.0;
   out_5774323429540918077[154] = 0.0;
   out_5774323429540918077[155] = 0.0;
   out_5774323429540918077[156] = 0.0;
   out_5774323429540918077[157] = 0.0;
   out_5774323429540918077[158] = 0.0;
   out_5774323429540918077[159] = 0.0;
   out_5774323429540918077[160] = 0.0;
   out_5774323429540918077[161] = 0.0;
   out_5774323429540918077[162] = 0.0;
   out_5774323429540918077[163] = 0.0;
   out_5774323429540918077[164] = 0.0;
   out_5774323429540918077[165] = 0.0;
   out_5774323429540918077[166] = 0.0;
   out_5774323429540918077[167] = 0.0;
   out_5774323429540918077[168] = 0.0;
   out_5774323429540918077[169] = 0.0;
   out_5774323429540918077[170] = 0.0;
   out_5774323429540918077[171] = 1.0;
   out_5774323429540918077[172] = 0.0;
   out_5774323429540918077[173] = 0.0;
   out_5774323429540918077[174] = 0.0;
   out_5774323429540918077[175] = 0.0;
   out_5774323429540918077[176] = 0.0;
   out_5774323429540918077[177] = 0.0;
   out_5774323429540918077[178] = 0.0;
   out_5774323429540918077[179] = 0.0;
   out_5774323429540918077[180] = 0.0;
   out_5774323429540918077[181] = 0.0;
   out_5774323429540918077[182] = 0.0;
   out_5774323429540918077[183] = 0.0;
   out_5774323429540918077[184] = 0.0;
   out_5774323429540918077[185] = 0.0;
   out_5774323429540918077[186] = 0.0;
   out_5774323429540918077[187] = 0.0;
   out_5774323429540918077[188] = 0.0;
   out_5774323429540918077[189] = 0.0;
   out_5774323429540918077[190] = 1.0;
   out_5774323429540918077[191] = 0.0;
   out_5774323429540918077[192] = 0.0;
   out_5774323429540918077[193] = 0.0;
   out_5774323429540918077[194] = 0.0;
   out_5774323429540918077[195] = 0.0;
   out_5774323429540918077[196] = 0.0;
   out_5774323429540918077[197] = 0.0;
   out_5774323429540918077[198] = 0.0;
   out_5774323429540918077[199] = 0.0;
   out_5774323429540918077[200] = 0.0;
   out_5774323429540918077[201] = 0.0;
   out_5774323429540918077[202] = 0.0;
   out_5774323429540918077[203] = 0.0;
   out_5774323429540918077[204] = 0.0;
   out_5774323429540918077[205] = 0.0;
   out_5774323429540918077[206] = 0.0;
   out_5774323429540918077[207] = 0.0;
   out_5774323429540918077[208] = 0.0;
   out_5774323429540918077[209] = 1.0;
   out_5774323429540918077[210] = 0.0;
   out_5774323429540918077[211] = 0.0;
   out_5774323429540918077[212] = 0.0;
   out_5774323429540918077[213] = 0.0;
   out_5774323429540918077[214] = 0.0;
   out_5774323429540918077[215] = 0.0;
   out_5774323429540918077[216] = 0.0;
   out_5774323429540918077[217] = 0.0;
   out_5774323429540918077[218] = 0.0;
   out_5774323429540918077[219] = 0.0;
   out_5774323429540918077[220] = 0.0;
   out_5774323429540918077[221] = 0.0;
   out_5774323429540918077[222] = 0.0;
   out_5774323429540918077[223] = 0.0;
   out_5774323429540918077[224] = 0.0;
   out_5774323429540918077[225] = 0.0;
   out_5774323429540918077[226] = 0.0;
   out_5774323429540918077[227] = 0.0;
   out_5774323429540918077[228] = 1.0;
   out_5774323429540918077[229] = 0.0;
   out_5774323429540918077[230] = 0.0;
   out_5774323429540918077[231] = 0.0;
   out_5774323429540918077[232] = 0.0;
   out_5774323429540918077[233] = 0.0;
   out_5774323429540918077[234] = 0.0;
   out_5774323429540918077[235] = 0.0;
   out_5774323429540918077[236] = 0.0;
   out_5774323429540918077[237] = 0.0;
   out_5774323429540918077[238] = 0.0;
   out_5774323429540918077[239] = 0.0;
   out_5774323429540918077[240] = 0.0;
   out_5774323429540918077[241] = 0.0;
   out_5774323429540918077[242] = 0.0;
   out_5774323429540918077[243] = 0.0;
   out_5774323429540918077[244] = 0.0;
   out_5774323429540918077[245] = 0.0;
   out_5774323429540918077[246] = 0.0;
   out_5774323429540918077[247] = 1.0;
   out_5774323429540918077[248] = 0.0;
   out_5774323429540918077[249] = 0.0;
   out_5774323429540918077[250] = 0.0;
   out_5774323429540918077[251] = 0.0;
   out_5774323429540918077[252] = 0.0;
   out_5774323429540918077[253] = 0.0;
   out_5774323429540918077[254] = 0.0;
   out_5774323429540918077[255] = 0.0;
   out_5774323429540918077[256] = 0.0;
   out_5774323429540918077[257] = 0.0;
   out_5774323429540918077[258] = 0.0;
   out_5774323429540918077[259] = 0.0;
   out_5774323429540918077[260] = 0.0;
   out_5774323429540918077[261] = 0.0;
   out_5774323429540918077[262] = 0.0;
   out_5774323429540918077[263] = 0.0;
   out_5774323429540918077[264] = 0.0;
   out_5774323429540918077[265] = 0.0;
   out_5774323429540918077[266] = 1.0;
   out_5774323429540918077[267] = 0.0;
   out_5774323429540918077[268] = 0.0;
   out_5774323429540918077[269] = 0.0;
   out_5774323429540918077[270] = 0.0;
   out_5774323429540918077[271] = 0.0;
   out_5774323429540918077[272] = 0.0;
   out_5774323429540918077[273] = 0.0;
   out_5774323429540918077[274] = 0.0;
   out_5774323429540918077[275] = 0.0;
   out_5774323429540918077[276] = 0.0;
   out_5774323429540918077[277] = 0.0;
   out_5774323429540918077[278] = 0.0;
   out_5774323429540918077[279] = 0.0;
   out_5774323429540918077[280] = 0.0;
   out_5774323429540918077[281] = 0.0;
   out_5774323429540918077[282] = 0.0;
   out_5774323429540918077[283] = 0.0;
   out_5774323429540918077[284] = 0.0;
   out_5774323429540918077[285] = 1.0;
   out_5774323429540918077[286] = 0.0;
   out_5774323429540918077[287] = 0.0;
   out_5774323429540918077[288] = 0.0;
   out_5774323429540918077[289] = 0.0;
   out_5774323429540918077[290] = 0.0;
   out_5774323429540918077[291] = 0.0;
   out_5774323429540918077[292] = 0.0;
   out_5774323429540918077[293] = 0.0;
   out_5774323429540918077[294] = 0.0;
   out_5774323429540918077[295] = 0.0;
   out_5774323429540918077[296] = 0.0;
   out_5774323429540918077[297] = 0.0;
   out_5774323429540918077[298] = 0.0;
   out_5774323429540918077[299] = 0.0;
   out_5774323429540918077[300] = 0.0;
   out_5774323429540918077[301] = 0.0;
   out_5774323429540918077[302] = 0.0;
   out_5774323429540918077[303] = 0.0;
   out_5774323429540918077[304] = 1.0;
   out_5774323429540918077[305] = 0.0;
   out_5774323429540918077[306] = 0.0;
   out_5774323429540918077[307] = 0.0;
   out_5774323429540918077[308] = 0.0;
   out_5774323429540918077[309] = 0.0;
   out_5774323429540918077[310] = 0.0;
   out_5774323429540918077[311] = 0.0;
   out_5774323429540918077[312] = 0.0;
   out_5774323429540918077[313] = 0.0;
   out_5774323429540918077[314] = 0.0;
   out_5774323429540918077[315] = 0.0;
   out_5774323429540918077[316] = 0.0;
   out_5774323429540918077[317] = 0.0;
   out_5774323429540918077[318] = 0.0;
   out_5774323429540918077[319] = 0.0;
   out_5774323429540918077[320] = 0.0;
   out_5774323429540918077[321] = 0.0;
   out_5774323429540918077[322] = 0.0;
   out_5774323429540918077[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7338345877331788808) {
   out_7338345877331788808[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7338345877331788808[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7338345877331788808[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7338345877331788808[3] = dt*state[12] + state[3];
   out_7338345877331788808[4] = dt*state[13] + state[4];
   out_7338345877331788808[5] = dt*state[14] + state[5];
   out_7338345877331788808[6] = state[6];
   out_7338345877331788808[7] = state[7];
   out_7338345877331788808[8] = state[8];
   out_7338345877331788808[9] = state[9];
   out_7338345877331788808[10] = state[10];
   out_7338345877331788808[11] = state[11];
   out_7338345877331788808[12] = state[12];
   out_7338345877331788808[13] = state[13];
   out_7338345877331788808[14] = state[14];
   out_7338345877331788808[15] = state[15];
   out_7338345877331788808[16] = state[16];
   out_7338345877331788808[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5312483910149324978) {
   out_5312483910149324978[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5312483910149324978[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5312483910149324978[2] = 0;
   out_5312483910149324978[3] = 0;
   out_5312483910149324978[4] = 0;
   out_5312483910149324978[5] = 0;
   out_5312483910149324978[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5312483910149324978[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5312483910149324978[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5312483910149324978[9] = 0;
   out_5312483910149324978[10] = 0;
   out_5312483910149324978[11] = 0;
   out_5312483910149324978[12] = 0;
   out_5312483910149324978[13] = 0;
   out_5312483910149324978[14] = 0;
   out_5312483910149324978[15] = 0;
   out_5312483910149324978[16] = 0;
   out_5312483910149324978[17] = 0;
   out_5312483910149324978[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5312483910149324978[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5312483910149324978[20] = 0;
   out_5312483910149324978[21] = 0;
   out_5312483910149324978[22] = 0;
   out_5312483910149324978[23] = 0;
   out_5312483910149324978[24] = 0;
   out_5312483910149324978[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5312483910149324978[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5312483910149324978[27] = 0;
   out_5312483910149324978[28] = 0;
   out_5312483910149324978[29] = 0;
   out_5312483910149324978[30] = 0;
   out_5312483910149324978[31] = 0;
   out_5312483910149324978[32] = 0;
   out_5312483910149324978[33] = 0;
   out_5312483910149324978[34] = 0;
   out_5312483910149324978[35] = 0;
   out_5312483910149324978[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5312483910149324978[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5312483910149324978[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5312483910149324978[39] = 0;
   out_5312483910149324978[40] = 0;
   out_5312483910149324978[41] = 0;
   out_5312483910149324978[42] = 0;
   out_5312483910149324978[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5312483910149324978[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5312483910149324978[45] = 0;
   out_5312483910149324978[46] = 0;
   out_5312483910149324978[47] = 0;
   out_5312483910149324978[48] = 0;
   out_5312483910149324978[49] = 0;
   out_5312483910149324978[50] = 0;
   out_5312483910149324978[51] = 0;
   out_5312483910149324978[52] = 0;
   out_5312483910149324978[53] = 0;
   out_5312483910149324978[54] = 0;
   out_5312483910149324978[55] = 0;
   out_5312483910149324978[56] = 0;
   out_5312483910149324978[57] = 1;
   out_5312483910149324978[58] = 0;
   out_5312483910149324978[59] = 0;
   out_5312483910149324978[60] = 0;
   out_5312483910149324978[61] = 0;
   out_5312483910149324978[62] = 0;
   out_5312483910149324978[63] = 0;
   out_5312483910149324978[64] = 0;
   out_5312483910149324978[65] = 0;
   out_5312483910149324978[66] = dt;
   out_5312483910149324978[67] = 0;
   out_5312483910149324978[68] = 0;
   out_5312483910149324978[69] = 0;
   out_5312483910149324978[70] = 0;
   out_5312483910149324978[71] = 0;
   out_5312483910149324978[72] = 0;
   out_5312483910149324978[73] = 0;
   out_5312483910149324978[74] = 0;
   out_5312483910149324978[75] = 0;
   out_5312483910149324978[76] = 1;
   out_5312483910149324978[77] = 0;
   out_5312483910149324978[78] = 0;
   out_5312483910149324978[79] = 0;
   out_5312483910149324978[80] = 0;
   out_5312483910149324978[81] = 0;
   out_5312483910149324978[82] = 0;
   out_5312483910149324978[83] = 0;
   out_5312483910149324978[84] = 0;
   out_5312483910149324978[85] = dt;
   out_5312483910149324978[86] = 0;
   out_5312483910149324978[87] = 0;
   out_5312483910149324978[88] = 0;
   out_5312483910149324978[89] = 0;
   out_5312483910149324978[90] = 0;
   out_5312483910149324978[91] = 0;
   out_5312483910149324978[92] = 0;
   out_5312483910149324978[93] = 0;
   out_5312483910149324978[94] = 0;
   out_5312483910149324978[95] = 1;
   out_5312483910149324978[96] = 0;
   out_5312483910149324978[97] = 0;
   out_5312483910149324978[98] = 0;
   out_5312483910149324978[99] = 0;
   out_5312483910149324978[100] = 0;
   out_5312483910149324978[101] = 0;
   out_5312483910149324978[102] = 0;
   out_5312483910149324978[103] = 0;
   out_5312483910149324978[104] = dt;
   out_5312483910149324978[105] = 0;
   out_5312483910149324978[106] = 0;
   out_5312483910149324978[107] = 0;
   out_5312483910149324978[108] = 0;
   out_5312483910149324978[109] = 0;
   out_5312483910149324978[110] = 0;
   out_5312483910149324978[111] = 0;
   out_5312483910149324978[112] = 0;
   out_5312483910149324978[113] = 0;
   out_5312483910149324978[114] = 1;
   out_5312483910149324978[115] = 0;
   out_5312483910149324978[116] = 0;
   out_5312483910149324978[117] = 0;
   out_5312483910149324978[118] = 0;
   out_5312483910149324978[119] = 0;
   out_5312483910149324978[120] = 0;
   out_5312483910149324978[121] = 0;
   out_5312483910149324978[122] = 0;
   out_5312483910149324978[123] = 0;
   out_5312483910149324978[124] = 0;
   out_5312483910149324978[125] = 0;
   out_5312483910149324978[126] = 0;
   out_5312483910149324978[127] = 0;
   out_5312483910149324978[128] = 0;
   out_5312483910149324978[129] = 0;
   out_5312483910149324978[130] = 0;
   out_5312483910149324978[131] = 0;
   out_5312483910149324978[132] = 0;
   out_5312483910149324978[133] = 1;
   out_5312483910149324978[134] = 0;
   out_5312483910149324978[135] = 0;
   out_5312483910149324978[136] = 0;
   out_5312483910149324978[137] = 0;
   out_5312483910149324978[138] = 0;
   out_5312483910149324978[139] = 0;
   out_5312483910149324978[140] = 0;
   out_5312483910149324978[141] = 0;
   out_5312483910149324978[142] = 0;
   out_5312483910149324978[143] = 0;
   out_5312483910149324978[144] = 0;
   out_5312483910149324978[145] = 0;
   out_5312483910149324978[146] = 0;
   out_5312483910149324978[147] = 0;
   out_5312483910149324978[148] = 0;
   out_5312483910149324978[149] = 0;
   out_5312483910149324978[150] = 0;
   out_5312483910149324978[151] = 0;
   out_5312483910149324978[152] = 1;
   out_5312483910149324978[153] = 0;
   out_5312483910149324978[154] = 0;
   out_5312483910149324978[155] = 0;
   out_5312483910149324978[156] = 0;
   out_5312483910149324978[157] = 0;
   out_5312483910149324978[158] = 0;
   out_5312483910149324978[159] = 0;
   out_5312483910149324978[160] = 0;
   out_5312483910149324978[161] = 0;
   out_5312483910149324978[162] = 0;
   out_5312483910149324978[163] = 0;
   out_5312483910149324978[164] = 0;
   out_5312483910149324978[165] = 0;
   out_5312483910149324978[166] = 0;
   out_5312483910149324978[167] = 0;
   out_5312483910149324978[168] = 0;
   out_5312483910149324978[169] = 0;
   out_5312483910149324978[170] = 0;
   out_5312483910149324978[171] = 1;
   out_5312483910149324978[172] = 0;
   out_5312483910149324978[173] = 0;
   out_5312483910149324978[174] = 0;
   out_5312483910149324978[175] = 0;
   out_5312483910149324978[176] = 0;
   out_5312483910149324978[177] = 0;
   out_5312483910149324978[178] = 0;
   out_5312483910149324978[179] = 0;
   out_5312483910149324978[180] = 0;
   out_5312483910149324978[181] = 0;
   out_5312483910149324978[182] = 0;
   out_5312483910149324978[183] = 0;
   out_5312483910149324978[184] = 0;
   out_5312483910149324978[185] = 0;
   out_5312483910149324978[186] = 0;
   out_5312483910149324978[187] = 0;
   out_5312483910149324978[188] = 0;
   out_5312483910149324978[189] = 0;
   out_5312483910149324978[190] = 1;
   out_5312483910149324978[191] = 0;
   out_5312483910149324978[192] = 0;
   out_5312483910149324978[193] = 0;
   out_5312483910149324978[194] = 0;
   out_5312483910149324978[195] = 0;
   out_5312483910149324978[196] = 0;
   out_5312483910149324978[197] = 0;
   out_5312483910149324978[198] = 0;
   out_5312483910149324978[199] = 0;
   out_5312483910149324978[200] = 0;
   out_5312483910149324978[201] = 0;
   out_5312483910149324978[202] = 0;
   out_5312483910149324978[203] = 0;
   out_5312483910149324978[204] = 0;
   out_5312483910149324978[205] = 0;
   out_5312483910149324978[206] = 0;
   out_5312483910149324978[207] = 0;
   out_5312483910149324978[208] = 0;
   out_5312483910149324978[209] = 1;
   out_5312483910149324978[210] = 0;
   out_5312483910149324978[211] = 0;
   out_5312483910149324978[212] = 0;
   out_5312483910149324978[213] = 0;
   out_5312483910149324978[214] = 0;
   out_5312483910149324978[215] = 0;
   out_5312483910149324978[216] = 0;
   out_5312483910149324978[217] = 0;
   out_5312483910149324978[218] = 0;
   out_5312483910149324978[219] = 0;
   out_5312483910149324978[220] = 0;
   out_5312483910149324978[221] = 0;
   out_5312483910149324978[222] = 0;
   out_5312483910149324978[223] = 0;
   out_5312483910149324978[224] = 0;
   out_5312483910149324978[225] = 0;
   out_5312483910149324978[226] = 0;
   out_5312483910149324978[227] = 0;
   out_5312483910149324978[228] = 1;
   out_5312483910149324978[229] = 0;
   out_5312483910149324978[230] = 0;
   out_5312483910149324978[231] = 0;
   out_5312483910149324978[232] = 0;
   out_5312483910149324978[233] = 0;
   out_5312483910149324978[234] = 0;
   out_5312483910149324978[235] = 0;
   out_5312483910149324978[236] = 0;
   out_5312483910149324978[237] = 0;
   out_5312483910149324978[238] = 0;
   out_5312483910149324978[239] = 0;
   out_5312483910149324978[240] = 0;
   out_5312483910149324978[241] = 0;
   out_5312483910149324978[242] = 0;
   out_5312483910149324978[243] = 0;
   out_5312483910149324978[244] = 0;
   out_5312483910149324978[245] = 0;
   out_5312483910149324978[246] = 0;
   out_5312483910149324978[247] = 1;
   out_5312483910149324978[248] = 0;
   out_5312483910149324978[249] = 0;
   out_5312483910149324978[250] = 0;
   out_5312483910149324978[251] = 0;
   out_5312483910149324978[252] = 0;
   out_5312483910149324978[253] = 0;
   out_5312483910149324978[254] = 0;
   out_5312483910149324978[255] = 0;
   out_5312483910149324978[256] = 0;
   out_5312483910149324978[257] = 0;
   out_5312483910149324978[258] = 0;
   out_5312483910149324978[259] = 0;
   out_5312483910149324978[260] = 0;
   out_5312483910149324978[261] = 0;
   out_5312483910149324978[262] = 0;
   out_5312483910149324978[263] = 0;
   out_5312483910149324978[264] = 0;
   out_5312483910149324978[265] = 0;
   out_5312483910149324978[266] = 1;
   out_5312483910149324978[267] = 0;
   out_5312483910149324978[268] = 0;
   out_5312483910149324978[269] = 0;
   out_5312483910149324978[270] = 0;
   out_5312483910149324978[271] = 0;
   out_5312483910149324978[272] = 0;
   out_5312483910149324978[273] = 0;
   out_5312483910149324978[274] = 0;
   out_5312483910149324978[275] = 0;
   out_5312483910149324978[276] = 0;
   out_5312483910149324978[277] = 0;
   out_5312483910149324978[278] = 0;
   out_5312483910149324978[279] = 0;
   out_5312483910149324978[280] = 0;
   out_5312483910149324978[281] = 0;
   out_5312483910149324978[282] = 0;
   out_5312483910149324978[283] = 0;
   out_5312483910149324978[284] = 0;
   out_5312483910149324978[285] = 1;
   out_5312483910149324978[286] = 0;
   out_5312483910149324978[287] = 0;
   out_5312483910149324978[288] = 0;
   out_5312483910149324978[289] = 0;
   out_5312483910149324978[290] = 0;
   out_5312483910149324978[291] = 0;
   out_5312483910149324978[292] = 0;
   out_5312483910149324978[293] = 0;
   out_5312483910149324978[294] = 0;
   out_5312483910149324978[295] = 0;
   out_5312483910149324978[296] = 0;
   out_5312483910149324978[297] = 0;
   out_5312483910149324978[298] = 0;
   out_5312483910149324978[299] = 0;
   out_5312483910149324978[300] = 0;
   out_5312483910149324978[301] = 0;
   out_5312483910149324978[302] = 0;
   out_5312483910149324978[303] = 0;
   out_5312483910149324978[304] = 1;
   out_5312483910149324978[305] = 0;
   out_5312483910149324978[306] = 0;
   out_5312483910149324978[307] = 0;
   out_5312483910149324978[308] = 0;
   out_5312483910149324978[309] = 0;
   out_5312483910149324978[310] = 0;
   out_5312483910149324978[311] = 0;
   out_5312483910149324978[312] = 0;
   out_5312483910149324978[313] = 0;
   out_5312483910149324978[314] = 0;
   out_5312483910149324978[315] = 0;
   out_5312483910149324978[316] = 0;
   out_5312483910149324978[317] = 0;
   out_5312483910149324978[318] = 0;
   out_5312483910149324978[319] = 0;
   out_5312483910149324978[320] = 0;
   out_5312483910149324978[321] = 0;
   out_5312483910149324978[322] = 0;
   out_5312483910149324978[323] = 1;
}
void h_4(double *state, double *unused, double *out_4643980062039690148) {
   out_4643980062039690148[0] = state[6] + state[9];
   out_4643980062039690148[1] = state[7] + state[10];
   out_4643980062039690148[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_2425981454432306690) {
   out_2425981454432306690[0] = 0;
   out_2425981454432306690[1] = 0;
   out_2425981454432306690[2] = 0;
   out_2425981454432306690[3] = 0;
   out_2425981454432306690[4] = 0;
   out_2425981454432306690[5] = 0;
   out_2425981454432306690[6] = 1;
   out_2425981454432306690[7] = 0;
   out_2425981454432306690[8] = 0;
   out_2425981454432306690[9] = 1;
   out_2425981454432306690[10] = 0;
   out_2425981454432306690[11] = 0;
   out_2425981454432306690[12] = 0;
   out_2425981454432306690[13] = 0;
   out_2425981454432306690[14] = 0;
   out_2425981454432306690[15] = 0;
   out_2425981454432306690[16] = 0;
   out_2425981454432306690[17] = 0;
   out_2425981454432306690[18] = 0;
   out_2425981454432306690[19] = 0;
   out_2425981454432306690[20] = 0;
   out_2425981454432306690[21] = 0;
   out_2425981454432306690[22] = 0;
   out_2425981454432306690[23] = 0;
   out_2425981454432306690[24] = 0;
   out_2425981454432306690[25] = 1;
   out_2425981454432306690[26] = 0;
   out_2425981454432306690[27] = 0;
   out_2425981454432306690[28] = 1;
   out_2425981454432306690[29] = 0;
   out_2425981454432306690[30] = 0;
   out_2425981454432306690[31] = 0;
   out_2425981454432306690[32] = 0;
   out_2425981454432306690[33] = 0;
   out_2425981454432306690[34] = 0;
   out_2425981454432306690[35] = 0;
   out_2425981454432306690[36] = 0;
   out_2425981454432306690[37] = 0;
   out_2425981454432306690[38] = 0;
   out_2425981454432306690[39] = 0;
   out_2425981454432306690[40] = 0;
   out_2425981454432306690[41] = 0;
   out_2425981454432306690[42] = 0;
   out_2425981454432306690[43] = 0;
   out_2425981454432306690[44] = 1;
   out_2425981454432306690[45] = 0;
   out_2425981454432306690[46] = 0;
   out_2425981454432306690[47] = 1;
   out_2425981454432306690[48] = 0;
   out_2425981454432306690[49] = 0;
   out_2425981454432306690[50] = 0;
   out_2425981454432306690[51] = 0;
   out_2425981454432306690[52] = 0;
   out_2425981454432306690[53] = 0;
}
void h_10(double *state, double *unused, double *out_5661069393973278441) {
   out_5661069393973278441[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5661069393973278441[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5661069393973278441[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_6368917634896469223) {
   out_6368917634896469223[0] = 0;
   out_6368917634896469223[1] = 9.8100000000000005*cos(state[1]);
   out_6368917634896469223[2] = 0;
   out_6368917634896469223[3] = 0;
   out_6368917634896469223[4] = -state[8];
   out_6368917634896469223[5] = state[7];
   out_6368917634896469223[6] = 0;
   out_6368917634896469223[7] = state[5];
   out_6368917634896469223[8] = -state[4];
   out_6368917634896469223[9] = 0;
   out_6368917634896469223[10] = 0;
   out_6368917634896469223[11] = 0;
   out_6368917634896469223[12] = 1;
   out_6368917634896469223[13] = 0;
   out_6368917634896469223[14] = 0;
   out_6368917634896469223[15] = 1;
   out_6368917634896469223[16] = 0;
   out_6368917634896469223[17] = 0;
   out_6368917634896469223[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_6368917634896469223[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_6368917634896469223[20] = 0;
   out_6368917634896469223[21] = state[8];
   out_6368917634896469223[22] = 0;
   out_6368917634896469223[23] = -state[6];
   out_6368917634896469223[24] = -state[5];
   out_6368917634896469223[25] = 0;
   out_6368917634896469223[26] = state[3];
   out_6368917634896469223[27] = 0;
   out_6368917634896469223[28] = 0;
   out_6368917634896469223[29] = 0;
   out_6368917634896469223[30] = 0;
   out_6368917634896469223[31] = 1;
   out_6368917634896469223[32] = 0;
   out_6368917634896469223[33] = 0;
   out_6368917634896469223[34] = 1;
   out_6368917634896469223[35] = 0;
   out_6368917634896469223[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_6368917634896469223[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_6368917634896469223[38] = 0;
   out_6368917634896469223[39] = -state[7];
   out_6368917634896469223[40] = state[6];
   out_6368917634896469223[41] = 0;
   out_6368917634896469223[42] = state[4];
   out_6368917634896469223[43] = -state[3];
   out_6368917634896469223[44] = 0;
   out_6368917634896469223[45] = 0;
   out_6368917634896469223[46] = 0;
   out_6368917634896469223[47] = 0;
   out_6368917634896469223[48] = 0;
   out_6368917634896469223[49] = 0;
   out_6368917634896469223[50] = 1;
   out_6368917634896469223[51] = 0;
   out_6368917634896469223[52] = 0;
   out_6368917634896469223[53] = 1;
}
void h_13(double *state, double *unused, double *out_829426422309673114) {
   out_829426422309673114[0] = state[3];
   out_829426422309673114[1] = state[4];
   out_829426422309673114[2] = state[5];
}
void H_13(double *state, double *unused, double *out_8410131410960543997) {
   out_8410131410960543997[0] = 0;
   out_8410131410960543997[1] = 0;
   out_8410131410960543997[2] = 0;
   out_8410131410960543997[3] = 1;
   out_8410131410960543997[4] = 0;
   out_8410131410960543997[5] = 0;
   out_8410131410960543997[6] = 0;
   out_8410131410960543997[7] = 0;
   out_8410131410960543997[8] = 0;
   out_8410131410960543997[9] = 0;
   out_8410131410960543997[10] = 0;
   out_8410131410960543997[11] = 0;
   out_8410131410960543997[12] = 0;
   out_8410131410960543997[13] = 0;
   out_8410131410960543997[14] = 0;
   out_8410131410960543997[15] = 0;
   out_8410131410960543997[16] = 0;
   out_8410131410960543997[17] = 0;
   out_8410131410960543997[18] = 0;
   out_8410131410960543997[19] = 0;
   out_8410131410960543997[20] = 0;
   out_8410131410960543997[21] = 0;
   out_8410131410960543997[22] = 1;
   out_8410131410960543997[23] = 0;
   out_8410131410960543997[24] = 0;
   out_8410131410960543997[25] = 0;
   out_8410131410960543997[26] = 0;
   out_8410131410960543997[27] = 0;
   out_8410131410960543997[28] = 0;
   out_8410131410960543997[29] = 0;
   out_8410131410960543997[30] = 0;
   out_8410131410960543997[31] = 0;
   out_8410131410960543997[32] = 0;
   out_8410131410960543997[33] = 0;
   out_8410131410960543997[34] = 0;
   out_8410131410960543997[35] = 0;
   out_8410131410960543997[36] = 0;
   out_8410131410960543997[37] = 0;
   out_8410131410960543997[38] = 0;
   out_8410131410960543997[39] = 0;
   out_8410131410960543997[40] = 0;
   out_8410131410960543997[41] = 1;
   out_8410131410960543997[42] = 0;
   out_8410131410960543997[43] = 0;
   out_8410131410960543997[44] = 0;
   out_8410131410960543997[45] = 0;
   out_8410131410960543997[46] = 0;
   out_8410131410960543997[47] = 0;
   out_8410131410960543997[48] = 0;
   out_8410131410960543997[49] = 0;
   out_8410131410960543997[50] = 0;
   out_8410131410960543997[51] = 0;
   out_8410131410960543997[52] = 0;
   out_8410131410960543997[53] = 0;
}
void h_14(double *state, double *unused, double *out_158537382404063139) {
   out_158537382404063139[0] = state[6];
   out_158537382404063139[1] = state[7];
   out_158537382404063139[2] = state[8];
}
void H_14(double *state, double *unused, double *out_6389222310771791219) {
   out_6389222310771791219[0] = 0;
   out_6389222310771791219[1] = 0;
   out_6389222310771791219[2] = 0;
   out_6389222310771791219[3] = 0;
   out_6389222310771791219[4] = 0;
   out_6389222310771791219[5] = 0;
   out_6389222310771791219[6] = 1;
   out_6389222310771791219[7] = 0;
   out_6389222310771791219[8] = 0;
   out_6389222310771791219[9] = 0;
   out_6389222310771791219[10] = 0;
   out_6389222310771791219[11] = 0;
   out_6389222310771791219[12] = 0;
   out_6389222310771791219[13] = 0;
   out_6389222310771791219[14] = 0;
   out_6389222310771791219[15] = 0;
   out_6389222310771791219[16] = 0;
   out_6389222310771791219[17] = 0;
   out_6389222310771791219[18] = 0;
   out_6389222310771791219[19] = 0;
   out_6389222310771791219[20] = 0;
   out_6389222310771791219[21] = 0;
   out_6389222310771791219[22] = 0;
   out_6389222310771791219[23] = 0;
   out_6389222310771791219[24] = 0;
   out_6389222310771791219[25] = 1;
   out_6389222310771791219[26] = 0;
   out_6389222310771791219[27] = 0;
   out_6389222310771791219[28] = 0;
   out_6389222310771791219[29] = 0;
   out_6389222310771791219[30] = 0;
   out_6389222310771791219[31] = 0;
   out_6389222310771791219[32] = 0;
   out_6389222310771791219[33] = 0;
   out_6389222310771791219[34] = 0;
   out_6389222310771791219[35] = 0;
   out_6389222310771791219[36] = 0;
   out_6389222310771791219[37] = 0;
   out_6389222310771791219[38] = 0;
   out_6389222310771791219[39] = 0;
   out_6389222310771791219[40] = 0;
   out_6389222310771791219[41] = 0;
   out_6389222310771791219[42] = 0;
   out_6389222310771791219[43] = 0;
   out_6389222310771791219[44] = 1;
   out_6389222310771791219[45] = 0;
   out_6389222310771791219[46] = 0;
   out_6389222310771791219[47] = 0;
   out_6389222310771791219[48] = 0;
   out_6389222310771791219[49] = 0;
   out_6389222310771791219[50] = 0;
   out_6389222310771791219[51] = 0;
   out_6389222310771791219[52] = 0;
   out_6389222310771791219[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_4640888545343984264) {
  err_fun(nom_x, delta_x, out_4640888545343984264);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8995415760930999757) {
  inv_err_fun(nom_x, true_x, out_8995415760930999757);
}
void pose_H_mod_fun(double *state, double *out_5774323429540918077) {
  H_mod_fun(state, out_5774323429540918077);
}
void pose_f_fun(double *state, double dt, double *out_7338345877331788808) {
  f_fun(state,  dt, out_7338345877331788808);
}
void pose_F_fun(double *state, double dt, double *out_5312483910149324978) {
  F_fun(state,  dt, out_5312483910149324978);
}
void pose_h_4(double *state, double *unused, double *out_4643980062039690148) {
  h_4(state, unused, out_4643980062039690148);
}
void pose_H_4(double *state, double *unused, double *out_2425981454432306690) {
  H_4(state, unused, out_2425981454432306690);
}
void pose_h_10(double *state, double *unused, double *out_5661069393973278441) {
  h_10(state, unused, out_5661069393973278441);
}
void pose_H_10(double *state, double *unused, double *out_6368917634896469223) {
  H_10(state, unused, out_6368917634896469223);
}
void pose_h_13(double *state, double *unused, double *out_829426422309673114) {
  h_13(state, unused, out_829426422309673114);
}
void pose_H_13(double *state, double *unused, double *out_8410131410960543997) {
  H_13(state, unused, out_8410131410960543997);
}
void pose_h_14(double *state, double *unused, double *out_158537382404063139) {
  h_14(state, unused, out_158537382404063139);
}
void pose_H_14(double *state, double *unused, double *out_6389222310771791219) {
  H_14(state, unused, out_6389222310771791219);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
