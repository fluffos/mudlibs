/*
** ilz
*/

#include <mudlib.h>

inherit OBJECT;

void create() {
  set("id", ({ "#HOLD#" }) );
set("prevent_drop", 1);
set("prevent_get", 1);
}

void begin_spell (object ob, int level) {
  tell_object(ob, "You become paralyzed!\n");
  tell_room(environment(ob), ob->query("cap_name")+" is paralyzed and held.\n", ({ ob }) );
   set("extra_look", "$N is held.\n");  
  ob->set("no_move", level);
  ob->block_attack(level);
  call_out("remove", (level));
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
