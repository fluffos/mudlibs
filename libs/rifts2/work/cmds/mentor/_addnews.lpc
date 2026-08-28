#include <daemons.h>
#include <std.h>

inherit DAEMON;

int cmd_addnews(string str)
   {
   string type;
   if (!str || str == "news")
      type = "news";
   if (str == "immortal")
      type = "immortal";
   if (str == "arch")
      type = "arch";
   NEWS_D->add_news(type);
   return 1;
   }

int help(){
  message("help",
  "Syntax: 'addnews <type>'\n"
   "Valid types are: news, immortal, and arch.\n"
   "No argument will default to 'news'.\n"
  "\n",
  this_player());
  return 1;
}
