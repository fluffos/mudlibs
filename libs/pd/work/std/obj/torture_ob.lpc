
#include <std.h>
#include <daemons.h>

#define COL "%^BOLD%^%^RED%^"
#define RES "%^RESET%^"

#define STAY_HERE "/d/nopk/tirun/square"

inherit OBJECT;

int not_allowed(string str);
void punish();
void decay_stats(string which);
void decay_level();
void decay_skills();

mixed *punishments = ({
  ({"decay_stats", "strength"}),
  ({"decay_stats", "dexterity"}),
  ({"decay_stats", "constitution"}),
  ({"decay_stats", "charisma"}),
  ({"decay_stats", "intelligence"}),
  ({"decay_stats", "wisdom"}),
  ({"decay_level"}),
  ({"decay_skills"}),
  ({"decay_skills"}),
  ({"decay_skills"}),
  ({"decay_skills"}),
  ({"decay_exp"}),
  ({"decay_exp"}),
  ({"decay_exp"}),
  ({"decay_exp"})
});

string *punish_these = ({
  "say", "emote", "tell", "emoteto", "reply",
  "speak", "shout", "yell", "whisper"
});

void create() {
  ::create();
  set_name("torture_ob");
  set_id( ({"torture_ob"}) );
  set_weight(0);
  set_value(0);
  set_long("What?");
  set_heart_beat(1);
}

void init() {
  ::init();
  add_action("not_allowed", "", 1);
}

void heart_beat() {
  object env=environment();
  string *p;
  if (env && env->is_player() && file_name(environment(env)) != STAY_HERE)
    if (random(100) < 35)
      punish();
}

int drop() { return 1; }

int not_allowed(string str) {
  object tp=this_player();
  string verb=query_verb();
  if (member_array(verb, punish_these) != -1 ||
      member_array(verb,tp->query_channels()) != -1 ||
      member_array(replace_string(verb,":",""),tp->query_channels()) != -1 ||
      member_array(replace_string(verb,"emote",""),tp->query_channels()) != -1 ||
      sizeof(load_object(SOUL_D)->query_atmos(verb)) >= 1)
        punish();
  return 0;
}

void punish() {
  object env=environment();
  if (env && env->is_player()) {
    string *p = punishments[random(sizeof(punishments))];
    call_other(this_object(), p);
    if (random(100) < 3)
      message("info", COL+"Your body and mind decay."+RES,env);
  }
}

void decay_stats(string st) {
  object env=environment();
  if (env && env->is_player() &&
      member_array(st, env->query_all_stats()) != -1 &&
      env->query_stats(st) > 1)
        env->set_stats(st, env->query_stats(st)-1);
}

void decay_level() {
  object env=environment();
  if (env && env->is_player()) {
    if (env->query_level() == 20 || env->query_level() == 1)
      return;
    env->set_level(env->query_level()-1);
  }
}

void decay_skills() {
  object env=environment();
  if (env && env->is_player()) {
    string *k = keys(env->query_skills());
    string sk = k[random(sizeof(k))];
    if (env->query_skill(sk) > 10)
      env->set_skill(sk, env->query_skill(sk)-10);
  }
}

void decay_exp() {
  object env=environment();
  if (env && env->is_player()) {
    if (env->query_exp() > env->query_level()*3000)
      env->add_exp(-(env->query_level()*3000));
  }
}

int query_auto_load() { return 1; }
