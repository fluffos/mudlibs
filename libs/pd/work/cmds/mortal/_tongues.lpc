
#include <std.h>
#include <daemons.h>

#define COL "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <tongues>\n\n"
    "Lists the languages spoken by the different races.\n\n"
    "See also: languages, speak, shout",
    this_player() );
}

int cmd_tongues(string str) {
  string *races = sort_array(RACE_D->query_player_races(), 1);
  string out = header_line("Tongues") + "\n";

  races = map(races, (:
    COL+capitalize(pluralize($1))+RES+" speak "+
    COL+capitalize(RACE_D->query_language($1))+RES+"."
  :) );

  out += format_page(races, 2);
  out += header_line()+"\n";

  message("info", out, this_player() );

  return 1;
}

