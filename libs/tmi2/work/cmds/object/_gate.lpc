//	File	:  /cmds/xtra/_gate.c
//	Creator	:  Watcher@TMI-2   (01/93)
//
//	This is a wizard command which allows the moving of an
//	object, player, or monster from one location to another.
 
#include <mudlib.h>
 
inherit DAEMON ;
 
#define SYNTAX	"Syntax: gate [object] to [location | object]\n" + \
		"        gate [object] in [loc | obj] to [loc | obj]\n"
 
int cmd_gate(string str) {
   object prev, whatp, wherep;
   string prefix, loc, what, where, tmp_where;
   int ret;
 
   notify_fail(SYNTAX);
 
   //	Parse the input into proper command request
 
   if( !str || str == "")  return 0;
 
   if( sscanf(str, "%s in %s to %s", what, loc, where) != 3 &&
       sscanf(str, "%s to %s", what, where) != 2 &&
       sscanf(str, "%s %s", what, where) !=2)
	return 0;
 
   //  Locate the object to be moved
 
   if(loc && loc != "") {
	if(get_object(loc))   whatp = present(what, get_object(loc));
   }
   else  whatp = get_object(what);
 
   if(!whatp) {
   write("Gate: Could not locate \"" + what + "\"");
   if(loc)  write(" in \"" + loc + "\"");
   write(".\n");
   return 1; }
 
   //  See if you have permission to move the object
 
   if(wizardp(whatp) && whatp != this_player() &&
      !adminp(geteuid(this_player()))) {
   write("You do not have permission to move that user.\n");
   return 1; }
 
   //  Locate where to move the object
 
   wherep = get_object(where);
 
   //  Move living objects to environment, nonliving to actual object
 
   if(wherep && living(wherep) && living(whatp))
   	wherep = environment(wherep);
 
   if(!wherep) {
   tmp_where = resolv_path( "cwd", where );
   catch( call_other( tmp_where, "???" ) );	// Load the poss. location
   wherep = get_object( tmp_where );  
   }
 
   if(!wherep) {
   write("Gate: Could not locate \"" + where + "\".\n");
   return 1; }
 
   where = file_name(wherep);			// Get final location name
 
   //  Check to see if the object is already at the desired location
 
   if(wherep == environment(whatp)) {
   write("Gate: \"" + what + "\" is already at \"" + where + "\".\n");
   return 1; }
 
   //  Note pre-move location of the moving object
 
   prev = environment(whatp);
 
   //  Attempt to move the object to the new location
 
   ret = whatp->move(wherep);
 
   if(ret) {
   write("Gate: Could not move \"" + what + "\" to \"" + where + "\".\n");
   return 1; }
 
   //  Check to make sure object is still in existence.

   if(!whatp) {
   write("Gate: The object was moved and destroyed at the destination.\n");
   return 1; }
 
   //  Give reaction messages to object, caller, and surroundings
 
   if(living(whatp))  prefix = capitalize((string)whatp->query("name"));
   else  prefix = article(what) + " " + what;
 
   tell_room(prev, capitalize(prefix) + " suddenly shimmers " +
	     "and fades away.\n", ({ whatp }) );
   tell_object(whatp, "The air around you shimmers and you suddenly find" +
		      " yourself elsewhere.\n\n");
   tell_room(wherep, "The air around you shimmers and " + prefix +
		      " suddenly forms before you.\n", ({ whatp }) );
   if(interactive(whatp))   whatp->force_me("look");
 
   if(member_array(this_player(), ({ wherep, prev })) == -1 &&
      member_array(environment(this_player()), ({ wherep, prev })) == -1)
	write("Ok.\n");
 
return 1; }
 
int help() {
 
   write(SYNTAX + "\n" +
     "This command allows the user to move an object, monster, or player\n" +
     "to another location, living or nonliving object.  If the moved object\n"+
     "is living and the destination is living, it will be moved to the\n" +
     "destination's environment, while an non-living object will actually\n" +
     "be moved to that living object's inventory.  The gate command also\n" +
     "responds to such aliases as here, me, env, environment.\n");
 
return 1; }
 
