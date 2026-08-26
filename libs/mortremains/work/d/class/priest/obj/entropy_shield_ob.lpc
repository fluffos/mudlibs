//ilz
// Cyanide fixed this, 14 July 2000

#include <magic.h>

inherit OBJECT;

void create() {
    seteuid(getuid());
    set("id", ({ "#ENTROPY_SHIELD#", "#REFLEXIVE_SPELL#", "shield",
      "entropy shield", "aura" }));
    set("long", "A glowing aura of chaotically shifing colors and intensities.\n"+ 
      "It can be dispelled by typing \"dispel eshield\".\n");
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}

void init() {
    add_action("dispel", "dispel");
}

int dispel( string str ) {
    if (str) 
	str = lower_case(str);
    else 
	str = "";

    if (str == "eshield") {
	write("You dispel your Entropy Shield spell.\n");
	remove();
	return 1;
    }

    return 0;
}

int begin_spell(object caster) {
    set("level", caster->query_level());
    set("caster", caster->query("name"));
    set("enchantment", MODERATE);
    set("schools", ({ "abjuration" }) );

    tell_object(caster, wrap("You are surrounded by a chaotically shifting "+
	"aura of light and darkness."));
    tell_room(environment(caster), wrap(caster->query("cap_name") +
	" is surrounded by a chaotically shifting "+
	"aura of light and darkness.") , ({ caster }) );
    set("extra_look", "$N is protected by a chaotic field of energy.\n");

    call_out("remove", caster->query_level() * 30 );
    return 1;
}

int reflex(int damage, string type, object ob) {
    string done;
    int ran;

    ran = ((environment()->query_level() << 1));
    if (ran>50) ran=50;
    if ((random(100)+1) < ran){
	if (ob && living(ob) && (damage>0)) {
	    tell_object(environment(), wrap("You entropy shield protects you from "+
		ob->query("cap_name")+"'s attack!"));
	    tell_room(environment(environment()), wrap(environment()->query("cap_name")+
		"'s entropy shield protects "+objective(environment()->query("gender"))+
		" from "+ob->query("cap_name")+"'s attacks!"),
	      ({ ob, environment() }) );
	    tell_object(ob, "Your attack gets absorbed by "+
	      environment()->query("cap_name")+"'s entropy shield.\n");
	    return 0;    
	}
    }

    return damage;
}

int remove() {
    object caster = environment(this_object());

    if ((caster) && living(caster)) {
	tell_object(caster, "Your entropy shield dissapears in a flash "+
	  "of light.\n");
	tell_room(environment(caster), caster->query("cap_name") +
	  "'s aura of chaos dissapears in a flash of light.\n", ({ caster }) );
    }
    return ::remove();
}                                                  

/* EOF */
