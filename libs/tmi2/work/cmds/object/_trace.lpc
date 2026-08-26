 
//	File	:  /cmds/xtra/_trace.c
//	Creator	:  Watcher@TMI  (03/04/93)
//	
//	This command allows you to locate any object, as well as
//	any clones of it active in the mud.  Descriptors and 
//	systematic destruction are options available.
 
#include <mudlib.h>
 
inherit DAEMON ;
 
#define SYNTAX "Syntax: trace -[d/m/v] [object/filename]\n"
#define PROTECT ({ "/std/user" , "/std/connection" })
 
int cmd_trace(string str) {
   object target;
   mixed *clones;
   string para, hold, tmp1, tmp2;
   int loop, dest, view, More, original;
 
   notify_fail( SYNTAX );
 
   if(!str || str == "")  return 0;
 
   //	Check for requested command parameters
 
   if(sscanf(str, "-%s %s", para, str) == 2) {
 
	if(sscanf(" " + para + " ", "%sd%s", tmp1, tmp2) == 2)	dest = 1;
	if(sscanf(" " + para + " ", "%sv%s", tmp1, tmp2) == 2)	view = 1;
	if(sscanf(" " + para + " ", "%sm%s", tmp1, tmp2) == 2)	More = 1;

   }
 
   //	Try to locate the requested object
 
   target = get_object( str );
 
   //	Oh well, couldn't find the object
 
   if(!target) {
   write("Trace: Could not locate requested object.\n");
   return 1; }
 
   hold = "Trace: " + identify(target);

   if(environment(target))
	hold += " in " + identify(environment(target)) + "\n";
   else hold += "\n";

   //	Try to located all copies of the object
 
   clones = children( file_name(target) );
 
   //	Its either the Master object or has no other copies around
 
   if(sizeof(clones) == 1) {

   if(base_name(clones[0]) != file_name(clones[0]))  write(hold);
   else write(hold + "There are no active copies of this object.\n");
 
   if(dest) {

	if((interactive(target) ||
	    member_array(base_name(target), PROTECT) != -1) &&
   	   !adminp(geteuid(this_player()))) {
	write("You do not have authorization to destruct that object.\n");
	return 1; }

	target->remove();
	if(target)  destruct(target);

	if(target)  write("Could not remove or destroy object.\n");
	else	    write("Object has been removed and destructed.\n");
   }
 
   return 1; }
 
   //	Remove the target object from the clone array
 
   else clones -= ({ target });
 
   //	Get original number of clones of designated object
 
   original = sizeof( clones );
 
   if(!(dest && !(More || view))) {
 
   hold += "\n   There are " + sizeof(clones) + " copies active.\n\n";
 
 
   //	Loop through the clone array to display contents
 
   for(loop=0; loop<sizeof(clones); loop++) {
 
     if(interactive(clones[loop]))  hold += " I ";  else hold += "   ";
 
     hold += identify( clones[loop] );
   
     //	If the object has an environment, display it...
 
     if(environment( clones[loop] ))
	hold += "\tin " + identify(environment(clones[loop])) + "\n";
     else hold += "\n";
 
   }
   }
 
   if(!More)  write(hold + "\n");
 
   else this_player()->more( explode(hold, "\n"), 0 ,1 );
 
 
   //	If the destruct flag is set, attempt to destruct
   //	all active copies of the requested object.
 
   if(dest) {
 
   if(More)  write("\n");
 
   //	Security check...don't want anyone just wiping out
   //	specific file objects like /std/user.c
 
   if(!adminp(geteuid(this_player())) &&
      member_array(base_name(target), PROTECT) != -1) {
   write("You do not have authorization to destruct that object group.\n");
   return 1; }

   //	Try to remove all clone copies
 
   clones->remove();
 
   clones = children( file_name(target) );
   clones -= ({ target });
 
   //	If there are any copies left...this should get rid of them
 
   for(loop=0; loop<sizeof(clones); loop++)
	destruct( clones[loop] );
 
   clones = children( file_name(target) );
   clones -= ({ target });
 
   write("All " + original + " copies of " + file_name(target) + " have " +
	 "been removed and destroyed");
 
   if(!sizeof(clones)) {  write(".\n");  return 1;  }
 
   write("except:\n");
 
   for(loop=0; loop<sizeof(clones); loop++)
	write("  " + clones[loop] + "\n");
   }
 
return 1; }
 
int help() {
 
   write( SYNTAX + "\n" +
	  "This command allows the user to locate the requested object\n" +
	  "and any active clones with their respective locations. The\n" +
	  "parameter 'd' can be used to remove and destruct every copy.\n" +
	  "When the 'd' parameter is envoked, the clones and locations\n" +
	  "will not be displayed. This can be overridden with the 'v'\n" +
	  "parameter. The 'm' parameter can be used to have the output\n" +
	  "given in a more format.\n\n" +
	  "The parameters can be given together and in any combination.\n" +
	  "For example:  trace -dm /obj/dagger  will destruct every copy\n" +
	  "of /obj/dagger and display their respective ids and locations\n" +
	  "in a more format.\n");

return 1; }
 
