/*
 * This note is for long output done by the inet daemon as by remote who or
 * remote locate.
 * by Alfe for Tubmud 1996-Feb-26
 */

#include <prop/item.h>
#include <udp.h>
#include <grammar.h>
#include <persistence.h>  // Coogan, 27-Jul-1998

inherit "basic/parser";
inherit "complex/item";

#define RESULT_FAILED_REQUESTS   "Failed Requests"
#define RESULT_NOBODY_LISTENING  "Nobody Listening"
#define RESULT_NO_SUCH_CHANNEL   "No Such Channel"
#define RESULT_NO_SUCH_PLAYER    "No Such Player"
#define RESULT_PLAYER_NOT_ONLINE "Player Not Online"
#define RESULT_TIMEOUTS          "Timeouts"

string text = "";
string title;
mapping results;

void set_title(string s) {
  title = s;
}

string get_text() {
  mixed h;

  h = map(m_indices(results),
                (: break_string($1 + ": " + implode(sort_array($2[$1], #'>),
                                                    ", "),0,2,-1) :),
                results);
  h = implode(h,"\n");
  if (text == "")
    return h + "\n";
  return (h + "\n"
          "Unparsed Replies:\n" +
          text);
}

void set_text(string t) {
  text = t;
}

string my_long() {
  string result;
  string text;
  result = ("A magic note on which the Inet Daemon writes thin spidery lines"
            " while you hold it. " +
            (title? "The note's title is \"" + title + "\". " :
             "The note's got no title. "));
  // check whether there is a title at all,
  // Chameloid, 18-Dec-1996
  text = get_text();
  if (strlen(text) < 500) {  // short text
    result += (strlen(text)?
               "It contains some text that vanishes as you read it:\n" +
               text :
               "It is empty.\n");
    set_text("");
  }
  else  // long text
    result += "It contains a lot of text. Read the note.\n";
  return result;
}

void configure() {
  item::configure();
  set_short("note");
  set_id(({ "note","magic note","inet note","inetd note" }));
  set_long(#'my_long);
  set_persistence(PER_NO_PERSISTENCE);  // Coogan, 27-Jul-1998
  set_property(P_DESTRUCT_ON_DROP);
  add_rule("read "G_ME,"read");
  add_error_message("read","Read the note?\n"); // Chameloid, 18-Dec-1996
  if (!results)
    results = ([ ]);  // Coogan, 12-Jul-2001
}

void init() {
  add_actions();
}

status do_action(string action,mapping args) {
  switch (action) {
  case "read":
    this_player()->view_text(get_text(),title);
    this_player()->start_view();
    return 1;
  }
}

void add_result(string key,string mud) {
  if (!results)
    results = ([]);
  if (results[key])
    results[key] += ({ mud });
  else
    results[key] = ({ mud });
}

void udp_reply(mapping data) {
  mixed h;
  string mud,h1,h2;

  if (data[SYSTEM]) {
    switch(data[SYSTEM]) {
    case TIME_OUT:
#if 1
      add_result(RESULT_TIMEOUTS,
                 (data[RECIPIENT] ?
                  capitalize(data[RECIPIENT]) + "@" + data[NAME] :
                  data[NAME]));
#else
      text += (capitalize(data[REQUEST]) + " request to " +
               (data[RECIPIENT] ?
                capitalize(data[RECIPIENT]) + "@" + data[NAME] :
                data[NAME]) + " timed out.\n");
#endif
      break;
    default:
      // maybe raise an error here?  unfortunately we have no warning
      // mechanism in LPC :-/
    }
  }
  else {
    if (intp(data[DATA]))  // sometimes DATA=0, Coogan. 29-May-2005
      data[DATA] = "\n";
    if (data[DATA][<1] != '\n')  // Coogan, 12-Jul-2001
      data[DATA] += "\n";
    // rules for channel list query (remote wiz?intermud)
    if (sscanf(lower_case(data[DATA]),"channel request failed @%s.\n%s",
               mud,h) == 2 && h == "")
      add_result(RESULT_FAILED_REQUESTS,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),"invalid request @%s: %s\n%s",
                    mud,h1,h) == 3 && h == "")
      add_result(RESULT_FAILED_REQUESTS,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),"%s request failed @%s.\n%s",
                    h1,mud,h) == 3 && h == "")
      add_result(RESULT_FAILED_REQUESTS,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),"[%s@%s] nobody listening.\n%s",
                    h1,mud,h) == 3 && h == "")
      add_result(RESULT_NOBODY_LISTENING,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),"%snobody listening%s\n%s",
                    mud,h1,h) == 3 && h == "")
      add_result(RESULT_NOBODY_LISTENING,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),
                    "%s: channel %s (no listeners).\n%s",mud,h1,h) == 3 &&
             h == "")
      add_result(RESULT_NOBODY_LISTENING,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),"%s: no such channel.\n%s",
                    mud,h) == 2 && h == "")
      add_result(RESULT_NO_SUCH_CHANNEL,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),"no such channel: %s@%s\n%s",
                    h1,mud,h) == 3 && h == "")
      add_result(RESULT_NO_SUCH_CHANNEL,data[NAME]);
    // rules for locate (remote locate pengo)
    // no such player:
    else if (sscanf(lower_case(data[DATA]),
                    "[locate@%s] %s does not exist.\n%s",
                    mud,h1,h) == 3 && h == "")
      add_result(RESULT_NO_SUCH_PLAYER,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),"locate@%s: no such player: %s\n%s",
                    mud,h1,h) == 3 && h == "")
      add_result(RESULT_NO_SUCH_PLAYER,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),
                    "%s: %s gibt es hier gar nicht.\n%s",
                    mud,h1,h) == 3 && h == "")
      add_result(RESULT_NO_SUCH_PLAYER,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),"no such player.\n%s",h) == 1 &&
             h == "")
      add_result(RESULT_NO_SUCH_PLAYER,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),
                    "locate@%s: %s gibt es hier gar nicht.\n%s",
                    mud,h1,h) == 3 && h == "")
      add_result(RESULT_NO_SUCH_PLAYER,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),
                    "locate@%s: %s: not known\n%s",
                    mud,h1,h) == 3 && h == "")
      add_result(RESULT_NO_SUCH_PLAYER,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),
                    "%s: no such player \"%s\".\n%s",
                    mud,h1,h) == 3 && h == "")
      add_result(RESULT_NO_SUCH_PLAYER,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),
                    "%s: %s is not a known player here.\n%s",
                    mud,h1,h) == 3 && h == "")
      add_result(RESULT_NO_SUCH_PLAYER,data[NAME]);
    // player not online:
    else if (sscanf(lower_case(data[DATA]),"player not logged on.\n%s",
                    h) == 1 && h == "")
      add_result(RESULT_PLAYER_NOT_ONLINE,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),
                    "%s: %s ist gerade nicht eingeloggt.\n%s",
                    mud,h1,h) == 3 && h == "")
      add_result(RESULT_PLAYER_NOT_ONLINE,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),
                    "locate@%s: no such player online%s\n%s",
                    mud,h1,h) == 3 && h == "")
      add_result(RESULT_PLAYER_NOT_ONLINE,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),
                    "locate@%s: %s found but he/she isn't logged in currently."
                    "\n%s",mud,h1,h) == 3 && h == "")
      add_result(RESULT_PLAYER_NOT_ONLINE,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),
                    "locate@%s: %s: known but not logged in\n%s",
                    mud,h1,h) == 3 && h == "")
      add_result(RESULT_PLAYER_NOT_ONLINE,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),
                    "locate@%s: %s: known but not logged in\n%s",
                    mud,h1,h) == 3 && h == "")
      add_result(RESULT_PLAYER_NOT_ONLINE,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),
                    "locate@%s: %s not logged on.\n%s",
                    mud,h1,h) == 3 && h == "")
      add_result(RESULT_PLAYER_NOT_ONLINE,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),
                    "locate@%s: %s found, but not logged in.\n%s",
                    mud,h1,h) == 3 && h == "")
      add_result(RESULT_PLAYER_NOT_ONLINE,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),
                    "%s: %s not logged on.\n%s",
                    mud,h1,h) == 3 && h == "")
      add_result(RESULT_PLAYER_NOT_ONLINE,data[NAME]);
    else if (sscanf(lower_case(data[DATA]),
                    "locate@%s: %s ist gerade nicht eingeloggt.\n%s",
                    mud,h1,h) == 3 && h == "")
      add_result(RESULT_PLAYER_NOT_ONLINE,data[NAME]);
    // standard behaviour:
    else  // else block follows after #endif
      text += sprintf("%'-'|78s\n"," " + data[NAME] + " ") + data[DATA];
  }
}

