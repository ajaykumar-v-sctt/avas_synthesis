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

#include "Heavy_jetengine.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_jetengine *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_jetengine_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_jetengine));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_jetengine(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_jetengine_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_jetengine));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_jetengine(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_jetengine_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_jetengine();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_jetengine::Heavy_jetengine(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sRPole_init(&sRPole_Tkqarq6a);
  numBytes += sPhasor_init(&sPhasor_IizXNe9O, sampleRate);
  numBytes += sPhasor_init(&sPhasor_dLXdHO4Y, sampleRate);
  numBytes += sPhasor_init(&sPhasor_bZBbvLeJ, sampleRate);
  numBytes += sPhasor_init(&sPhasor_srctTtDY, sampleRate);
  numBytes += sPhasor_init(&sPhasor_fjSfx6yP, sampleRate);
  numBytes += sBiquad_k_init(&sBiquad_k_TKf4bdsJ, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sCPole_init(&sCPole_h869UVgq);
  numBytes += sRPole_init(&sRPole_KlOAYpsU);
  numBytes += sDel1_init(&sDel1_lCwqkMAy);
  numBytes += sCPole_init(&sCPole_wf5Llkas);
  numBytes += sRPole_init(&sRPole_R75VoFa9);
  numBytes += cVar_init_f(&cVar_NB00609e, 0.2f);
  numBytes += cBinop_init(&cBinop_ubxzeolV, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_sOmyNnU1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_BWDMm3tl, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qxKuVp2E, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_0aMjvsjC, -2130701548);
  numBytes += cSlice_init(&cSlice_nPWhcK74, 1, 1);
  numBytes += sVari_init(&sVari_f2NZKiwf, 0, 0, false);
  numBytes += sVarf_init(&sVarf_Z6H7iqvw, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_BrWwzaHI, 120.0f);
  numBytes += cBinop_init(&cBinop_hZzLAonm, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_t0L4cqKJ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_0UrGPfNn, 8000.0f);
  numBytes += cVar_init_f(&cVar_8qSVXjyS, 0.5f);
  numBytes += cBinop_init(&cBinop_YwcZ3qYt, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_SlMJqpdG, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_8amU5Ult, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_O0cuXbow, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_SdpYUId5, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_XA6TNMZY, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_c27xZIsa, 0.0f);
  numBytes += cIf_init(&cIf_zTCxBInf, false);
  numBytes += sVarf_init(&sVarf_LeEjvRCj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Ybfz8Hr3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6scjgMqH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_vk9RqiXF, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_BBDQZEbp, 0.0f);
  numBytes += cIf_init(&cIf_qlvl6JNS, false);
  numBytes += sVarf_init(&sVarf_wpoRgWmv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3aA6Nsp1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_5Dd18m1L, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qgcX139e, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_M5pwsDfe, 4, 1);
  numBytes += cSlice_init(&cSlice_YsgCS8GS, 3, 1);
  numBytes += cSlice_init(&cSlice_jHJofzRq, 2, 1);
  numBytes += cSlice_init(&cSlice_lZGTNAVP, 1, 1);
  numBytes += cSlice_init(&cSlice_xuJO9vd0, 0, 1);
  numBytes += sVarf_init(&sVarf_unvc5kk3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_P7VZ7NUy, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_2MS0NtNx, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_C5z1AJ0b, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_hVrkdfIV, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_0XoPS2rL, 11000.0f);
  numBytes += cBinop_init(&cBinop_ptjtHNRr, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_RCvXU8ou, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Fsc8BAcQ, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_jetengine::~Heavy_jetengine() {
  // nothing to free
}

HvTable *Heavy_jetengine::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_jetengine::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ld6rFBQk_sendMessage);
      break;
    }
    case 0x29E4A0EF: { // speed
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qEoGBVMC_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_jetengine::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "speed";
        info->hash = 0x29E4A0EF;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.1f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 1;
}



/*
 * Send Function Implementations
 */


void Heavy_jetengine::cVar_NB00609e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ubxzeolV, HV_BINOP_MULTIPLY, 0, m, &cBinop_ubxzeolV_sendMessage);
}

void Heavy_jetengine::cMsg_szrjDLmq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xOnc1k8N_sendMessage);
}

void Heavy_jetengine::cSystem_xOnc1k8N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZAyfGBMn_sendMessage(_c, 0, m);
}

void Heavy_jetengine::cBinop_ubxzeolV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_jwn2ozdf_sendMessage);
}

void Heavy_jetengine::cBinop_O1pOYZLx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ubxzeolV, HV_BINOP_MULTIPLY, 1, m, &cBinop_ubxzeolV_sendMessage);
}

