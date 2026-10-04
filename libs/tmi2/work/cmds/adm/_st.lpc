 
//	File	:  /cmds/adm/_st.c
//	Creator	:  Watcher@TMI  (03/28/93)
//
//	This is the Admin snoop trace command.  

#include <mudlib.h>

inherit DAEMON;

#define SYNTAX 	"Syntax: st [user]\n"

int cmd_st(string str) {
   mixed *user_list;
   object who;
   int loop;
 
   if(!adminp(geteuid(this_player()))) {
   notify_fail("St: Permission denied.\n");
   return 0; }
 
   if(!str || str == "") {
 
	user_list = users();
	user_list = filter_array(user_list, "filter_snoop", this_object());
 
	if(!user_list || !sizeof(user_list)) {
	write("St: No one is presently being snooped.\n");
	return 1; }

	printf("Snoop Trace Display [%d user%s]\n", sizeof(user_list),
	       ((sizeof(user_list) > 1) ? "s" : ""));
	write("===================\n\n");
 
	for(loop=0; loop<sizeof(user_list); loop++)
	printf("%s is being snooped by %s\n", 
	       (string)user_list[loop]->link_data("cap_name"),
	       (string)query_snoop(user_list[loop])->link_data("cap_name") );
	write("\n");
 
   return 1; }
 
   str = lower_case(str);
 
   who = find_player(str);
 
   if(!who) {
   notify_fail("St: No such user.\n");
   return 0; }
 
   if(query_snoop(who))  
	printf("St: %s is being snooped by %s.\n",
	       (string)who->query("cap_name"),
	       (string)query_snoop(who)->link_data("cap_name"));
   else printf("St: %s is not presently being snooped.\n",
	       (string)who->query("cap_name"));
 
return 1; }
 
protected object filter_snoop(object obj) {  return query_snoop(obj);  }
 
string help() {

   return( SYNTAX + "\n" +
     "This command allows an admin to see if a specific user is presently\n" +
     "being snooped. If no user is given, a list of all users being snooped\n"+
     "presently on the mud.\n");
 
}
 
