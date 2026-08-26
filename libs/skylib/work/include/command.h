#ifndef _COMMAND_H
#define _COMMAND_H

#define CMD_D "/secure/command"
#define DIR_PLAYER_CMDS "/cmds/player"
#define DIR_PENDING_CMDS "/cmds/pending"
#define DIR_SECURE_PLAYER_CMDS "/secure/cmds/player"
#define DIR_LIVING_CMDS "/cmds/living"
#define DIR_CREATOR_CMDS "/cmds/creator"
#define DIR_SECURE_CREATOR_CMDS "/secure/cmds/creator"
#define DIR_LORD_CMDS "/cmds/lord"
#define DIR_SECURE_LORD_CMDS "/secure/cmds/lord"
#define DIR_ADMIN_CMDS "/cmds/admin"
#define DIR_SECURE_ADMIN_CMDS "/secure/cmds/admin"
#define DIR_GUILD_CMDS "/cmds/guild-race"
#define DIR_PLAYTESTER_CMDS "/cmds/playtester"

class command {
  string verb;
  string file;
  string args;
  string filepart;
}

#endif
