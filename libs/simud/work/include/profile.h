#ifndef __PROF_H__
#define __PROF_H__
#define PROFILED "/daemon/profiled"

#define PROF_FNAME  0
#define PROF_PROFPT 1
#define PROF_EVALC  2
#define PROF_TDELTA 3

#define UTIME_COST 2
#define OVERHEAD   4
#define PROF(x,y)  { int *___time1; int *___time2; int ___cost; \
                     PROFILED->init_prof(); \
                     ___cost = get_eval_cost(); \
                     ___time1 = utime(); \
                     y \
                     ___time2 = utime(); \
                     ___cost = ___cost - get_eval_cost(); \
                     ___cost = ___cost - UTIME_COST*2 - OVERHEAD; \
                     ___time2[0] = ___time2[0] - ___time1[0]; \
                     ___time2[1] = ___time2[1] - ___time1[1]; \
                     if( ___time2[1] < 0 ) { ___time2[1] += 1000000; \
                     ___time2[0]--; } \
                     PROFILED->finish_prof(__FILE__,"x",___cost,___time2); \
                   }
#define PROF_PRINT  if(this_player() && \
                       this_player()->query_level()>=WIZLEVEL) { \
                      mixed ___temp; \
                      ___temp = PROFILED->query_last_exec_data(); \
                      msg("~CCOM"+___temp[PROF_FNAME]+"::" + \
                          ___temp[PROF_PROFPT]+"~CDEF"); \
                      msg("   Eval Cost: "+___temp[PROF_EVALC]); \
                      msg("   Real Time: "+ \
                          PROFILED->tdelta_to_string(___temp[PROF_TDELTA]) + \
                          " seconds"); \
                    }
#endif
