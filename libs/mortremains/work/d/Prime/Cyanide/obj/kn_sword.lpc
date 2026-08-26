#include <mudlib.h>

inherit WEAPON ;

void create() {
    set ("id", ({ "sword" }) ) ;
    set ("short", "a bloody longsword");
    set ("long", "This sword gleams in the light, and seems valuable.\n") ;
    set_weapon_type("sword/long");
    // message will not be grammatical.
    set ("name", "sword") ;
    set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
    set_verbs2( ({ "attacks", "swings at", "stabs at", "slashes at" }) ) ;
    set("second", 0) ;
    set("nosecond",0) ;
    set ("wield_func", "glow") ;
    set ("unwield_func", "noglow") ;
}

void glow() {
    write ("The sword begins to glow in your hand.\n") ;
    say ("The sword begins to glow in "+
      possessive(this_player()->query("gender"))+" hand.\n") ;  
    set ("light", 1) ;
}

void noglow() {
    write ("The sword stops glowing.\n") ;
    say ("It ceases to glow.\n") ;
    set("light", 0) ;
}