void Heavy_jetengine::cMsg_ZAyfGBMn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_O1pOYZLx_sendMessage);
}

void Heavy_jetengine::cBinop_jwn2ozdf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_2ys2hxUI_sendMessage);
}

void Heavy_jetengine::cBinop_2ys2hxUI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Dhf0QTZG_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_BWDMm3tl, m);
}

void Heavy_jetengine::cBinop_Dhf0QTZG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sOmyNnU1, m);
}

void Heavy_jetengine::cSwitchcase_YSvqEhRT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_nPWhcK74, 0, m, &cSlice_nPWhcK74_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0aMjvsjC, 0, m, &cRandom_0aMjvsjC_sendMessage);
      break;
    }
  }
}

void Heavy_jetengine::cBinop_wJLdOh4d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_XMGzDgCh_sendMessage);
}

void Heavy_jetengine::cUnop_XMGzDgCh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sjR62ymx_sendMessage(_c, 0, m);
}

void Heavy_jetengine::cRandom_0aMjvsjC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_wJLdOh4d_sendMessage);
}

void Heavy_jetengine::cSlice_nPWhcK74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0aMjvsjC, 1, m, &cRandom_0aMjvsjC_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_jetengine::cMsg_sjR62ymx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_f2NZKiwf, m);
}

void Heavy_jetengine::cBinop_cLMmpfj8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_CENGNoMy_sendMessage);
}

void Heavy_jetengine::cBinop_CENGNoMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_QdtlykfK_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_a5fc4gT1_sendMessage);
}

void Heavy_jetengine::cVar_BrWwzaHI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_X9s9o5MB_sendMessage);
}

void Heavy_jetengine::cMsg_FhaB30Kx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TrLi18eI_sendMessage);
}

void Heavy_jetengine::cSystem_TrLi18eI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hZzLAonm, HV_BINOP_DIVIDE, 1, m, &cBinop_hZzLAonm_sendMessage);
}

void Heavy_jetengine::cBinop_QdtlykfK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_sDNungzg_sendMessage);
}

void Heavy_jetengine::cBinop_sDNungzg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_t0L4cqKJ, m);
}

void Heavy_jetengine::cMsg_dWw1tMpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_WE74hlNg_sendMessage);
}

void Heavy_jetengine::cBinop_WE74hlNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_cLMmpfj8_sendMessage);
}

void Heavy_jetengine::cBinop_a5fc4gT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Z6H7iqvw, m);
}

void Heavy_jetengine::cBinop_X9s9o5MB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_KYJOteMN_sendMessage);
}

void Heavy_jetengine::cBinop_KYJOteMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hZzLAonm, HV_BINOP_DIVIDE, 0, m, &cBinop_hZzLAonm_sendMessage);
}

void Heavy_jetengine::cBinop_hZzLAonm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dWw1tMpq_sendMessage(_c, 0, m);
}

void Heavy_jetengine::cMsg_Qhnezv67_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pKW0EZjj_sendMessage);
}

void Heavy_jetengine::cSystem_pKW0EZjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YwcZ3qYt, HV_BINOP_DIVIDE, 1, m, &cBinop_YwcZ3qYt_sendMessage);
}

void Heavy_jetengine::cVar_0UrGPfNn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_S1VbKnn1_sendMessage);
}

void Heavy_jetengine::cVar_8qSVXjyS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_ockTKJi7_sendMessage);
}

void Heavy_jetengine::cUnop_94obQedK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_j386QcU1_sendMessage);
}

void Heavy_jetengine::cBinop_YwcZ3qYt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O0cuXbow, HV_BINOP_MULTIPLY, 1, m, &cBinop_O0cuXbow_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_94obQedK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SlMJqpdG, HV_BINOP_DIVIDE, 0, m, &cBinop_SlMJqpdG_sendMessage);
}

void Heavy_jetengine::cBinop_S1VbKnn1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YwcZ3qYt, HV_BINOP_DIVIDE, 0, m, &cBinop_YwcZ3qYt_sendMessage);
}

void Heavy_jetengine::cBinop_SlMJqpdG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_NO9DjnQU_sendMessage);
}

void Heavy_jetengine::cBinop_gJP3sT0R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_KGC4Sykq_sendMessage);
}

void Heavy_jetengine::cBinop_KGC4Sykq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_o0YpKKaB_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8amU5Ult, HV_BINOP_MULTIPLY, 0, m, &cBinop_8amU5Ult_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_O0cuXbow, HV_BINOP_MULTIPLY, 0, m, &cBinop_O0cuXbow_sendMessage);
}

