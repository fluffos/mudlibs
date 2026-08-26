/*
** The general mages' class object.
** Now mages can have class.   ;)
** Cyanide worked all the bugs out, 23 July 1997.
** Nightmask took the file and made it a belt for no reason st all.
*/

#define THCMD "/d/class/rogue/thief/cmds"

#include <daemons.h>
#include <rogues.h>

inherit ARMOR;

string path;

void create() {
  seteuid(getuid());
  set("short", "a leather belt");
   set("long", "A leather belt, you can see pictures molded\n"+
       "into it. There is a small compartment in it for, well\n"+
       "you figure it out. The word \"thelp\" jumps into your mind.\n");
  set("id", ({ "#CLASS_OBJECT#", "belt", "leather belt" }) );
  set("prevent_get", 1);
  set("prevent_give", 1);
  set("prevent_drop", 1);
  set("prevent_insert", 1);
  set("prevent_clean", 1);
  set_armor_type("clothing");
set("banned_weight", 35);
}

void init() {
  add_action("cmd_hook", "", 1);
   if (!living(environment())) remove();
}

int cmd_hook(string cmd) {
  string file, verb;
  int blah;

  path = THCMD;
  verb = query_verb();

  if (verb == "clean") return 0;
  file = (string)CMD_D->find_cmd(verb, explode(path, ":"));
  if (file && (file!=""))
    blah = (int)call_other(file, "cmd_"+verb, cmd);

  return blah;
}

int query_auto_load() { return 1; } 
