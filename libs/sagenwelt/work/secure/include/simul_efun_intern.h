/// @addtogroup sefun
/// @{
/// @file simul_efun_intern.h
/// @brief for internal use only
/// @author Gwenhwyvar
/// @version 0.1.0
/// @date 2016-01-25

#ifndef __SEC_SIMUL_EFUN_INTERN_H
#define  __SEC_SIMUL_EFUN_INTERN_H

private void init_object_sefuns(void);
private void init_terminal_sefuns(void);

private varargs void _syslog(object caller, string uid, string gid, int priority, string format, mixed *args...);

#endif;
