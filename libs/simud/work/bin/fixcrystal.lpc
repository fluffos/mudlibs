#include <magic.h>

int main(string arg) {
	object ob, *obs;
	int mana_type;
	obs = filter( deep_inventory(this_player()), (: load_name($1) == "/magic/obj/spell_crystal" && $1->query_mana_type() < C_FIRE_MANA :) );
	if( !sizeof(obs) )
		return notify_fail("You do not have any broken spell crystals.\n");
	
	if( (mana_type = MAGIC_DAEMON->query_mana_aspect( arg )) == -1 ) {
		if( arg )
			return notify_fail("'"+arg+"' is not a valid mana type.\n");
		return notify_fail("You must tell me which mana type you would like to make the broken crystal.\n");
	}
	
	ob = obs[0];
	ob->set_mana_capacity( 1000 );
	ob->set_mana_type( mana_type );
	ob->set_mana_quantity( 500 );

	msg("Your broken crystal has been turned into a half-charged "+arg+" crystal.");
	return 1;
}
