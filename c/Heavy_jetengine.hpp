/**
 * Copyright (c) 2026 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _HEAVY_CONTEXT_JETENGINE_HPP_
#define _HEAVY_CONTEXT_JETENGINE_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalCPole.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvControlUnop.h"
#include "HvControlRandom.h"
#include "HvControlIf.h"
#include "HvMath.h"
#include "HvControlBinop.h"
#include "HvSignalDel1.h"
#include "HvControlVar.h"
#include "HvSignalRPole.h"
#include "HvControlSystem.h"
#include "HvSignalBiquad.h"
#include "HvControlCast.h"
#include "HvSignalPhasor.h"

class Heavy_jetengine : public HeavyContext {

 public:
  Heavy_jetengine(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_jetengine();

  const char *getName() override { return "jetengine"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        SPEED = 0x29E4A0EF, // speed
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;


  /*
  * Code for expr~ implementation
  * Write out the generic header code
  */

  // per class code

  // per object code


  // static sendMessage functions
  static void cVar_NB00609e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_szrjDLmq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_xOnc1k8N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ubxzeolV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_O1pOYZLx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZAyfGBMn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jwn2ozdf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2ys2hxUI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Dhf0QTZG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_YSvqEhRT_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_wJLdOh4d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_XMGzDgCh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_0aMjvsjC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_nPWhcK74_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sjR62ymx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cLMmpfj8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CENGNoMy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_BrWwzaHI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FhaB30Kx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_TrLi18eI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QdtlykfK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sDNungzg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dWw1tMpq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WE74hlNg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_a5fc4gT1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_X9s9o5MB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KYJOteMN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hZzLAonm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Qhnezv67_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_pKW0EZjj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0UrGPfNn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8qSVXjyS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_94obQedK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YwcZ3qYt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_S1VbKnn1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SlMJqpdG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gJP3sT0R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KGC4Sykq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_j386QcU1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8amU5Ult_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kNkIQkdO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YwR7Lo7a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dqpyoWwy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oNlKuils_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LduD4CRS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_O0cuXbow_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_o0YpKKaB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SdpYUId5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XA6TNMZY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ockTKJi7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NO9DjnQU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cMPxGzBZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_34EtE4Kj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_c27xZIsa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_zTCxBInf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xf7Wb9Pa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uBccz1sF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zHstsj3x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hTc77euQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_drKKT78x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dapASwtb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lA5s8iq4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qwolqGmT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WHReWVvC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SA9rHDP0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8ooxT7nZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NcPx0mtf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_txxHtkzP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ru0uHf25_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_BBDQZEbp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_qlvl6JNS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_V3yYs05n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Dk6AiyVW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1lmAGXDd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Js7W4TKA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UIWkWq9U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_roSUbLa9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Uxv1yaZX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Y1lHBwfw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EuEim2Hd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RgTLruly_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qTN1QkgD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BhzNYsoA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bVcEirpj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Cplqbrbl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_M5pwsDfe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_YsgCS8GS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_jHJofzRq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_lZGTNAVP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_xuJO9vd0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TApFn9uF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0XoPS2rL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_28dXtUXH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_IF86Av30_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ptjtHNRr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mMMINaTd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_e7utVrKj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ip2kl8bw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_k9Ob7VBx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3yfL2D7l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_ld6rFBQk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_qEoGBVMC_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalRPole sRPole_Tkqarq6a;
  SignalPhasor sPhasor_IizXNe9O;
  SignalPhasor sPhasor_dLXdHO4Y;
  SignalPhasor sPhasor_bZBbvLeJ;
  SignalPhasor sPhasor_srctTtDY;
  SignalPhasor sPhasor_fjSfx6yP;
  SignalBiquad_k sBiquad_k_TKf4bdsJ;
  SignalCPole sCPole_h869UVgq;
  SignalRPole sRPole_KlOAYpsU;
  SignalDel1 sDel1_lCwqkMAy;
  SignalCPole sCPole_wf5Llkas;
  SignalRPole sRPole_R75VoFa9;
  ControlVar cVar_NB00609e;
  ControlBinop cBinop_ubxzeolV;
  ControlBinop cBinop_O1pOYZLx;
  SignalVarf sVarf_sOmyNnU1;
  ControlBinop cBinop_jwn2ozdf;
  ControlBinop cBinop_2ys2hxUI;
  ControlBinop cBinop_Dhf0QTZG;
  SignalVarf sVarf_BWDMm3tl;
  SignalVarf sVarf_qxKuVp2E;
  ControlBinop cBinop_wJLdOh4d;
  ControlRandom cRandom_0aMjvsjC;
  ControlSlice cSlice_nPWhcK74;
  SignalVari sVari_f2NZKiwf;
  ControlBinop cBinop_cLMmpfj8;
  ControlBinop cBinop_CENGNoMy;
  SignalVarf sVarf_Z6H7iqvw;
  ControlVar cVar_BrWwzaHI;
  ControlBinop cBinop_QdtlykfK;
  ControlBinop cBinop_sDNungzg;
  ControlBinop cBinop_WE74hlNg;
  ControlBinop cBinop_a5fc4gT1;
  ControlBinop cBinop_X9s9o5MB;
  ControlBinop cBinop_KYJOteMN;
  ControlBinop cBinop_hZzLAonm;
  SignalVarf sVarf_t0L4cqKJ;
  ControlVar cVar_0UrGPfNn;
  ControlVar cVar_8qSVXjyS;
  ControlBinop cBinop_YwcZ3qYt;
  ControlBinop cBinop_S1VbKnn1;
  ControlBinop cBinop_SlMJqpdG;
  ControlBinop cBinop_gJP3sT0R;
  ControlBinop cBinop_KGC4Sykq;
  ControlBinop cBinop_j386QcU1;
  ControlBinop cBinop_8amU5Ult;
  ControlBinop cBinop_YwR7Lo7a;
  ControlBinop cBinop_dqpyoWwy;
  ControlBinop cBinop_oNlKuils;
  ControlBinop cBinop_LduD4CRS;
  ControlBinop cBinop_O0cuXbow;
  ControlBinop cBinop_o0YpKKaB;
  ControlBinop cBinop_SdpYUId5;
  ControlBinop cBinop_XA6TNMZY;
  ControlBinop cBinop_ockTKJi7;
  ControlBinop cBinop_NO9DjnQU;
  ControlVar cVar_c27xZIsa;
  ControlIf cIf_zTCxBInf;
  ControlBinop cBinop_xf7Wb9Pa;
  ControlBinop cBinop_zHstsj3x;
  ControlBinop cBinop_hTc77euQ;
  ControlBinop cBinop_dapASwtb;
  ControlBinop cBinop_qwolqGmT;
  ControlBinop cBinop_WHReWVvC;
  SignalVarf sVarf_LeEjvRCj;
  SignalVarf sVarf_Ybfz8Hr3;
  SignalVarf sVarf_6scjgMqH;
  SignalVarf sVarf_vk9RqiXF;
  ControlVar cVar_BBDQZEbp;
  ControlIf cIf_qlvl6JNS;
  ControlBinop cBinop_V3yYs05n;
  ControlBinop cBinop_1lmAGXDd;
  ControlBinop cBinop_Js7W4TKA;
  ControlBinop cBinop_roSUbLa9;
  ControlBinop cBinop_Y1lHBwfw;
  ControlBinop cBinop_EuEim2Hd;
  SignalVarf sVarf_wpoRgWmv;
  SignalVarf sVarf_3aA6Nsp1;
  SignalVarf sVarf_5Dd18m1L;
  SignalVarf sVarf_qgcX139e;
  ControlSlice cSlice_M5pwsDfe;
  ControlSlice cSlice_YsgCS8GS;
  ControlSlice cSlice_jHJofzRq;
  ControlSlice cSlice_lZGTNAVP;
  ControlSlice cSlice_xuJO9vd0;
  SignalVarf sVarf_unvc5kk3;
  SignalVarf sVarf_P7VZ7NUy;
  SignalVarf sVarf_2MS0NtNx;
  SignalVarf sVarf_C5z1AJ0b;
  SignalVarf sVarf_hVrkdfIV;
  ControlVar cVar_0XoPS2rL;
  ControlBinop cBinop_ptjtHNRr;
  ControlBinop cBinop_mMMINaTd;
  SignalVarf sVarf_RCvXU8ou;
  ControlBinop cBinop_Ip2kl8bw;
  ControlBinop cBinop_k9Ob7VBx;
  ControlBinop cBinop_3yfL2D7l;
  SignalVarf sVarf_Fsc8BAcQ;
};

#endif // _HEAVY_CONTEXT_JETENGINE_HPP_
