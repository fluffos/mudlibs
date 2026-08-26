/*
** Bard's class object
*/

#define BCMD "/d/class/bard/cmds"

#include <daemons.h>
#include <rogues.h>

inherit OBJECT;

string path;

void create() {
  seteuid(getuid());
   set("short", "a Zither");
   set("long", "A small Zither, it's a musical instrament. This\n"+
       "makes you a bard and such. The word bardhelp comes into mind.\n");
  set("id", ({ "#CLASS_OBJECT#", "zither", "musical instrament" }) );
  set("prevent_get", 1);
  set("prevent_give", 1);
  set("prevent_drop", 1);
  set("prevent_insert", 1);
  set("prevent_clean", 1);
set("banned_weight", 35);
}

void init() {
  add_action("cmd_hook", "", 1);
   if (!living(environment())) remove();
}

int cmd_hook(string cmd) {
  string file, verb;
  int blah;

  path = BCMD;
  verb = query_verb();

  if (verb == "clean") return 0;
  file = (string)CMD_D->find_cmd(verb, explode(path, ":"));
  if (file && (file!=""))
    blah = (int)call_other(file, "cmd_"+verb, cmd);

  return blah;
}

int query_auto_load() { return 1; } 
