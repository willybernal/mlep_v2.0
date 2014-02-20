/* Include files */

#include "blascompat32.h"
#include "campus_windows_sfun.h"
#include "c1_campus_windows.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "campus_windows_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[32] = { "coolSP", "heatSP",
  "RoomCoolSch1", "RoomHeatSch1", "SatSch1", "RoomCoolSch2", "RoomHeatSch2",
  "SatSch2", "ChWTempControl1", "ChWTempControl2", "BldLightSch", "chillerVar",
  "satVar", "roomVar", "refPower", "minChillerV", "maxChillerV", "minSatV",
  "maxSatV", "minRoomV", "maxRoomV", "startTime", "endTime", "nargin", "nargout",
  "time", "chillerSP", "satSP", "roomSP", "totPower", "speedPower", "y" };

/* Function Declarations */
static void initialize_c1_campus_windows(SFc1_campus_windowsInstanceStruct
  *chartInstance);
static void initialize_params_c1_campus_windows
  (SFc1_campus_windowsInstanceStruct *chartInstance);
static void enable_c1_campus_windows(SFc1_campus_windowsInstanceStruct
  *chartInstance);
static void disable_c1_campus_windows(SFc1_campus_windowsInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_campus_windows
  (SFc1_campus_windowsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_campus_windows
  (SFc1_campus_windowsInstanceStruct *chartInstance);
static void set_sim_state_c1_campus_windows(SFc1_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_campus_windows(SFc1_campus_windowsInstanceStruct
  *chartInstance);
static void sf_c1_campus_windows(SFc1_campus_windowsInstanceStruct
  *chartInstance);
static void c1_chartstep_c1_campus_windows(SFc1_campus_windowsInstanceStruct
  *chartInstance);
static void initSimStructsc1_campus_windows(SFc1_campus_windowsInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_campus_windowsInstanceStruct *chartInstance,
  const mxArray *c1_y, const char_T *c1_identifier, real_T c1_b_y[9]);
static void c1_b_emlrt_marshallIn(SFc1_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[9]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_campus_windows, const char_T *
  c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_campus_windowsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_campus_windows(SFc1_campus_windowsInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_campus_windows = 0U;
}

static void initialize_params_c1_campus_windows
  (SFc1_campus_windowsInstanceStruct *chartInstance)
{
}

static void enable_c1_campus_windows(SFc1_campus_windowsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_campus_windows(SFc1_campus_windowsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_campus_windows
  (SFc1_campus_windowsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_campus_windows
  (SFc1_campus_windowsInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[9];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T (*c1_d_y)[9];
  c1_d_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  for (c1_i0 = 0; c1_i0 < 9; c1_i0++) {
    c1_u[c1_i0] = (*c1_d_y)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 9), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_campus_windows;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_campus_windows(SFc1_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[9];
  int32_T c1_i1;
  real_T (*c1_y)[9];
  c1_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "y",
                      c1_dv0);
  for (c1_i1 = 0; c1_i1 < 9; c1_i1++) {
    (*c1_y)[c1_i1] = c1_dv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_campus_windows = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_campus_windows");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_campus_windows(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_campus_windows(SFc1_campus_windowsInstanceStruct
  *chartInstance)
{
}

static void sf_c1_campus_windows(SFc1_campus_windowsInstanceStruct
  *chartInstance)
{
  int32_T c1_i2;
  real_T *c1_time;
  real_T *c1_chillerSP;
  real_T *c1_satSP;
  real_T *c1_roomSP;
  real_T *c1_totPower;
  real_T *c1_speedPower;
  real_T (*c1_y)[9];
  c1_speedPower = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_totPower = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_roomSP = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_satSP = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_chillerSP = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_time = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_time, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_chillerSP, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_satSP, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_roomSP, 3U);
  for (c1_i2 = 0; c1_i2 < 9; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_y)[c1_i2], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_totPower, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_speedPower, 6U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_campus_windows(chartInstance);
  sf_debug_check_for_state_inconsistency(_campus_windowsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_campus_windows(SFc1_campus_windowsInstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_e_hoistedGlobal;
  real_T c1_f_hoistedGlobal;
  real_T c1_time;
  real_T c1_chillerSP;
  real_T c1_satSP;
  real_T c1_roomSP;
  real_T c1_totPower;
  real_T c1_speedPower;
  uint32_T c1_debug_family_var_map[32];
  real_T c1_coolSP;
  real_T c1_heatSP;
  real_T c1_RoomCoolSch1;
  real_T c1_RoomHeatSch1;
  real_T c1_SatSch1;
  real_T c1_RoomCoolSch2;
  real_T c1_RoomHeatSch2;
  real_T c1_SatSch2;
  real_T c1_ChWTempControl1;
  real_T c1_ChWTempControl2;
  real_T c1_BldLightSch;
  real_T c1_chillerVar;
  real_T c1_satVar;
  real_T c1_roomVar;
  real_T c1_refPower;
  real_T c1_minChillerV;
  real_T c1_maxChillerV;
  real_T c1_minSatV;
  real_T c1_maxSatV;
  real_T c1_minRoomV;
  real_T c1_maxRoomV;
  real_T c1_startTime;
  real_T c1_endTime;
  real_T c1_nargin = 6.0;
  real_T c1_nargout = 1.0;
  real_T c1_y[9];
  int32_T c1_i3;
  real_T *c1_b_time;
  real_T *c1_b_chillerSP;
  real_T *c1_b_satSP;
  real_T *c1_b_roomSP;
  real_T *c1_b_totPower;
  real_T *c1_b_speedPower;
  real_T (*c1_b_y)[9];
  c1_b_speedPower = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_b_totPower = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_roomSP = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_satSP = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_chillerSP = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_time = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_time;
  c1_b_hoistedGlobal = *c1_b_chillerSP;
  c1_c_hoistedGlobal = *c1_b_satSP;
  c1_d_hoistedGlobal = *c1_b_roomSP;
  c1_e_hoistedGlobal = *c1_b_totPower;
  c1_f_hoistedGlobal = *c1_b_speedPower;
  c1_time = c1_hoistedGlobal;
  c1_chillerSP = c1_b_hoistedGlobal;
  c1_satSP = c1_c_hoistedGlobal;
  c1_roomSP = c1_d_hoistedGlobal;
  c1_totPower = c1_e_hoistedGlobal;
  c1_speedPower = c1_f_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 32U, 32U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_coolSP, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_heatSP, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_RoomCoolSch1, 2U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_RoomHeatSch1, 3U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_SatSch1, 4U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_RoomCoolSch2, 5U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_RoomHeatSch2, 6U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_SatSch2, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_ChWTempControl1, 8U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_ChWTempControl2, 9U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_BldLightSch, 10U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_chillerVar, 11U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_satVar, 12U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_roomVar, 13U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_refPower, 14U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_minChillerV, 15U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_maxChillerV, 16U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_minSatV, 17U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_maxSatV, 18U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_minRoomV, 19U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_maxRoomV, 20U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_startTime, 21U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_endTime, 22U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 23U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 24U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_time, 25U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_chillerSP, 26U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_satSP, 27U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_roomSP, 28U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_totPower, 29U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_speedPower, 30U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_y, 31U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  if (CV_EML_IF(0, 1, 0, c1_time < 6.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
    c1_coolSP = 26.7;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
    if (CV_EML_IF(0, 1, 1, c1_time < 22.0)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
      c1_coolSP = 24.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
      c1_coolSP = 26.7;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  if (CV_EML_IF(0, 1, 2, c1_time < 6.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
    c1_heatSP = 15.6;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
    if (CV_EML_IF(0, 1, 3, c1_time < 22.0)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
      c1_heatSP = 21.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
      c1_heatSP = 15.6;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  c1_RoomCoolSch1 = c1_coolSP;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  c1_RoomHeatSch1 = c1_heatSP;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
  c1_SatSch1 = 12.8;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
  c1_RoomCoolSch2 = c1_coolSP;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
  c1_RoomHeatSch2 = c1_heatSP;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 30);
  c1_SatSch2 = 12.8;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
  if (CV_EML_IF(0, 1, 4, c1_time < 6.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
    c1_ChWTempControl1 = 6.7;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
    c1_ChWTempControl2 = 6.7;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 36);
    if (CV_EML_IF(0, 1, 5, c1_time < 12.0)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 37);
      c1_ChWTempControl1 = 6.7;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 38);
      c1_ChWTempControl2 = 6.7;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 39);
      if (CV_EML_IF(0, 1, 6, c1_time < 13.0)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 40);
        c1_ChWTempControl1 = 6.7;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 41);
        c1_ChWTempControl2 = 6.7;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 43);
        c1_ChWTempControl1 = 6.7;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 44);
        c1_ChWTempControl2 = 6.7;
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 48);
  if (CV_EML_IF(0, 1, 7, c1_time < 5.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 49);
    c1_BldLightSch = 0.05;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 50);
    if (CV_EML_IF(0, 1, 8, c1_time < 7.0)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 51);
      c1_BldLightSch = 0.1;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 52);
      if (CV_EML_IF(0, 1, 9, c1_time < 8.0)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 53);
        c1_BldLightSch = 0.3;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 54);
        if (CV_EML_IF(0, 1, 10, c1_time < 17.0)) {
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 55);
          c1_BldLightSch = 0.9;
        } else {
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 56);
          if (CV_EML_IF(0, 1, 11, c1_time < 18.0)) {
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 57);
            c1_BldLightSch = 0.7;
          } else {
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 58);
            if (CV_EML_IF(0, 1, 12, c1_time < 20.0)) {
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 59);
              c1_BldLightSch = 0.5;
            } else {
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 60);
              if (CV_EML_IF(0, 1, 13, c1_time < 22.0)) {
                _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 61);
                c1_BldLightSch = 0.3;
              } else {
                _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 62);
                if (CV_EML_IF(0, 1, 14, c1_time < 23.0)) {
                  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 63);
                  c1_BldLightSch = 0.1;
                } else {
                  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 65);
                  c1_BldLightSch = 0.05;
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 70);
  c1_chillerVar = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 71);
  c1_satVar = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 72);
  c1_roomVar = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 73);
  c1_refPower = 4.0E+6;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 76);
  c1_minChillerV = 6.7;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 77);
  c1_maxChillerV = 9.44;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 78);
  c1_minSatV = 12.8;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 79);
  c1_maxSatV = 15.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 80);
  c1_minRoomV = 20.6;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 81);
  c1_maxRoomV = 26.7;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 84);
  c1_startTime = 13.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 85);
  c1_endTime = 15.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 88);
  CV_EML_IF(0, 1, 15, c1_chillerVar == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 114);
  CV_EML_IF(0, 1, 20, c1_satVar == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 140U);
  CV_EML_IF(0, 1, 25, c1_roomVar == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 167U);
  c1_y[0] = c1_RoomCoolSch1;
  c1_y[1] = c1_RoomHeatSch1;
  c1_y[2] = c1_SatSch1;
  c1_y[3] = c1_RoomCoolSch2;
  c1_y[4] = c1_RoomHeatSch2;
  c1_y[5] = c1_SatSch2;
  c1_y[6] = c1_ChWTempControl1;
  c1_y[7] = c1_ChWTempControl2;
  c1_y[8] = c1_BldLightSch;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -167);
  sf_debug_symbol_scope_pop();
  for (c1_i3 = 0; c1_i3 < 9; c1_i3++) {
    (*c1_b_y)[c1_i3] = c1_y[c1_i3];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_campus_windows(SFc1_campus_windowsInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i4;
  real_T c1_b_inData[9];
  int32_T c1_i5;
  real_T c1_u[9];
  const mxArray *c1_y = NULL;
  SFc1_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc1_campus_windowsInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i4 = 0; c1_i4 < 9; c1_i4++) {
    c1_b_inData[c1_i4] = (*(real_T (*)[9])c1_inData)[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 9; c1_i5++) {
    c1_u[c1_i5] = c1_b_inData[c1_i5];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 9), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_campus_windowsInstanceStruct *chartInstance,
  const mxArray *c1_y, const char_T *c1_identifier, real_T c1_b_y[9])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
}

