// Cyanide fixed this, 21 Nov 98.

#include <mudlib.h>
#include <messages.h>

inherit MONSTER ;

int delay = 4;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "cyanide");
    set ("short", "a magma golem") ;
    set("long", wrap("This monstrosity is composed entirely of molten rock. It's roughly"+
	" man-shaped but seems to ooze and flow as it moves. It's surface "+
	"is black, but covered with a latticework of cracks thourgh which "+
	"glows the inner radiance of the lava.") );
    set("lore_type", "arcanology");
    set("lore", wrap("Little is known of these creatures, except "+
	"that they are constructs created by powerful mages. They are "+
	"known for escaping their masters control relatively often.") );
    set ("id", ({ "golem", "magma golem" }) ) ;
    set("stat", ([
      "strength" : 18,
      "constitution" : 16,
      "dexterity" : 5,
      "intelligence" : 2,
      "wisdom" : 2,
      "charisma" : 2
    ]) );
    set_align("tn");
    set_size(8);
    set_name ("magma golem") ;
    set ("race", "golem");
    set ("gender", "neuter") ;
    enable_commands() ;
    set_living_name("magme golem") ;
    set("resist_type",([ "cold":0, "dehydration":0,"fire":0, "poison":0, 
      "mental":0, "electricity":50, "necromancy":0]));
    set ("base_ac", 5);
    set ("armor_class", 5);
    set("CLASS", "warrior");
    set ("damage", ({ 4,24 }) ) ;
    set("damage_type", "fire");
    set ("weapon_name", "fiery fists") ;
    set_verbs( ({ "crush", "pummel" }) ) ;
    set ("special", 5);

    set_level(18);

    credit( query("hit_points") / 2 ); 
}

varargs int receive_damage( int d, string t, object o, int w) {
    if (w && o && !o->query("weapon1") && !o->query("weapon2")) {
	if( o->receive_damage(random(10)+1,"fire",TO,0) )
	    message(MSG_COMBAT, "You badly burn your hands on "+
	      "the golem!\n", o);
    }
    return ::receive_damage(d,t,o,w);
}

void heart_beat() {
    object *obs = query_attackers();
    int sz = sizeof(obs);

    for (int b=0; b<sz; b++) {
	if (!obs[b]) continue;
	if (obs[b]->receive_damage(random(6) + 1, "fire", TO, 0))
	    message(MSG_COMBAT, "You are burned from the intense heat!\n", 
	      obs[b]);
    }

    ::heart_beat();
}

int special_attack() {
    object ob = get_random_attacker();

    if (--delay == 0) {
	message(MSG_COMBAT, "The magma golem collects itself into a fiery "+
	  "mass, and launches itself\nat you!\n", ob);
	message(MSG_COMBAT, "The magma golem collects itself into a fiery "+
	  "mass, and launches itself\nat "+ob->query("cap_name")+"!\n", 
	  all_inventory(environment(TO)), ob);

	ob->receive_damage(random(35) + 7, "fire", TO, 1);
	ob->receive_damage(random(15) + 3, "crushing", TO, 1);

	block_attack(2);
	delay = 5;

	return 1;
    }
}

/* EOF */
