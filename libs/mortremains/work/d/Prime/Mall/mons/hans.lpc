
// A generic monster.
// Ilz coded 28 Jan 98

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1);
    set("author" , "herself");
    set("short" , "hans the sexy surfer dude");
    set("long" , wrap(
	"Hans is as buff as they come. He wears a white "+
	"muscle shirt with the words 'No Fear' across the "+
	"front in bold black letters. His shorts are "+
	"black and show off his bulging leg muscles. "+
	"His hair looks like it's been bleached a bright "+
	"blonde from many hours in the sun. "
      ) );
    set("id" , ({"hans" , "Hans" , "keeper" , "shopkeeper"}) );
    set("smell" , "He smells of suntan oil and sand. \n");
    set_size(6);
    set_name("hans");
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
    set("damage" , ({3,6}) );
    set ("weapon_name" , "hands");
    set_verbs( ({"slap at" , "hit" , "pound on"}) );
    set_level(25);
}

