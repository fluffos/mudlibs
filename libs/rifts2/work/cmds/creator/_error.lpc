



#include <security.h>



int cmd_error(string str) {

  string file;

   seteuid(getuid());

  if(str=="rm") {

    file = "/log/errors/"+(string)this_player()->query_name();

    if(!file_exists(file)) {

     write("you don't have a error file in /log/errors.\n");

      return 1;

      }

    seteuid(UID_LOG);

    rm(file);

    seteuid(getuid());

    write(file+" is removed.\n");

    return 1;

    }

  if(str) {

    file="/log/errors/"+str;

    if(!file_exists(file)) {

      write(file+" doesn't exist.\n");

      return 1;

      }

    }

  else { 

    file= "/log/errors/"+this_player()->query_name();

    if(!file_exists(file)) {

      write("You don't have a error file in /log/errors.\n");

      return 1;

      }

    }

  this_player()->more(file);

  seteuid(UID_LOG);

  if(this_player()->getenv("AUTO_DEL") ||

	(string)this_player()->getenv("AUTO_DEL") != "0")

	rm(file);

  seteuid(getuid());

  return 1;

  }



void help() {

  write("SYNTAX: error <str>\n"+

	"	 <str> can be name of a wizard.\n"+

	"	 if <str> is not specify, default as this_player.\n"+

	"	 if <str> is 'rm', it'll remove your error file\n"+

        "        in /log/errors\n\n"+

        "Displays error messages in /log/errors.\n"+

        "If you have an environment variable 'AUTO_DEL' be 1, this\n"+

	"command will delete your log file automatically after you read\n"+

	"the file with 'error' command.\n");

  }

