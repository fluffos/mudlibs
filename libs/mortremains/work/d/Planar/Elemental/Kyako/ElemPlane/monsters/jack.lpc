// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "plane.h"
#define NAME this_player()->query("cap_name")
inherit MONSTER ;


void create () {

        object ob1, ob2, ob3, ob4 ;

        ::create() ;
        seteuid(getuid()) ;
        set ("short", "jack") ;
        set ("long", @Jack
This is jack, an expirate.
He is no longer a pirate because they made him do uncivilized things
(by pirates standards). He will hate them forever
He is wearing a button that says "Ask me about 'pirates'"
Jack
 );
        set ("id", ({ "jack", "Jack", "expirate" }) ) ;
        set ("capacity", 10000) ;
        set ("max_cap", 10000) ;
        set ("max_vol", 10000) ; 
        set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
        set ("gender", "male") ;
        set ("race", "human");
        enable_commands() ;
        set ("chat_chance", 10);
        set ("chat_output", ({
          "Jack says: I hate those damn pirates.\n",
          "Jack shows you his button.\n",
          "Jack says: Ask me about pirates if you want my help.\n",
        }) );
        set_name ("jack") ;
        set ("stat/constitution", 16);
        set ("stat/charisma", 2);
        set ("stat/intelligence", 9);
        set ("stat/dexterity", 15);
        set ("stat/wisdom", 4);
        set_level(4);
        set("thac0", 10);
        set ("damage", ({ 4,7 }) ) ;
        set ("weapon_name", "hands") ;
        set ("CLASS", "thief");
        set_skill("Short Blades", 2, "Strength");
        set_verbs( ({ "strike at", "swing at", "slash at" }) ) ;
        ob1 = clone_object (PLANE+"weapon/pirdag") ;
        ob1 -> move (this_object()) ;
        ob2 = clone_object (PLANE+"obj/button") ;
        ob2 -> move (this_object()) ;
        }
void init () {
::init();
command("wield dagger");
command("equip button");
add_action("bamph", "say");
}

int bamph(string str){
   if (str == "pirates") {
     write("You ask Jack about: "+str+"\n");
     write("Jack tells you: Those fucking pirates, they ruined my life.\n");
     write("Jack tells you: I just want to get revenge.\n");
     write("Jack tells you: Hey, did you know they pay off the mayor?\n");
   return 1;
  }
   if (str == "mayor"){
     write("You ask Jack about: "+str+"\n");
     write("Jack tells you: Yeah, he's corrupt all right.\n");
     write("Jack tells you: You may be able to get something out of him,\n");
     write("Jack tells you: if you confront him with it.\n");
   return 1;
  }
  return 0;
}