void Heavy_jetengine::cBinop_j386QcU1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8amU5Ult, HV_BINOP_MULTIPLY, 1, m, &cBinop_8amU5Ult_sendMessage);
}

void Heavy_jetengine::cBinop_8amU5Ult_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_oNlKuils_sendMessage);
}

void Heavy_jetengine::cCast_kNkIQkdO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0UrGPfNn, 0, m, &cVar_0UrGPfNn_sendMessage);
}

void Heavy_jetengine::cBinop_YwR7Lo7a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_dqpyoWwy_sendMessage);
}

void Heavy_jetengine::cBinop_dqpyoWwy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_TKf4bdsJ, 5, m);
}

void Heavy_jetengine::cBinop_oNlKuils_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_TKf4bdsJ, 4, m);
}

void Heavy_jetengine::cBinop_LduD4CRS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XA6TNMZY, HV_BINOP_MULTIPLY, 0, m, &cBinop_XA6TNMZY_sendMessage);
}

void Heavy_jetengine::cBinop_O0cuXbow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SdpYUId5, HV_BINOP_ADD, 1, m, &cBinop_SdpYUId5_sendMessage);
}

void Heavy_jetengine::cBinop_o0YpKKaB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_YwR7Lo7a_sendMessage);
}

void Heavy_jetengine::cBinop_SdpYUId5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XA6TNMZY, HV_BINOP_MULTIPLY, 1, m, &cBinop_XA6TNMZY_sendMessage);
}

void Heavy_jetengine::cBinop_XA6TNMZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_TKf4bdsJ, 1, m);
}

void Heavy_jetengine::cBinop_ockTKJi7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SlMJqpdG, HV_BINOP_DIVIDE, 1, m, &cBinop_SlMJqpdG_sendMessage);
}

void Heavy_jetengine::cBinop_NO9DjnQU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_gJP3sT0R_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SdpYUId5, HV_BINOP_ADD, 0, m, &cBinop_SdpYUId5_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_LduD4CRS_sendMessage);
}

void Heavy_jetengine::cMsg_cMPxGzBZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_34EtE4Kj_sendMessage);
}

void Heavy_jetengine::cSystem_34EtE4Kj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SA9rHDP0_sendMessage(_c, 0, m);
}

void Heavy_jetengine::cVar_c27xZIsa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_xf7Wb9Pa_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_zTCxBInf, 0, m, &cIf_zTCxBInf_sendMessage);
}

void Heavy_jetengine::cIf_zTCxBInf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_8ooxT7nZ_sendMessage(_c, 0, m);
      cMsg_NcPx0mtf_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_uBccz1sF_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_hTc77euQ_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_vk9RqiXF, m);
      break;
    }
    default: return;
  }
}

void Heavy_jetengine::cBinop_xf7Wb9Pa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zTCxBInf, 1, m, &cIf_zTCxBInf_sendMessage);
}

void Heavy_jetengine::cMsg_uBccz1sF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_zHstsj3x_sendMessage);
}

void Heavy_jetengine::cBinop_zHstsj3x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ybfz8Hr3, m);
}

void Heavy_jetengine::cBinop_hTc77euQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_drKKT78x_sendMessage(_c, 0, m);
}

void Heavy_jetengine::cMsg_drKKT78x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_dapASwtb_sendMessage);
}

void Heavy_jetengine::cBinop_dapASwtb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lA5s8iq4_sendMessage(_c, 0, m);
}

void Heavy_jetengine::cMsg_lA5s8iq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_qwolqGmT_sendMessage);
}

void Heavy_jetengine::cBinop_qwolqGmT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6scjgMqH, m);
}

void Heavy_jetengine::cBinop_WHReWVvC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LeEjvRCj, m);
}

void Heavy_jetengine::cMsg_SA9rHDP0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_WHReWVvC_sendMessage);
}

void Heavy_jetengine::cMsg_8ooxT7nZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_hTc77euQ_sendMessage);
}

void Heavy_jetengine::cMsg_NcPx0mtf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ybfz8Hr3, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vk9RqiXF, m);
}

void Heavy_jetengine::cMsg_txxHtkzP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ru0uHf25_sendMessage);
}

void Heavy_jetengine::cSystem_ru0uHf25_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RgTLruly_sendMessage(_c, 0, m);
}

void Heavy_jetengine::cVar_BBDQZEbp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_V3yYs05n_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_qlvl6JNS, 0, m, &cIf_qlvl6JNS_sendMessage);
}

