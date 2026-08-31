
#include <std.h>
#include <daemons.h>

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <expbonus>\n"
    "        <expbonus [percentage]>\n\n"
    "Displays or sets the current mud-wide exp bonus, as a percentage. "
    "100% is the default. Only those in the superuser group can set it.",
    this_player() );
}

int cmd_expbonus(string str) {
  object tp = this_player();
  int x;

  if (str && member_group(geteuid(tp), "superuser")) {
    x = to_int(str);
    if (!x) x = 100;
    ADVANCE_D->set_exp_bonus(x);
  }

  message("info", "Exp bonus: "+ADVANCE_D->query_exp_bonus()+"%", tp);

  return 1;
}
