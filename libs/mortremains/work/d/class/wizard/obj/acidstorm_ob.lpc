// The storm object.
// (06-22-96) Written by Chronos.
// (08-28-96) Modified by Chronos.
// (11-01-96) Adapted by chronos to acidstorm.

#include <magic.h>
#include <messages.h>

inherit OBJECT;

void create() {
    seteuid(getuid());
    set("short", "Acidic rain is falling from above.") ;
    set("id", ({ "#ACIDSTORM#", "storm", "acid storm" }) );
    set("long", @ENDLONG
Acid rain is falling from somewhere above, burning everything it
touches.
ENDLONG
    ) ;
    set("enchantment", MODERATE);
    set("schools", ({ "evocation" }) );
    set("prevent_get", 1);
    set("prevent_insert", 1);
}

int start_spell(int power, object caster) {
    tell_room(environment(), "Suddenly, sticky green globs of"+
      " acid begin raining from the sky!\n");
    call_out("kill_people", 1 + random(4), power, caster);
    call_out("remove", (random(power) + 1) * 3);
    return 1;
}

int remove() {
    object env = environment();

    if (env) {
	message(MSG_SPELL, "The acid rain finally thins out "+
	  "and stops.\n", environment(TO) ) ;
	if (!environment()->query("burnt")) {
	    environment()->set("burnt", 1) ;
	    environment()->add("long",
	      "There are splashes of acid burns everywhere here.\n") ;
	}
    }

    ::remove();
    return 1;
}

int kill_people(int power, object caster) {
    int damage, i;
    object *inv;
    string msg;
    inv = all_inventory(environment());
    if (!inv || !sizeof(inv)) {
	call_out("kill_people", 5 + random(5), power, caster);
	return 1;
    }
    for(i=0;i<sizeof(inv);i++) {
	if (!random(4)) {
	    tell_object(inv[i], "The acid rain falls all around you,"+
	      " but you aren't injured by it.\n") ;
	    continue;
	}
	damage = 8 + random(power);
	damage = inv[i]->receive_damage(damage, "acid", 0, 0) ;

	switch(damage) {
	case -1000..0: msg = "You are unaffected by the acid.\n";
	    break;
	case 1..12: msg="You are singed by the acidic rain.\n" ;
	    break;
	case 13..15: msg = "Acid rain burns your flesh lightly.\n" ;
	    break;
	case 16..17: msg = "Acid rain gets in your eyes, "+
	    "burning them.\n" ;
	    break;
	case 18..20 : msg = "Acid pours down from above, burning "+
	    "you badly.\n" ;
	    break;
	case 21..23 : msg = "You are burned horribly by the "+
	    "acid rain.\n" ;
	    break;
	case 24..28: msg = "You scream aloud as the acid burns "+
	    "through your flesh!\n" ;
	    break;
	case 29..33 : msg = "You are injured severely by the "+
	    "raining acid!\n" ;
	    break ;
	default: msg = "You let out a tortured scream as acid eats"+
	    " through your flesh!\n" ;
	    break;
	}

	tell_object(inv[i], msg);
    }
    call_out("kill_people", 5 + random(5), power, caster);
    return 1;
}
