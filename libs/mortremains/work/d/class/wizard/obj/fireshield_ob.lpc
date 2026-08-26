/*
** File:  fireshield_ob.c
** Purpose: Spell object for 4st-level alteration/evocation spell, 
**    "fireshield".
** Duration 20 sec + 20 sec/level.
** Cost:  35 SP("
** Credits:
**   22 Jul 97   Cyanide@Nightfall's Keep write the file.
**   16 Dec 98   Cyanide made it not work with a stoneskin on.
*/

#include <m_spells.h>
#include <magic.h>
#include <mudlib.h>

inherit OBJECT;
inherit SPELL;

object env;
string color, *f_c = ({ "fire", "cold" });
int level, hot_cold = 0;

void create() {
    seteuid(getuid());
    set("enchantment", FAINT);
    set("schools", ({ "alteration", "evocation" }) );
    set("id", ({ "#FIRE_SHIELD#", "#REFLEXIVE_SPELL#" }) );
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}

varargs int start_spell(object caster, int hc_int, int lvl) {
    env = caster;
    if (level)
	set("level", level);
    else
	set("level", caster->query_level("mage") );

    if (hc_int==1) 
	color = ({"blue", "green"})[random(2)];
    else 
	color = ({"blue", "violet"})[random(2)];

    tell_object(caster, "You are suddenly surrounded by a shield of " +
      color + " flames.\n");
    tell_room(environment(caster), caster->query("cap_name") +
      " is suddenly engulfed in "+color+" flames.\n", ({ caster }) );
    set("extra_look", "$N is engulfed in "+color+" flames.\n");
    set("fire_type", f_c[hc_int]);
    caster->resistance(f_c[hc_int], 200);
    caster->resistance(f_c[!hc_int], 50);

    /*
      if (member_array("fire", f_c) == hc_int)
	 caster->resistance("magical_fire", 200);
      else
	 caster->resistance("magical_fire", 50);
    */

    call_out("remove", (20 + (caster->query_level() * 20) ));
    return 1;
}

int reflex(int damage, string type, object ob, int weap) {
    string done;

    if (!env) env = environment();
    if (!env) remove();

    if (ob && living(ob) && (damage>0) && 
      (weap)) {
	if (present("#STONESKIN#", env)) return 0;
	if (query("fire_type")=="fire") {
	    ob->receive_damage(damage, "fire");
	    done = "burned";
	} else { 
	    done = "frozen";
	    ob->receive_damage(damage, "cold");
	}

	ob->set("last_attacker", environment());
	tell_room(environment(environment()), ob->query("cap_name")+
	  " is badly "+done+" by "+environment()->query("cap_name")+
	  "'s fire shield!\n", ({ environment(), ob }) );
	tell_object(environment(), ob->query("cap_name")+ 
	  " is badly "+done+" by your fire shield!\n");
	tell_object(ob, "You are badly "+done+" by "+
	  environment()->query("cap_name")+" fire shield.\n");
    }

    return damage;
}

int remove() {
    object caster = environment(this_object());
    int hc_int;

    if (environment()) caster = environment();
    if ((caster) && living(caster)) {

	tell_object(caster, "Your fire shield sputters and dies out.\n");
	tell_room(environment(caster), caster->query("cap_name") +
	  "'s fire shield sputters and dies down.\n", ({ caster }) );
	if (query("fire_type") == "fire") {
	    caster->resistance("cold", 200);
	    caster->resistance("fire", 50); 
	} else {
	    caster->resistance("cold", 50);
	    caster->resistance("fire", 200);  
	}
    }
    ::remove();
}               
