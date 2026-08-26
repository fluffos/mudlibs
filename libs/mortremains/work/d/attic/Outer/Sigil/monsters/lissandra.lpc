
// A generic monster.

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Lissandra") ;
    set ("long", "The Gate-seeker of Sigil.\n") ;
    set ("id", ({ "lissandra", "gate seeker"}) ) ;
    set_name ("lissandra") ;
    set ("gender", "female") ;
    set("inquiry", ([
      "statue" : "I think it has something to do with one of the gates.\n",
      "gate" : "I'm seeking out all the gates of Sigil.  I'm SURE there is one here, but I can't seem to find it.\n",
      "gates" : "I'm seeking out all the gates of Sigil.  I'm SURE there is one here, but I can't seem to find it.\n",
      "portal" : "I'm almost positive there is a portal here, but I don't know where it is or how to activate it!\n",
      "portals" : "I'm almost positive there is a portal here, but I don't know where it is or how to activate it!\n",
    ]) ) ;
    set ("race", "human");
    enable_commands() ;
    set_living_name("lissandra") ;
    set ("stat/constitution", 15);
    set ("stat/strength", 12);
    set ("stat/charisma", 14);
    set ("stat/intelligence", 16);
    set ("stat/dexterity", 8);
    set ("stat/wisdom", 10);
    set_level(9);
    set("natt", 1);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "wizard");
    set_skill("Staves", 2, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    arm(OBJ(staff3), "staff") ;
    wear(OBJ(ring2), "ring") ;
    wear("/d/class/wizard/general/obj/book", "book") ;
    wear(OBJ(bracers2), "bracers") ;
    set ("mage_spells", ({ "missile", "bolt", "shield", "fireshield", "enlarge" }) );
    set ("max_sp", 130);
    set ("spell_points", 130);
    set ("special", 3);
}

void init(){
    ::init();
    command ("cast shield");
}


void special_attack() {
    //this is the spell function for raw excessive damage
    object ob;
    int sv; 
    string target;
    if (this_object()->query("cast_delay") || (this_object()->query("spell_points") < 3) ){
	return;
    }else{	 
	if (!present("#ENLARGE_OB#", this_object())){
	    command ("cast enlarge");
	    return;
	}
	if (!present("#FIRE_SHIELD#", this_object())){
	    command ("cast fireshield");
	    return;
	}
	switch (random(2)){
	case 0 : command("cast missile");break;
	case 1 : command("cast bolt");break;
	}
    }
}
