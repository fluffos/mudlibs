
#include <std.h>

#define WRACKING_REEL_PROP "wracking_reel_song_skill"

inherit SONG;

string myparty="";
int euph=0;

void create() {
  ::create();
  set_verses(({
    "Oh, dance a jig for the bonnie lasses!",
    "Dance a jig for the laddies too!",
    "Well dance a jig for the greenest grasses,",
    "And a jig for the morning dew!",
    "Oh, dance a jig a'fore the moment passes,",
    "Dance a jig a'fore your time is through!"
  }));
  set_auto(0);
  set_type("detrimental");
  set_target_required(0);
  set_song_name("wracking reel");
}

int song() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "jester" &&
      tp->query_skill("euphony") >= 19*3)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <sing wracking reel>\n\n"
    "This enchanting song causes everyone in the audience to dance as hard as they can, tiring themselves.",
    this_player() );
}

int check() {
  object tp = query_caster();
  euph = tp->query_skill("euphony")*4/5;
  euph += tp->query_skill("entertainment")/2;
  myparty = tp->query_party();
  if (!myparty) myparty = "";
  return 1;
}

void performance(int round) {

  object tp=query_caster();
  object env = environment(tp);
  object *tgts;
  int time;

  tgts = filter(all_inventory(env),
    function(object t, string p) {
      string party;
      object own;
      if (!$1->is_living())
        return 0;
      if ($1 == query_caster())
        return 0;
      if (objectp(own = $1->query_owner()) && own == query_caster())
        return 0;
      if (strlen(p) && strlen(party = $1->query_party()) && party == p)
        return 0;
      return 1;
    }, myparty);

  time = tp->query_skill("euphony")/2;
  time -= round*2;
    
  foreach (object tgt in tgts) {
    int resist;
    int bonus;
    string ranskill;

    if (round == 1) {
      ranskill = tgt->query_all_skills()[random(sizeof(tgt->query_all_skills()))];
      tgt->set(WRACKING_REEL_PROP, ranskill);
    }
    else
      ranskill = tgt->query(WRACKING_REEL_PROP) || "attack";

    resist = tgt->query_base_stats("constitution");
    resist += tgt->query_base_stats("intelligence");
    resist += tgt->query_skill("perception")/2;
  
    bonus = euph - resist;
    if (bonus > 3) bonus = 3 + (bonus-3)/3;
    if (bonus > 5) bonus = 5 + (bonus-5)/4;
    if (bonus > 7) bonus = 7 + (bonus-7)/5;

    if (bonus < 2) bonus = 2;

    if (tgt->query_stat_bonus("strength") > -(tgt->query_base_stats("strength")/2))
      tgt->add_stat_bonus("strength", -bonus, time);
    if (tgt->query_skill_bonus(ranskill) > -(tgt->query_base_skill(ranskill)/2))
      tgt->add_skill_bonus(ranskill, -(bonus*2), time);
    tgt->add_sp(-(bonus*3));

  }

  if (round == 1 || round == 3 || round == 5)
    message("song", "You dance as fast as you can, your feet moving swiftly!", tgts);
  if (round == 6)
    message("song", "You feel very tired.", tgts);
  
}

void finish() {
  this_object()->performance(6);
  message("song", "%^CYAN%^Everyone seems quite tired.%^RESET%^", query_caster());
}
