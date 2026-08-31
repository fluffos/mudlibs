/*
// The new, more efficient, improved ls command.
// Thanks to Huthar and Wayfarer for this one.
   Plura 930119, I changed size/=1000 into size/=1024
                 I added the '*' in front of loaded objects.
                 I added the write() with totsize and # of files.
   write() changed to message() by Valodin, August 19, 1993
*/
//  Fixes by Whit for driver change.
#include <std.h>
#include <daemons.h>
inherit DAEMON;
mapping fcolours = ([ "c"   : "%^CYAN%^",
                      "h"   : "%^CYAN%^%^BOLD%^",
                      "bak" : "%^BLACK%^%^BOLD%^" ]);
string spaces;
int tfiles,tsize,tdirs; /* too many local variables... */
varargs int do_ls(mixed path, object act_ob, int show_dots, string real_path)
{
//  All comment out by Whit
   string *files;
//   string *Files,*Dirs;
   int index,x,y,rows,cols,l,length,num,size,i;
//   string *wcfiles;
//   string string_path;
   string colour, tmp, junk;
// DEBUG PTER
#if 0
int tmp1, tmp2;
tmp1=sizeof(path);
write("do_ls sizeof(path)="+sizeof(path)+"\n");
while (tmp1--)
        {
        tmp2=sizeof(path[tmp1]);
        write("do_ls sizeof[tmp1]="+tmp2+"\n");
        while (tmp2--)
                write("do_ls path="+path[tmp1][tmp2]+"\n");
        }
#endif
   
   if(!act_ob)
      act_ob = previous_object();
   tsize = tfiles = tdirs = 0;
   spaces = "                                                                  
";
   seteuid(getuid(act_ob));
   if(!pointerp(path))
   {
      size = file_size(path);
      if (size > -1) {
         size /= 1024;
         if (size == 0) size = 1;
         files = explode(path,"/");
         path = files[sizeof(files)-1];
         message("system", size + " " + path, this_player());
         return 1;
      }
      if (path != "/")
         path += "/";
      if( !((int)master()->valid_read(path, this_player())) ) {
        message("system", path+": permission denied", this_player());
        return 1;
        }
      files = get_dir(path);
      if(!files) {
        message("system", path[0..sizeof(path)-2]+": no such directory", this_player());
        return 1;
      }
      files = sort_array(files,"mycmp",this_object());
   }
   else
   {
      files = path[1];
      path = path[0][0] + "/";
   }
// Code added by peter
   path=resolv_path("cwd",path);
   if (path[ strlen(path)-1..strlen(path)-1 ] !="/")
        path=path+"/";
// End code by Peter
   if(!show_dots)
      files = filter_array(files, "remove_dots", this_object());
   if (!files) {
      size = file_size(path);
      if (size == -2) {
         return 1;
       }
      if (size == -1) {
         notify_fail("No such file or directory.\n");
         return 0;
       }
      message("system", size + " " + path, this_player());
      return 1;
   }
   num = sizeof(files);
   for (index = 0; index < num; index++) {
      i = strlen(files[index]);
      if (i > length) length = i;
   }
   length ++;
   if (length > 75)
      length = 75;
   cols = 77 / (length + 5);
   if (!cols) cols = 1; /* filenames can be huge in un*x */
   rows = num / cols;
   if (rows * cols < num)
      rows++;
   message("system", path+":", this_player());
   for (y = 0; y < rows; y++) {
      for (x = 0; x < cols; x++) {
         index = x * rows + y;
         if (index > num - 1) 
            break;
         size = file_size((string)path + files[index]);
         l = strlen(files[index]);
         switch(size) {
            case -2:
              message("Nsystem","     %^BLUE%^%^BOLD%^" + files[index] + "/", this_player());
              tdirs++;
              l++;
              break;
            case -1:
              message("Nsystem","   - %^RED%^%^BOLD%^" + files[index]+"", this_player());
              break;
            default:
              if (sscanf(files[index], "%s.%s", junk, tmp) == 2)
                if (fcolours[tmp])
                  colour = fcolours[tmp]; 
                     else colour = "";
                 else colour = "";
              tfiles++;
              tsize += size;
              size /= 1024;
              if (size == 0) size = 1;
              if (size < 10) message("Nsystem", " ", this_player());
              if (size < 100) message("Nsystem", " ", this_player());
              if(find_object(path+files[index]))
                 message("Nsystem", "*", this_player());    /* Plura 930119  */
              else
                 message("Nsystem", " ", this_player());
              message("Nsystem", size + " "+colour+files[index]+"", this_player());
              break;
           }
         if (length - l > 0)
            message("Nsystem", spaces[1 .. (length - l)], this_player());
        }
      message("Nsystem", "\n", this_player());
   }
#if 0
   if (index % cols != 0)
      message("Nsystem", "\n", this_player());
#endif
   message("system", "A total of "+add_commas(tsize)+" bytes in "+add_commas(tfiles) +
         " file" + ((tfiles != 1) ? "s." : ".") +
         "  ("+tdirs+" director"+((tdirs != 1)?"ies)":"y)"), this_player());
   return 1;
}
int cmd_ls(string path)
{
//  Comentsout by Whit
//   string *Files,*Dirs;
//   int i, num;
//   string *wcfiles;
//   mixed *tmp;
   int show_dots;
   string str2;
   object act_ob;
  act_ob = this_player();
   seteuid(getuid(act_ob));
   if(path && (path == "-a" || sscanf(path,"-a %s",str2)))
   {
      show_dots = 1;
      path = str2;
   }
// Code added by peter
   IMSTAT_D->add_stat(this_player()->query_name(), "ls", time());
   path=resolv_path("cwd",path);
   if(!path) {
     message("system", "No current working directory.", this_player());
     return 1;
   }
   if (path[ strlen(path)-1..strlen(path)-1 ] !="/")
        path=path+"/";
// End code by Peter
#if 0
   wcfiles = (string *)act_ob->wild_card(path);
   if (!wcfiles || !sizeof(wcfiles))
   {
         message("system", "No such file or directory.", this_player());
         return 1;
   }
   num = sizeof(wcfiles);
   if(num == 1)
   {
      do_ls(wcfiles[0], act_ob, show_dots);
      return 1;
   }
   tmp = path_file(wcfiles);
   Files = filter_array(wcfiles, "is_file", this_object());
   Dirs = wcfiles - Files;
   if(Files)
      do_ls(path_file(Files), act_ob, show_dots);
   if(Dirs)
   {
      for(i = 0; i < sizeof(Dirs); i++)
      {
         message("system", Dirs[i]+":", this_player());
         do_ls(Dirs[i],act_ob, show_dots);
      }
   }
#else
   if (stringp(path)==0) 
        path=this_player()->get_path();
   do_ls(path,act_ob,show_dots);
#endif
   return 1;
}
int is_file(string file)
{
   return(file_size(file) >= 0);
}
int remove_dots(string file)
{
   if(file[0] == '.')
      return 0;
   return 1;
}
int mycmp(string one, string two) {
     return strcmp(one, two);
   }
int help()
{
  write( @EndText
Syntax: ls <directory>
Effect: Lists the names of the files in <directory>
See also: cd, more, ed, pwd
EndText
  );
  return 1;
}
