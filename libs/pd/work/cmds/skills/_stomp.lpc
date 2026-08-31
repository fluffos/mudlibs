
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define RES "%^RESET%^"
#define COL RES+"%^WHITE%^"
#define COL2 "%^BOLD%^%^RED%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "thug" &&
      tp->query_skill("attack") >= 8*5 &&
      tp->query_skill("murder") >= 8*5)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <stomp [whom]>\n\n"
    "One of the dirtiest attacks known, a thug can stomp "
    "and kick at someone who is on the ground.",
    this_player() );
}

int can_cast(object tp, object tgt) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your attack.");

  if (tp->query_disable() || tp->query_magic_round() || tp->query_casting())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your ghostly body is not well suited for physical assault.");

  if (!tgt)
    FAIL("Stomp whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("That is not possible.");

  if (!tgt->query_rest_type())
    FAIL(capitalize(tgt->query_subjective())+" is not on the ground!");

  if (!tp->ok_to_kill(tgt))
    FAIL("You may not attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_stomp(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int dmg, cost;
  int def;
  string limb;

  if (!abil()) return 0;
  
  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 2,
    ({ "attack", "murder" }),
    ({ "strength" }),
    ({ "strength" }) );

  dmg *= 1.1;

  cost = BALANCE3_D->get_cost(dmg, 2, "sp") * 65 / 100;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  if (!tp->kill_ob(tgt))
    FAIL("You may not attack "+tgt->query_cap_name()+".");

  tp->set_disable();
  tp->add_sp(-cost);
  tp->add_alignment(-7);
  
  message("combat", "You "+COL+"STO"+COL2+"M"+COL+"P"+RES+" "+
                    tgt->query_cap_name()+" cruelly!", tp);
  message("combat", tp->query_cap_name()+" "+COL+"STO"+COL2+"M"+COL+"PS"+RES+
                    " you cruelly!", tgt);
  message("combat", tp->query_cap_name()+" "+COL+"STO"+COL2+"M"+COL+"PS"+RES+
                    " "+tgt->query_cap_name()+" cruelly!", env, ({ tp, tgt }) );

  limb = tgt->return_target_limb();
  def = tgt->query_skill("defense")*2/3;

  tgt->add_skill_bonus("defense", -def);
  tgt->do_damage(limb, dmg, DAMAGE_PHYSICAL | DAMAGE_UNARMED | DAMAGE_IMPACT, DAMAGE_NO_SEVER, tp);
  tgt->add_skill_bonus("defense", def);

  if (random(100) < 30 && limb != "torso" &&
      tp->query_stats("strength") > tgt->query_stats("constitution")*3/2) {
        message("combat", "You hear a "+COL2+"sickening"+RES+" SNAP.", env, tgt);
        message("combat", "Pain "+COL2+"floods"+RES+" through your "+
                          (limb == "head" ? "neck" : limb)+" as it SNAPS!", tgt);
        if (limb == "head")
          tgt->die(tp);
        else
          tgt->set_crippled(limb, -1);
  }

  return 1;
}

