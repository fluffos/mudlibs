
// A generic monster.
// Ilz coded 28 Jan 98

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1);
    set("author" , "herself");
    set("short" , "bratty kid's dad");
    set("long" , "This guy looks quite like Bruce Willis \n"+
      "in the movie 'Die Hard'. His bulging muscles protrude\n"+
      "from under his torn white t-shirt. Through his stone-\n"+
      "washed jeans you can see his defined leg muscles. He\n"+
      "looks really pissed.\n");
    set("id" , ({"dad" , "kids dad" , "kid's dad" , "bratty kid's dad"}) );
    set("smell" , "He smells sweaty. \n");
    set_size(8);
    set_name("dad");
    set ("gender" , "male") ;
    set("race" , "orc");
    set_align("le");
    enable_commands() ;
    set ("base_ac", 2);
    set("chat_chance", 10);
    set("chat_output", ({
    }) );
    set("att_chat_output", ({
      "The kid's dad says: You stupid little fucker!\n",
      "The kid's dad says: I'm gonna pound you into the ground!\n",
    }) );
    set("damage" , ({4,10}) );
    set ("weapon_name" , "hands");
    set_verbs( ({"slap at" , "hit" , "pound on"}) );
    set_level(17);
}

