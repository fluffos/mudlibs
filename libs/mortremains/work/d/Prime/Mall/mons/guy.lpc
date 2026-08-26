
// A generic monster.
// Ilz coded 28 Jan 98

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1);
    set("author" , "herself");
    set("short" , "a bored man");
    set("long" , "This man has been left here by his wife. \n"+
      "He sits around twiddling his thumbs, \n"+
      "holding a bunch of bags for his wife. \n");
    set("id", ({"man" , "guy" , "bored man" }) );
    set("smell" , "He smells like his wife's perfume. \n");
    set_size(7);
    set_name("bored man");
    set("gender" , "male");
    set("race", "human");
    set_align("le");
    enable_commands() ;
    set_living_name("bored man");
    set("wealth" , 400);
    set ("base_ac", 2);
    set ("armor_class", 2);
    set("chat_chance", 10);
    set("chat_output", ({
      "The man passes gas. \n",
      "Man says: This sucks. \n",
      "The man yawns. \n",
    }) );
    set("att_chat_output", ({
    }) );
    set("damage" , ({3,6}) );
    set ("weapon_name", "fists");
    set ("CLASS", "warrior");
    set_verbs( ({"pound" , "knock" , "hit at" }) );
    set_level(10);
}

