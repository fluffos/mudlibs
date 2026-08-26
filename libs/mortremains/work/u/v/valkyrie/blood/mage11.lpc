#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "blood");
    set("short", "Apprentice Mage");
    set ("long", @EndText
Long black hair frames the face of this student of magic. He sits here in
this room studying intently everything he has learned from the master of
the house.
EndText
);  
    set("id", ({ "monster", "mage", "apprentice", "apprentice mage" }) );
    set_size(6);
    set_name("apprentice") ;
    set("gender", "male");
    set("race", "human");
    set("undead", 0);
    set("damage", ({ 11,20 }) );
    set("weapon_name", "fists") ;
    set_verbs( ({ "attack", "swing at" }) ) ;
    set("natt", 4);
    set_level(11);
}
