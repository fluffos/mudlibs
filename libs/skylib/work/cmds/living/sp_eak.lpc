
inherit COMMAND_BASE;
#include <language.h>

int cmd(string which) {
  string *langs, skill;
  int i;
  mapping skills;

  skills = TP->query_skills();
  if (!which) {
    langs = LANGUAGE_HAND->query_languages();
    for (i = 0; i < sizeof(langs); i++) {
      if (TP->query_skill(
               LANGUAGE_HAND->query_language_spoken_skill(langs[i])) > 1 ||
          TP->query_skill(
               LANGUAGE_HAND->query_language_written_skill(langs[i])) > 1) {
      } else {
        langs = langs[0..i-1] + langs[i+1..];
        i--;
      }
    }
    write("You are currently speaking " + TP->query_current_language() +
          ".\n");
    write("You can speak "+query_multiple_short(map(langs, (: capitalize :)) +
           ({ "Grunt" }) )+".\n");
    write("Please note that the language you are speaking is used for "
          "writing as well, so some of the languages may be just written.\n");
    return 1;
  }

  which = lower_case(which);
  skill = LANGUAGE_HAND->query_language_spoken_skill(which);
  
  if (!skill) {
    return notify_fail("You cannot speak that language.\n");
  }
  
  if (!TP->query_skill(skill) &&
      which != "grunt") {
    return notify_fail("You don't know that language.\n");
  }
  
  if(!TP->set_language(which)) {
    return notify_fail("Argh... something weird happened.\n");
  }

  write("Now using " + which + " for speaking and writing.\n");
  return 1;
} /* cmd() */

mixed *query_patterns() {
  return ({ (TP->query_womens_day()?"wommon":"{" +
            implode(LANGUAGE_HAND->query_languages(), "|") + "}"),
            (: cmd(implode($4, " ")) :),
            "", (: cmd(0) :) });
} /* query_patterns() */
