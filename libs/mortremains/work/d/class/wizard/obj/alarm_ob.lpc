/*
** File:  alarm_ob.c
** Purpose:  The spell object for the 1st level mage spell "alarm".
** Credits: 
**   20 Apr 97  Cyanide wrote the file...
**   03 Jul 97  Cyanide FINALLY got around to creating THIS file.
*/

#include <magic.h>

inherit OBJECT;

object master;

void create() {
  seteuid(getuid());
  set("enchantment", DIM);
  set("schools", ({ "abjuration" }) );
  set("id", ({ "#ALARM_OB#" }) );
  set("prevent_get", 1);
}

varargs int start_spell (object ob) {
  if (ob) {
    master = ob;
    tell_room(environment(), "You hear a bell chime softly in the"+ 
      " distance.\n");
    return 1;
  }
  return 0;
}

void init() {
  if ((master) && living(TP) && (TP!=master)) { 
    tell_room(environment(), "A loud ringing fills the room!\n");
    if (!present(master->query("name"), environment())) {
      tell_object(master, wrap("[*Alarm*] "+TP->query("cap_name")+
        " has set off you alarm in "+environment()->query("short")+
        ".\n"));
    } else {
      if (master->query("rest")) {
        tell_object(master, "The alarm sounds, waking you with a start!\n");
        master->set("rest", 0);
      }
    }

  if (!query("dissolving")) {
    call_out("remove", 3);
    set("dissolving", 1);
  }
  }
}

string query_master() {
  if (master) return (master->query("cap_name"));
  else return ("NONE");
}
