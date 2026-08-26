#include <mudlib.h>  
    
inherit MONSTER ;
    
void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "blood");
    set("short", "Rat");
    set ("long", @EndText
A large, disgusting, furry rodent who does nothing but crawls around
picking up everyone else's garbage.
EndText
);  
    set("id", ({ "monster", "rat" }) );
    set_size(6);
    set_name("rat") ;
    set("gender", "male");
    set("race", "rat");
    set("undead", 0);
set("damage", ({ 1,5 }) );
    set("weapon_name", "teeth") ;
    set_verbs( ({ "attack", "bite at" }) ) ;
    set("natt", 2);
    set_level(4);
    set("prevent_summon", 1);
}
