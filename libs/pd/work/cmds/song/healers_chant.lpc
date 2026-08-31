#include <std.h>
#include <effect_cl.h>

#define COL "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

inherit SONG;

void create() {
  ::create();
  set_verses(({
    "Heal us, mend us, keep us strong -",
    "Shield us, defend us, from all wrong;",
    "Purge us, save us, if we stray -",
    "Cure us, convey us, night and day.",
  }));
  set_type("beneficial");
  set_auto(0);
  set_target_required(1);
  set_song_name("healers chant");
}

int song() {
  object o=this_player();
  if (o->query_subclass() == "bard" && o->query_skill("euphony") >= 28*6)
    return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <sing healers chant to [whom]>\n\n"
    "Singing this chant to someone will grant him better healing and faith.",
    this_player() );
}

void finish() {
  object tp = query_caster();
  object tgt = query_target();
  object env = environment(tp);
  string *skills = ({"magic defense", "healing", "faith", "belief"});
  int i = 0;
  int time;
  float ratio;

  if (!tgt || environment(tgt) != env) {
    message("info", "Nothing happens.", tp);
    return;
  }

  time = (5*60);
  time += 3*(tp->query_skill("entertainment")-(4*28));
  
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
    eff->name = "healer's chant";
    eff->desc = "Your healing skills are increased.";
    eff->caster = tp;
    eff->target = tgt;
    eff->castername = tp->query_name();
    eff->endtime = time()+time;
    eff->endmessages = ({
      "The inspiration of the healer's chant fades.",
      tgt->query_cap_name()+"'s healing inspiration fades."
    });
    tgt->add_effect(eff);
    message("song", COL+"Your healing skills seem to increase."+RES, tgt);
    message("song", COL+tgt->query_cap_name()+" seems more able."+RES, env, tgt);
  }
  else
    message("song", "Nothing happens.", tp);
}


