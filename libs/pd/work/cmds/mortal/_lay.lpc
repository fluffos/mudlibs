#include <rest.h>

int cmd_lay() {
    if(this_player()->query_current_attacker())
	return notify_fail("You cannot sit in battle.\n");

    if (this_player()->query_rest_type() == LAY )
	return notify_fail("You are already laying down.\n");

    if((this_player()->query_riding() ||
	this_player()->query_mounting()))
	this_player()->force_me("dismount");

    write("You find a nice spot to lay down on the ground.");
    this_player()->set_rest_type( LAY );
    say(capitalize(this_player()->query_cap_name())+" lays down on the ground.");
    return 1;
}

int help()
{
    write( @EndText
Syntax: rest
Effect: allows you to lay down and rest.
See also: sit, stand
EndText
    );
    return 1;
}
