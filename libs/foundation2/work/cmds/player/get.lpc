/*    /cmds/player/get.c
 *    from the Foundation II LPC Library
 *    the get command, *bing*
 *    created by Descartes of Borg 950412
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    object ob;
    int y;

    if( !args || args == "" ) args = "all";
    if( !environment(this_player()) ) return "You are nowhere.";
    if( args == "all" ) {
	object *obs;
	int i, maxi;

	maxi = sizeof(obs = filter(all_inventory(environment(this_player())),
			     (: !((int)$1->GetInvis(this_player())) &&
			      !living($1) && 
			      (int)$1->CanGet(this_player()) :)));
	if( maxi < 1 ) {
	    message("my_action", "There is nothing to get.", this_player());
	    return 1;
	}
	for(i=0; i<maxi; i++) {
	    if( !((int)this_player()->CanCarry((int)obs[i]->GetMass())) )
	      message("my_action", capitalize((string)obs[i]->GetShort()) +
		      " is too heavy for you.", this_player());
	    else if( !((int)obs[i]->eventMove(this_player())) )
	      message("my_action", capitalize((string)obs[i]->GetShort()) +
		      " refuses to move.", this_player());
	    else {
		message("my_action", "You get " + (string)obs[i]->GetShort() +
			".", this_player());
		message("other_action", (string)this_player()->GetName() +
			" gets " + (string)obs[i]->GetShort() + ".",
			environment(this_player()), ({ this_player() }));
	    }
	}
	return 1;
    }
    if( !(ob = present(args, environment(this_player()))) ) {
	message("my_action", "You do not notice that here.", this_player());
	return 1;
    }
    if( !((int)ob->CanGet(this_player())) ) return 1;
    if( !((int)this_player()->CanCarry((int)ob->GetMass())) ) {
	message("my_action", "It is too heavy for you to carry.", 
		this_player());
	return 1;
    }
    if( !((int)ob->eventMove(this_player())) ) {
	message("my_action", "You fail.", this_player());
	return 1;
    }
    message("my_action", "You get " + (string)ob->GetShort() + ".",
	    this_player());
    message("other_action", (string)this_player()->GetName() + 
	    " reaches for " + (string)ob->GetShort() + ".", 
	    environment(this_player()), ({ this_player() }));
    return 1;
}

void help() {
    message("help", "Syntax: <get>\n"
	    "        <get all>\n"
	    "        <get [object]>\n\n"
	    "Assuming you can carry the objects, the \"get\" command allows "
	    "you to pick them up and carry them around.\n\n"
	    "See also: drop, give, put", this_player());
}
