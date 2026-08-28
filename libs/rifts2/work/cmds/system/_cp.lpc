/*

// This file is a part of the TMI distribution mudlib.

// Please retain this header if you use this code.

// Coded by Grog (10/15/91 - 11/03/91)

// Added to the /bin structure by Buddha  (1/18/91) 

// Help added by Brian (1/28/92)

// Single arg cp added by Scythe@Nightmare (1/25/93)

// Bug in single arg cp fixed by Pallando (5/26/93)

*/



// Modified to support wildcards by Diewarzau 4/9/96



#include <std.h>

inherit DAEMON;



int help();



int

cmd_cp(string str) {

    string line;

    string file1, *list, *file;

    string file2, path;

    int localdest, i;

    seteuid(geteuid(previous_object()));

    if(this_player()->query_forced()) {

        write("Someone has tried forcing you to cp " + str);

        return 1;

    }

    localdest = 0;    /* Assume it's not a local destination */

    if (!str || sscanf(str, "%s %s", file1, file2) != 2) {

       if (str && sscanf(str, "%s", file1)) {

          file2 = "";     // Check to see if it's a one arg

          localdest = 1;  // cp function.  Assume localdest.

       } else {

          help();

          return 1;

       }

    }

    /* check for last parameter == "." */

    if (file2 == ".") {

        localdest = 1;     /* It's a local destination */

        file2 = "";

    }

    /* Given the player's current working directory and the path(s)

       for the file, construct the new full path for both files */

    file1 = resolv_path(this_player()->get_path(), file1);

    file2 = resolv_path(this_player()->get_path(), file2);



    /* This used to give and lstat error, fixed 930208 by Plura */

   if(file_size(file1) == -2) {

    write("Cannot copy a directory.");

    return 1;

   }

   list = get_dir(file1);

   if(!list || !sizeof(list)) {

    write(file1+": No such file or directory");

    return 1;

   }

   file = explode(file1, "/");

   while((i=member_array("", file)) >= 0)

    file = exclude_array(file, i);

   i = sizeof(file) - 2;

   if(i == 0) path = "/"+file[0];

   else if(i > 0) path = "/"+implode(file[0..i], "/");

   else path = "/";

   if(localdest) file2 = (string)this_player()->get_path();

   i = sizeof(list);

   if(file_size(file2) == -1 && i > 1) {

    write(file2 + ": No such file or directory.");

    return 1;

   }

   if(file_size(file2) != -2) {

    if(i > 1) {

      write("You cannot copy multiple files to a single file.");

      return 1;

    }

    else {

      if(path+"/"+list[0] == file2) {

        write("Cannot copy a file on to itself.");

        return 1;

      }

      if(file_size(path+"/"+list[0]) == -2) {

        write("Cannot copy a directory.");

        return 1;

      }

      if(cp(path + "/" + list[0], file2) >= 1) {

        write("File copied.");

        return 1;

      }

      else {

        write("Error while copying.");

        return 1;

      }

    }

   }

   while(i--) {

    file1 = path+"/"+list[i];

    if(file_size(file1) == -2) {

      write(file1+": Directory.");

      continue;

    }

    if(file_size(file1) == -1) {

      write(file1+": Not found.");

      continue;

    }

    if(file1 == file2+"/"+list[i]) {

      write(file1+": Cannot copy a file onto itself.");

      continue;

    }

    if(cp(file1, file2+"/"+list[i]) < 1)

      write(file1+": Copy failed.");

    else

      write(file1+" to "+file2+"/"+list[i]+": File copied.");

   }

   return 1;

}



int 

help() {

  message("help", "Command: cp\nSyntax: cp <oldfile> [pathname]<newfile>\n"

	  "This command makes a copy of the file using the new name "

	  "and location passed.  If a new pathname is not specified "

	  "then the copy is put into the present working directory.", 

	  this_player());

  return 1;

}



/* EOF */

