
#include <std.h>
#include <daemons.h>

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <mraces>\n"
    "        <mraces [race]>\n\n"
    "Lists the available body types for monsters.\n"
    "If given an argument, displays body type aliases for that race.",
    this_player() );
}

int cmd_mraces(string str) {
  object tp = this_player();
  string *races;

  if (str) {
    races = RACE_D->query_aliases(str);
    if (sizeof(races)) {
      message("info",
        header_line("Body Type Aliases: "+str)+"\n"+
        format_page(races, 2)+
        header_line(),
        tp
      );
    }
    else
      message("info", "No body type aliases for \""+str+"\".", tp);
    return 1;
  }
  
  races = RACE_D->query_races();
  races = map(races, function(string race) {
    string *aliases = RACE_D->query_aliases(race);
    if (sizeof(aliases))
      return race+"*";
    return race;
  } );
  races = sort_array(races, 1);
  message("info",
    header_line("Body Types")+"\n"+
    "Those with a * have aliases, <mraces race> will display them\n"+
    header_line()+"\n"+
    format_page(races, 4)+
    header_line(),
    this_player()
  );
  return 1;
}