void Heavy_jetengine::cIf_qlvl6JNS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_qTN1QkgD_sendMessage(_c, 0, m);
      cMsg_BhzNYsoA_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_Dk6AiyVW_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_Js7W4TKA_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_qgcX139e, m);
      break;
    }
    default: return;
  }
}

void Heavy_jetengine::cBinop_V3yYs05n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qlvl6JNS, 1, m, &cIf_qlvl6JNS_sendMessage);
}

void Heavy_jetengine::cMsg_Dk6AiyVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_1lmAGXDd_sendMessage);
}

void Heavy_jetengine::cBinop_1lmAGXDd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3aA6Nsp1, m);
}

void Heavy_jetengine::cBinop_Js7W4TKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UIWkWq9U_sendMessage(_c, 0, m);
}

void Heavy_jetengine::cMsg_UIWkWq9U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_roSUbLa9_sendMessage);
}

void Heavy_jetengine::cBinop_roSUbLa9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Uxv1yaZX_sendMessage(_c, 0, m);
}

void Heavy_jetengine::cMsg_Uxv1yaZX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Y1lHBwfw_sendMessage);
}

void Heavy_jetengine::cBinop_Y1lHBwfw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5Dd18m1L, m);
}

void Heavy_jetengine::cBinop_EuEim2Hd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wpoRgWmv, m);
}

void Heavy_jetengine::cMsg_RgTLruly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_EuEim2Hd_sendMessage);
}

void Heavy_jetengine::cMsg_qTN1QkgD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_Js7W4TKA_sendMessage);
}

void Heavy_jetengine::cMsg_BhzNYsoA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_3aA6Nsp1, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_qgcX139e, m);
}

void Heavy_jetengine::cMsg_bVcEirpj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.6f);
  cVar_onMessage(_c, &Context(_c)->cVar_BBDQZEbp, 0, m, &cVar_BBDQZEbp_sendMessage);
}

void Heavy_jetengine::cMsg_Cplqbrbl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_c27xZIsa, 0, m, &cVar_c27xZIsa_sendMessage);
}

void Heavy_jetengine::cSlice_M5pwsDfe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_hVrkdfIV, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_jetengine::cSlice_YsgCS8GS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_C5z1AJ0b, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_jetengine::cSlice_jHJofzRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_2MS0NtNx, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_jetengine::cSlice_lZGTNAVP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_P7VZ7NUy, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_jetengine::cSlice_xuJO9vd0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_unvc5kk3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_jetengine::cMsg_TApFn9uF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3097.0f);
  msg_setFloat(m, 1, 4495.0f);
  msg_setFloat(m, 2, 5588.0f);
  msg_setFloat(m, 3, 7471.0f);
  msg_setFloat(m, 4, 11000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_M5pwsDfe, 0, m, &cSlice_M5pwsDfe_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_YsgCS8GS, 0, m, &cSlice_YsgCS8GS_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_jHJofzRq, 0, m, &cSlice_jHJofzRq_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_lZGTNAVP, 0, m, &cSlice_lZGTNAVP_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_xuJO9vd0, 0, m, &cSlice_xuJO9vd0_sendMessage);
}

void Heavy_jetengine::cVar_0XoPS2rL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ptjtHNRr, HV_BINOP_MULTIPLY, 0, m, &cBinop_ptjtHNRr_sendMessage);
}

void Heavy_jetengine::cMsg_28dXtUXH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IF86Av30_sendMessage);
}

void Heavy_jetengine::cSystem_IF86Av30_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_e7utVrKj_sendMessage(_c, 0, m);
}

void Heavy_jetengine::cBinop_ptjtHNRr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Ip2kl8bw_sendMessage);
}

void Heavy_jetengine::cBinop_mMMINaTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ptjtHNRr, HV_BINOP_MULTIPLY, 1, m, &cBinop_ptjtHNRr_sendMessage);
}

void Heavy_jetengine::cMsg_e7utVrKj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_mMMINaTd_sendMessage);
}

void Heavy_jetengine::cBinop_Ip2kl8bw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_k9Ob7VBx_sendMessage);
}

void Heavy_jetengine::cBinop_k9Ob7VBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_3yfL2D7l_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Fsc8BAcQ, m);
}

void Heavy_jetengine::cBinop_3yfL2D7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RCvXU8ou, m);
}

