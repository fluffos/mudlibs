// The new, more efficient, improved ls command.
// Thanks to Huthar and Wayfarer for this one.
// Italian added the -la options (18-11-92)
// Mobydick added the help 11-13-92, using the ls.command doc file.
// Hacked by Zeus to work a bit faster...by putting the output into
// an array of string, and displaying it at the end using more. 29/01/92
// Modified by Zeus to use get_dir(path, -1) thus increasing the overall
// speed by twofolds.
// Watcher rerouted the output through the mudlib's PAGER system (4/10/93).
// Fixed by Blue to be a bit faster and to work properly with wildcards
//  (previously something like ls /adm/daemons/*.t would give everything
//  in /adm/daemons). (11/5/93) (that's 11th of May for US ppl :) Also
//  the pager now works properly for stuff like 'ls /adm/*'

#include <mudlib.h>

#define spaces "                                                                               "

inherit DAEMON ;

string *text;
int show_dots, show_long, line;

string *long_ls(mixed *files, string path);
int is_file(mixed *file);
int remove_dots(string file);
void do_more(string *str);

string *do_ls(mixed *files, string path) {
   int index,x,y,rows,cols,l,length,num,size,i;
   string *output;

   if(!files)  files = ({});
 
   if(!show_dots)
      files = filter_array(files, "remove_dots", this_object());
   num = sizeof(files);
   if(!num) {
      return ({ "Directory is empty.\n" });
   }
   if(show_long) return long_ls(files, path);
   for (index = 0; index < num; index++) {
      i = strlen(files[index][0]);
      if (i > length) length = i;
   }
   length ++;
   if (length > 75) length = 75;
   cols = 80 / (length + 5);
   if (!cols) cols = 1; /* filenames can be huge in un*x */
   rows = num / cols;
   if (rows * cols < num) rows++;
   output = allocate(rows);
   for (y = 0; y < rows; y++) {
      output[y] = "";
      for (x = 0; x < cols; x++) {
         index = x * rows + y;
         if (index > num - 1) break;
         size = files[index][1];
         l = strlen(files[index][0]);
         switch(size) {
            case -2:
            output[y] += "   1 " + files[index][0] + "/";
            l++;
            break;
            case -1:
            output[y] += "   - " + files[index][0];
            break;
            default:
            size /= 1024;
            if (size == 0) size = 1;
            if (size < 10) output[y] += " ";
            if (size < 100) output[y] += " ";
            output[y] += " " + size + " " + files[index][0];
            break;
           }
         if (length - l > 0)
            output[y] += (spaces[1 .. (length - l)]);
        }
   }
   return output;
}

string *long_ls(mixed *files, string path) {
  int i, j;
  mixed *stats;
  string *output;
  int num;
  string tmp;

  num = sizeof(files);
  output = allocate(num+2);
  output[0]="     Last change              Loaded           Size       Name";
  output[1]="--------------------   --------------------   ------   -----------";
  for(i=0; i<num; i++) {
    tmp = path + "/" + files[i][0];
    j = strlen(tmp);
    if (file_size(tmp) == -2 || (j > 2 && tmp[j-3 .. j-1] == "/.."))
      output[i+2] = sprintf(spaces[0..46]+"<DIR>   "+files[i][0]);
    else if (file_size(tmp) == -1)
      output[i+2] = sprintf(spaces[0..39]+"<UNREADABLE>   "+files[i][0]);
// The above line added 22/9/93 by Blue, to fix /adm/link problem.
    else {
      stats = stat(tmp);
      stats[0]=spaces[0..(8-strlen(stats[0]+" "))]+stats[0];
      stats[1]=ctime(stats[1]);
      if(stats[2]) stats[2]=ctime(stats[2]);
      else stats[2]="       < not loaded >   ";
      output[i+2] = sprintf("%s   %s %s   %s", stats[1][4..strlen(stats[1])],
        stats[2][4..strlen(stats[2])], stats[0], files[i][0]);
    }
  }
  return output;
}


void do_more(string *str) {
   this_player()->more( str, 1, 1 );
}


int cmd_ts(string path) {
   mixed *Files,*Dirs;
   string *output;
   int i, num;
   string *wcfiles;
   string str1, str2, full_path;

   show_dots = 0;
   show_long = 0;
   seteuid(getuid(this_player()));
   if(path && sscanf(path,"-%s %s",str1,str2) == 2) {
      path = str2;
      switch(str1) {
        case "a" :
          show_dots = 1;
          break;
        case "l" :
          show_long = 1;
          break;
        case "al" :
        case "la" :
          show_long = 1;
          show_dots = 1;
          break;
        default :
          show_long = 0;
          show_dots = 0;
      }
   }
   else if(path && sscanf(path,"-%s",str1) == 1) {
      path = 0;
      switch(str1) {
        case "a" :
          show_dots = 1;
          break;
        case "l" :
          show_long = 1;
          break;
        case "al" :
        case "la" :
          show_long = 1;
          show_dots = 1;
          break;
        default :
          show_long = 0;
          show_dots = 0;
      }
   }
   output = ({ });
   full_path = extract(resolv_path(this_player()->query("cwd"), path),1);
   if (file_size(full_path)==-2) {
      output = do_ls(get_dir(full_path+"/*", -1), full_path);
      do_more(output);
      return 1;
   }
   wcfiles = get_dir(full_path, -1);
   if (!wcfiles || !sizeof(wcfiles)) {
      write("No such file or directory.\n");
      return 1;
   }
   full_path = extract(path_file(full_path)[0], 1);
   Files = filter_array(wcfiles, "is_file", this_object());
   Dirs = wcfiles - Files;
   if(pointerp(Files) && sizeof(Files) > 0) {
      output += do_ls(wcfiles, full_path);
   }
   if(pointerp(Dirs) && sizeof(Dirs) > 0) {
      for(i = 0; i < sizeof(Dirs); i++) {
	 string *ffiles;
	 if (Dirs[i][0]=="." || Dirs[i][0]=="..") continue;
         output += ({ "\n"+Dirs[i][0]+":" });
	 ffiles = get_dir(full_path+"/"+Dirs[i][0]+"/*", -1);
	 if (sizeof(ffiles))
	    output += do_ls(ffiles, full_path+"/"+Dirs[i][0]);
      }
   }
   do_more(output);
   return 1;
}

int is_file(mixed *file) {
   return(file[1] != -2); // isn't file size in field 2 from get_dir()?
			  // and isn't it undefined for dirs?
			  // bleah...who's to argue...this seems to work
}

int remove_dots(mixed *file) {
   if(file[0][0] == '.') return 0;
   return 1;
}

string help() {
	return (
"Give a list of all files in 'path'. If no argument is given, list the\n"+
"files in the current directory.\n"+
"'ls /' will give a list of all files in the root directory.\n") ;
}
