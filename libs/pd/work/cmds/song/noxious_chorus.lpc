
#include <std.h>
#include <daemons.h>

inherit SONG;

string myparty="";
int euph=0;

void create() {
  ::create();
  set_verses( ({
    "Once upon a time there lived a king who smelled like fish,",
    "And every courtier in his court could well attest to this,",
    "For twice a week the pungent king would give his men a talk,",
    "But his rancid stench could brown a rose and make a butcher balk,",
    "So one day his royal wife swore to wash off his ferment -",
    "And ever since, the fragrant queen has shared her husband's scent!",
  }) );
  set_auto(0);
  set_type("detrimental");
  set_target_required(0);
  set_song_name("noxious chorus");
}

int song() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "jester" &&
      tp->query_skill("euphony") >= 3*25)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <sing noxious chorus>\n\n"
    "This song causes a very strong smell of garbage to fill the area, "
    "affecting those around you.",
    this_player() );
}

int check() {
  object tp = query_caster();
  euph = tp->query_skill("euphony");
  euph += tp->query_skill("entertainment");
  myparty = tp->query_party();
  if (!myparty) myparty = "";
  return 1;
}

void performance(int round) {
  object tp = query_caster();
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

    resist = tgt->query_stats("constitution");
    resist += tgt->query_stats("intelligence");
    resist += tgt->query_skill("perception")/2;

    bonus = euph - resist;
    if (bonus > 3) bonus = 3 + (bonus-3)/3;
    if (bonus > 5) bonus = 5 + (bonus-5)/4;
    if (bonus > 7) bonus = 7 + (bonus-7)/5;
    if (bonus < 2) bonus = 2;

    if (tgt->query_stat_bonus("charisma") > -(tgt->query_base_stats("charisma")/2))
      tgt->add_stat_bonus("charisma", -bonus, time);
    if (tgt->query_skill_bonus("perception") > -(tgt->query_base_skill("perception")/2))
      tgt->add_skill_bonus("perception", -bonus, time);
    if (tgt->query_skill_bonus("stealth") > -(tgt->query_base_skill("stealth")/2))
      tgt->add_skill_bonus("stealth", -bonus, time);

    if (round == 3) {
      tgt->set_smell("default", capitalize(tgt->query_subjective())+
        " smells like garbage!");
      DELAY_D->add_delay(time, tgt, "remove_smell", ({ "default" }), 0);
    }
  }

  if (round == 2)
    message("song", "%^CYAN%^A terrible smell begins to waft into the room.%^RESET%^", env);
  if (round == 6)
    message("song", "The air thickens with the scent of rotting garbage.", env);

}

void finish() {
  this_object()->performance(6);
}
