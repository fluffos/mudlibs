#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "shya");
    set("short", "a white cat");
    set ("long",
      "This cat is as white as the snow surrounding it.\n");
    set_living_name("cat") ;
    set_name ("cat") ;
    set ("gender", "male") ;
    enable_commands() ;
    set("id", ({ "cat", "snowcat" }) );
    set_alignment("evil");
    set_size(3);
    set ("damage", ({1,4}) ) ;
    set ("weapon_name", "claws") ;
    set_verbs( ({ "attacks","swings at" }) ) ;
    set ("stat/strength", 15) ;
    set ("stat/dexterity", 22) ;
    set_level(3);
    set ("moving", 1) ;
    set ("speed", 8) ;
}

void init () {
    ::init();

    if (userp(TP) && !wizardp(TP))
	kill_ob(TP);
}
