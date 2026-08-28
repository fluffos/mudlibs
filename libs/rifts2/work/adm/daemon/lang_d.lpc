// Language daemon create by Valodin as an experimental racial language
// reference
// revamped by Parnell 2019 - Rifts doesn't use race as a language consideration
inherit DAEMON;
string * language_list;

void create()
{
  ::create();
  language_list = ({"american",
  "techno-can",
  "spanish",
  "japanese",
  "chinese",
  "euro",
  "dragonese",
  "gobblely",
  "faerie"
  });
}

void init_languages(object ob)
{
  //TODO: setup some sort of region/race combination of things
  ob->set_lang_prof("american", 88,1);
  ob->set_primary_lang("american");
}

string *all_languages()
{
  return language_list;
}

