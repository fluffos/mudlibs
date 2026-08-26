#include <mudlib.h>

inherit MONSTER;

create(){
    ::create();
    set("short", "a fluffy white lamb");
    set("long", "It's a cute white lamb.\n");
    set("id", ({ "#LAMB#", "#BLAH#", "lamb" }) ) ;
    set("race", "lamb") ;
    set_name("lamb");
    set_level(1) ;
    set_alignment("n");
    set("damage", ({ 1, 4 }) );
    set("weapon_name", "hooves");
    set_verbs( ({ "kick at", "attack" }) );
    credit(query_level() * 20); 
    set("chat_chance", 10) ;
    set("chat_output", ({ 
      "Lamb says: Bah.\n",
      "The lamb chews on your clothing.\n",
    }) ) ;
}


