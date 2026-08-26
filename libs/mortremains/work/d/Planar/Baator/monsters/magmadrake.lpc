// Cyanide made this, 10 Jun 2000

#include <mudlib.h>
#include <messages.h>

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "cyanide");
    set ("short", "a magma drake") ;
    set ("long", @EndText
This creature looks like a giant worm with two claws just behind its head.
Its body is covered with thick scales in varying shades of red and two 
black eyes set toward the top of its head.
EndText
) ;
    set ("id", ({ "drake", "magma drake" }) ) ;
    set("stat", ([
      "strength" : 18,
      "constitution" : 16,
      "intelligence" : 6,
      "wisdom" : 8,
    ]) );
    set_align("tn");
    set_size(60);
    set_name ("magma drake") ;
    set ("race", "drake");
    set ("gender", "neuter") ;
    enable_commands() ;
    set_living_name("magma drake") ;
    set("resist_type",([ "fire":0 ]));
    set ("base_ac", 0);
    set ("armor_class", 0);
    set("CLASS", "warrior");
    set ("damage", ({ 7, 18 }) ) ;
    set("damage_type", "slashing");
    set ("weapon_name", "sharp claws") ;
    set_verbs( ({ "slash at" }) ) ;
    set ("special", 2);

    set_level(15);

    credit( query("hit_points") / 2 ); 
}

int special_attack() {
    object ob = get_random_attacker();

    if (query_hit(ob)) {
        message(MSG_COMBAT, "The magma drake crushes you with its bite!\n", ob);
        message(MSG_COMBAT, "The magma drake crushes "+
            ob->query("cap_name")+" with its bite!\n", 
            all_inventory(environment(TO)), ob);

        ob->receive_damage(random(26) + 5, "crushing", TO, 1);
    }
    
    ob = get_random_attacker();
    if (query_hit(ob)) {
        message(MSG_COMBAT, "The magma drake beats you with its tail!\n", ob);
        message(MSG_COMBAT, "The magma drake beats "+
            ob->query("cap_name")+" with its tail\n", 
            all_inventory(environment(TO)), ob);

        ob->receive_damage(random(12) + 1, "crushing", TO, 1);
    }

    return 0;
}

/* EOF */
