int main( string arg ) {
	object obj = single_present( arg, environment(this_player()) );
	object *enemies, enemy;

	if( !arg )
		return notify_fail("Who do you want to defend?\n");
	if( !obj )
		return notify_fail("I can't find any such '"+arg+"' to defend.\n");
	if( !obj->query_is_player() )
		return notify_fail("You can only defend other players.\n");
	// TEMPORARY RESTRICTION - eventually allow for defending of friendly npc's
	if( obj == this_player() )
		return notify_fail("You can't quite figure out how to stand in front of yourself.\n");
	if( !obj->query_in_combat() )
		return notify_fail("You can only defend targets that are already in combat...\n");
	if( obj->is_fighting( this_player() ) || this_player()->is_fighting( obj ) )
		return notify_fail("You can't defend your enemy!\n");
	if( this_player()->query_endurance() < 20 )
		return notify_fail("You are too tired to defend anyone.\n");

	this_player()->add_endurance( -10 );
	set_target( obj );
	this_player()->msg_local("~CACT~Name ~verbdefend ~targ.~CDEF");

	debug( this_player()->query_name()+" is defending "+ obj->query_name() );

	enemies = filter( all_inventory(environment(obj)), (: $1->is_fighting(obj) :) );
	debug( as_lpc(enemies) );
	foreach( enemy : enemies ) {
		if( this_player()->query_endurance() < 5 ) {
			this_player()->msg_local("~CEMO~Name ~verbpant in exhaustion.~CDEF");
			return 1;
		}
		enemy->set_targets( enemy->query_targets() - ({obj}) );
		enemy->start_combat( this_player() );
		this_player()->start_combat( enemy );
		this_player()->add_endurance( -5 );
		enemy->start_combat( obj );
	}
	return 1;
}
