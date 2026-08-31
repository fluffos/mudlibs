
#include <std.h>
#include <daemons.h>
#include <rest.h>

#define FAIL(s) return notify_fail(s);

#define COL "%^YELLOW%^"
#define COL2 "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

#define PILLOW "/d/nopk/standard/obj/misc/pillow"

// three real-life days
#define HOW_OFTEN 60*60*24*3

inherit DAEMON;

string *player_unressable = ({
  "dragon",
  "vampire",
  "lich"
});

string *corpse_unressable = ({
  "demon",
  "archangel",
  "dragon",
  "vampire",
  "lich",
});

int query_ready(object tp);

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "cleric" &&
      tp->query_skill("healing") >= 50*6 &&
      tp->query_skill("belief") >= 50*6 &&
      tp->query_skill("faith") >= 50*6)
        return 1;
  return 0;
}

string type() { return "healing"; }

void help() {
  message("help",
    "Syntax: <resurrect [who]>\n\n"
    "Some very faithful and powerful clerics can resurrect "
    "the soul of a fallen comrade into the original body or "
    "another empty body. Reviving someone from death is very "
    "taxing and can only be done on occasion. Entering <resurrect> will give a general idea how long until you can use it again.",
    this_player() );
}

int can_cast(object tp, object tgt, object corpse) {
  object env;

  if (!tp) return 0;

  env=environment(tp);

  if (env->query_property("no magic"))
    FAIL("Some power keeps you from casting this.\n");

  if (tp->query_ghost())
    FAIL("You're far too dead to do that.\n");

  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers.\n");
  
  if (!tgt) {
    if (!query_ready(tp)) return 0;
    else return notify_fail("Your power of resurrection is ready.");
  }

  if (!living(tgt))
    FAIL("That was never alive in the first place.\n");

  if (!userp(tgt))
    FAIL("You may only resurrect players.\n");

  if (tgt == tp)
    FAIL("You can't resurrect yourself!\n");
  
  if (!(tgt->query_ghost()))
    FAIL(capitalize(tgt->query_subjective())+" is already alive.\n");

  if (!objectp(corpse))
    FAIL("There is no empty body here in which to house the soul.\n");

  if (member_array(tgt->query_race(), player_unressable) != -1)
    FAIL("The soul of a "+tgt->query_race()+" cannot be resurrected.\n");

  if (member_array(corpse->query_old_race(), corpse_unressable) != -1)
    FAIL(capitalize(corpse->query_old_race())+" bodies cannot hold a new soul.\n");

  return 1;
}

int cmd_resurrect(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  object corpse;
  object *tmp;
  int cost=1000;

  if (!spell()) return 0;

  if (str)
    tgt=find_player(str);

  tmp=filter(all_inventory(env), (: $1->query_corpse() :) );
  if (sizeof(tmp))
    corpse = tmp[0];

  if (!can_cast(tp, tgt, corpse)) return 0;

  if (tp->query_mp() < cost)
    FAIL("You need more magic power for that.\n");

  tp->add_mp(-(cost+random(cost/12)));

  message("magic", "You pray to the gods.", tp);
  message("magic", tp->query_cap_name()+" mutters a prayer.", env, tp);

  message("magic", COL+"A bright "+COL2+"white light"+COL+" surrounds "+
          corpse->query_short()+"!", env);
  message("magic", COL+"A bright "+COL2+"white light"+COL+" surrounds "+
          tgt->query_cap_name()+"!", environment(tgt), tgt);
  message("magic", COL+"A bright "+COL2+"white light"+COL+" surrounds you!",
          tgt);
  
  call_out("do_res", 6, ({tp, tgt, corpse}) );
  tp->set_paralyzed(6, "You are busy trying to resurrect somebody.");
  
  return 1;
}

