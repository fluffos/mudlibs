#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_nextreboot(string str) {
  int rebootTime = (int)EVENTS_D->query_next_reboot();
  int timeleft = rebootTime - time();
  int days, hours, minutes, seconds;
  string timestr = "";
  string tzone = (string)this_player()->getenv("TZONE");
  tzone = (tzone && tzone != "") ? tzone : "PST";

  seconds = timeleft;
  days = seconds / 86400;
  seconds %= 86400;
  hours = seconds / 3600;
  seconds %= 3600;
  minutes = seconds / 60;
  seconds %= 60;
  if (days) timestr += days+" day"+(days!=1?"s":"")+" ";
  if (hours) timestr += hours+" hour"+(hours!=1?"s":"")+" ";
  if (minutes) timestr += minutes+" minute"+(minutes!=1?"s":"")+" ";
  if (seconds) timestr += seconds+" second"+(seconds!=1?"s":"");

  write("%^BLUE%^=+=+=%^BOLD%^(%^WHITE%^ Next Reboot "
    "%^BLUE%^)%^RESET%^%^BLUE%^+=+=+=+=+=+=+=+=+=+=+=+"
    "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+");

  write("Next reboot on "+ctime(gmt_time(rebootTime, tzone))+" ["
    +((tzone[0..0]!="+"&&tzone[0..0]!="-") ? tzone : "GMT "+tzone)+"]");
  write("("+(timeleft<0?"Now":timestr)+")");

  write("This mud reboots every "
    +cardinal(EVENTS_D->query_reboot_interval())+" hours.");
  write("%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+"
    "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
  return 1;
}

void help() {
  message("help", "Syntax: <nextreboot>\n\n"
   "Tells you when the mud is scheduled for its next reboot.",
   this_player()
  );
}
