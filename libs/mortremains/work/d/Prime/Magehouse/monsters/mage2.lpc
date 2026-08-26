inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "blood");
    set("short", "Apprentice Mage");
    set ("long", @EndText
Long black hair frames the face of this student of magic. She sits here in
this room studying intently everything she has learned from the master of
the house.
EndText
);  
    set("id", ({ "monster", "mage", "apprentice", "apprentice mage" }) );
    set_size(6);
    set_name("apprentice") ;
    set("gender", "female");
    set("race", "human");
    set("undead", 0);
set("damage", ({ 1,5 }) );
    set("weapon_name", "fists") ;
    set_verbs( ({ "attack", "swing at" }) ) ;
    set("natt", 2);
    set_level(2);
}
