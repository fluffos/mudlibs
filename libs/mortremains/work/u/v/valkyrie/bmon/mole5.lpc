#include <mudlib.h>
    
inherit MONSTER ;
    
void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "blood");
    set("short", "Giant Mole");
    set ("long", @EndText
This mole is much larger than most moles, but just as blind. It is
a furry critter with a bad attitude and an appetite for anything it
can catch.
EndText
);  
    set("id", ({ "giant mole", "mole" }) );
    set_size(6);
    set_name("mole") ;
    set("gender", "male");
    set("race", "mole");
    set("undead", 0);
    set("damage", ({ 9,14 }) );
    set("weapon_name", "claws") ;
    set_verbs( ({ "attack", "swipe at" }) ) ;
    set("natt", 2);
    set_level(5);
    set("prevent_summon", 1);

}
