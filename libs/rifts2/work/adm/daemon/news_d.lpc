// Written by Brand 7/96
// for the Darkemud and Renegade mudlibs

#include <daemons.h>

#define DEFAULT_COLS 70
#define MAX_NEWS 10
#define OLD_NEWS_DIR "/news/oldnews/"
#define NEWS_DIR "/news/"
#define TMP_FILE_NAME "/tmp/news."
#define FILTER(array, var) filter_array(array, "check_time_stamp", this_object(), var)

void clean_up_news();

void create() { seteuid( getuid() ); }

void add_news(string type)
   {
   string filename;
   if (!type)
      return;
   filename = TMP_FILE_NAME+this_player()->query_true_name();
   this_player()->edit(filename, "really_add_news", this_object(), type); 
   }

void really_add_news(string type)
   {
   string tempshit;
   string strap_on_string="";
   tempshit = read_file(TMP_FILE_NAME+this_player()->query_true_name());
   rm(TMP_FILE_NAME+this_player()->query_true_name());
   strap_on_string = "Posted by "+
      capitalize(this_player()->query_true_name())+
      " "+(string)ctime(time())+".\n";
   tempshit = tempshit + "\n\n" + strap_on_string;
   if (verify_dir_exists(NEWS_DIR+type+"/") < 1 )
      {
      printf("Directory not found or created. Exiting.\n");
      return;
      }
   write_file(NEWS_DIR+type+"/"+(string)time(), tempshit, 1);
   printf("Posted.\n");
   }

int check_time_stamp(mixed time_t, object user)
   {
   int tru_time, p_time;
   tru_time = to_int(time_t);
   p_time = user->query_property("last read news");
   if (tru_time > p_time)
      return 1;
   return 0;
   }

string get_news(object player)
   {
   int i, columns, tmptime;
   string *nfiles;
   string news, tmpstr;
   nfiles = get_dir(NEWS_DIR+"news/");
   news = "";
   if (nfiles)
      nfiles = filter_array(nfiles, "check_time_stamp", this_object(), player);
   if (!columns = to_int(this_player()->getenv("COLUMNS") ) )
      columns = DEFAULT_COLS;
   if (nfiles && sizeof(nfiles))
      {
      tmpstr = "Darkemud News";
      news += sprintf("%s\n", tmpstr);
      news += "\n"+write_border(columns, "*")+"\n";
      for (i=0; i < sizeof(nfiles); i++)
         if (to_int(nfiles[i]) > (int)player->query_property("last read news"))
            {
            news += read_file(resolv_path(NEWS_DIR+"news/", nfiles[i]));
            news += "\n"+write_border(columns, "*")+"\n";
            }
      }
   nfiles = get_dir(NEWS_DIR+"immortal/");
   if (wizardp(player) && (nfiles = FILTER(nfiles, player)) && sizeof(nfiles))
      {
      tmpstr = "Immortal News";
      news += sprintf("%s:\n", tmpstr);
      news += "\n"+write_border(columns, "*")+"\n";
      for (i=0; i < sizeof(nfiles); i++)
         if (to_int(nfiles[i]) > (int)player->query_property("last read news"))
            {
            news += read_file(resolv_path(NEWS_DIR+"immortal/", nfiles[i])); 
            news += "\n"+write_border(columns, "*")+"\n";
            }
      }
   nfiles = get_dir(NEWS_DIR+"arch/");
   if (archp(player) && (nfiles = FILTER(nfiles, player)) && sizeof(nfiles))
      {
      tmpstr = "Arch News";
      news += sprintf("%s:\n", tmpstr);
      news += "\n"+write_border(columns, "*")+"\n";
      for (i=0; i < sizeof(nfiles); i++)
         if (to_int(nfiles[i]) > (int)player->query_property("last read news"))
            {
            news += read_file(resolv_path(NEWS_DIR+"arch/", nfiles[i])); 
            news += "\n"+write_border(columns, "*")+"\n";
            }
      }
   tmptime = to_int(player->query_property("last read news"));
   news += sprintf("\nNews last read %s.\n\n", 
      (tmptime > 0 ? ctime(tmptime) : "NEVER") );
   player->set_property("last read news", time());
   clean_up_news();
   return news;
   }

int verify_is_dir(string dir, string current_dir)
   {
   dir = resolv_path(current_dir, dir);
   if (file_size(dir) == -2)
      return 1;
   return 0;
   }

void clean_up_news()
   {
   string *news_dirs;
   string current_dir, fa, fb;
   string *current_files;
   int i,j;
   news_dirs = get_dir(NEWS_DIR);
   news_dirs = filter_array(news_dirs, "verify_is_dir", 
      this_object(), NEWS_DIR);
   if (!sizeof(news_dirs))
      {
      printf("Odd, no news dirs exist.\n");
      return;
      }
   for (i=0; i < sizeof(news_dirs); i++)
      {
      current_dir = resolv_path("", NEWS_DIR+news_dirs[i]);
      if (sizeof(current_files = get_dir(current_dir+"/")) > MAX_NEWS)
         {
         current_files = sort_array(current_files, -1);
         current_files = current_files[10..(sizeof(current_files)-1)];
         if (verify_dir_exists(OLD_NEWS_DIR+news_dirs[i]) == 1)
            {
            for (j=0; j < sizeof(current_files); j++)
               {
               fa = resolv_path(current_dir, current_files[j]);
               fb = resolv_path(OLD_NEWS_DIR+news_dirs[i], current_files[j]);
               rename(fa, fb);
               log_file("clean_news", ctime(time())+":\n");
               log_file("clean_news", "\t"+fa+" moved to "+fb+"\n");
               }
            }
         }
      }
   }
