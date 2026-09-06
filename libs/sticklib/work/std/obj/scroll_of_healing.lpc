// Ugh! ANCIENT code. Someone help!

#include <treasure.h>

void
create_treasure()
{
    set_short("Scroll of Healing");
    set_long("Usage: 'heal <name_of_player>'");
    set_name("scroll of healing");
    set_id("scroll");
    set_value(1000);
    set_weight(1);
}

void
init_treasure()
{
    add_action("heal","heal");
}

int
heal(string str)
{
    object target;
    if(!this_player()->query_can_move()) {
	write("You are unconscious and unable to move. You should seek help!\n");
	return 1;
    }
    if(environment()!=this_player()) {
	write("You must get it first.\n");
	return 1;
    }
    if(!str) {
	write("Heal who?\n");
	return 1;
    }
    if(!(target=present(lower_case(str),environment(this_player())))) {
	write("No one here by that name.\n");
	return 1;
    }
    if(this_player()->query_coder_level()) {
	write("Coders cannot use it.\n");
	return 1;
    }
    if(target->query_hp()>100) {
	if(target==this_player())
	    write("You don't need healing.\n");
	else
	    write(capitalize(str)+" does not need healing.\n");
	return 1;
    }
    write("You recite the Scroll of Healing.\n");
    if(target!=this_player())
	tell_object(target,this_player()->query_name()+" heals you with the Scroll of Healing.\n");
    tell_room(environment(this_player()),this_player()->query_name()+" heals "+capitalize(str)+" using the Scroll of Healing.\n",({ this_player(),target }));
    target->heal_self(50);
    if(target!=this_player())
	write(capitalize(str)+" seems to feel better.\n");
    else
	write("You feel better.\n");
    write("The scroll disappears.\n");
    destruct(this_object());
    return 1;
}
