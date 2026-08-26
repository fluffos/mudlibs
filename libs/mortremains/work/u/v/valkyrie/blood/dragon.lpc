#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "blood");
    set("short", "Dragon");
    set ("long", @EndText
A red dragon of magnificent proportions, layered in scales,
a huge tail and very large head. Long powerful claws extend
from the dragon's feet, which are resting on the cold stone
floor.
EndText
);  
    set("id", ({ "dragon" }) );
    set_size(60);
    set_name("dragon") ;
    set("gender", "male");
    set("race", "dragon");
    set("undead", 0);
    set("damage", ({ 15,40 }) );
    set("weapon_name", "claws") ;
    set_verbs( ({ "attack", "swing at" }) ) ;
    set("natt", 2);
    set_level(40);
    set("prevent_summon", 1);
}
