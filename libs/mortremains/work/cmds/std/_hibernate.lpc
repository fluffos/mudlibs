//	File	:  /cmds/std/_hibernate.c
//	Creator	:  Watcher@TMI-2  (4/29/93)
//
//	This command allows a user to place their character into 
//	hiberation for a designated number of days. During this time,
//	the user will be unable to login. This is useful for self-imposed
//	exile from mudding during exam times, etc.
 
#include <logs.h>
#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

#define SYNTAX	"Syntax: hibernate [name] [number of days]\n"
 
int cmd_hibernate(string str) {
   int when;
 
  string user,time;
  object victim,link;

  if( !str )  {
     notify_fail( SYNTAX );
     return 0;
  }
	// Evil Admin purposes
  if(sscanf(str,"%s %s",user,time)) when = to_int(time);
  else when = to_int(str);
 
   notify_fail( SYNTAX );
 
   if(when < 1)  return 0;
 
   seteuid(getuid(this_object()));
 
   if(when > 90) {
   notify_fail("You cannot hibernate for longer than 90 days.\n");
   return 0; }
 
  // Admin check, see if we want to hibernate someone else.

  if(user) 
	{
          if(!adminp(geteuid(previous_object())) ||
             adminp(user)) 
						 {
                    notify_fail("hibernate: permission denied\n");
                    return 0;
             }
          if(!user_exists(user))
						 {
										 notify_fail("hibernate: no such user\n");
										 return 0;
             }
					 
          else {

       victim = find_player(user);
       if(victim) link = (object)victim->query_link();
			 else link = (object)FINGER_D->restore_data(user);
       link->set("hibernate", (time() + when*86400));
	     if(victim) {
			   tell_object(victim, capitalize(this_player()->query("name"))+
                 " has put you in hibernation for "+when+ " days.\n");
			   victim->quit();
				 write("Hibernated "+user+" for "+when+" days.\n");
#ifdef HIBERNATE
				 log_file(HIBERNATE, capitalize(this_player()->query("name")) + 
				 " has hibernated "+ capitalize(user) +" from " +
				 extract(ctime(time()), 4, 15) + " to " +
				 extract(ctime(time() + (when * 86400)), 4 ,15) + " [" +
					query_ip_number(this_player()) + "]\n");
#endif
			            }
                }
  return 1;
	} 


   input_to("pass_check", 1, when);
   write("\nAre you SURE you wish to place your character in hiberation for " +
	 when + " day" + (when == 1 ? "" : "s") + "?\nYou will not be able "+
	 "to login as that character until " + ctime(time() + (when*86400)) +
	 ".\n\nPlease confirm by entering your password: ");
 
return 1; }
 
protected int pass_check(string pass, int when) {
   string name, password;
 
   //   Get player's name for logging purposes

   name = (string)this_player()->link_data("name");

   //   Get the user's password from the linked connection object

   password = (string)this_player()->link_data("password");

   //   Check to see the inputed password matches the actual password

   if(password != crypt(pass, password)) {
   write("\nInvalid password. Hibernation request aborted.\n");
   return 1; }

   write("\n\nFare thee well, adventurer. You may return on " + 
	 ctime(time() + when*86400) + ".\nEverything slowly fades away " +
	 "as you fall into a deep, peaceful slumber.\n\n");

   tell_room(environment(this_player()),
	capitalize(name) + " decides to hibernate until " +
	ctime(time() + when*86400) + ".\n", ({ this_player() }));

   //	Set the user's connection hibernation time length.
 
   this_player()->query_link()->set("hibernate", (time() + when*86400));

   //   Save the players attributes before file transfer

   this_player()->query_link()->save_data();

   //	IF HIBERNATE is defined, write the particulars to a log file

#ifdef HIBERNATE
   log_file(HIBERNATE, capitalize(name) + " has hibernated from " +
	    extract(ctime(time()), 4, 15) + " to " +
	    extract(ctime(time() + (when * 86400)), 4 ,15) + " [" +
	    query_ip_number(this_player()) + "]\n");
#endif
 
   this_player()->quit();
 
return 1; }
 
string help() {
 
   return( SYNTAX + "\n" +
    "This command allows you to place your character in hibernation. It will\n"+
    "disconnect your character and prevent you from logging back in until\n"+
    "the requested number of days have passed. This is useful for those who\n"+
    "wish to exile themselves temporarily from the mud during exam time.\n"+
                "Admins may supply a name to hibernate someone else.\n");

}
 
