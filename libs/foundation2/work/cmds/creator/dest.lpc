/*    /cmds/creator/dest.c
 *    from the Foundation II LPC Library
 *    destructs the object named
 *    created by Descartes of Borg 950425
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    object *inv;
    object ob;
    string msg, tmp;
    int i;

    if( !args || args == "" ) return "Dest what?";
    if( args == "all" ) {
        i = sizeof(inv = all_inventory(environment(this_player())));
        while(i--) {
            if(interactive(inv[i])) continue;
            msg = (string)this_player()->GetMessage("dest", inv[i]);
	    message("system", "You dest " + (string)inv[i]->GetShort() + ".",
		    this_player());
	    message("other_action", msg, environment(this_player()),
		    ({ this_player() }));
            inv[i]->eventDestruct();
            if(inv[i]) destruct(inv[i]);
        }
        return 1;
    }
    if( !(ob = present(lower_case(args), this_player()))  &&
       !(ob = present(lower_case(args), environment(this_player()))) )
      return "No such thing.";
    if( interactive(ob) && !archp(this_player()) )
      return "You are not permitted to do that.";
    message("system", "You dest " + (string)ob->GetShort() + ".",
	    this_player());
    msg = (string)this_player()->GetMessage("dest", ob);
    if( interactive(ob) )
      message("system", (string)this_player()->GetName() + " dests you.",
	      ob);
    message("other_action", msg, environment(this_player()),
	    ({ this_player(), ob }));
    ob->eventDestruct();
    if(ob) destruct(ob);
    return 1;
}

void help() {
   message("help", "Syntax: <dest [object]>\n\nThis command destroys the "
           "object named.  \"dest all\" destroys all the items in your "
           "inventory.  See \"help format\" for how to denote objects.",
           this_player());
   message("help", "See also: I, format, dref, clean", this_player());
}
