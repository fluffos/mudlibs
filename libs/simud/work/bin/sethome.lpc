#include <wizard.h>

int main() {
	mapping valid_homes = ([ "/bldg/shack",
							 "/bldg/cottage",
							 "/bldg/house" ]);
	object room = environment(this_player());
	string building = object_name(environment(room));
	int tmp;
	sscanf( building, "%s#%d", building, tmp );
	if( !member(valid_homes, building) && !room->query_valid_home() )
		msg("You cannot set your home here.");
	else {
		if( this_player()->query_env_var("home") == to_objectref(room) ) {
			msg("This room is already set as your home.");
		} else {
			msg("You have now set your home here.");
			this_player()->set_env_var("home",to_objectref(room));
		}
	}
	return 1;
}
