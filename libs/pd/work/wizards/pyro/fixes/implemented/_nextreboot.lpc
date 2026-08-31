#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_nextreboot(string str) {
  int rebootTime = (int)EVENTS_D->query_next_reboot();
  int timeleft = rebootTime - time();
  string tzone = (string)this_player()->getenv("TZONE");
  tzone = (tzone && tzone != "") ? tzone : "PST";

  write("%^BLUE%^=+=+=%^BOLD%^(%^WHITE%^ Next Reboot "
    "%^BLUE%^)%^RESET%^%^BLUE%^+=+=+=+=+=+=+=+=+=+=+=+"
    "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+");

  write("Next reboot on "+ctime(gmt_time(rebootTime, tzone))+" ["
    +((tzone[0..0]!="+"&&tzone[0..0]!="-") ? tzone : "GMT "+tzone)+"]");
  write("("+(timeleft<0?"Now":timeleft+" seconds")+")");

  write("This mud reboots every "
    +cardinal(EVENTS_D->query_reboot_interval())+" hours.");
  write("%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+"
    "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
  return 1;
}

void help() {
  message("help", "Syntax: <reboot>\n\n"
   "Tells you when the mud is scheduled for its next reboot.",
   this_player()
  );
}
