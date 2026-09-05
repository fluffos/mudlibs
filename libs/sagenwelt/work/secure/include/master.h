/// @addtogroup privileged
/// @{
/// @file master.h
/// @brief master specific macros and function declaratios
/// @author Gwenhwyvar
/// @version 0.1.0
/// @date 2015-11-29

#ifndef __SEC_MASTER_H
#define __SEC_MASTER_H

#include "std_paths.h"      // standard paths used by various objects

#define MASTER_SAVE     __SAVE_FILE(PRIV_SAVE_DIR "master")

public int       check_acl(int request, string euid, string egid, mixed info);
public int       valid_read(string file, object ob, string func);
public int       valid_write(string file, object ob, string func);

#endif // __SEC_MASTER_H

///  @}
