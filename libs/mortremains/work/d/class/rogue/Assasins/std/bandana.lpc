/*
** The general mages' class object.
** Now mages can have class.   ;)
** Cyanide worked all the bugs out, 23 July 1997.
** Nightmask took the file and made it a belt for no reason st all.
*/

#define ASSASIN "/d/class/rogue/Assasins/cmds"

#include <daemons.h>
//#include <rogues.h>

inherit ARMOR;

string path;

void create() {
  seteuid(getuid());
  set("short", "a black bandana");
   set("long", "A black bandana, to keep the hair out of your\n"+
       "eyes while you kill shit.The word ahelp comes into mind.\n");
      
  set("id", ({ "#CLASS_OBJECT#", "bandana", "black bandana" }) );
  set("prevent_get", 1);
  set("prevent_give", 1);
  set("prevent_drop", 1);
  set("prevent_insert", 1);
  set("prevent_clean", 1);
  set_armor_type("clothing");
}

void init() {
  add_action("cmd_hook", "", 1);
   if (!living(environment())) remove();
}

int cmd_hook(string cmd) {
  string file, verb;
  int blah;

  path = ASSASIN;
  verb = query_verb();

  if (verb == "clean") return 0;
  file = (string)CMD_D->find_cmd(verb, explode(path, ":"));
  if (file && (file!=""))
    blah = (int)call_other(file, "cmd_"+verb, cmd);

  return blah;
}

int query_auto_load() { return 1; } 
