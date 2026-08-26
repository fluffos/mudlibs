
// A generic monster.
// Ilz coded 28 Jan 98

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1);
    set("author" , "herself");
    set("short" , "a store clerk");
    set("long" , "This guy is just your regular, ordinary, \n"+
      "normal looking desk clerk. He works here. Cut him \n"+
      "some slack, he hates his job too. \n");
    set("id" , ({"clerk" , "store clerk" }) );
    set("smell" , "He smells faintly of cheez-its. \n");
    set_size(6);
    set_name("clerk");
    set ("gender" , "male") ;
    set("race", "human");
    set_align("le");
    enable_commands() ;
    set ("base_ac", 2);
    set ("armor_class", 2);
    set("chat_chance", 10);
    set("chat_output", ({
      "The clerk says: Hey, i just work here. \n",
      "The clerk looks bored. \n",
      "The clerk looks through some receipts. \n",
    }) );
    set("att_chat_output", ({
    }) );
    set("damage" , ({3,6}) );
    set("weapon_name" , "hands");
    set_verbs( ({"punch at" , "hit" , "pound on"  }) );
    set_verbs2( ({"punches at" , "hits" , "pounds on" }) );
    set_level(11);
}

