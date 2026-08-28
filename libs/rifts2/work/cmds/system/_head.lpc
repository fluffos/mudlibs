//   written by Plura@Nightmare in January 93

#include <std.h>



inherit DAEMON;



int help();



int

cmd_head(string file) {

   int n;

   n = 22;

   seteuid(getuid(previous_object()));

   if(!file) {

      help();

      return 1;

   }

   else {

      file = resolv_path(this_player()->get_path(), file);

      if(!cat(file,1,n))

         write(file+": no such file\n");

      return 1;

   }

}





int help()

{

  write( @EndText

Syntax: head <file>

Effect: lists the first 20 lines of the file <file>

See also: tail, cat, more, less

EndText

  );

  return 1;

}

