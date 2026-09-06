// A simple object that others can see when someone is melted to the earth

#include <treasure.h>

object pl;
int can_sense;

string my_short() {
    if(!random(8)) return "You notice a slightly darker spot on the ground";
    return 0;
}

create_treasure() {
    set_name("dark spot");
    set_id( ({"spot"}) );
    set_short(#'my_short);
    set_long("It about a human-sized spot somewhat darker than the ground \
surrounding it.");
}
int get() { return 0; }
int drop() { return 1; }

init_treasure() {
    if(!pl || pl == this_player()) return;
    if(can_sense)
	pl->tell_me(":You feel %<me.name>% entering the room above you.",
	  0,0,this_player(),0,0);
    else
	pl->tell_me("You feel someone walking over you.");
}

set_pl(object x, int sense_status) { pl = x, can_sense = sense_status; }

