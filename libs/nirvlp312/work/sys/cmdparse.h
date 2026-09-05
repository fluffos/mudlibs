/*
 * /sys/cmdparse.h
 */
#ifndef _sys_cmdparse_h
#define _sys_cmdparse_h

#define CMDPARSE_STD "/sys/global/cmdparse"

#define CMDPARSE_ONE_ITEM(c,fun) call_other(CMDPARSE_STD,"do_verb_1obj",c,fun,this_object())
#define CMDPARSE_IN_ITEM(c,p,f) call_other(CMDPARSE_STD,"do_verb_inside",c,p,f,this_object())
#define CMDPARSE_WITH_ITEM(c,ch,fun) call_other(CMDPARSE_STD,"do_verb_with",c,ch,fun,this_object())

#endif
