
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "shya");   
    set("short", "a black cat");
    set ("long",
      "This cat is as black as night, with glowing yellow eyes, and long fangs.\n");
    set("id", ({"cat", "black cat"}) );
    set_size(1);
    set_name ("cat") ;
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("cat") ;
/*
    set ("aggressive", 0 );
*/
    set("lore_type", "Animal Lore");	
    set ("hit_points", 750);
    set("max_hp",750);
    set ("damage", ({2,20}) ) ;
    set ("weapon_name", "claws") ;
    set ("stat/strength", 18) ;
    set("stat/charisma", 18);
    set ("stat/dexterity", 22) ;
    set_verbs( ({ "slash at", "lunge at", "swipe at" }) ) ;
    set ("moving", 1) ;
    set ("speed", 8) ;
    set_level(15);
}

void init () {
    ::init();

    if (userp(TP) && !wizardp(TP))
	kill_ob(TP);
}
