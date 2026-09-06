#include <lord.h>

#include <generic_items.h>

/*
	Lord command:	update
	Syntax:		update crown
	Conditions:
		Must be a lord.
	Effects:
		Replaces old crown.
*/

#define CROWN_ID        "lord_player_object"

int update_cmd(string str,object who) {
    object crown,ncrown;

    if((LL < SQUIRE) && !(CODER)) return 0;

    if(str!="crown") return notify_fail("Update what?\n"),0;

    if(!(crown=present(CROWN_ID,who)))
	return notify_fail("You must obtain a crown before you can update it.\n"),0;

    if(!(ncrown=clone_object(GENERIC_LORD_CROWN)))
	return notify_fail("Error with crown.. please hold on to your old one.\n"),0;

    destruct(crown);
    move_object(ncrown,who);

    who->tell_me("Updated lords crown. Have a nice day.");
    return 1;
}
