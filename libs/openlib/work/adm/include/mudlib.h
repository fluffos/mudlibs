/*  -*- LPC -*-  */
// file: mudlib.h
#ifndef _MUDLIB_H
#define _MUDLIB_H

#include "dirs.h"

// Conflict with type.h
#undef OBJECT

// Objects
#define MASTER_OB    SECURE_DAEMON_DIR "/master"
#define SIMUL_EFUN   SECURE_DAEMON_DIR "/simul_efun"
#define VOID_OB      SECURE_DAEMON_DIR "/void"

#define BASE         INHERIT_DIR "/base"
#define OBJECT       INHERIT_DIR "/object"
#define CONTAINER    INHERIT_DIR "/container"
#define TORCH        INHERIT_DIR "/torch"
#define ROOM	     INHERIT_DIR "/room"
#define LIVING       INHERIT_DIR "/living"
#define DAEMON       INHERIT_DIR "/daemon"
#define SHOP         INHERIT_DIR "/shop"
#define WEAPON       INHERIT_DIR "/weapon"
#define ARMOUR       INHERIT_DIR "/armour"
#define USER         CLONE_DIR "/user"
#define MONSTER      CLONE_DIR "/monster"
#define MAILBOX      SECURE_CLONE_DIR "/mailbox"

#endif /* _MUDLIB_H */
