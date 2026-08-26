/*
**  File: _whenreboot.c
**  Purpose: A standard cmd.  Returns the time left to the next reboot
**           in seconds.
**  Credits:
**    17 Jun 97    Cyanide created the file.
** (04-06-98) Chronos adds a help() function.
*/

#include <config.h>
#include <daemons.h>
#include <mudlib.h>

inherit DAEMON;

int cmd_whenreboot() {
  int x, hour = 0, min = 0, sec = 0;
  string obname;
  mixed *callouts;

  callouts = call_out_info();
  x = sizeof(callouts);

  sec = (int)SHUTDOWN_D->query_shutdown();
  if (!sec) {
    while (x--) {
      catch(obname = file_name(callouts[x][0]));
      if ((obname=="/adm/daemons/rebootd") &&
        ((string)callouts[x][1] == "doomsday"))
        sec = ((int)callouts[x][2] + 3600);
    }
  } else {
    sec = (sec - time());
    write ("A shutdown is currently in progress.\n");
  }

  if (sec > -1) {
    hour = (sec/3600);
    sec = (sec%3600);
    min = (sec/60);
    sec = (sec%60);
  } else {
    write ("There is no reboot currently scheduled.\n");
    return 1;
  }

  write ("Next reboot: ");
  if (hour > 0) {
    if (hour==1) {
      write(hour+" hour");
    } else {
      write (hour+" hours");
    }
    if ((!min) && (!sec)) {
      write("There is no reboot currently scheduled.\n");
      return 1;
    } else {
      if ((!min) || (!sec)) {
        write (" and ");
      } else {
        write (", ");
      }
    }
  }

  if (min > 0) {
    if (min==1) {
      write (min+" minute");
    } else {
      write (min+" minutes");
    }
    if (!sec) {
      write (" exactly.\n");
    } else {
      if (!hour) {
        write (" and ");

     } else {
       write (", and ");
      }
    }
  }

  if (sec) {
    if (sec==1) {
      write (sec+" second.\n");
    } else {
      write(sec+" seconds.\n");
    }
  } else {
    write("There is no reboot currently scheduled.\n");
    return 1;
  }

  return 1;
}

string help() {
  return @ENDHELP
Usage: whenreboot

This command tells you when the next reboot is scheduled for.
ENDHELP
  ;
}
