 
//	File	:  /cmds/adm/_userid.c
//	Creator	:  Watcher@TMI-2  (5/93)
//
//	This admin command displays the source userid of specific
//	users or a complete list of all user's userids.
 
#include <mudlib.h>

inherit DAEMON;
 
#define SYNTAX	"Syntax: userid [user]\n"
 
protected string get_userid(object who);

int cmd_userid(string str) {
   mixed *all;
   object who;
   string name;
   int loop;
 
   seteuid(getuid(this_object()));
 
   if(!adminp(geteuid(this_player()))) return 0;
 
   if(!str || str == "") {
  
      all = users();

      write(underscore("Present Active User's Source Accounts") + "\n\n");
 
      for(loop=0; loop<sizeof(all); loop++) {
	name = (string)all[loop]->link_data("cap_name");
	if(!name) continue;

	if(strlen(name) > 6) 
	  write(" " + name + "\t" + get_userid(all[loop]) + "\n");
	else write(" " + name + "\t\t" + get_userid(all[loop]) + "\n");
      }

   return 1; }
 
   who = find_player(str);
 
   if(!who) {
     notify_fail("Userid: No such user is presently online.\n");
   return 0; }
 
   write((string)who->link_data("cap_name") + "'s userid is " +
	 lower_case(get_userid(who)) + ".\n");
 
return 1; }
 
protected string get_userid(object who) {
   string userid;
 
   userid = (string)who->query_link()->query("userid");
 
return (userid ? userid : "Not available"); }
 
string help() { 

   return( SYNTAX + "\n" +
     "This command allows admins to get a listing of all user's presently\n" +
     "online, and their corresponding account userid, if it is available.\n" +
     "If a particular user is specified, it will display their userid, if\n" +
     "it is available from their host machine.\n");
 
}
 
