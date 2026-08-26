/*
** File _idle.c
** Purpose: Cyanide discovered "idlemsg".
** Credits
**   31 July 97   Cyanide created the file.
**   ?? ???? 96   Chronos seems to remember making idlemsg.
**   04 Aug  99   Chronos adds a help function.
*/

#include <mudlib.h>

int cmd_idle (string idle) {

  if (!idle) {
    idle = TP->query("idlemsg");
    if (!idle) {
      write("You currently have no idle message set.\n");
      return 1;
    } else {
      write(wrap("Your idle message is: "+idle));
      return 1;
    }
  }

  if (idle=="purge") {
    write("Idle message purged.\n");
    TP->delete("idlemsg");
    return 1;
  }

  if (strlen(idle) > 150) {
    write("Message is too long...  please keep to under 150 characters.\n");
    return 1;
  }

  TP->set("idlemsg", idle);
  write(wrap("You set your idle message to: "+idle));
  return 1;
}

string help() {
  return @ENDHELP
Usage: idle [<msg> or purge]

This command will set your character as being idle, and you can
leave a msg for people trying to get ahold of you via the tell command.
If you want to erase your idle msg, use "purge" as the argument.

ENDHELP
  ;
}
