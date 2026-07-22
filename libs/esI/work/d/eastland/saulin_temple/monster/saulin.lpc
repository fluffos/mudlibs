// saulin.c
// This object is inherited by all saulin fellows
#include "../saulin_temple.h"

inherit MONSTER;

void heal_saulin(int heal)
{
	receive_healing( heal );
}

int stop_attack()
{
	object *people;

	people = all_inventory(environment());
	people -= ({ this_object() });
	if( sizeof(people) )
		people->help_me_saulin( this_object(), this_player() );
	return 0;
}
