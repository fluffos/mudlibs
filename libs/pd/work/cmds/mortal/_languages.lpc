
#include <std.h>
#include <daemons.h>

#define COL "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

inherit DAEMON;

string get_prof(object tp, string lang);

void help() {
  message("help",
    "Syntax: <languages>\n\n"
    "Lists the languages you can speak and your proficiency in each.\n\n"
    "See also: tongues, speak, shout",
    this_player() );
}

int cmd_languages(string str) {
  object tp = this_player();
  string race = tp->query_race();
  string *langs;
  string out;

  if (!race)
    return notify_fail("You must pick a race first.");
  
  langs = sort_array(LANG_D->all_languages(), 1);

  out = header_line("Languages") + "\n";
  out += "%^BOLD%^%^WHITE%^Your primary language is "+
         COL+capitalize(tp->query_primary_lang())+
         "%^BOLD%^%^WHITE%^."+RES+"\n";
  out += header_line() + "\n";

  langs = map(langs, (:
    arrange_string(COL+capitalize($1), 10)+" : "+RES+get_prof($2, $1)
  :), tp );

  out += format_page(langs, 2);

  out += header_line();

  message("info", out, tp);

  return 1;
}

string get_prof(object tp, string lang) {
  switch (tp->query_lang_prof(lang)) {
    default:
    case 0:
      break; // so we get Unknowledgeable
    case 1:
      return "Stuttering";
    case 2:
    case 3:
      return "Learning";
    case 4:
    case 5:
      return "Moderate";
    case 6:
    case 7:
      return "Proficient";
    case 8:
    case 9:
      return "Skilled";
    case 10:
      return "Fluent";
  }
  return "Unknowledgeable";
}

