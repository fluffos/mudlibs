//      /bin/user/_stats.c
//      from the Nightmare mudlib
//      lists a player's stats
//      created by Descartes of Borg 25 april 1993

#include <std.h>

inherit DAEMON;

#define BMAG "%^BOLD%^%^MAGENTA%^"
#define BGRE "%^BOLD%^%^GREEN%^"
#define RES  "%^RESET%^"

#define COLS 3
#define WIDTH 25

string *allstats = ({
  "strength", "constitution", "dexterity",
  "charisma", "intelligence", "wisdom",
});

string format_stat(object, string, int);

int cmd_stats(string str) {
  object tp = this_player();
  string out = "";

  if (!tp->query_race())
    return notify_fail("You do not yet have a body.\n");

  out += format_stat(tp, "strength", 8);
  out += format_stat(tp, "constitution", 12);
  out += format_stat(tp, "dexterity", 9);
  out += "\n";
  out += format_stat(tp, "charisma", 8);
  out += format_stat(tp, "intelligence", 12);
  out += format_stat(tp, "wisdom", 9);

  out = header_line("Stats") + "\n" + out + "\n" + header_line();

  message("info", out, tp);

  return 1;
}

void help() {
    message("help",
      "Syntax: <stats>\n\n"
      "Gives you a numerical representation of your genetically inherited "
      "physical traits.\n\nSee also: score, skills, status", this_player()
    );
}

string format_stat(object tp, string stat, int len) {
  string ret;
  ret = BMAG+ sprintf("%-*s", len, capitalize(stat)) +": "+RES;
  ret += tp->query_base_stats(stat);
  ret += " "+BMAG+"("+BGRE+ sprintf("%+d", tp->query_stat_bonus(stat)) + BMAG+")"+RES;
  ret = arrange_string(ret, WIDTH);
  return ret;
}
