#include <std.h>
#define DAY 86400

#include <daemons.h>
inherit DAEMON;

int cmd_news(string str) {
   int boogie;
   boogie = to_int(str);
   if (!boogie) 
   boogie = 1;
   if (boogie > 365) 
      {
      notify_fail("It's doubtful you want more than a year of messages.\n");
      return 0;
      }
   boogie = time() - (boogie * DAY);
   this_player()->set_property("last read news", boogie);
   this_player()->more(explode(NEWS_D->get_news(this_player()), "\n"));
   return 1;
   }

int help()
{
  write( @EndText
Syntax: news <arg>
Effect: Allows you to read the news.
Set an arg for number of days worth of news you want to read, default
is one day.

EndText);
  return 1;
}
