/*
** ilz
*/

#include <mudlib.h>

inherit OBJECT;

void create() {
  set("id", ({ "#PIN#" }) );
set("prevent_drop", 1);
set("prevent_get", 1);
}

void begin_spell (object ob, int level) {
  tell_object(ob, "You become frozen to the ground!\n");
  tell_room(environment(ob), ob->query("cap_name")+" is frozen in place.\n", ({ ob }) );
   set("extra_look", "$N is pinned to the ground.\n");  
  ob->set("no_move", (level*5));
  call_out("remove", (level*5));
  return;
}

void remove() {
  object caster;
  
  caster = environment(this_object());  
  
  if (caster){
   if (living(caster)) {
    caster->delete("no_move");
    }
    }
  ::remove();
}

/* EOF */
