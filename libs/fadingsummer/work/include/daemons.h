// mudlib: Fading Summer
// file:   daemons.h
// Museum: single-literal paths so MACRO->fn() is not parsed as
// "/system"+"/daemons"+("/logon_d"->fn()) (KB-style + vs -> precedence).

#ifndef _H_DAEMONS_
#define _H_DAEMONS_

#define LOGON_D         "/system/daemons/logon_d"
#define VERB_D          "/system/daemons/verb_d"
#define NEWUSER_D       "/system/daemons/newuser_d"
#define SHELL_D         "/system/daemons/shell_d"
#define BANISH_D        "/system/daemons/banish_d"
#define LOG_D           "/system/daemons/log_d"

#endif
