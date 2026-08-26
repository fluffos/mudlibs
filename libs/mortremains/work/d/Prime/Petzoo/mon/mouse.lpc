#include <mudlib.h>

inherit MONSTER;

create(){
    ::create();
    set("short", "a mouse");
    set("long", "It is little mouse.\n");
    set("id", ({ "#meese#", "#BLAH#", "mouse" }) );
    set("race", "rodent");
    set_name("mouse");
    set_size(1);
    set_level(1);
    set_alignment("n");
    set("damage", ({ 1, 3 }) );
    set("weapon_name", "teeth");
    credit(query_level() * 20); 
    set_verbs( ({ "attack", "bite at" }) );
}


