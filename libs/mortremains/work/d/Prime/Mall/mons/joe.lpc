
// A generic monster.
// Ilz coded 28 Jan 98

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1);
    set("author" , "herself");
    set("short" , "joe the shopkeeper");
    set("long" , "Joe is an extremely tall, lanky man. \n"+
      "He seems kind of weak and frail, but he's \n"+
      "actually quite strong for his size. He \n"+
      "is dressed in a nice button up blouse, \n"+
      "and black slacks. He's very professional looking. \n");
    set("id" , ({"joe" , "keeper" , "shopkeeper" }) );
    set("smell" , "You can smell his aftershave. \n");
    set_size(8);
    set_name("joe");
    set ("gender" , "male") ;
    set("race", "human");
    set_align("le");
    enable_commands() ;
    set ("base_ac", 2);
    set("chat_chance", 10);
    set("chat_output", ({
    }) );
    set("att_chat_output", ({
    }) );
    set("damage" , ({6,10}) );
    set ("weapon_name" , "hands");
    set_verbs( ({"slap at" , "hit" , "pound on"}) );
    set_level(25);
}

