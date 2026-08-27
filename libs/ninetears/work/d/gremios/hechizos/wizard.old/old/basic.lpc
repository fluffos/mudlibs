/* standard spell object */
string name, spell_type, skill_used, full_name;
int min_lvl, xp_cost, duration;
string info;

int cast_me(string str) {
  int skill;
  mixed ret;
  object *ob;

  if(str) {
    sscanf(str, "on %s", str);
    sscanf(str, "at %s", str);
  }
  skill = (int)this_player()->query_skill_bonus(skill_used);
  if (skill < min_lvl) {
    write("You are not skillful enough.\n");
    return 1;
  }
  if ((int)this_player()->query_spell_effect(spell_type)) {
    write("You are already casting a spell.\n");
    return 1;
  }
  ob = find_match(str, environment(this_player()));
  this_player()->add_spell_effect(duration, spell_type, name, this_object(),
    ("heart_beat_" + name), ({ skill, ob, 1 }));
  write("You begin to cast " + full_name + ".\n");
  say(this_player()->query_cap_name() + " starts casting a spell.\n");
  return 1;
}

/* all the interesting set stuff */
string query_name() { return name; }
string set_name(string str) { return name = str; }

string query_full_name() { return full_name; }
string set_full_name(string str) { return full_name = str; }

string query_skill_used() { return skill_used; }
string set_skill_used(string str) { return skill_used = str; }

string query_spell_type() { return spell_type; }
string set_spell_type(string str) { return spell_type = str; }

int query_min_lvl() { return min_lvl; }
int set_min_lvl(int i) { return min_lvl = i; }

int query_xp_cost() { return xp_cost; }
int set_xp_cost(int i) { return xp_cost = i; }

int query_duration() { return duration; }
int set_duration(int i) { return duration = i; }

string query_info() { return info; }
string set_info(string str) { return info = str; }