void Heavy_jetengine::cReceive_ld6rFBQk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_YSvqEhRT_onMessage(_c, NULL, 0, m, NULL);
  cMsg_FhaB30Kx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BrWwzaHI, 0, m, &cVar_BrWwzaHI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8qSVXjyS, 0, m, &cVar_8qSVXjyS_sendMessage);
  cMsg_Qhnezv67_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0UrGPfNn, 0, m, &cVar_0UrGPfNn_sendMessage);
  cMsg_cMPxGzBZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_c27xZIsa, 0, m, &cVar_c27xZIsa_sendMessage);
  cMsg_txxHtkzP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BBDQZEbp, 0, m, &cVar_BBDQZEbp_sendMessage);
  cMsg_szrjDLmq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NB00609e, 0, m, &cVar_NB00609e_sendMessage);
  cMsg_bVcEirpj_sendMessage(_c, 0, m);
  cMsg_Cplqbrbl_sendMessage(_c, 0, m);
  cMsg_TApFn9uF_sendMessage(_c, 0, m);
  cMsg_28dXtUXH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0XoPS2rL, 0, m, &cVar_0XoPS2rL_sendMessage);
}

void Heavy_jetengine::cReceive_qEoGBVMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qxKuVp2E, m);
}



/*
 * Code for expr~ implementation
 * Write out the generic implementation code
 */

 // per class code

 // per object code


/*
 * Context Process Implementation
 */

int Heavy_jetengine::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }

  sendBangToReceiver(0xDD21C0EB); // send to __hv_bang~ on next cycle
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9;
  hv_bufferi_t Bi0, Bi1;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_varread_f(&sVarf_qxKuVp2E, VOf(Bf0));
    __hv_varread_f(&sVarf_BWDMm3tl, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_sOmyNnU1, VOf(Bf0));
    __hv_rpole_f(&sRPole_Tkqarq6a, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_C5z1AJ0b, VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf1));
    __hv_phasor_f(&sPhasor_IizXNe9O, VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_hVrkdfIV, VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf4));
    __hv_phasor_f(&sPhasor_dLXdHO4Y, VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf6), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf4), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f);
    __hv_varread_f(&sVarf_unvc5kk3, VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf3));
    __hv_phasor_f(&sPhasor_bZBbvLeJ, VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf6), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_P7VZ7NUy, VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf5));
    __hv_phasor_f(&sPhasor_srctTtDY, VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf7), VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf5), VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_varread_f(&sVarf_2MS0NtNx, VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf6));
    __hv_phasor_f(&sPhasor_fjSfx6yP, VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf9), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf6), VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf3), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f);
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), -0.9f, -0.9f, -0.9f, -0.9f, -0.9f, -0.9f, -0.9f, -0.9f);
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_varread_i(&sVari_f2NZKiwf, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_i(&sVari_f2NZKiwf, VIi(Bi1));
    __hv_biquad_k_f(&sBiquad_k_TKf4bdsJ, VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 150.0f, 150.0f, 150.0f, 150.0f, 150.0f, 150.0f, 150.0f, 150.0f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_LeEjvRCj, VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_vk9RqiXF, VOf(Bf1));
    __hv_min_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_Ybfz8Hr3, VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf4));
    __hv_varread_f(&sVarf_6scjgMqH, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf7), VIf(Bf4), VOf(Bf7));
    __hv_cos_f(VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf4));
    __hv_gt_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_sqrt_f(VIf(Bf3), VOf(Bf3));
    __hv_and_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_cpole_f(&sCPole_h869UVgq, VIf(Bf1), VIf(ZERO), VIf(Bf6), VIf(Bf3), VOf(Bf3), VOf(Bf6));
    __hv_varread_f(&sVarf_Z6H7iqvw, VOf(Bf6));
    __hv_rpole_f(&sRPole_KlOAYpsU, VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_lCwqkMAy, VIf(Bf6), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_t0L4cqKJ, VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 120.0f, 120.0f, 120.0f, 120.0f, 120.0f, 120.0f, 120.0f, 120.0f);
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_max_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f);
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_wpoRgWmv, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_qgcX139e, VOf(Bf0));
    __hv_min_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_3aA6Nsp1, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf3));
    __hv_varread_f(&sVarf_5Dd18m1L, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf1));
    __hv_cos_f(VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf3));
    __hv_gt_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_sqrt_f(VIf(Bf6), VOf(Bf6));
    __hv_and_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_cpole_f(&sCPole_wf5Llkas, VIf(Bf0), VIf(ZERO), VIf(Bf7), VIf(Bf6), VOf(Bf6), VOf(Bf7));
    __hv_fma_f(VIf(Bf5), VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_Fsc8BAcQ, VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_RCvXU8ou, VOf(Bf6));
    __hv_rpole_f(&sRPole_R75VoFa9, VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf2), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_jetengine::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_jetengine::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
