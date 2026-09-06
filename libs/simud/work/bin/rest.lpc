#include <const.h>
#define READY_PER_END	75

string query_action_name() {
	return "Rest";
}

int main( string str ) {
	if( this_player()->query_in_combat() ) {
		return notify_fail( "You can't rest right now!\n" );
	}
	if( this_player()->query_max_endurance() - this_player()->query_endurance() < 5 ) {
		return notify_fail( "You don't need to rest at the moment.\n" );
	}

	this_player()->push_action( ({ 1000, this_object(), this_player(), ST_SITTING, str }) );
	return 1;
}// end: main

void on_action( object target, mixed param ) {
	if( this_player()->query_in_combat() ) {
		notify_fail( "You can't rest right now!\n" );
		return;
	}

	int end;
	end = this_player()->query_max_endurance() - this_player()->query_endurance();
	if( end < 5 ) {
		notify_fail( "You don't need to rest at the moment.\n" );
		return;
	}

	if( end * READY_PER_END > this_player()->query_readiness() ) {
		end = (int)floor(this_player()->query_readiness() / READY_PER_END);
	}

	this_player()->add_endurance( end );
	this_player()->add_readiness( -end * READY_PER_END - 250 );
	this_player()->set_busy( end );

	this_player()->msg_local( "~CACT~Name ~verbrest briefly.~CDEF" );
}// end: on_action
