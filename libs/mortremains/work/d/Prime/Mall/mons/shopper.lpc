
// A generic monster.
// Ilz coded 28 Jan 98

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1);
    set("author" , "Herself");
    set("short" , "a crazed shopper");
    set("long", "A crazy shopper whose eyes are wild. \n"+
      "She searches the area for a good sale. \n");
    set("id", ({ "shopper", "crazed shopper" }) ) ;
    set("smell" , "She smells like cleaning solutions. \n");
    set_size(6);
    set_name ("crazed shopper") ;
    set ("gender", "female") ;
    set("race", "human");
    set_align("le");
    enable_commands() ;
    set_living_name("crazed shopper") ;
    set("moving", 1);
    set("speed" , 5);
    set("wealth" , 400);
    set ("base_ac", 2);
    set ("armor_class", 2);
    set("chat_chance", 10);
    set("chat_output", ({
      "The crazy shopper reaches for your goods! \n",
      "The crazed shopper searches through her purse for a credit card. \n",
    }) );
    set("att_chat_output", ({
    }) );
    set("damage" , ({3,6}) );
    set ("weapon_name", "shopping bag") ;
    set ("CLASS", "warrior");
    set_verbs( ({ "swing at" , "shove" , "pound" }) );
    set_level(9);
}