void do_res(mixed *args) {
  object tp=args[0];
  object tgt=args[1];
  object corpse=args[2];
  object env;
  string prace, crace;
  int xp, xpmod;

  if (!tp || !tgt || !corpse) return;

  env=environment(tp);
  
  // this is here before the failure part on purpose
  tp->set_hp(5+tp->query_max_hp()/10);
  tp->set_sp(5+tp->query_max_sp()/10);
  tp->set_mp(5+tp->query_max_mp()/10);

  crace = corpse->query_old_race();
  prace = tgt->query_race();

  // if corpse is a non-player race then fail
  if (member_array(crace, RACE_D->query_races()) == -1) {
    message("magic", COL+"The light vanishes abruptly."+RES,
      ({ env, environment(tgt) }) );
    return;
  }

  message("magic", COL+"A "+COL2+"flash"+COL+" of light pulls "+
    tgt->query_cap_name()+"'s "+COL2+"soul"+COL+" into the body!", tp);
  message("magic", COL+"A force suddenly "+COL2+"yanks"+COL+
    " on your incorporeal form and your senses "+COL2+"fade"+COL+" away."+RES,
    tgt);
  message("magic", COL+"A "+COL2+"flash"+COL+" of light fills the area!"+RES,
    env, ({tp, tgt}) );

  if (crace != prace) {
    foreach (string st in tgt->query_all_stats()) {
      // reduce stats if changing races, the worse the new race is at the stat,
      // the lower the percentage to multiply by
      float mod = 8500.0/ADVANCE_D->get_race_change(crace, st, 10000);
      // every 5 levels of maxed healing gives a bit higher percentage
      float tmp = ((tp->query_skill("healing")-(50*6))/(5*6))*0.02;
      if (tmp > 0.08) tmp=0.08;
      tgt->set_stats(st, to_int(tgt->query_base_stats(st)*mod) );
      if (tgt->query_base_stats(st) < 1) tgt->set_stats(st, 1);
    }
  }

  // more wisdom gives back more exp, xpmod==3 is exactly the amount
  // that was lost upon death (as of this writing)
  xpmod = 6-(tp->query_stats("wisdom")/75);
  if (xpmod < 3) xpmod=3;
  xp = tgt->query_exp()/xpmod;
  tgt->add_exp(xp);

  tgt->move(env);
  tgt->set_race(crace);
  tgt->set_gender(corpse->query_gender());
  tgt->new_body();
  tgt->set_ghost(0);
  tgt->set_heart_beat(1);
  tgt->fix_skills();
  tgt->set_heal_rate(2);
  tgt->fix_vital_bonus();
  tgt->set_hp(5+tgt->query_max_hp()/10);
  tgt->set_sp(5+tgt->query_max_sp()/10);
  tgt->set_mp(5+tgt->query_max_mp()/10);
  tgt->save_player(tgt->query_name());
  tgt->set_rest_type(SLEEP);
  new(PILLOW)->move(tgt);

  foreach (object thing in all_inventory(corpse))
    if (thing->move(tgt))
      thing->move(env);
  corpse->remove();

  tp->remove_property("resurrect_spell");
  tp->set_property("resurrect_spell", time());
  tp->add_skill_points("healing", xp/20);

}

int query_ready(object tp) {
  int last = tp->query_property("resurrect_spell");
  int bonus = ((tp->query_skill("faith")-(50*6))/(1*6))*60*60;
  int time_to_next = HOW_OFTEN - bonus;
  int elapsed = time() - last;
  int perc = elapsed * 100 / time_to_next;

  if (perc >= 100 || last == 0) return 1;

  if (perc < 0) perc = 0;

  switch (perc) {
    case 0..24:
      return notify_fail("Your power has not yet begun to recover.");
    case 25..49:
      return notify_fail("Your power is beginning to recover.");
    case 50..74:
      return notify_fail("Your power is halfway recovered.");
    case 75..99:
      return notify_fail("Your power has almost recovered.");
    default:
  }

  return 1;
}
