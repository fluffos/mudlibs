
#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

inherit OBJECT;

int thac=0;

void create() {
   set("id", ({ "#TDEADLYAIM#" }) );
   set("extra_look", "$N has the look of a weaponsmaster.\n");
  set("prevent_drop", 1);
  set("dest_at_die", 1);
}

void begin_spell (object caster, int lvl) {

   set("enchantment", 3);
  set("schools", ({ "alteration" }) );
  set("level", lvl);
  set("caster", caster->query("cap_name"));

   call_out("remove", 8*lvl);

  return;
}
int thac() {
object current = 0, caster = 0;
set("caster", caster->query("LEVEL"));
set("current", 21 - caster->query_level() );
add("magical_bonus", current);
return 1;
}



int remove() {
  object ruum = 0, caster = 0;

  caster = environment(this_object());
  if (caster) ruum = environment(caster);
  if (ruum) {
    tell_room(ruum, wrap(caster->query("cap_name")+
    " loses the warrior's edge."), ({ caster }) );
   tell_object(caster, "You lose the warrior essence and ability.\n");
   caster->delete("tdeadlyaim");
  }
  ::remove();
  return 1;
}          
