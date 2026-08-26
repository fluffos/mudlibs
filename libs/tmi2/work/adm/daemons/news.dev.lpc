// Written by Guile@TMI
// incorporated into the TMI mudlib by Buddha@TMI
// Please give credit to the author of this code if you should use it.
// more code added by Buddha@TMI... actually revised quite a bit...
   
#include <news.h>

void create() { seteuid(getuid(this_object())); }

void read_news(int last_login) {
   int i, j, date, read;
   string data;
   string *files, *lines, *newfiles = ({});
   files = get_dir(NEWS_DIR + "/.");
   for(i = 0; i < sizeof(files); i ++)
   {
      if (sscanf(files[i], "%d", date)) {
         if(date > last_login) {
		newfiles += ({ NEWS_DIR + "/" + date });	
            write("::" + ctime(date) + "::\n");
            data = read_file(NEWS_DIR + "/" + files[i]);
            lines = explode(data, "\n"); // news might be too long for write
            for(j = 0; j < sizeof(lines); j ++)
            if (lines[j] != 0)
               write(lines[j] + "\n");
          }
       }
   }
   if(!read)
      write(":: No new news ::\n");
}

