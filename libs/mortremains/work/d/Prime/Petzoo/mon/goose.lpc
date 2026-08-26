#include <mudlib.h>

inherit MONSTER;

create(){
    ::create();
    set("short", "a goose");
    set("long", "It is white goose.\n");
    set("id", ({ "#GOOSE#", "#BLAH#", "goose" }) );
    set("race", "goose");
    set_name("goose");
    set_level(1);
    set_alignment("n");
    set("damage", ({ 1, 3 }) );
    set("weapon_name", "beak");
    set_verbs( ({ "attack", "peck at", "bite at" }) );
    credit(query_level() * 20); 
    set("chat_chance", 10) ;
    set("chat_output", ({
      "The goose honks loudly.\n",
      "The goose tries to bite you on the ass.\n",
    }) ) ;
}


