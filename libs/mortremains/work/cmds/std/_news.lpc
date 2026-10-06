 
/*
// This file is part of the TMI Mudlib distribution.
// Please include this header if using this code.
// Written by Sulam(12-21-91)
// Help added by Brian (1/28/92)
//
// Overhauled and upgraded by Watcher@TMI-2  (6/93)
*/

#include <config.h>
#include <daemons.h>
#include <mudlib.h>
 
inherit DAEMON;

#define RESTRICT	({ "wiznews", "README" })
 
protected string display_dir(mixed *dir);
 
 
int cmd_news(string file) {
   string *dir;
 
   dir = get_dir(NEWS_DIR);

   if(!wizardp(this_player()))
	dir = filter_array(dir, "filter_news", this_object());
 
        if( !file || file == "") {
		write("Topics are:\n\n");
		write(display_dir(dir) + "\n");
		write("Type news <topic> to see more specific information.\n");
	} else {
 
	 	if(member_array(file, dir) == -1) {
		write("There is no such news article.\n");
		return 1; }
 
		previous_object()->more(NEWS_DIR + "/" + file, 1);
	}
 
return 1; }

string help() {
  return(@HELP
Syntax: news [news name]

This command allows you to read news which is important on this MUD.
Without and argument, this command will show all of the news items
which are available for reading.
HELP
  );
}
 
protected string display_dir(mixed *dir) {
   string output;
 
   output = implode(dir[0..sizeof(dir)-2], ", ");
   output += ", and " + dir[sizeof(dir)-1] + ".";
 
return wrap(output); }
 
protected int filter_news(string str) {  
   int tmp1, tmp2;
 
   if(member_array(str, RESTRICT) != -1)  return 0;
 
   return (sscanf(str, "%d:w:%d", tmp1, tmp2) != 2);  }
 
/* EOF */
