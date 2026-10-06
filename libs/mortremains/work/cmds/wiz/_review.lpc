 
//	File	:  /cmds/xtra/_review.c
//	Creator	:  Sulam@TMI  (12-21-91)
//
//	Completely overhauled by Watcher@TMI (3/27/93)
//
//	This is the standard wizard message review command.

#include <mudlib.h>

inherit DAEMON;
 
#define SYNTAX	"Syntax: review [user]\n" 

protected int review_user(object obj);
 
int cmd_review(string str) {
   object who;
 
   if(!str || str == "")  return review_user(this_player());

   who = get_object( str = lower_case(str) );
 
   if(!who || !living(who)) {
   write("Review: There is no such living object active.\n");
   return 1; }
 
return review_user(who); }
 
//	This function does the actually querying and displaying
//	of the specified user's messages.
 
protected int review_user(object who) {
 
   if(who == this_player())  write("Your messages are:\n\n");
   else write((string)who->query("cap_name") + "'s messages are:\n\n");
 
   if(!who->query("title"))  write("TITLE\t:  UNDEFINED\n");
   else write("TITLE\t:  " + (string)who->query("title") + "\n");
 
   if(!who->query_min())  write("MIN\t:  UNDEFINED\n");
   else write("MIN\t:  " + (string)who->query_min() + "\n");
 
   if(!who->query_mout())  write("MOUT\t:  UNDEFINED\n");
   else write("MOUT\t:  " + (string)who->query_mout() + "\n");
 
   if(!who->query_mmin())  write("MMIN\t:  UNDEFINED\n");
   else write("MMIN\t:  " + (string)who->query_mmin() + "\n");
 
   if(!who->query_mmout())  write("MMOUT\t:  UNDEFINED\n");
   else write("MMOUT\t:  " + (string)who->query_mmout() + "\n");
 
   if(!who->query_minvis())  write("MINVIS\t:  UNDEFINED\n");
   else write("MINVIS\t:  " + (string)who->query_minvis() + "\n");
 
   if(!who->query_mvis())  write("MVIS\t:  UNDEFINED\n");
   else write("MVIS\t:  " + (string)who->query_mvis() + "\n");
 
   if(!who->query_mhome())  write("MHOME\t:  UNDEFINED\n");
   else write("MHOME\t:  " + (string)who->query_mhome() + "\n");
 
   if(!who->query_mdest())  write("MDEST\t:  UNDEFINED\n");
   else write("MDEST\t:  " + (string)who->query_mdest() + "\n");
 
   if(!who->query_mclone())  write("MCLONE\t:  UNDEFINED\n");
   else write("MCLONE\t:  " + (string)who->query_mclone() + "\n");
 
   write("\n  You can change your messages with the set command\n  " +
	 "for more information, type \"help movement_messages\".\n\n");
 
return 1; }
 
int help() {
 
   write( SYNTAX + "\n" +
     "This command displays the preset messages of the selected user. If\n" +
     "no argument is given, it will display your messages. The set command\n" +
     "can be used to change your present messages.\n");
 
return 1; }
 