static void c1_b_emlrt_marshallIn(SFc1_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[9])
{
  real_T c1_dv1[9];
  int32_T c1_i6;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 2, 1, 9);
  for (c1_i6 = 0; c1_i6 < 9; c1_i6++) {
    c1_y[c1_i6] = c1_dv1[c1_i6];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_b_y[9];
  int32_T c1_i7;
  SFc1_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc1_campus_windowsInstanceStruct *)chartInstanceVoid;
  c1_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
  for (c1_i7 = 0; c1_i7 < 9; c1_i7++) {
    (*(real_T (*)[9])c1_outData)[c1_i7] = c1_b_y[c1_i7];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc1_campus_windowsInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc1_campus_windowsInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_campus_windows_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[6];
  c1_ResolvedFunctionInfo (*c1_b_info)[6];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i8;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[6])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "mpower";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c1_b_info)[0].fileTimeLo = 1286851242U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c1_b_info)[1].name = "power";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  (*c1_b_info)[1].fileTimeLo = 1307683640U;
  (*c1_b_info)[1].fileTimeHi = 0U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  (*c1_b_info)[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  (*c1_b_info)[2].name = "eml_scalar_eg";
  (*c1_b_info)[2].dominantType = "double";
  (*c1_b_info)[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c1_b_info)[2].fileTimeLo = 1286851196U;
  (*c1_b_info)[2].fileTimeHi = 0U;
  (*c1_b_info)[2].mFileTimeLo = 0U;
  (*c1_b_info)[2].mFileTimeHi = 0U;
  (*c1_b_info)[3].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  (*c1_b_info)[3].name = "eml_scalexp_alloc";
  (*c1_b_info)[3].dominantType = "double";
  (*c1_b_info)[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c1_b_info)[3].fileTimeLo = 1286851196U;
  (*c1_b_info)[3].fileTimeHi = 0U;
  (*c1_b_info)[3].mFileTimeLo = 0U;
  (*c1_b_info)[3].mFileTimeHi = 0U;
  (*c1_b_info)[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  (*c1_b_info)[4].name = "eml_scalar_floor";
  (*c1_b_info)[4].dominantType = "double";
  (*c1_b_info)[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  (*c1_b_info)[4].fileTimeLo = 1286851126U;
  (*c1_b_info)[4].fileTimeHi = 0U;
  (*c1_b_info)[4].mFileTimeLo = 0U;
  (*c1_b_info)[4].mFileTimeHi = 0U;
  (*c1_b_info)[5].context = "";
  (*c1_b_info)[5].name = "mtimes";
  (*c1_b_info)[5].dominantType = "double";
  (*c1_b_info)[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[5].fileTimeLo = 1289552092U;
  (*c1_b_info)[5].fileTimeHi = 0U;
  (*c1_b_info)[5].mFileTimeLo = 0U;
  (*c1_b_info)[5].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 6), FALSE);
  for (c1_i8 = 0; c1_i8 < 6; c1_i8++) {
    c1_r0 = &c1_info[c1_i8];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i8);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc1_campus_windowsInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i9;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i9, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i9;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc1_campus_windowsInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_campus_windows, const char_T *
  c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_campus_windows), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_campus_windows);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_campus_windowsInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_campus_windows_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2009965191U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(806129840U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4013986150U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1506242967U);
}

