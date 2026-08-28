//      /bin/dev/_replog.c

//      from the Nightmare Mudlib

//      Views the report log for the player named

//      created by Descartes of Borg 930623



#include <std.h>

#include <security.h>



inherit DAEMON;



int cmd_replog(string str) {

    int flag = 0;



    if(!str) {

      str = (string)this_player()->query_name();

      flag = 1;

    }

    str = "/log/reports/"+str;

    if(!file_exists(str)) {

        notify_fail("No such file: "+str+".\n");

        return 0;

    }

    if(flag) {

      this_player()->more(str);

      seteuid(UID_LOG);

      rm(str);

      return 1;

    }

    if(!tail(str)) {

        notify_fail("Failed to read file: "+str+".\n");

        return 0;

    }

    return 1;

}



void help() {

    write("Syntax: <replog [(logname)]>\n\n"

      "Tails the reports log of the immortal or domain named.\n"

      "If no immortal or domain is named, the report log is given\n"

      "for the person issuing the command.\n"

    );

}

