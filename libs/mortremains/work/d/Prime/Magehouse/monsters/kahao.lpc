#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "blood");
    set("short", "Kahao");
    set ("long", @EndText
Kahao is a little runt who should not be here, kill it.
EndText
);  
    set("id", ({ "monster", "kahao" }) );
    set_size(8);
    set_name("kahao") ;
    set("gender", "male");
    set("race", "human");
    set("undead", 0);
set("damage", ({ 13,18 }) );
    set("weapon_name", "fists") ;
    set_verbs( ({ "attack", "swing at" }) ) ;
    set("natt", 1);
    set_level(18);
    set("prevent_summon", 1);
    credit(200);
}
