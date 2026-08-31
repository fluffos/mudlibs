
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define COL "%^BOLD%^GREEN%^%^"
#define COL2 "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s);

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "cleric" &&
      tp->query_skill("healing") >= 22*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <unknit [whom]>\n\n"
    "This spell utilizes a cleric's healing ability to cause "
    "the bones of the target to come apart.",
    this_player());
}

int can_cast(object tp, object tgt) {

  object env;
  
  if (!tp) return;

  env=environment(tp);

  if (env->query_property("no attack") || env->query_property("no magic"))
    FAIL("You may not cast that here.\n");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (!tgt)
    FAIL("Unknit whose bones?\n");

  if (!living(tgt))
    FAIL("That's not alive.\n");

  if (tp == tgt)
    FAIL("Not the brightest idea.\n");

  if (userp(tgt) && !interactive(tgt))
    FAIL("You may not attack link-dead players.\n");
  
  if (!(tp->kill_ob(tgt)))
    FAIL("You cannot attack "+tgt->query_objective()+".\n");
  
  return 1;
}

int cmd_unknit(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int dmg, cost, rank;
  int bodydam;
  string limb;
  string *limbs;

  if (!spell()) return 0;

  if (str && str != "")
    tgt=present(str,env);
  else
    tgt=tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  if (tp->query_skill("healing") >= 30*6) rank=3;
  else rank=2;
  
  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
          ({"healing", "healing", "healing", "belief"}),
          ({"wisdom", "wisdom", "wisdom", "intelligence"}),
          ({"healing", "belief"}) );

  dmg = dmg * 65 / 100;

  cost = BALANCE3_D->get_cost(dmg, rank, "sp") * 90 / 100;
  
  if (tp->query_mp() < cost)
    FAIL("Not enough magic.\n");

  limbs = tgt->query_limbs();
  limbs = filter(limbs,
    function(string l) {
      string *lwords = explode(l, " ");
      foreach (string check in ({"leg","arm","wing","tail"}))
        if (member_array(check, lwords) != -1)
          return 1;
      return 0;
    } );
 
  if (!sizeof(limbs))
    FAIL(capitalize(tgt->query_cap_name())+" has no limbs you can unknit!\n");
  
  limb = limbs[random(sizeof(limbs))];
  
  tp->add_mp(-(cost+random(cost/10)));
  tp->set_magic_round(1);

  message("magic", "You point at "+tgt->query_cap_name()+".", tp);
  message("magic", tp->query_cap_name()+" points at you.", tgt);
  message("magic", tp->query_cap_name()+" points at "+
                   tgt->query_cap_name()+".", env, ({tp, tgt}) );
  message("magic", COL+"A sharp pain fills your "+COL2+limb+RES+COL+
                   " as it gets weaker!"+RES, tgt);
  message("magic", COL+tgt->query_cap_name()+" cringes as "+
                   tgt->query_possessive()+" "+limb+" seems to get weaker!"+
                   RES, env, tgt);

  tgt->do_damage(limb, dmg, DAMAGE_FAITH, DAMAGE_NO_HP | DAMAGE_NO_SEVER, tp);
  tgt->do_damage(limb, dmg, DAMAGE_FAITH, 0, tp);

  if (random(100) > 60)
    tp->add_alignment(-1);

  return 1;
}

