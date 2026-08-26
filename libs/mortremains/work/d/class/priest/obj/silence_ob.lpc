/*
** ilz
*/

#include <mudlib.h>

inherit OBJECT;

void create() {
  set("id", ({ "#SILENCE_OB#" }) );
set("prevent_drop", 1);
set("prevent_get", 1);
}

void begin_spell (object ob, int level) {
  tell_object(ob, "You can no longer speak!\n");
  tell_room(environment(ob), ob->query("cap_name")+" is silenced.\n", ({ ob }) );
  ob->set("silenced", (level*2));
  call_out("remove", (level*2));
  return;
}

void remove() {
  object caster;
  
  caster = environment(this_object());  
  
  if (caster){
   if (living(caster)) {
    caster->delete("silenced");
    }
    }
  ::remove();
}

/* EOF */
