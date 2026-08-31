#include <std.h>
#include <effect_cl.h>

#define COL "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

inherit SONG;

void create() {
  ::create();
  set_verses(({
    "Skulk in the back ways, creep through the door,",
    "Now, aye, they boast of their kills,",
    "They'll pilfer your purse and ransack your store,",
    "Then, aye, they make for the hills!",
  }));
  set_type("beneficial");
  set_auto(0);
  set_target_required(1);
  set_song_name("brigands shanty");
}

int song() {
  object o=this_player();
  if (o->query_subclass() == "bard" && o->query_skill("euphony") >= 32*6)
    return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <sing brigands shanty to [whom]>\n\n"
    "This dark song can make someone more sneaky.",
    this_player() );
}

void finish() {
  object tp = query_caster();
  object tgt = query_target();
  object env = environment(tp);
  string *skills = ({"stealing", "stealth", "agility", "knife"});
  int *amts = allocate(sizeof(skills));
  int y = 0;
  int time;
  float ratio;
  class Effect eff;

  if (!tgt || environment(tgt) != env) {
    message("info", "Nothing happens.", tp);
    return;
  }

  time = (5*60);
  time += 3*(tp->query_skill("entertainment")-(4*32));
  
  ratio = 0.1;
  ratio += to_float(tp->query_skill("euphony"))/(70*6);
  if (ratio > 1.0) ratio = 1.0 + (ratio-1.0)/3.0;

  for (int i = 0; i < sizeof(skills); i++) {
    string sk = skills[i];
    int amt;

    amts[i] = 0;

    if (!tgt->skill_exists(sk)) continue;
    if (!tgt->query_skill(sk)) continue;
    if (tgt->query_skill_bonus(sk)) continue;

    amt = tgt->query_skill(sk);
    amt *= ratio;
    
    tgt->add_skill_bonus(sk, amt);
    amts[i] = amt;

    y++;
  }

  if (!y) {
    message("song", "Nothing happens.", tp);
    return;
  }

  eff = new(class Effect);
  eff->name = "brigand's shanty";
  eff->desc = "Your sneaking skills are increased.";
  eff->caster = tp;
  eff->target = tgt;
  eff->castername = tp->query_name();
  eff->endtime = time()+time;
  eff->endmessages = ({
    "The inspiration of the brigand's shanty fades.",
    tgt->query_cap_name()+"'s sneaking inspiration fades."
  });
  eff->misc = amts;
  eff->endfunc = function(class Effect buff) {
    object tgt = buff->target;
    int stealing = buff->misc[0];
    int stealth = buff->misc[1];
    int agility = buff->misc[2];
    int knife = buff->misc[3];

    tgt->add_skill_bonus("stealing", -stealing);
    tgt->add_skill_bonus("stealth", -stealth);
    tgt->add_skill_bonus("agility", -agility);
    tgt->add_skill_bonus("knife", -knife);
  };

  tgt->add_effect(eff);
  message("song", COL+"You feel more sneaky."+RES, tgt);
  message("song", COL+tgt->query_cap_name()+" seems more sneaky."+RES, env, tgt);
}


