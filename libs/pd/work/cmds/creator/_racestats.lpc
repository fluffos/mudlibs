
#include <std.h>
#include <daemons.h>

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <racestats>\n"
    "        <racestats all>\n"
    "        <racestats [race1] [race2] [race...]>\n\n"
    "Displays the stat costs, as percentages, for each player race. "
    "The number in parentheses is the roll modifier (ignored for mobs).\n"
    "You can also ask for 'all' races (including monster body types), or for "
    "specific races.",
    this_player() );
}

int cmd_racestats(string str) {
  object tp = this_player();
  string *races;
  string out;
  int max = 0;

  if (!str || !strlen(str))
    races = RACE_D->query_player_races();
  else if (str == "all")
    races = RACE_D->query_races();
  else {
    races = ({});
    foreach (string r in explode(str, " ")) {
      if (RACE_D->is_race(r)) {
        races += ({ r });
      }
    }
    if (!sizeof(races)) {
      message("info", "No valid races found.", tp);
      return 1;
    }
  }

  out = header_line("Race Stats") + "\n";
  // complicated but fast way of finding the length of the longest race name
  races = map(races, function(string r, int ref max) {
    if (strlen(r) > max)
      max = strlen(r);
    return r;
  }, ref max );

  out += repeat_string(" ", max) + "       Str        Con        Dex        Cha        Int        Wis\n";
  out += "%^BLUE%^" + repeat_string("-", 77) + "%^RESET%^\n";

  races = sort_array(races, 1);
  foreach (string race in races) {
    out += sprintf("%-*s  %%^BLUE%%^|%%^RESET%%^  %3d (%+d)   %3d (%+d)   %3d (%+d)   %3d (%+d)   %3d (%+d)   %3d (%+d)\n",
      max, capitalize(race),
      RACE_D->query_stat_cost("strength", race),
      RACE_D->query_stat_roll("strength", race),
      RACE_D->query_stat_cost("constitution", race),
      RACE_D->query_stat_roll("constitution", race),
      RACE_D->query_stat_cost("dexterity", race),
      RACE_D->query_stat_roll("dexterity", race),
      RACE_D->query_stat_cost("charisma", race),
      RACE_D->query_stat_roll("charisma", race),
      RACE_D->query_stat_cost("intelligence", race),
      RACE_D->query_stat_roll("intelligence", race),
      RACE_D->query_stat_cost("wisdom", race),
      RACE_D->query_stat_roll("wisdom", race)
    );
  }

  out += header_line() + "\n";

  message("info", out, tp);

  return 1;
}

