
// A generic monster.
// Ilz coded 28 Jan 98

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1);
    set("author" , "herself");
    set("short" , "bozo the clown");
    set("long" , wrap(
	"Bozo is pretty evil looking. He spends his "+
	"time here at the toy store, supplying all the "+
	"evil little mudders with some annoying toys. "+
	"His face is painted white, with an evil smile "+
	"drawn in red. He has bright red hair which seems "+
	"to stand up in a crazy red afro! "
      ));
    set("id" , ({"bozo" , "bozo the clown" , "clown"}) );
    set("smell" , "He smells like candy and bubblegum. \n");
    set_size(10);
    set_name("bozo");
    set("gender" , "male");
    set("race" , "clown");
    set_align("ce");
    enable_commands() ;
    set ("base_ac", 2);
    set("chat_chance", 10);
    set("chat_output", ({
      "Bozo grins at you evilly.\n",
      "Bozo cackles like a maniac!\n",
      "The clown jumps up on the table and starts to dance.\n",
    }) );
    set("att_chat_output", ({
    }) );
    set("damage" , ({4,11}) );
    set("weapon_name" , "gloved hands");
    set_verbs( ({"slap at" , "strangle" , "hit" , "beat on"}) );
    set_level(26);
}

