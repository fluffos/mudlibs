//	File	:  /cmds/adm/_setnews.c
//	Creator	:  Watcher@TMI	(02/03/93)
//
//	This command is used by admins to create NEWS items 
//	to be read on login by specific users groups.

#include <config.h>
#include <mudlib.h>
#include <daemons.h>

inherit DAEMON ;
 
#define	SYNTAX	"Usage: setnews [source file]\n"
 
 
string title, file, Class;
int busy, count;

int cmd_setnews(string str) {
 
   notify_fail( SYNTAX );
   if(!str || str == "")  return 0;
 
   // 	Command permissions check
 
   if(!adminp(geteuid(this_player()))) {
   notify_fail("Setnews: permission denied.\n");
   return 0; }
 
   //	Get full path name for requested file
 
   file = resolv_path(this_player()->query("cwd"), str);
 
   //	Check to see if the requested file exists
 
   if(!file_exists(file)) {
   notify_fail("Setnews: Invalid filename.\n");
   return 0; }
 
   busy = 1;			// Set command busy command 
 
   write("\nTitle of news item: ");
   input_to("item_title");
 
return 1; }
 
protected int item_title(string str) {
 
   if(!str || str == "")  str = "General news item.";
 
   title = str;
 
   write("Is the news item for wizards, players, or all? [w/p/a] ");
   input_to("news_level");
 
return 1; }

protected int news_level(string str) {
 
   if(!str  || member_array(str, ({ "w", "p", "a" })) == -1)  {
   write("Setnews: Invalid response.\n");
   busy = 0;  return 1;  }
 
   Class = str;
 
   write("How many repeats ? [0 = always] ");
   input_to("set_repeat");
 
return 1; }
 
protected int set_repeat(string str) {

   //	Convert string input to its corresponding numerical value
 
   count = atoi(str);
 
   if(!intp(count) || count < 0) {
   write("Setnews: Invalid response.\n");
   busy = 0;  return 1; }
 
   //	Attempt to write new news item to news directory
 
   if(!write_file( (NEWS_DIR + time() + ":" + Class + ":" + count),
		title + "\n\n" + read_file( file ) + "\n")) 
   write("\nSetnews: Failed to save news item.\n");
 
   else {
   write("\nNew news item added.\n");
   rm( file );
   MSG_D->load_news_list();  }
 
   busy = 0;				// Reset command activity flag
 
return 1; }
 
int query_busy() {  return busy;  }
 
string help() {
 
   return( SYNTAX + "\n" +
     "This command will add the specified file to the news, and remove\n" +
     "your source file.  The command will also request display settings\n" +
     "like the number of repeats and the display audience for the new\n" +
     "item.  The command works in conjunction with the news daemon and\n" +
     "the user mud login sequence.\n");
 
}
 
