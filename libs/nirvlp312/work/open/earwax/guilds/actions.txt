#include "../include/def.h"
#define FREEZE ({ "ge", "gt", "gts", "help", "quit", "i", "inventory", \
"quit", "unfreeze", "run", "wear", "tag", "untag", "gossip", "babble", \
"equip", "junk", "risque", "sc", "score", "guildbug", "guildfix", \
"gpromote", "ally", "channel", "darken", "restore", \
"expell", "execute", "gsave", "gstat", "grin", "rehash", "remove", \
"unguild", "sacrifice", "mount", "guilderr", "finger" })

static mapping cmds;           
static mapping base;    


void
GetMap() {
   int         i;
   string      *f, cmd;
   i = sizeof(f = files(BINDIR + "*.c"));
   cmds = allocate_mapping(i);
   while (i--) {
      sscanf(f[i], "%s.c", cmd);
      cmds[cmd] = BINDIR + cmd;    } 
   i = sizeof(f = FREEZE);
   base = allocate_mapping(i);
   while (i--)
   base[f[i]] = cmds[f[i]];
}

mapping
query_cmds(status frozen)
{
   /*
   * Just return the mapping, share share share!
   */
   if(!cmds) GetMap();
   return (frozen ? base : cmds);
}

void
rehash()
{
   int         i;
   string      *f, cmd;
   
   /*
   * Add any new commands to the shared mapping
   */
   i = sizeof( f = files( BINDIR + "*.c"));
   while (i--) {
      sscanf(f[i], "%s.c", cmd);
      cmds[cmd] = BINDIR + f[i];
   }
}

void
reset() {
   GetMap();
}

void create() {
   GetMap();
}

string *
query_base() { return FREEZE; }
