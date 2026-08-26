/*
** The general mages' class object.
** Now mages can have class.   ;)
** Cyanide worked all the bugs out, 23 July 1997.
*/

#define VIKING_PATH "/d/Prime/Dagaard/dilligaf/Vikings/cmds"
#include <daemons.h>

inherit OBJECT;

string path;

void create() {
  seteuid(getuid());
  set("short" , "A full beard with many braids in it");
  set("long" , @EndText
  This is your Viking Clan badge of courage. Each braid is a symbol
  of prowess and ability when faced with combat. It is a true mark
  of courage, and should be worn with pride...it has taken you a long
  time to earn it.
EndText
);
  set("id" , ({ "#CLASS_OBJECT#" , "beard" }) );
   set("prevent_get", 1);
  set("prevent_drop", 1);
  set("prevent_insert", 1);
  set("prevent_clean", 1);
}

void init() {
  add_action("cmd_hook", "", 1);
   if (!living(environment())) remove();
}

int cmd_hook(string cmd) {
  string file, verb;
  int blah;

  path = VIKING_PATH;
  verb = query_verb();

  if (verb == "clean") return 0;
  file = (string)CMD_D->find_cmd(verb, explode(path, ":"));
  if (file && (file!=""))
    blah = (int)call_other(file, "cmd_"+verb, cmd);

  return blah;
}

int query_auto_load() { return 1; } 
