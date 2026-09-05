/*
 * In this file some closures are given names which can be used instead of
 * the weird syntax starting with hash-quote which causes lots of troubles
 * with paranthesis-matching editors.
 */

#ifndef _sys_closures_h
#define _sys_closures_h

#define CL_INDEX CL_L_INDEX
#define CL_L_INDEX #'[                 /* #'index */
#define CL_R_INDEX #'[<                /* #'rindex */
#define CL_ARRAY #'({                  /* #'aggregate */
#define CL_MAPPING #'([                /* #'m_caggregate */
#define CL_RANGE CC_LL_RANGE
#define CL_LL_RANGE #'[..]             /* #'..  */
#define CL_LR_RANGE #'[..<]            /* #'nr_range */
#define CL_RL_RANGE #'[<..]            /* #'rn_range */
#define CL_RR_RANGE #'[<..<]           /* #'rr_range */
#define CL_L_RANGE #'[..               /* #'extract2 */
#define CL_R_RANGE #'[<..              /* #'[<..  (operator *puzzle*)  */

#define CL_MAPPING_INDEX #'[,]         /* indexing in mappings with width > 1
                                        * without lambda() but directly via
                                        * funcall(). in lamnda() this is
                                        * identical wit CL_INDEX (#'[)   */

#endif  /* _sys_closures_h  */
