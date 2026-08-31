
#include <std.h>
#include <daemons.h>

inherit DAEMON;

void init_languages(object);
string *all_languages();
string *all_races();


string *all_langs;


void create() {
  ::create();
}

void init_languages(object ob) {
  string race = ob->query_race();
  string lang;
  string tmp;

  lang = RACE_D->query_language(race);
  ob->set_primary_lang(lang);

  // this is not a very good way to go about this
  if (sscanf(race, "half-%s", tmp) == 1) {
    ob->set_lang_prof(RACE_D->query_language("human"), 6);
    ob->set_lang_prof(RACE_D->query_language(tmp), 6);
  }
  else {
    ob->set_lang_prof(lang, 10);
  }
}

string *all_languages() {
  string *races;
  string *langs;

  if (!sizeof(all_langs)) {
    all_langs = ({});
    races = all_races();

    langs = map(races, (: RACE_D->query_language($1) :) );

    foreach (string lang in langs)
      all_langs |= ({ lang });
  }
  
  return all_langs;
}

string *all_races() {
  return RACE_D->query_player_races();
}

