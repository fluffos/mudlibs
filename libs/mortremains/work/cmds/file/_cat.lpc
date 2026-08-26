// _cat.c
// the cat command dumps a file to the screen.
// Original author unknown, probably old. Possbily Lars?
// Help added, probably by Brian@TMI, probably Jan. 1992.
// This comment added by mobydick, 11-9-92

#include <mudlib.h>

inherit DAEMON ;

string help();
int cmd_cat(string file);


int
cmd_cat(string file) {
   seteuid(getuid(previous_object()));
   if(!file) {
      help();
      return 1;
   }
   else {
      file = resolv_path(this_player()->query("cwd"), file);
      if(!cat(file))
         write(file+": no such file\n");
      return 1;
   }
}

string help() {
   return("Usage:\tcat <filename>\n"+
      "Writes the contents of the filename given to standard output.\n" +
      "If the file is over a system-defined maximum (usually 80 lines)\n" +
      "then the message \"*****TRUNCATED****\" will appear.\n" +
      "In this case, you may wish to use the more command instead.\n");
}
/* EOF */
