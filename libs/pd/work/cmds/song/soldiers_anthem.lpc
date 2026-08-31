#include <std.h>
#include <effect_cl.h>

#define COL "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

inherit SONG;

void create() {
  ::create();
  set_verses(({
    "A soldier's life is by the sword,",
    "His pike turns out the deadly blow,",
    "An arrow true protects his fort,",
    "The mighty axe destroys his foe."
  }));
  set_type("beneficial");
  set_auto(0);
  set_target_required(1);
  set_song_name("soldiers anthem");
}

int song() {
  object o=this_player();
  if (o->query_subclass() == "bard" && o->query_skill("euphony") >= 20*6)
    return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <sing soldiers anthem to [whom]>\n\n"
    "This song can improve your allies' weapon proficiencies.",
    this_player() );
}

void finish() {
  object tp = query_caster();
  object tgt = query_target();
  object env = environment(tp);
  string *skills = ({"axe", "blade", "projectile", "ranged"});
  int i = 0;
  int time;
  float ratio;

  if (!tgt || environment(tgt) != env) {
    message("info", "Nothing happens.", tp);
    return;
  }

  time = (5*60);
  time += 3*(tp->query_skill("entertainment")-(4*20));
  
  ratio = 0.1;
  ratio += to_float(tp->query_skill("euphony"))/(70*6);
  if (ratio > 1.0) ratio = 1.0 + (ratio-1.0)/3.0;

  foreach (string sk in skills) {
    int amt;

    if (!tgt->skill_exists(sk)) continue;
    if (!tgt->query_skill(sk)) continue;
    if (tgt->query_skill_bonus(sk)) continue;

    amt = tgt->query_skill(sk);
    amt *= ratio;
    
    tgt->add_skill_bonus(sk, amt, time);

    i++;
  }

  if (i) {
    class Effect eff = new(class Effect);
    eff->name = "soldier's anthem";
    eff->desc = "Your weapons skills are increased.";
    eff->caster = tp;
    eff->target = tgt;
    eff->castername = tp->query_name();
    eff->endtime = time()+time;
    eff->endmessages = ({
      "The inspiration of the soldier's anthem fades.",
      tgt->query_cap_name()+"'s arms inspiration fades."
    });
    tgt->add_effect(eff);
    message("song", COL+"Your skill with weapons seems to increase."+RES, tgt);
    message("song", COL+tgt->query_cap_name()+" seems more skilled with "+tgt->query_possessive()+" weapons."+RES, env, tgt);
  }
  else
    message("song", "Nothing happens.", tp);
}


