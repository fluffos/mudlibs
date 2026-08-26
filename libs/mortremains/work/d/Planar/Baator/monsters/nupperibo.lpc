// Ilzarion wrote this.  Cyanide cleaned it.

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "nupperibo") ;
    set ("long", @EndLong
An amorphous blob of molten flesh with almost no discernable features.
EndLong
    );
    set("author", "ilzarion");
    set ("id", ({ "nupperibo", "baatezu" }) ) ;
    set_name ("nupperibo") ;
    set ("race", "baatezu");
    set ("gender", "male") ;
    set_size(4);
    enable_commands() ;
    set_living_name("nupperibo") ;
    set("resist_type",([ "cold":50, "fire":0, "poison":0]));
    set ("base_ac", 9);
    set ("armor_class", 9);
    set("CLASS", "warrior");
    set ("damage", ({ 1,3 }) ) ;
    set ("weapon_name", "claws") ;
    set("aggressive", 9);
    set_verbs( ({ "rip", "slash at", "rend" }) ) ;
    set_level(1);
    credit( query("hit_points") / 2 ); 
}

/* EOF */