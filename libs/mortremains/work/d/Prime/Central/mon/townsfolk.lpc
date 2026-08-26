// Chronos coded this off a template, basically.
#include <mudlib.h>
#include "../central.h"

inherit MONSTER;

void create() {
    string race ;
    int level ;
    ::create();
    seteuid(getuid());  
    switch(random(30)) {
    case 0..10 : race = "human";
	set_size(6);
	break;
    case 11..17 : race = "orc"; 
	set_size(5);
	break;
    case 18..21 : race = "half-orc"; 
	set_size(6);
	break;
    case 22..24 : race = "dwarf"; 
	set_size(4);
	break;
    case 25..26: race = "gnome" ;
	set_size(6);
	break;
    case 27..29 : race = "half-elf"; 
	set_size(6);
	break;
    }
    set("prevent_summon", 1);
    credit(random(169)) ;
    set("race", race);
    if (!random(10)) {
	set("gender", "female");
	set("short", "a "+race+" woman") ;
	set("id", ({ "woman", race, race+" woman" }) ) ;
	set_name( race+" woman") ;
	set("long", "She's just a woman trying to make a living in Decatur.\n") ;
    } else {
	set("gender", "male");
	set("short", "a "+race+" man") ;
	set("long", "He's just a man trying to make a living in Decatur.\n") ;
	set("id", ({ "man", race, race+" man" }) ) ;
	set_name( race+" man") ;
    }
    set("author", "Chronos") ;
    set("damage", ({ 4, 10 }) ) ;
    set ("weapon_name", "fists") ; 
    set_verbs( ({ "swing at", "attack", "punche at" }) );
    set("stat", ([
      "strength" : 12 + random(8),
      "intelligence" : 12 + random(7),
      "dexterity" : 10+ random(9) ,
      "constitution" : 10 + random(9),
      "charisma" : 10 + random(9) ,
      "wisdom" : 10 + random(9) ,
    ]) ) ;
    switch (random(100)+1) {
    case  1..20 : level = 3; break;
    case 21..30 : level = 4; break;
    case 31..40 : level = 5; break;
    case 41..60 : level = 6; break;
    case 61..80 : level = 7; break;
    case 81..90 : level = 8; break;
    case 91..95 : level = 9; break;
    case 96..98 : level = 10; break;
    case 99: level = 11 ; break ;
    default : level = 12; break;
    }
    set_level(level);
    set("moving", 1) ;
    set("speed", 15 + random(10) ) ;
    switch(random(15)) {
    case 1:  clone_object("/obj/obj/bag")->move(TO) ;
	break ;
    case 2:  clone_object("/obj/obj/torch")->move(TO) ;
	break ;
    case 3:  clone_object("/obj/weapon/dagger")->move(TO) ;
	command("wield dagger") ;
	break ;
    case 4:  clone_object("/obj/weapon/staff")->move(TO) ;
	command("wield staff") ;
	break ;
    case 5:  clone_object("/obj/examples/rose")->move(TO) ;
	break ;
    case 6: clone_object(M_OBJ+"backpack")->move(TO) ;
	break ;
    case 7: clone_object(M_OBJ+"blahkey")->move(TO) ;
	break ;
    default:
	break ;
    }
}
