//#pragma save_binary

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
   else write((string)who->query("c_name") + "'s messages are:\n\n");

   if(!who->query("title"))  write("C_TITLE\t:  UNDEFINED\n");
   else write("C_TITLE\t\t:  " + (string)who->query("title") + "\n");

   if(!who->query_c_min())  write("C_MIN\t:  UNDEFINED\n");
   else write("C_MIN\t\t:  " + (string)who->query_c_min() + "\n");

   if(!who->query_c_mout())  write("C_MOUT\t:  UNDEFINED\n");
   else write("C_MOUT\t\t:  " + (string)who->query_c_mout() + "\n");

   if(!who->query_c_mmin())  write("C_MMIN\t:  UNDEFINED\n");
   else write("C_MMIN\t\t:  " + (string)who->query_c_mmin() + "\n");

   if(!who->query_c_mmout())  write("C_MMOUT\t:  UNDEFINED\n");
   else write("C_MMOUT\t\t:  " + (string)who->query_c_mmout() + "\n");

   if(!who->query_c_minvis())  write("C_MINVIS\t:  UNDEFINED\n");
   else write("C_MINVIS\t:  " + (string)who->query_c_minvis() + "\n");

   if(!who->query_c_mvis())  write("C_MVIS\t:  UNDEFINED\n");
   else write("C_MVIS\t\t:  " + (string)who->query_c_mvis() + "\n");

   if(!who->query_c_mhome())  write("C_MHOME\t:  UNDEFINED\n");
   else write("C_MHOME\t\t:  " + (string)who->query_c_mhome() + "\n");

   if(!who->query_c_mdest())  write("C_MDEST\t:  UNDEFINED\n");
   else write("C_MDEST\t\t:  " + (string)who->query_c_mdest() + "\n");

   if(!who->query_c_mclone())  write("C_MCLONE\t:  UNDEFINED\n");
   else write("C_MCLONE\t:  " + (string)who->query_c_mclone() + "\n");

   write("\n  You can change your messages with the set command\n  " +
	 "for more information, type \"help movement_messages\".\n\n");

return 1; }

int help() {

   write( SYNTAX + "\n" +
     "This command displays the preset messages of the selected user. If\n" +
     "no argument is given, it will display your messages. The set command\n" +
     "can be used to change your present messages.\n");

return 1; }
