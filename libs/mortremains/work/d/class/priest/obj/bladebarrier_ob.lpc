//first attempt to amke a spell
//Cyanide advice and code helped me.
//with ilz code to help me

#include <m_spells.h>
#include <magic.h>
#include <mudlib.h>

inherit SPELL;
inherit OBJECT;

object master;

void create() {
    seteuid(getuid());
    set("id", ({ "#BLADEBARRIER##", "#REFLEXIVE_SPELL#" }) );
    set("short", "Tiny sharp blades spinning around like a globe.") ;
    set("long", "A wall of circling,razor sharp blades.\n"+ 
      "They Whirl and flash in endless movement around.\n");
    set("prevent_get", 1);

}

void init() {
int dmg;
dmg = (random(49)+16);
  if ((master) && living(TP) && (TP!=master)) { 
    tell_room(environment(), "Thousands of blades swirl about!\n");
    if (!check_magic_resist(master, TP, 80, dmg)){
    if (!(TP->save_throw())){
   TP->receive_damage(dmg, "slashing", master);
   TP->set("last_attacker", master);
    }
    }
}
}

int start_spell(object caster){
    set("level", caster->query_level("priest"));
    set("enchantment", STRONG);
    set("schools", ({ "evocation" }) );
master = caster;
    call_out("remove", 3 );
    return 1;
}

int remove() {

    object caster = environment(this_object());

    if ((caster) && living(caster)) {
	tell_object(caster, "Your Awesome Blade Barrier spell ends.\n");
    }
    ::remove();
    return 1;
}


