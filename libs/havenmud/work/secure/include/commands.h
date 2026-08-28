#ifndef __COMMANDS_H
#define __COMMANDS_H

#include "dirs.h"

#define CMD_ASSUME            "/secure/cmds/creators/assume"
#define CMD_CALL              ("/secure/cmds/creators/call")
#define CMD_COSTS             "/cmds/common/costs"
#define CMD_CHANHIST          ("/cmds/players/chanhist")
#define CMD_ENCRE             (DIR_SECURE_ADMIN_CMDS "/angel")
#define CMD_END               (DIR_ADMIN_CMDS+"/end")
#define CMD_DECRE             (DIR_SECURE_ADMIN_CMDS "/decre")
#define CMD_SAY			(DIR_PLAYER_CMDS "/say")
#define CMD_SETREBOOT         (DIR_SECURE_ADMIN_CMDS+"/setreboot")
#define CMD_SUICIDE           (DIR_MORTAL_CMDS+"/suicide")
#define CMD_CHFN              "/secure/cmds/players/chfn"
#define CMD_UPDATE            "/secure/cmds/creators/update"
#define CD "/cmds/dev/cd"
#define SU "/cmds/user/su"

#endif /* __COMMANDS_H */
