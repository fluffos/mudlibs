/* Paths */
#include "../lib/attribs.h"

#define ROOTDIR       "/obj/guilds/"
#define LOGDIR        (ROOTDIR + "log/")
#define CMDDIR        (ROOTDIR + "cmds/")
#define NPCDIR        (ROOTDIR + "npc/")
#define DAEMONS       (ROOTDIR + "daemon/")
#define HELPDIR       (ROOTDIR + "help/")
#define WIZHELP       (HELPDIR + "wiz/")
#define OBJDIR        (ROOTDIR + "obj/")
#define WEPDIR        (ROOTDIR + "wep/")
#define ARMDIR        (ROOTDIR + "arm/")
#define LIBDIR        (ROOTDIR + "lib/")
#define ROOMDIR       (ROOTDIR + "room/")
#define SPELLS        (ROOTDIR + "spells/")
#define STDDIR        (ROOTDIR + "std/")
#define PERSONAL_LOGS "/obj/guilds/log/personal/"

#define MAINSAVE      "obj/guilds/save/"
#define BACKUPDIR     "obj/guilds/save/backup/"

mixed query_path(string str)
{
  switch(str)
  {
    case "root":         return ROOTDIR;
    case "log":          return LOGDIR;
    case "cmds":         return CMDDIR;
    case "npc":          return NPCDIR;
    case "daemons":      return DAEMONS;
    case "help":         return HELPDIR;
    case "wizhelp":      return WIZHELP;
    case "obj":          return OBJDIR;
    case "wep":          return WEPDIR;
    case "arm":          return ARMDIR;
    case "lib":          return LIBDIR;
    case "rooms":        return ROOMDIR;
    case "spells":       return SPELLS;
    case "std":          return STDDIR;
    case "personal":     return PERSONAL_LOGS;
    case "mainsave":     return MAINSAVE;
    case "backupdir":    return BACKUPDIR;
    case "master": return MASTER;
    case "guildname": return GUILDNAME;
    case "wiztool": return WIZTOOL;
    case "gwiz": return GWIZ;
    case "objpath": return OBJPATH;
  }
  return str;
}
    
