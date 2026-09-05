/*
 * /sys/closure_def.h
 */

#ifndef _sys_closure_def_h
#define _sys_closure_def_h

#define C_INDEX(on,in) ({#'[,on,in})  

#define C_CALL(ob,fun) ({#'call_other,ob,fun}) 
#define C_CALL1(ob,fun,arg) ({#'call_other,ob,fun,arg}) 
#define C_CALL2(ob,fun,arg,arg2) ({#'call_other,ob,fun,arg,arg2}) 
#define C_CALL3(ob,fun,arg,arg2,arg3) ({#'call_other,ob,fun,arg,arg2,arg3}) 

#define C_PLAYER ({#'this_player})
#define C_OBJECT ({#'this_object})

#endif /* _sys_closure_def_h */
