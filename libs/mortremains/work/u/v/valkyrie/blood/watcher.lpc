#include <mudlib.h>

inherit MONSTER ;
    
void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;  
    set("author", "blood");
    set("short", "The Watcher ");
    set ("long", @EndText
This shadowy daemon has differing forms every time you look at him. The   
only consistant thing about the daemon are his eyes. A deep blue, they
seem to look beyond the mere physical and see your heart, pumping in your
chest. And he just watches..here in the room with the chest, just watches.
EndText
);       
    set("id", ({ "monster", "watcher", "eyes" }) );
    set_size(10);
    set_name("the watcher") ;
    set("gender", "male");
    set("race", "daemon");
    set("undead", 0);
    set("damage", ({ 1,30 }) );
    set("weapon_name", "claws") ;
    set_verbs( ({ "attack", "claw at", "swing at" }) ) ;
    set("natt", 1);
    set_level(5);
    set("prevent_summon", 1);
    credit(200);
}
