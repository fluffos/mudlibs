 
//	File	:  /cmds/xtra/_data.c
//	Creator	:  Watcher@TMI  (04/10/93)
//	Update	:  Watcher@TMI  (5/2/93)  to allow protection of secured
//			properties to all but Admins.
//
//	This wizard command produces a printout of an object's 
//	stored data set.

#include <priv.h>
#include <mudlib.h>

inherit DAEMON ;

#define SYNTAX	"Syntax: data [object]\n"

int cmd_data(string str) {
   mapping list;
   mixed *klist;
   object what;
   string text;
   int loop;

   if(!str || str == "")  str = "me";
 
   str = lower_case(str);
 
   what = get_object(str);

   if(!what) {
   notify_fail("Data: Could not locate that object.\n");
   return 0; }
 
   list = (mapping)what->query_ob_data();
 
   if(!list || !mapp(list)) {
   notify_fail("Data: That object does not have any stored data.\n");
   return 0; }
 
   klist = keys(list);
   klist = sort_array(klist, "sort_keys", this_object());
 
   if(!adminp(geteuid(this_player())))
	klist = filter_array(klist, "filter_props", this_object(), what);
 
   if(!klist || !sizeof(klist)) {
   notify_fail("Data: That object does not have any stored data.\n");
   return 0; }
 
   text = "Object :\t" + identify(what) + "\n\n";
 
   for(loop=0; loop<sizeof(klist); loop++)  {
 
      if(strlen(klist[loop]) > 7)  text += klist[loop] + "\t: ";
      else text += klist[loop] + "\t\t: ";
 
      text += wrap( identify(list[klist[loop]]), 60);
   }
 
   text += "\nA total of " + sizeof(klist) + " stored data properties.\n\n";
 
   this_player()->more( explode(text, "\n") );
 
return 1; }
 
//  This function is used to sort the key array.
 
protected int sort_keys(string one, string two) {
   return strcmp(one, two);  }
 
//  This function strips out the secured props from the data array.
 
protected int filter_props(string prop, object target) {
 
   if(member_array((int)target->query_permission(prop),
	({ MASTER_ONLY, PRIVATE, OWNER_ONLY })) != -1)   return 0;
 
return 1; }

int help() {

   write( SYNTAX + "\n" +
     "This command allows you to view the saved object data set for a\n" +
     "specified object, in a \"more\" printout format. If no argument is\n" +
     "given, the calling user will be used.\n");
 
return 1; }
 
