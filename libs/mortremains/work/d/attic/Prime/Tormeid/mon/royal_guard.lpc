#include "../defs.h"

inherit GUARD ;

create(){
    ::create() ;
    set("short", "a royal guard") ;
    set("long", @ENDLONG
This man is a member of the Royal Guard, who is responsible directly
for guarding the King's life.  He wears a golden suit of armor that
glimmers in the light.
ENDLONG
    );
    set("id", ({ "royal guard", "guard" }) ) ;
    set_level(30) ;
    set_name("Royal Guard") ;
    set_alignment("ln") ;
    arm(WEAPONS(royal_weapon), "ROYAL_WEAPON") ;
    set_size( 7 ) ;
    wear(ARM(royal_plate),  "platemail") ;
    wear(ARM(gauntlets), "gauntlets") ;
    set_skill("Long Blades", 5, "strength") ;
    set_skill("Polearms", 2, "strength") ;
    wear(ARM(chain_leggings), "leggings") ;
    wear(ARM(fine_helmet), "helmet") ;
    wear(ARM(hlboots), "boots");
}


void init() {
    add_action("prevent_go", "go") ;
    add_action("prevent_go", "sneak") ;
}

int prevent_go(string dir) {
    if (dir != "north") return 0 ;
    if (TP->query("invisible") || wizardp(TP)) {
	write("You walk right past the guard, unnoticed.\n") ;
	return 0 ;
    }
    write("Royal guard stops you.\n");
    say("Royal guard stops "+TPN+" from going north.\n") ;
    return 1;
}
