
#include <std.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s+"\n")
#define COL "%^YELLOW%^"
#define COL2 "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

#define CLEANSE_PROP "cleanse_spell_time"
#define CLEANSE_DELAY 10

inherit DAEMON;

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "paladin" &&
      tp->query_skill("faith") >= 28*4)
        return 1;
  return 0;
}

string type() { return "faith"; }

void help() {
  message("help",
    "Syntax: <cleanse [who]>\n\n"
    "A holy paladin can cleanse another's soul of evil. "
    "The process is painful, though, and those not expecting "
    "it will probably become hostile.\n\n"
    "See also: allow",
    this_player() );
}

int can_cast(object tp, object tgt, int allowed) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your powers.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You are but a soul yourself!");

  if (!tgt)
    FAIL("Cleanse who?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers!");

  if (tp->query(CLEANSE_PROP) > time())
    FAIL("You must wait before attempting another cleansing.");

  if (tgt == tp)
    FAIL("No one is perfect enough to cleanse himself.");

  if (tgt->query_alignment() >= 0)
    FAIL(capitalize(tgt->query_possessive())+
         " soul is clean.");

  if (tgt->is_player() && !interactive(tgt))
    FAIL(capitalize(tgt->query_subjective())+
         " must be present in body and mind to be cleansed.");

  if (tp->query_mp() < 200)
    FAIL("Your magic is too low.");

  if (!allowed) {
    if (environment(tp)->query_property("no attack") ||
        !tgt->ok_to_kill(tp) || !tp->ok_to_kill(tgt))
          FAIL("Some force prevents your powers.");
  }

  return 1;
}

int cmd_cleanse(string str) {

  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int tpalign, tgtalign, allowed, amt, dmg, cost;
  
  if (!spell()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (tgt)
    allowed = (member_array(tp, tgt->query_allow("cleanse")) != -1);
  else
    allowed = 0;
  
  if (!can_cast(tp, tgt, allowed)) return 0;

  tpalign = tp->query_alignment();
  tgtalign = tgt->query_alignment();

  amt = tpalign/20;
  amt += random(amt/4);
  if (!allowed) amt /= 2;
  dmg = (absolute_value(tgtalign)-200)/11;
  dmg += random(dmg);
  cost = 200+amt+random(amt);
  cost += dmg/3;

  if (tp->query_mp() < cost)
    FAIL("Your magic is too low.");

  tp->add_mp(-cost);
  tp->set_magic_round(2);
  tp->set(CLEANSE_PROP, time()+CLEANSE_DELAY);
  tp->add_alignment(1);
  tgt->set_alignment(tgtalign+amt);

  message("magic", COL+"You mutter a prayer to "+COL2+"cleanse"+COL+
                   " "+tgt->query_cap_name()+"'s soul."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" mutters a prayer of "+
                   COL2+"cleansing"+COL+" for "+tgt->query_cap_name()+".",
                   env, ({ tp, tgt }) );
  message("magic", COL+tp->query_cap_name()+" mutters a prayer to "+
                   COL2+"cleanse"+COL+" your soul."+RES, tgt);

  if (dmg > 0) {
    tgt->do_damage(tgt->query_torso(), dmg, DAMAGE_FAITH | DAMAGE_HOLY,
       DAMAGE_BYPASS_ARMOUR | DAMAGE_NO_PLAYER_REDUCE | DAMAGE_NONLETHAL, tp);
    message("magic", COL2+"Your insides burn painfully!"+RES, tgt);
    message("magic", COL2+tgt->query_cap_name()+" looks pained."+RES, env, tgt);
  }

  if (!allowed) {
    if (tgt->is_player())
      tp->kill_ob(tgt);
    else {
      tgt->force_me("kill "+tp->query_name());
      tgt->kill_ob(tp);
    }
  }

  return 1;
}

