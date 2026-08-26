/*
** File: _monitor.c
** Purpose: Standard cmd to turn hp monitoring on and off.
** Credits:
**    22 July 97  Cyanide created the file.
*/

int cmd_monitor(string);
string help();

int cmd_monitor(string str) {
  
  if (!str) {
    if ((int)TP->query("monitor")>0) {
      write("Monitor: Your hp monitor is currently on.\n");
    } else {
      write("Monitor: Your hp monitor is currently off.\n");
    }
    return 1;
  }

  if (str!="on" && str!="off") {
    write(help());
    return 1;
  }

  switch (str) {
    case "on" : TP->set("monitor", 1); break;
    case "off" : TP->set("monitor", 0); break;
    default : write("Error: notify Cyanide.\n"); return 1; break;
  }

  write("Your hit point monitor has been turned "+str+".\n");
  return 1;
}

string help() {
  return @EndHelp
Syntax: monitor <on|off>

The monitor command turns on or off hit point monitoring.
Typing "monitor" without an argument gives you your current monitor
status.

See also: hp.
EndHelp
;
}
