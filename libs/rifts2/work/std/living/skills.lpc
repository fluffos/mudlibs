//	/std/living/skills.c
//	from the Nightmare mudlib
//	code for the Nightmare skill system
//	created by Descartes of Borg 1september 1992
//	recoded 14 february 1993

#include <daemons.h>
#include <clock.h>

string char_class;
mapping skills;
mapping spells;
string primary_language;

void set_skill(string str, int x);
void set_last_use(string str);
int has_skill(string str);
int query_max_skill(string str);
int query_skill(string str);
void set_class(string str);
string query_class();

void create () {
  if(!skills)
    skills = ([]);
  if(!spells)
    spells = ([]);
}

int has_skill(string name) {
    return member_array(name, keys(skills)) != -1;
}

int spell_exists(string str) {
     if(!spells || undefinedp(spells[str])) return 0;
     return (member_array(str, keys(spells)) < 0)? 0:1;
}

int query_spell_level(string spell) {
    if(!spells || !spells[spell]) return 0;
    return (spells[spell]["level"] > 6)? 6:spells[spell]["level"];
}

int query_skill(string name) {
    if(!skills) {
      return 0;
    }
    if(undefinedp(skills[name]))
      return 0;
    return undefinedp(skills[name]["value"]) ? 0 : skills[name]["value"];
}

int query_skill_per_level(string name) {
     if(!skills) {
      return 0;
    }
    if(undefinedp(skills[name]))
      return 0;
    return undefinedp(skills[name]["per_level"]) ? 0 : skills[name]["per_level"];
}

int query_base_spell(string spell) {
    if(!spells || !spells[spell]) return 0;
    else if(!spells[spell]["level"] ||
      spells[spell]["level"] < 0) return 0;
    else return spells[spell]["level"];
}

void set_spell_level(string spell, int x) {
    if(!spells) spells = ([]);
    if(!spells[spell]) spells[spell] = ([]);
    if(x < 0 || x > 6) return;
    spells[spell]["level"] = x;
}

void delete_spell(string spell) {
    if(!spells || !spells[spell]) return;
    if(member_array(spell, keys(spells)) < 0) return;
    map_delete(spells,spell);
}

void set_last_use(string str) {
    if(!str) return;
    if(!skills) skills = ([]);
    if(skills[str])
      skills[str]["last use"] = time();
    return;
}

int query_last_use(string str) {
  if(!str) return 0;
  if(!skills || !skills[str]) return 0;
  if(!skills[str]["last use"]) skills[str]["last use"] = 0;
  return skills[str]["last use"];
}

varargs void set_skill(string name, int value, int per_level) {
    if(!skills)
      skills = ([]);
    if(!name)
      return;
    if(undefinedp(skills[name]))
      skills[name] = ([]);
    if(value)
      skills[name]["value"] = value;
    if(per_level)
      skills[name]["per_level"] = per_level;
}

void set_class(string str) { char_class = str; }

string query_class() { return char_class; }

varargs int add_skill(string name, int value, int per_level)
{
    if(has_skill(name))
      return 0;
    set_skill(name, value, per_level);
    return 1;
}

int delete_skill(string skill_name)
{
     if(!has_skill(skill_name)) return 0;
     map_delete(skills, skill_name);
     return 1;
}

string *query_all_skills() {
  return keys(skills);
}

mapping query_skills() {
  return skills;
}

string *query_all_spells() {
  if(mapp(spells)) return keys(spells);
  return ({});
}

string query_primary_lang() {
    if(!primary_language && living(this_object()) &&
      !this_object()->is_player()) return "american";
    return primary_language;
}

void set_primary_lang(string str) { primary_language = str; }


// language system added by Valodin in August 1993

int query_lang_prof(string lang)
{
    return this_object()->query_skill(sprintf("language: %s", lang));
}

varargs int set_lang_prof(string lang, int i, int per_level)
{
    set_skill(sprintf("language: %s", lang), i, per_level);
}

int is_language(string skill_name) {
  string language;
  return sscanf(skill_name, "language: %s", language) == 1;
}

string *query_all_languages()
{
    string *lang_skills = filter_array(query_all_skills(), "is_language");
    string *langs = ({});
    string language;
    for(int i = 0; i < sizeof(lang_skills);i++) {
      if(sscanf(lang_skills[i], "language: %s", language) == 1)
        langs += ({ language });
    }
    return langs;
}
