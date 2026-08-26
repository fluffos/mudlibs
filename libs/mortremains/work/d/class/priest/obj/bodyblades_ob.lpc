//first attempt to amke a spell
//Cyanide advice and code helped me.
//with ilz code to help me
// 01-10-99  Cyanide fixed some bugs.  Who coded this?


#include <m_spells.h>
#include <magic.h>
#include <mudlib.h>

inherit OBJECT;

void create() {
    seteuid(getuid());
    set("id", ({ "#BODYBLADES#", "#REFLEXIVE_SPELL#" }) );
    set("long", "Small sharp blades protrude from your flesh.\n");
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}


int begin_spell(object caster) {
    set("level", caster->query_level("priest"));
    set("enchantment", STRONG);
    set("schools", ({ "evocation" }) );

    call_out("remove", caster->query_level() * 30 );
    return 1;
}

int remove() {

    object caster = environment(this_object());

    if ((caster) && living(caster)) {
	tell_object(caster, "Your Body Blades spell ends.\n");
    }
    ::remove();
    return 1;
}


int reflex(int damage, string type, object ob, int weap) {
    string msg;
    int dam;

    if (ob && living(ob) && (damage>0) && (weap)){
	dam = 3 + random(12);
	switch(dam) {
	case 1..7: msg="You are cut by the body blades.\n" ;
	    break;
	case 8..10: msg="The body blades slice deep into your skin.\n" ;
	    break;
	case 11..1000: msg="You cry as chunks of flesh are chopped from your body.\n" ;
	    break;
	default: msg = "You scream as thousands of tiny blades"+
	    " dice your flesh up!\n" ;
	    break;
	}
	tell_object(ob, msg);
	tell_object(environment(TO), ob->query("cap_name")+
	  " is cut by your blades.\n");
	ob->set("last_attacker", environment(TO));
	ob->receive_damage(dam, "slashing");
    }
    return damage;
}
