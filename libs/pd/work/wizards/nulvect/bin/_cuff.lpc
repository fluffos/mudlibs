
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^WHITE%^"
#define COL2 "%^RED%^"
#define RES "%^RESET%^"

#define CUFF_PROP "cuff_abil_time"
#define CUFF_DELAY 30

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "swashbuckler" &&
      tp->query_level() >= 8)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <cuff [whom]>\n\n"
    "This quick punch to the face can slow your opponent down for "
    "a little while.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You cannot do that while a ghost.");

  if (!tgt)
    FAIL("Cuff whom?");

  if (!tgt->is_living())
    FAIL("That isn't alive.");

  if (tgt == tp)
    FAIL("That would not be a good idea.");

  if (!tgt->query_is_limb("head"))
    FAIL(capitalize(tgt->query_subjective())+" has no head!");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_cuff(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int dmg, rank, cost, hit, miss, time;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  if (tp->query_level() >= 15)
    rank = 2;
  else
    rank = 1;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "attack", "melee" }),
    ({ "strength", "dexterity" }),
    ({ "strength" }) );

  dmg /= 4;

  cost = dmg/6;
  if (cost < 10) cost = 10;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->kill_ob(tgt);
  tp->add_sp(-(cost-random(5)));

  hit = tp->query_stats("dexterity")*3;
  hit += tp->query_skill("entertainment")+20;

  miss = tgt->query_stats("dexterity")*3/2;
  miss += tgt->query_stats("constitution")*3/2;
  miss += tgt->query_skill("perception");

  if (tgt->query_blind())
    hit = miss+50;
  else if (tp->query_blind() || tgt->query(CUFF_PROP) >= time())
    miss = hit+50;
  
  if (miss > hit+random(10)) {
    message("combat", "You take a swing at "+tgt->query_cap_name()+", "
      "but miss.", tp);
    message("combat", tp->query_cap_name()+" takes a swing at you, but "+
      tp->query_subjective()+" misses.", tgt);
    message("combat", tp->query_cap_name()+" takes a swing at "+
      tgt->query_cap_name()+", but misses.", env, ({ tgt, tp }) );
    return 1;
  }

  time = 2 + 2*random(random(4));
  if (tp->query_skill("melee") > tgt->query_skill("defense")/2)
    time += 2;

  message("combat", "You take a "+COL+"swin"+COL2+"g"+RES+" and "+
    COL+"cuff"+RES+" "+tgt->query_cap_name()+" across the face!", tp);
  message("combat", tp->query_cap_name()+" takes a "+COL+"swin"+COL2+"g"+RES+
    " and "+COL+"cuffs"+RES+" you across the face!", tgt);
  message("combat", tp->query_cap_name()+" takes a "+COL+"swin"+COL2+"g"+RES+
    " and "+COL+"cuffs"+RES+" "+tgt->query_cap_name()+" across the face!",
    env, ({ tp, tgt }) );

  tgt->do_damage("head", dmg);
  tgt->add_combat_round_bonus(-1, time);
  tgt->add_skill_bonus("perception", -(tgt->query_base_skill("perception")/4), time);
  tgt->add_skill_bonus("attack", -(tgt->query_base_skill("attack")/5), time);
  tgt->add_skill_bonus("defense", -(tgt->query_base_skill("defense")/5), time);
  tgt->set(CUFF_PROP, time()+time+CUFF_DELAY);

  return 1;
}
