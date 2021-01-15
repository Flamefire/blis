/*

   BLIS
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas at Austin
   Copyright (C) 2018 - 2020, Advanced Micro Devices, Inc. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name(s) of the copyright holder(s) nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

//#ifndef BLIS_FAMILY_H
//#define BLIS_FAMILY_H

//To enable framework optimizations for EPYC family processors.
//With this macro defined, we can call kernels directly from
//BLAS interfaces for levels 1 & 2.
//This macro needs to be defined for all EPYC configurations.
#define BLIS_CONFIG_EPYC

// By default, it is effective to parallelize the outer loops.
// Setting these macros to 1 will force JR and IR inner loops
// to be not paralleized.
#define BLIS_DEFAULT_MR_THREAD_MAX 1
#define BLIS_DEFAULT_NR_THREAD_MAX 1

#define BLIS_ENABLE_ZEN_BLOCK_SIZES
#define BLIS_ENABLE_SMALL_MATRIX
// Disabling BLIS_ENABLE_SMALL_MATRIX_TRSM macro for trsm small , to avoid
// generating �inf� and �NaN� values for extremely small input test data 
// Ex: FLOAT_MIN  1.40129846e-45 and DOUBLE_MIN  4.9406564584124654e-324
// on single thread environment.
//#define BLIS_ENABLE_SMALL_MATRIX_TRSM

// This will select the threshold below which small matrix code will be called.
#define BLIS_SMALL_MATRIX_THRES        700
#define BLIS_SMALL_M_RECT_MATRIX_THRES 160
#define BLIS_SMALL_K_RECT_MATRIX_THRES 128

#define BLIS_SMALL_MATRIX_THRES_TRSM   32768 //128(128+128) => m*(m+n)
#define BLIS_SMALL_MATRIX_A_THRES_TRSM	128
#define BLIS_SMALL_MATRIX_A_THRES_M_SYRK	96
#define BLIS_SMALL_MATRIX_A_THRES_N_SYRK	128

//This macro will enable  BLIS DGEMM to choose block sizes for a  single instance mode
#define BLIS_ENABLE_SINGLE_INSTANCE_BLOCK_SIZES 	0

#define D_BLIS_SMALL_MATRIX_THRES_TRSM_NAPLES 250
#define D_BLIS_SMALL_MATRIX_THRES_TRSM_ALXB_NAPLES 90

#define D_BLIS_SMALL_MATRIX_THRES_TRSM_DIM_RATIO 22
// Allow the sup implementation to combine some small edge case iterations in
// the 2nd loop of the panel-block algorithm (MR) and/or the 2nd loop of the
// block-panel algorithm (NR) with the last full iteration that precedes it.
// NOTE: These cpp macros need to be explicitly set to an integer since they
// are used at compile-time to create unconditional branches or dead code
// regions.
#define BLIS_ENABLE_SUP_MR_EXT 1
#define BLIS_ENABLE_SUP_NR_EXT 0



//#endif