mxArray *sf_c1_campus_windows_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ENJO44sCJgwIxvnWHANqG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(9);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_campus_windows(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c1_campus_windows\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_campus_windows_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_campus_windowsInstanceStruct *chartInstance;
    chartInstance = (SFc1_campus_windowsInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_campus_windowsMachineNumber_,
           1,
           1,
           1,
           7,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_campus_windowsMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_campus_windowsMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_campus_windowsMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"time");
          _SFD_SET_DATA_PROPS(1,1,1,0,"chillerSP");
          _SFD_SET_DATA_PROPS(2,1,1,0,"satSP");
          _SFD_SET_DATA_PROPS(3,1,1,0,"roomSP");
          _SFD_SET_DATA_PROPS(4,2,0,1,"y");
          _SFD_SET_DATA_PROPS(5,1,1,0,"totPower");
          _SFD_SET_DATA_PROPS(6,1,1,0,"speedPower");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,30,0,0,0,0,6,3);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,3504);
        _SFD_CV_INIT_EML_IF(0,1,0,89,100,120,183);
        _SFD_CV_INIT_EML_IF(0,1,1,120,136,156,183);
        _SFD_CV_INIT_EML_IF(0,1,2,192,203,223,286);
        _SFD_CV_INIT_EML_IF(0,1,3,223,239,259,286);
        _SFD_CV_INIT_EML_IF(0,1,4,446,457,512,716);
        _SFD_CV_INIT_EML_IF(0,1,5,512,528,583,716);
        _SFD_CV_INIT_EML_IF(0,1,6,583,599,654,716);
        _SFD_CV_INIT_EML_IF(0,1,7,735,746,771,1081);
        _SFD_CV_INIT_EML_IF(0,1,8,771,786,810,1081);
        _SFD_CV_INIT_EML_IF(0,1,9,810,825,849,1081);
        _SFD_CV_INIT_EML_IF(0,1,10,849,865,889,1081);
        _SFD_CV_INIT_EML_IF(0,1,11,889,905,929,1081);
        _SFD_CV_INIT_EML_IF(0,1,12,929,945,969,1081);
        _SFD_CV_INIT_EML_IF(0,1,13,969,985,1009,1081);
        _SFD_CV_INIT_EML_IF(0,1,14,1009,1025,1049,1081);
        _SFD_CV_INIT_EML_IF(0,1,15,1339,1357,-1,2038);
        _SFD_CV_INIT_EML_IF(0,1,16,1421,1460,-1,1990);
        _SFD_CV_INIT_EML_IF(0,1,17,1561,1587,-1,1650);
        _SFD_CV_INIT_EML_IF(0,1,18,1748,1782,1827,1982);
        _SFD_CV_INIT_EML_IF(0,1,19,1827,1865,1910,1982);
        _SFD_CV_INIT_EML_IF(0,1,20,2046,2060,-1,2684);
        _SFD_CV_INIT_EML_IF(0,1,21,2124,2163,-1,2652);
        _SFD_CV_INIT_EML_IF(0,1,22,2264,2290,-1,2353);
        _SFD_CV_INIT_EML_IF(0,1,23,2446,2476,2513,2644);
        _SFD_CV_INIT_EML_IF(0,1,24,2513,2547,2584,2644);
        _SFD_CV_INIT_EML_IF(0,1,25,2693,2708,-1,3360);
        _SFD_CV_INIT_EML_IF(0,1,26,2770,2809,-1,3318);
        _SFD_CV_INIT_EML_IF(0,1,27,2910,2936,-1,2999);
        _SFD_CV_INIT_EML_IF(0,1,28,3093,3124,3166,3310);
        _SFD_CV_INIT_EML_IF(0,1,29,3166,3202,3244,3310);

        {
          static int condStart[] = { 1424, 1445 };

          static int condEnd[] = { 1441, 1460 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,1424,1460,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2127, 2148 };

          static int condEnd[] = { 2144, 2163 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,2127,2163,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2773, 2794 };

          static int condEnd[] = { 2790, 2809 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,2773,2809,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c1_time;
          real_T *c1_chillerSP;
          real_T *c1_satSP;
          real_T *c1_roomSP;
          real_T *c1_totPower;
          real_T *c1_speedPower;
          real_T (*c1_y)[9];
          c1_speedPower = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_totPower = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_roomSP = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_satSP = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_chillerSP = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_time = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_time);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_chillerSP);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_satSP);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_roomSP);
          _SFD_SET_DATA_VALUE_PTR(4U, *c1_y);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_totPower);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_speedPower);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_campus_windowsMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "6u0W033JFvT69KpeJkhMJD";
}

