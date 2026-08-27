#include <command.h>
#include <daemons.h>

void
save_newsrc(string file, mapping newsrc)
{
  rm(file);
  
  foreach(string group, string list in newsrc)
  {
    write_file(file, sprintf("%s: %s\n", group, list));
  }
}

int
main()
{
  string file = user_path(this_player()->query_name()) + ".newsrc";
  mapping newsrc;

  if( file_exists(file) )
  {
    int curr_line = 1;

    newsrc = ([ ]);
    
    foreach(string str in explode(read_file(file), "\n"))
    {
      string group, list;
      
      if( sscanf(str, "%s: %s", group, list) == 2 )
	newsrc[group] = list;
    }
  }

  return NEWS_D->read_news(newsrc, (: save_newsrc, file :));
}
