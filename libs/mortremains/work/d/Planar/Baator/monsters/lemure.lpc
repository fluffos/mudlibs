#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Lemure") ;
    set ("long", @EndText
The lemure is a gortesque, disfigured blob of molten flesh with a vaguely
humanoid torso and head. 
EndText
    );
    set ("id", ({ "lemure", "baatezu" }) ) ;
    set_size(3);
    set_name ("lemure") ;
    set ("race", "baatezu");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("lemure") ;
    set("resist_type",([ "cold":50, "fire":0, "poison":0]));
    set("stat/constitution", 14);
    set ("base_ac", 7);
    set ("armor_class", 7);
    set("CLASS", "warrior");
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "fists") ;
    set("aggressive", 9);
    set_verbs( ({ "rip", "club at", "pound on" }) ) ;
    set_level(2);
    credit( query("hit_points") / 2 ); 
}