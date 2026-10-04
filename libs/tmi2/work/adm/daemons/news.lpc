 
//	File	:  /adm/daemons/news.c
//	Creator	:  Glenn Ferguson  (Watcher@TMI)  02/03/93
//
//	This daemon handles the MOTD/NEWS displayed to a 
//	user on login.  It distinguishes between type of
//	user and how many times they have seen a message.
//
// 19-Dec-94 Leto added some copy()'s to prevent fake news ;)
 
#include <mudlib.h>
#include <config.h>
#include <ansi.h>
 
inherit DAEMON ;
 
// If HEADER = 1, the header will be placed on news message
// If HEADER = 0, the header will be ignored 
 
#define	HEADER	1
 
// If ANSI = 1, portions of the header will be bolded
// If ANSI = 0, standard header output will be used
 
#define ANSI	0
 
#define MUD_INTRO	NEWS_DIR + "news"
 
int load_news_list();
protected int sweep_save();
protected string add_message(string file);
protected string make_header(string file, string type, int date);
protected int check_read_num(string file, int view);
 
mapping list;
string *files;
 
void create() {  ::create();  load_news_list();  }
 
int load_news_list() {
   mixed *dir;
   string type;
   int date, view, loop;
 
   //	First declare the master list mapping
 
   list = ([ ]);
 
   //	Get array of all filenames in the news directory

   dir = get_dir( NEWS_DIR );
   if(!dir || !sizeof(dir))  return 0;		// Hmmmm...no news files
 
   for(loop=0; loop<sizeof(dir); loop++) {
 
   //	First parse the news item for structure info and
   //	discard any that do not match the preset format
 
   if(!dir || sscanf(dir[loop],"%d:%s:%d", date, type, view) != 3)
	continue;
 
   //	Save news item information in master list mapping
 
   list[ dir[loop] ] = ([ "date" : date, "type" : type, "view" : view ]);
   }
 
   //	Produce a list of news files in the master list mapping
 
   files = keys( list );
 
return 1; }
 
mapping query_list() {  return copy(list); }
 
 string *query_files() {  return copy(files); }
 
//   Display the news to user when called during login.  The news
//   are returned in the form of a string in case someone wants to
//   put the output in the form of a more, in the future.
 
string display_news() {
   string output, who;
   int loop, flag;
 
   // 	Initalize MOTD output string
 
   if(file_exists( MUD_INTRO ))  output = read_file( MUD_INTRO );
   else output = "";
 
   if (this_player()->query("hushlogin")) output = "";
   for(loop=0; loop<sizeof(files); loop++) {
 
   //	Ignore player news when user is a wizard
 
   if(list[files[loop]]["type"] == "p" && wizardp(this_player()))
	continue;
 
   //	Ignore wizard news when user is a player
 
   if(list[files[loop]]["type"] == "w" && !wizardp(this_player()))
	continue;
 
   //	Display news file if no view time limitations
 
   if(list[files[loop]]["view"] == 0) {
 
   if(HEADER)  
      output += make_header(files[loop], list[files[loop]]["type"],
			    list[files[loop]]["date"]);
 
   output += add_message(files[loop]);  flag++;  continue;  }

 
   //	Display news file if view times is under required
 
   if(check_read_num(files[loop], list[files[loop]]["view"])) {
 
   if(HEADER)
      output += make_header(files[loop], list[files[loop]]["type"],
			    list[files[loop]]["date"]);
 
   output += add_message(files[loop]);  flag++;  continue;  }
 
   }
 
   who = (string) this_player()->query("name");
 
   if(!flag)  output += "** No new News to read **\n\n";
 
   //  Clean up old news file names saved in user mapping
 
   sweep_save();
 
return output; }
 
//	Check to see how many times the news item has been
//	read by this user and save updated count.
 
protected int check_read_num(string file, int view) {
   mapping store;
 
   store = this_player()->query("news_save");
   if(!store)  store = ([ ]);
 
   if(store[file]) {
   if(store[file] == view)  return 0;		// Viewed required times
 
   store[file]++;
   this_player()->set("news_save", store);
   return 1; }
 
   store[file] = 1;
   this_player()->set("news_save", store);
 
return  1; }
 
//	Check through user's stored files and delete old versions
 
protected int sweep_save() {
   mapping save;
   string *tmp;
   int loop;
 
   save = (mapping)this_player()->query("news_save");
   if(!save || !sizeof(save))  return 0;
 
   tmp = keys( save );
   if(!tmp || !sizeof(tmp))  return 0;

   for(loop=0; loop<sizeof(tmp); loop++)
   if(member_array(tmp[loop], files) == -1)
	map_delete(save, tmp[loop]);

   this_player()->set("news_save", save);
 
return 1; }
 
//	Add news file contents to displaying output
 
protected string add_message(string file) {
   return read_file( NEWS_DIR + file, 3) + "\n";  }
 
//	Construct title header for news item
 
protected string make_header(string file, string type, int date) {
   string header;

   //	If ansi bolding is enabled, bold the news type
 
   if(ANSI)	header = ESC + "[7m";
   else		header = "";
 
   //	Output message news type
 
   if(type == "p")	header += "[Player News]";
   else if(type == "w") header += "[Wizard News]";
   else			header += "[General News]";
 
   if(ANSI)	header += ESC + "[0m";
 
   //	Add news item's title to header
 
   header += "  " + read_file ( NEWS_DIR + file, 1, 1);
 
   //	Add time stamp to header
 
   header += "Posted:\t" + ctime(date) + "\n";
 
return (header + "\n"); }
 
protected int clean_news_save() {
   mapping tmp;
 
   tmp = this_player()->query("news_save");
   

return 1; }
 
