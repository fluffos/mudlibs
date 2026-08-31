
#include <std.h>

inherit SONG;

string myparty="";
int euph=0;

void create() {
  ::create();
  set_verses(({
    "Ignorance is bliss they say,",
    "And I would surely agree.",
    "For knowledge is the greatest burden",
    "That could be laid on me!",
    "Heed not the counsel of the wise,",
    "Forget their words and be free!"
  }));
  set_auto(0);
  set_type("detrimental");
  set_target_required(0);
  set_song_name("fools ballad");
}

int song() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "jester" &&
      tp->query_skill("euphony") >= 12*3)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <sing fools ballad>\n\n"
    "A whimsical song that can lower your foes' brainpower.",
    this_player() );
}

int check() {
  object tp = query_caster();
  euph = tp->query_skill("euphony");
  euph += tp->query_skill("entertainment")/3;
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

    resist = tgt->query_base_stats("wisdom");
    resist += tgt->query_base_stats("intelligence");
    resist += tgt->query_skill("perception")/2;
  
    bonus = euph - resist;
    if (bonus > 3) bonus = 3 + (bonus-3)/3;
    if (bonus > 5) bonus = 5 + (bonus-5)/4;
    if (bonus > 7) bonus = 7 + (bonus-7)/5;

    if (bonus < 2) bonus = 2;

    if (tgt->query_stat_bonus("wisdom") > -(tgt->query_base_stats("wisdom")/2))
      tgt->add_stat_bonus("wisdom", -bonus, time);
    if (tgt->query_stat_bonus("intelligence") > -(tgt->query_base_stats("intelligence")/2))
      tgt->add_stat_bonus("intelligence", -(bonus/2), time);
    tgt->add_mp(-(bonus*4));

  }

  if (round == 2)
    message("song", "You feel your knowledge leaking away.", tgts);
  if (round == 6)
    message("song", "You feel stupefied!", tgts);
  
}

void finish() {
  this_object()->performance(6);
  message("song", "%^CYAN%^You stupefy your audience!%^RESET%^", query_caster());
}
