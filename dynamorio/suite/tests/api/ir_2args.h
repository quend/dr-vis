/* **********************************************************
 * Copyright (c) 2011-2013 Google, Inc.  All rights reserved.
 * Copyright (c) 2008-2010 VMware, Inc.  All rights reserved.
 * **********************************************************/

/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * 
 * * Neither the name of VMware, Inc. nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without
 *   specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL VMWARE, INC. OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

OPCODE(add, add, add, 0, REGARG(EAX), MEMARG(OPSZ_4))
OPCODE(or, or, or, 0, REGARG(EAX), MEMARG(OPSZ_4))
OPCODE(adc, adc, adc, 0, REGARG(EAX), MEMARG(OPSZ_4))
OPCODE(sbb, sbb, sbb, 0, REGARG(EAX), MEMARG(OPSZ_4))
OPCODE(and, and, and, 0, REGARG(EAX), MEMARG(OPSZ_4))
OPCODE(sub, sub, sub, 0, REGARG(EAX), MEMARG(OPSZ_4))
OPCODE(xor, xor, xor, 0, REGARG(EAX), MEMARG(OPSZ_4))
OPCODE(arpl, arpl, arpl, X86_ONLY, MEMARG(OPSZ_2), REGARG(AX))
OPCODE(lea, lea, lea, 0, REGARG(EAX), MEMARG(OPSZ_lea))
OPCODE(mov_ld, mov_ld, mov_ld, 0, REGARG(EAX), MEMARG(OPSZ_4))
OPCODE(mov_st, mov_st, mov_st, 0, MEMARG(OPSZ_4), REGARG(EAX))
OPCODE(mov_imm, mov_imm, mov_imm, 0, REGARG(EAX), IMMARG(OPSZ_4))
OPCODE(mov_seg, mov_seg, mov_seg, 0, REGARG(EAX), opnd_create_reg(SEG_FS))
OPCODE(mov_priv, mov_priv, mov_priv, 0, REGARG(XAX), REGARG(CR0))
OPCODE(lar, lar, lar, 0, REGARG(EAX), MEMARG(OPSZ_2))
OPCODE(lsl, lsl, lsl, 0, REGARG(EAX), MEMARG(OPSZ_2))
OPCODE(movd, movd, movd, 0, REGARG(MM0), MEMARG(OPSZ_4))
OPCODE(movq, movq, movq, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(movdqu, movdqu, movdqu, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(movdqa, movdqa, movdqa, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(movzx, movzx, movzx, 0, REGARG(EAX), MEMARG(OPSZ_2))
OPCODE(movsx, movsx, movsx, 0, REGARG(EAX), MEMARG(OPSZ_2))
OPCODE(movbe, movbe, movbe, 0, REGARG(EAX), MEMARG(OPSZ_4))
OPCODE(bsf, bsf, bsf, 0, REGARG(EAX), MEMARG(OPSZ_4))
OPCODE(bsr, bsr, bsr, 0, REGARG(EAX), MEMARG(OPSZ_4))

OPCODE(imul, imul, imul, 0, REGARG(EAX), MEMARG(OPSZ_4))
OPCODE(lds, lds, lds, X86_ONLY, REGARG(EAX), MEMARG(OPSZ_6_irex10_short4))
OPCODE(lss, lss, lss, 0, REGARG(EAX), MEMARG(OPSZ_6_irex10_short4))
OPCODE(les, les, les, X86_ONLY, REGARG(EAX), MEMARG(OPSZ_6_irex10_short4))
OPCODE(lfs, lfs, lfs, 0, REGARG(EAX), MEMARG(OPSZ_6_irex10_short4))
OPCODE(lgs, lgs, lgs, 0, REGARG(EAX), MEMARG(OPSZ_6_irex10_short4))
OPCODE(xchg, xchg, xchg, 0, MEMARG(OPSZ_4), REGARG(EAX))
OPCODE(xadd, xadd, xadd, 0, MEMARG(OPSZ_4), REGARG(EAX))
OPCODE(cmpxchg1, cmpxchg, cmpxchg_1, 0, MEMARG(OPSZ_1), REGARG(AL))
OPCODE(cmpxchg4, cmpxchg, cmpxchg_4, 0, MEMARG(OPSZ_4), REGARG(EAX))
OPCODE(cmp, cmp, cmp, 0, REGARG(EAX), MEMARG(OPSZ_4))
OPCODE(test, test, test, 0, MEMARG(OPSZ_4), REGARG(EAX))
OPCODE(bound, bound, bound, X86_ONLY, REGARG(EAX), MEMARG(OPSZ_bound))

OPCODE(setnz, setnz, setcc, 0, OP_setnz, REGARG(AL))

OPCODE(bts, bts, bts, 0, MEMARG(OPSZ_4), REGARG(EAX))
OPCODE(btr, btr, btr, 0, MEMARG(OPSZ_4), REGARG(EAX))
OPCODE(btc, btc, btc, 0, MEMARG(OPSZ_4), REGARG(EAX))

OPCODE(rol, rol, rol, 0, MEMARG(OPSZ_4), IMMARG(OPSZ_1))
OPCODE(ror, ror, ror, 0, MEMARG(OPSZ_4), IMMARG(OPSZ_1))
OPCODE(rcl, rcl, rcl, 0, MEMARG(OPSZ_4), IMMARG(OPSZ_1))
OPCODE(rcr, rcr, rcr, 0, MEMARG(OPSZ_4), IMMARG(OPSZ_1))
OPCODE(shl, shl, shl, 0, MEMARG(OPSZ_4), IMMARG(OPSZ_1))
OPCODE(shr, shr, shr, 0, MEMARG(OPSZ_4), IMMARG(OPSZ_1))
OPCODE(sar, sar, sar, 0, MEMARG(OPSZ_4), IMMARG(OPSZ_1))

OPCODE(pmovmskb, pmovmskb, pmovmskb, 0, REGARG(EAX), REGARG(MM0))
OPCODE(ptest, ptest, ptest, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(movups, movups, movups, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(movss, movss, movss, 0, REGARG(XMM0), MEMARG(OPSZ_4))
OPCODE(movupd, movupd, movupd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(movsd, movsd, movsd, 0, REGARG(XMM0), MEMARG(OPSZ_8))

OPCODE(movlps, movlps, movlps, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(movlpd, movlpd, movlpd, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(movhps, movhps, movhps, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(movhpd, movhpd, movhpd, 0, REGARG(XMM0), MEMARG(OPSZ_8))

OPCODE(movaps, movaps, movaps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(movapd, movapd, movapd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(cvtpi2ps, cvtpi2ps, cvtpi2ps, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(cvtsi2ss, cvtsi2ss, cvtsi2ss, 0, REGARG(XMM0), MEMARG(OPSZ_4))
OPCODE(cvtpi2pd, cvtpi2pd, cvtpi2pd, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(cvtsi2sd, cvtsi2sd, cvtsi2sd, 0, REGARG(XMM0), MEMARG(OPSZ_4))
OPCODE(cvttps2pi, cvttps2pi, cvttps2pi, 0, REGARG(MM0), MEMARG(OPSZ_16))
OPCODE(cvttss2si, cvttss2si, cvttss2si, 0, REGARG(EAX), MEMARG(OPSZ_4))
OPCODE(cvttpd2pi, cvttpd2pi, cvttpd2pi, 0, REGARG(MM0), MEMARG(OPSZ_16))
OPCODE(cvttsd2si, cvttsd2si, cvttsd2si, 0, REGARG(EAX), MEMARG(OPSZ_8))
OPCODE(cvtps2pi, cvtps2pi, cvtps2pi, 0, REGARG(MM0), MEMARG(OPSZ_16))
OPCODE(cvtss2si, cvtss2si, cvtss2si, 0, REGARG(EAX), MEMARG(OPSZ_4))
OPCODE(cvtpd2pi, cvtpd2pi, cvtpd2pi, 0, REGARG(MM0), MEMARG(OPSZ_16))
OPCODE(cvtsd2si, cvtsd2si, cvtsd2si, 0, REGARG(EAX), MEMARG(OPSZ_8))
OPCODE(cvtps2pd, cvtps2pd, cvtps2pd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(cvtss2sd, cvtss2sd, cvtss2sd, 0, REGARG(XMM0), MEMARG(OPSZ_4))
OPCODE(cvtpd2ps, cvtpd2ps, cvtpd2ps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(cvtsd2ss, cvtsd2ss, cvtsd2ss, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(cvtdq2ps, cvtdq2ps, cvtdq2ps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(cvttps2dq, cvttps2dq, cvttps2dq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(cvtps2dq, cvtps2dq, cvtps2dq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(cvtdq2pd, cvtdq2pd, cvtdq2pd, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(cvttpd2dq, cvttpd2dq, cvttpd2dq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(cvtpd2dq, cvtpd2dq, cvtpd2dq, 0, REGARG(XMM0), MEMARG(OPSZ_16))

OPCODE(movq2dq, movq2dq, movq2dq, 0, REGARG(XMM0), REGARG(MM0))
OPCODE(movdq2q, movdq2q, movdq2q, 0, REGARG(MM0), REGARG(XMM0))

OPCODE(movmskps, movmskps, movmskps, 0, REGARG(XAX), REGARG(XMM0))
OPCODE(movmskpd, movmskpd, movmskpd, 0, REGARG(XAX), REGARG(XMM0))
OPCODE(movddup, movddup, movddup, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(popcnt, popcnt, popcnt, 0, REGARG(EAX), MEMARG(OPSZ_4))
OPCODE(lzcnt, lzcnt, lzcnt, 0, REGARG(EAX), MEMARG(OPSZ_4))

OPCODE(movntss, movntss, movntss, 0, MEMARG(OPSZ_4), REGARG(XMM0))
OPCODE(movntsd, movntsd, movntsd, 0, MEMARG(OPSZ_8), REGARG(XMM0))
OPCODE(movntps, movntps, movntps, 0, MEMARG(OPSZ_16), REGARG(XMM0))
OPCODE(movntpd, movntpd, movntpd, 0, MEMARG(OPSZ_16), REGARG(XMM0))
OPCODE(movntdqa, movntdqa, movntdqa, 0, MEMARG(OPSZ_16), REGARG(XMM0))
OPCODE(movntq, movntq, movntq, 0, MEMARG(OPSZ_8), REGARG(MM0))
OPCODE(movntdq, movntdq, movntdq, 0, MEMARG(OPSZ_16), REGARG(XMM0))
OPCODE(movnti, movnti, movnti, 0, MEMARG(OPSZ_4), REGARG(EAX))

OPCODE(sqrtps, sqrtps, sqrtps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(sqrtss, sqrtss, sqrtss, 0, REGARG(XMM0), MEMARG(OPSZ_4))
OPCODE(sqrtpd, sqrtpd, sqrtpd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(sqrtsd, sqrtsd, sqrtsd, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(rsqrtps, rsqrtps, rsqrtps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(rsqrtss, rsqrtss, rsqrtss, 0, REGARG(XMM0), MEMARG(OPSZ_4))
OPCODE(rcpps, rcpps, rcpps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(rcpss, rcpss, rcpss, 0, REGARG(XMM0), MEMARG(OPSZ_4))
OPCODE(lddqu, lddqu, lddqu, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(movsldup, movsldup, movsldup, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(movshdup, movshdup, movshdup, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pshufb, pshufb, pshufb, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmovsxbw, pmovsxbw, pmovsxbw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmovsxbd, pmovsxbd, pmovsxbd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmovsxbq, pmovsxbq, pmovsxbq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmovsxdw, pmovsxdw, pmovsxdw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmovsxwq, pmovsxwq, pmovsxwq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmovsxdq, pmovsxdq, pmovsxdq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmovzxbw, pmovzxbw, pmovzxbw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmovzxbd, pmovzxbd, pmovzxbd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmovzxbq, pmovzxbq, pmovzxbq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmovzxdw, pmovzxdw, pmovzxdw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmovzxwq, pmovzxwq, pmovzxwq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmovzxdq, pmovzxdq, pmovzxdq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(phminposuw, phminposuw, phminposuw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(punpcklbw, punpcklbw, punpcklbw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(punpcklwd, punpcklwd, punpcklwd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(punpckldq, punpckldq, punpckldq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(packsswb, packsswb, packsswb, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pcmpgtb, pcmpgtb, pcmpgtb, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pcmpgtw, pcmpgtw, pcmpgtw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pcmpgtd, pcmpgtd, pcmpgtd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(packuswb, packuswb, packuswb, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(punpckhbw, punpckhbw, punpckhbw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(punpckhwd, punpckhwd, punpckhwd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(punpckhdq, punpckhdq, punpckhdq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(packssdw, packssdw, packssdw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(punpcklqdq, punpcklqdq, punpcklqdq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(punpckhqdq, punpckhqdq, punpckhqdq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pcmpeqb, pcmpeqb, pcmpeqb, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pcmpeqw, pcmpeqw, pcmpeqw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pcmpeqd, pcmpeqd, pcmpeqd, 0, REGARG(XMM0), MEMARG(OPSZ_16))

OPCODE(psrlw, psrlw, psrlw, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psrlw_16, psrlw, psrlw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(psrlw_imm, psrlw, psrlw, 0, REGARG(MM0), IMMARG(OPSZ_1))
OPCODE(psrlw_imm_16, psrlw, psrlw, 0, REGARG(XMM0), IMMARG(OPSZ_1))
OPCODE(psrld, psrld, psrld, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psrld_16, psrld, psrld, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(psrld_imm, psrld, psrld, 0, REGARG(MM0), IMMARG(OPSZ_1))
OPCODE(psrld_imm_16, psrld, psrld, 0, REGARG(XMM0), IMMARG(OPSZ_1))
OPCODE(psrlq, psrlq, psrlq, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psrlq_16, psrlq, psrlq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(psrlq_imm, psrlq, psrlq, 0, REGARG(MM0), IMMARG(OPSZ_1))
OPCODE(psrlq_imm_16, psrlq, psrlq, 0, REGARG(XMM0), IMMARG(OPSZ_1))
OPCODE(paddq, paddq, paddq, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(pmullw, pmullw, pmullw, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psubusb, psubusb, psubusb, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psubusw, psubusw, psubusw, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(pminub, pminub, pminub, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(pand, pand, pand, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(paddusb, paddusb, paddusb, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(paddusw, paddusw, paddusw, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(pmaxub, pmaxub, pmaxub, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(pandn, pandn, pandn, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(pavgb, pavgb, pavgb, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psraw, psraw, psraw, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psraw_16, psraw, psraw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(psraw_imm, psraw, psraw, 0, REGARG(MM0), IMMARG(OPSZ_1))
OPCODE(psraw_imm_16, psraw, psraw, 0, REGARG(XMM0), IMMARG(OPSZ_1))
OPCODE(psrad, psrad, psrad, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psrad_16, psrad, psrad, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(psrad_imm, psrad, psrad, 0, REGARG(MM0), IMMARG(OPSZ_1))
OPCODE(psrad_imm_16, psrad, psrad, 0, REGARG(XMM0), IMMARG(OPSZ_1))
OPCODE(pavgw, pavgw, pavgw, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(pmulhuw, pmulhuw, pmulhuw, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(pmulhw, pmulhw, pmulhw, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psubsb, psubsb, psubsb, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psubsw, psubsw, psubsw, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(pminsw, pminsw, pminsw, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(por, por, por, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(paddsb, paddsb, paddsb, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(paddsw, paddsw, paddsw, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(pmaxsw, pmaxsw, pmaxsw, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(pxor, pxor, pxor, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psllw, psllw, psllw, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psllw_16, psllw, psllw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(psllw_imm, psllw, psllw, 0, REGARG(MM0), IMMARG(OPSZ_1))
OPCODE(psllw_imm_16, psllw, psllw, 0, REGARG(XMM0), IMMARG(OPSZ_1))
OPCODE(pslld, pslld, pslld, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(pslld_16, pslld, pslld, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pslld_imm, pslld, pslld, 0, REGARG(MM0), IMMARG(OPSZ_1))
OPCODE(pslld_imm_16, pslld, pslld, 0, REGARG(XMM0), IMMARG(OPSZ_1))
OPCODE(psllq, psllq, psllq, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psllq_16, psllq, psllq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(psllq_imm, psllq, psllq, 0, REGARG(MM0), IMMARG(OPSZ_1))
OPCODE(psllq_imm_16, psllq, psllq, 0, REGARG(XMM0), IMMARG(OPSZ_1))
OPCODE(pmuludq, pmuludq, pmuludq, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(pmaddwd, pmaddwd, pmaddwd, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psadbw, psadbw, psadbw, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psubb, psubb, psubb, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psubw, psubw, psubw, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psubd, psubd, psubd, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(psubq, psubq, psubq, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(paddb, paddb, paddb, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(paddw, paddw, paddw, 0, REGARG(MM0), MEMARG(OPSZ_8))
OPCODE(paddd, paddd, paddd, 0, REGARG(MM0), MEMARG(OPSZ_8))

OPCODE(psrldq, psrldq, psrldq, 0, REGARG(XMM0), IMMARG(OPSZ_1))
OPCODE(pslldq, pslldq, pslldq, 0, REGARG(XMM0), IMMARG(OPSZ_1))

OPCODE(unpcklps, unpcklps, unpcklps, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(unpcklpd, unpcklpd, unpcklpd, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(unpckhps, unpckhps, unpckhps, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(unpckhpd, unpckhpd, unpckhpd, 0, REGARG(XMM0), MEMARG(OPSZ_8))

OPCODE(andps, andps, andps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(andpd, andpd, andpd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(andnps, andnps, andnps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(andnpd, andnpd, andnpd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(orps, orps, orps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(orpd, orpd, orpd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(xorps, xorps, xorps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(xorpd, xorpd, xorpd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(addps, addps, addps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(addss, addss, addss, 0, REGARG(XMM0), MEMARG(OPSZ_4))
OPCODE(addpd, addpd, addpd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(addsd, addsd, addsd, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(mulps, mulps, mulps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(mulss, mulss, mulss, 0, REGARG(XMM0), MEMARG(OPSZ_4))
OPCODE(mulpd, mulpd, mulpd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(mulsd, mulsd, mulsd, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(subps, subps, subps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(subss, subss, subss, 0, REGARG(XMM0), MEMARG(OPSZ_4))
OPCODE(subpd, subpd, subpd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(subsd, subsd, subsd, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(minps, minps, minps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(minss, minss, minss, 0, REGARG(XMM0), MEMARG(OPSZ_4))
OPCODE(minpd, minpd, minpd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(minsd, minsd, minsd, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(divps, divps, divps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(divss, divss, divss, 0, REGARG(XMM0), MEMARG(OPSZ_4))
OPCODE(divpd, divpd, divpd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(divsd, divsd, divsd, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(maxps, maxps, maxps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(maxss, maxss, maxss, 0, REGARG(XMM0), MEMARG(OPSZ_4))
OPCODE(maxpd, maxpd, maxpd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(maxsd, maxsd, maxsd, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(haddpd, haddpd, haddpd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(haddps, haddps, haddps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(hsubpd, hsubpd, hsubpd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(hsubps, hsubps, hsubps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(addsubpd, addsubpd, addsubpd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(addsubps, addsubps, addsubps, 0, REGARG(XMM0), MEMARG(OPSZ_16))

OPCODE(phaddw, phaddw, phaddw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(phaddd, phaddd, phaddd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(phaddsw, phaddsw, phaddsw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmaddubsw, pmaddubsw, pmaddubsw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(phsubw, phsubw, phsubw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(phsubd, phsubd, phsubd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(phsubsw, phsubsw, phsubsw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(psignb, psignb, psignb, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(psignw, psignw, psignw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(psignd, psignd, psignd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmulhrsw, pmulhrsw, pmulhrsw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pabsb, pabsb, pabsb, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pabsw, pabsw, pabsw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pabsd, pabsd, pabsd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pblendvb, pblendvb, pblendvb, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(blendvps, blendvps, blendvps, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(blendvpd, blendvpd, blendvpd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(packusdw, packusdw, packusdw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pcmpeqq, pcmpeqq, pcmpeqq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pcmpgtq, pcmpgtq, pcmpgtq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pminsb, pminsb, pminsb, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pminsd, pminsd, pminsd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pminuw, pminuw, pminuw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pminud, pminud, pminud, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmaxsb, pmaxsb, pmaxsb, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmaxsd, pmaxsd, pmaxsd, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmaxuw, pmaxuw, pmaxuw, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmaxud, pmaxud, pmaxud, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmuldq, pmuldq, pmuldq, 0, REGARG(XMM0), MEMARG(OPSZ_16))
OPCODE(pmulld, pmulld, pmulld, 0, REGARG(XMM0), MEMARG(OPSZ_16))

OPCODE(ucomiss, ucomiss, ucomiss, 0, REGARG(XMM0), MEMARG(OPSZ_4))
OPCODE(ucomisd, ucomisd, ucomisd, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(comiss, comiss, comiss, 0, REGARG(XMM0), MEMARG(OPSZ_4))
OPCODE(comisd, comisd, comisd, 0, REGARG(XMM0), MEMARG(OPSZ_8))
OPCODE(invept, invept, invept, 0, REGARG(XAX), MEMARG(OPSZ_16))
OPCODE(invvpid, invvpid, invvpid, 0, REGARG(XAX), MEMARG(OPSZ_16))

OPCODE(crc32, crc32, crc32, 0, REGARG(EAX), MEMARG(OPSZ_4))

OPCODE(vmread, vmread, vmread, X64_ONLY, MEMARG(OPSZ_4), REGARG(EAX))
OPCODE(vmwrite, vmwrite, vmwrite, X64_ONLY, REGARG(EAX), MEMARG(OPSZ_4))
OPCODE(movsxd, movsxd, movsxd, X64_ONLY, REGARG(RAX), MEMARG(OPSZ_4))

OPCODE(fadd, fadd, fadd, 0, REGARG(ST0), MEMARG(OPSZ_4))
OPCODE(fmul, fmul, fmul, 0, REGARG(ST0), MEMARG(OPSZ_4))
OPCODE(fdiv, fdiv, fdiv, 0, REGARG(ST0), MEMARG(OPSZ_4))
OPCODE(fdivr, fdivr, fdivr, 0, REGARG(ST0), MEMARG(OPSZ_4))
OPCODE(fsub, fsub, fsub, 0, REGARG(ST0), MEMARG(OPSZ_4))
OPCODE(fsubr, fsubr, fsubr, 0, REGARG(ST0), MEMARG(OPSZ_4))
OPCODE(fcmovbe, fcmovbe, fcmovcc, 0, OP_fcmovbe, REGARG(ST0))

OPCODE(extrq, extrq, extrq, 0, REGARG(XMM0), REGARG(XMM1))
OPCODE(insertq, insertq, insertq, 0, REGARG(XMM0), REGARG(XMM1))
OPCODE(bt, bt, bt, 0, MEMARG(OPSZ_4), REGARG(EAX))

OPCODE(maskmovq, maskmovq, maskmovq, 0, REGARG(MM0), REGARG(MM0))
OPCODE(maskmovdqu, maskmovdqu, maskmovdqu, 0, REGARG(XMM0), REGARG(XMM0))

OPCODE(enter, enter, enter, 0, IMMARG(OPSZ_2), IMMARG(OPSZ_1))

OPCODE(jnz, jnz, jcc, 0, OP_jnz, TGTARG)
OPCODE(jno_short, jno_short, jcc_short, 0, OP_jno_short, TGTARG)