static void sf_opaque_initialize_c1_campus_windows(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_campus_windowsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_campus_windows((SFc1_campus_windowsInstanceStruct*)
    chartInstanceVar);
  initialize_c1_campus_windows((SFc1_campus_windowsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_campus_windows(void *chartInstanceVar)
{
  enable_c1_campus_windows((SFc1_campus_windowsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_campus_windows(void *chartInstanceVar)
{
  disable_c1_campus_windows((SFc1_campus_windowsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_campus_windows(void *chartInstanceVar)
{
  sf_c1_campus_windows((SFc1_campus_windowsInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_campus_windows(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_campus_windows
    ((SFc1_campus_windowsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_campus_windows();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_campus_windows(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_campus_windows();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_campus_windows((SFc1_campus_windowsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_campus_windows(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_campus_windows(S);
}

static void sf_opaque_set_sim_state_c1_campus_windows(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_campus_windows(S, st);
}

static void sf_opaque_terminate_c1_campus_windows(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_campus_windowsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_campus_windows((SFc1_campus_windowsInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_campus_windows_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_campus_windows((SFc1_campus_windowsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_campus_windows(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_campus_windows((SFc1_campus_windowsInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_campus_windows(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_campus_windows_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1229960414U));
  ssSetChecksum1(S,(1327030703U));
  ssSetChecksum2(S,(3396913424U));
  ssSetChecksum3(S,(1971016636U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_campus_windows(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_campus_windows(SimStruct *S)
{
  SFc1_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc1_campus_windowsInstanceStruct *)malloc(sizeof
    (SFc1_campus_windowsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_campus_windowsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_campus_windows;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_campus_windows;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_campus_windows;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_campus_windows;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_campus_windows;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_campus_windows;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_campus_windows;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_campus_windows;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_campus_windows;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_campus_windows;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_campus_windows;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_campus_windows_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_campus_windows(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_campus_windows(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_campus_windows(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_campus_windows_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}