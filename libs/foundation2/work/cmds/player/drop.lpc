/*    /cmds/player/drop.c
 *    from the Foundation II LPC Library
 *    the drop command
 *    created by Descartes of Borg 950412
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    object ob, env;

    if( !(env = environment(this_player())) ) return "You are nowhere.";
    if( !args || args == "" ) args = "all";
    if( args == "all" ) {
	object *obs;
	int i, maxi;

	maxi = sizeof(obs = filter(all_inventory(this_player()), 
			    (: !((int)$1->GetInvis(this_player())) &&
			     !((mixed)$1->GetSave()) :)));
	if( maxi < 1 ) {
	    message("my_action", "You have nothng to drop.", this_player());
	    return 1;
	}
	for(i = 0; i<maxi; i++) {
	    if( !((int)obs[i]->CanDrop(this_player())) ) continue;
	    if( !((int)obs[i]->eventMove(env)) )
	      message("my_action", capitalize((string)obs[i]->GetShort()) +
		      " refuses to leave your grasp.", this_player());
	    else {
		message("my_action", "You drop " + (string)obs[i]->GetShort() +
			".", this_player());
		message("other_action", (string)this_player()->GetName() +
			" drops " + (string)obs[i]->GetShort() +".",
			env, ({ this_player() }));
	    }
	}
	return 1;
    }
    else if( !(ob = present(args, this_player())) ) {
	/* do money here later */
    }
    if( !((int)ob->CanDrop(this_player())) ) return 1;
    if( !((int)ob->eventMove(env)) ) {
	message("my_action", "You fail.", this_player());
	return 1;
    }
    message("my_action", "You drop " + (string)ob->GetShort() + ".",
	    this_player());
    message("other_action", (string)this_player()->GetName() + " drops " +
	    (string)ob->GetShort() + ".", env, ({ this_player() }));
    return 1;
}

void help() {
    message("help", "Syntax: <drop>\n"
	    "        <drop all>\n"
	    "        <drop [object]>\n\n"
	    "Drops items to the ground.\n\n"
	    "See also: get, give, put", this_player());
}
