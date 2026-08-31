#include <std.h>
#include <rest.h>

#define PILLOW "/d/nopk/standard/obj/misc/pillow"

inherit SONG;

void create() {
  ::create();
  set_verses(({
    "Ariel the Queen of Fae",
    "Spreads her sleeping dust all day;",
    "And all the night her princes work,",
    "And in the dark her workers lurk,",
    "To make you dream of damp and murk -",
    "They laugh and dance when down you lay!"
  }));
  set_type("detrimental");
  set_auto(0);
  set_target_required(0);
  set_song_name("lullaby of sylphs");
}

int song() {
  object o=this_player();
  if (o && o->query_subclass() == "bard" && o->query_skill("euphony") >= 30*6)
    return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <sing lullaby of sylphs>\n\n"
    "This magical song puts your audience to sleep.",
    this_player() );
}

int check() {
  object tp=query_caster();
  if (!tp) return 0;

  tp->clean_up_attackers();
  if (tp->query_current_attacker())
    return notify_fail("You are too busy fighting.\n");

  return 1;
}

void performance(int round) {
  switch (round) {
    case 3:
      message("song", "You start to feel drowsy.",
        environment(query_caster()), query_caster() );
      break;
    default:
  }
}

void finish() {

  object tp=query_caster();
  object env=environment(tp);
  object *tgts;
  string party=tp->query_party();
  
  if (env->query_property("no magic"))
    return;

  tgts = filter(all_inventory(env)-({tp}),
    function(object who, string party) {
      string p;
      if (!who->is_living()) return 0;
      if (who->query_rest_type() == SLEEP) return 0;
      p=who->query_party();
      if (sizeof(party) && sizeof(p) && p==party) return 0;
      return 1;
    }, party);
  
  foreach (object tgt in tgts) {
    if ((tgt->query_stats("wisdom")+tgt->query_skill("perception")/3) >
        (tp->query_skill("euphony")/3+tp->query_stats("charisma"))) {
          continue;
    }
    else {
      message("song", "You fall fast asleep.",tgt);
      message("song", tgt->query_cap_name()+" slumps down and falls asleep.",
        environment(tgt), tgt);
      tgt->set_rest_type(SLEEP);
      new(PILLOW)->move(tgt);
    }
  }
}

