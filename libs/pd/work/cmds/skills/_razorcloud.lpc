
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s+"\n");

#define COL "%^BOLD%^%^BLACK%^"
#define COL2 "%^BOLD%^%^RED%^"
#define COL3 "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "antipaladin" &&
      tp->query_skill("magic attack") >= 35*4 &&
      tp->query_skill("faith") >= 35*4)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <razorcloud [who]>\n\n"
    "This hellish spell lashes your opponent with razor-sharp "
    "blades of demonic energy, causing a huge amount of blood loss "
    "in a short time.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You are dead!");

  if (!tgt)
    FAIL("Inflict it upon whom?");

  if (!living(tgt))
    FAIL("That would be a waste of your power.");

  if (tgt == tp)
    FAIL("Hurting others is much more enjoyable.");

  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers.");

  if (tgt->is_player() && !interactive(tgt))
    FAIL("You cannot attack a link-dead player.");

  if (tp->query_mp() < 50)
    FAIL("You need more magic.");

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_razorcloud(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int rank, dmg, def, cost, hits;

  if (!spell()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  rank = 4;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "magic attack", "magic attack", "faith" }),
    ({ "wisdom", "wisdom", "intelligence" }),
    ({ "magic attack" }) );

  cost = BALANCE3_D->get_cost(dmg, rank, "mp") + 50;

  // the +50 means this spell could put you as low as -50 mp
  if (tp->query_mp()+50 < cost)
    FAIL("You need more magic.");

  tp->add_mp(-cost);
  tp->set_magic_round(1);
  tp->set_disable(1);
  tp->add_alignment(-1);

  message("magic",
    COL+"A swirling mass of demonic energy "
    "e"+COL2+"nv"+COL+"elo"+COL2+"pe"+COL+"s you!"+RES, tgt);
  message("magic",
    COL+"A swirling mass of demonic energy "
    "e"+COL2+"nv"+COL+"elo"+COL2+"pe"+COL+"s "+
    tgt->query_cap_name()+"!"+RES, env, tgt);

  def = tgt->query_skill("defense");
  def += tgt->query_stats("constitution");
  def -= tp->query_skill("magic attack");
  def -= tp->query_stats("intelligence");
  def -= tp->query_stats("wisdom");
  def -= random(tp->query_level());

  if (def > 0) {
    message("magic",
      COL+"The spell dissipates harmlessly."+RES, tgt);
    message("magic",
      COL+"The spell dissipates harmlessly around "+
      tgt->query_cap_name()+"."+RES, env, tgt);
    return 1;
  }

  hits = 1+random(4);
  for (int i = hits; i > 0; i--) {
    string limb = tgt->return_limb();
    string word = hits > 2 ? "lash" : "shred";
    message("magic",
      COL+"Flashing r"+COL3+"a"+COL2+"z"+COL3+"or"+COL+"s "+
      word+" your "+limb+"!"+RES, tgt);
    message("magic",
      COL+"Flashing r"+COL3+"a"+COL2+"z"+COL3+"or"+COL+"s "+
      word+" "+tgt->query_cap_name()+"'s "+limb+"!",
      env, tgt);
    tgt->do_damage(limb, (dmg*3/5)/hits, DAMAGE_FAITH | DAMAGE_SLASH | DAMAGE_UNHOLY, 0, tp);
  }

  message("magic", COL2+"Your wounds bleed."+RES, tgt);
  message("magic",
    COL2+"Blood flows from "+tgt->query_cap_name()+"'s wounds."+RES, env, tgt);
  tgt->add_bleeding(dmg*3/4);
  tp->add_skill_points("magic attack", 25);

  return 1;
}

