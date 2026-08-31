
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s);

#define COL ""
#define RES "%^RESET%^"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if ((tp->query_subclass() == "cleric" ||
      tp->query_subclass() == "monk") &&
      tp->query_skill("healing") >= 10)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <pain [living] [limb]>\n\n"
    "This spell uses the powers of healing in reverse to cause "
    "sharp pain in the body of the target.",
    this_player());
}

int can_cast(object tp, object tgt, string limb) {
  object env;

  if (!tp) return 0;

  env = environment(tp);

  if (env->query_property("no attack") || env->query_property("no magic"))
    FAIL("You cannot cast that here.\n");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (!tgt)
    FAIL("Cause pain in whom?\n");

  if (!living(tgt))
    FAIL("That cannot feel pain.\n");

  if (!(tgt->query_is_limb(limb)))
    FAIL(tgt->query_subjective()+" does not have a "+limb+".\n");

  if (tp == tgt)
    FAIL("Ouch.\n");

  if (userp(tgt) && !interactive(tgt))
    FAIL("You may not attack link-dead players.\n");

  if (!(tp->kill_ob(tgt)))
    FAIL("You cannot attack "+tgt->query_cap_name()+".\n");
  
  return 1;
}

int cmd_mypain(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  string *tmp;
  string limb;
  int i;
  int dmg, cost;

  if (!spell()) return 0;

  // this is necessary because both mob names and limb names
  // can have an arbitrary number of spaces
  // it starts with the full string typed in and cuts off one word
  // at a time until it finds a mob, then the limb is the rest
  // of the string
  tmp = explode(str, " ");
  for (i=sizeof(tmp)-1; i>=0; i--)
    if (objectp(tgt=present(implode(tmp[0..i], " "))))
      break;

  limb = implode(tmp[i+1..], " ");

  if (!can_cast(tp, tgt, limb)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 1,
    ({"healing"}),
    ({"wisdom"}) );

  dmg = dmg*3/4;

  cost = dmg/5;

  if (tp->query_mp() < cost)
    FAIL("Too low on magic.\n");

  if (random(100) < 35 && tp->query_skill("healing") >= 10*6 &&
      function_exists("special_"+limb) != 0)
        call_out("special_"+limb, 2, ({tp, tgt, dmg}) );

  tp->add_mp(-(cost+random(cost/7)));
  tp->set_casting(dmg);
  tp->set_disable();

  message("magic", COL+"You send a sharp pain through "+
                   tgt->query_cap_name()+"'s "+limb+"!"+RES, tp);
  message("magic", COL+tp->query_cap_name()+" sends a sharp pain through "
                   "your "+limb+"!", tgt);
  message("magic", COL+tp->query_cap_name()+" sends a sharp pain through "+
                   tgt->query_cap_name()+"'s "+limb+"!", env, ({tp, tgt}) );
  
  return 1;
}

void special_head(mixed *args) {
  object tp=args[0];
  object tgt=args[1];
  int dmg=args[2];

  if (!tp || !tgt) return;

  tgt->set_paralyzed(2, "The pain in your head overwhelms you!");
}
