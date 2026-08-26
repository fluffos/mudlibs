#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "blood");
    set("short", "Brat");
    set ("long", @EndText
Its a brat, you know the kind screaming and muttering about how everybody
hates him and yet being a bastard like everyone knows.
EndText
);  
    set("id", ({ "monster", "brat" }) );
    set_size(6);
    set_name("brat") ;         
    set("gender", "male");
    set("race", "human");
    set("undead", 0);
set("damage", ({ 15,20 } ) );
    set("weapon_name", "fists") ;
    set_verbs( ({ "attack", "swing at" }) ) ;
    set("natt", 2);
    set_level(20);
    set("prevent_summon", 1);
    credit(400);
}
