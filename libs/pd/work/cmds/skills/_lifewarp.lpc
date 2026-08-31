#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
#define RES "%^RESET%^"
#define COL "%^BOLD%^%^GREEN%^"
#define COL2 RES+"%^ORANGE%^"
inherit DAEMON;
int spell();
string type() { return "attack"; }
int cmd_lifewarp(string str) {
  int dmg;
  object ob, tp, env;
  tp = this_player();
  env = environment(tp);
  if (!str) ob = tp->query_current_attacker();
  else ob = present(str, env);
  if(!spell()) return 0;
  if (!ob) {
    notify_fail("You do not see "+str+" here.\n");
    return 0;
  }
  if (this_player()->query_busy())
    return notify_fail("You are busy.\n");
  if (tp->query_skill("belief") < 150)
    return notify_fail("Your faith is not yet strong enough.\n");
  if (tp->query_skill("healing") < 150)
    return notify_fail("Your powers of healing are not yet strong enough.\n");
  if (tp->query_subclass() != "cleric")
    return notify_fail("What?\n");
  if (tp->query_level() < 35)
    return notify_fail("You cannot cast this.\n");
  if (env->query_property("no attack") || env->query_property("no magic"))
    return notify_fail("Greater powers prevent your malice.\n");
  if (!living(ob))
    return notify_fail("This spell does not affect ghosts.\n");
  if (ob == tp)
    return notify_fail("Don't we wish that was possible.\n");
  if (tp->query_mp() < 95) 
    return notify_fail("Your spell fails, due to lack of magic.\n");
  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }
  dmg = BALANCE3_D->get_damage( tp, ob, 4, ({ "healing", "healing", "belief" }),
   ({ "wisdom" }), ({ "wisdom", "intelligence" }) );
  dmg = dmg*7/8;
  if (dmg < 10) {
    write("Your spell fails!");
    tell_room(env, ""+tp->query_cap_name()+"'s spell fails.", ({ tp }));
    return 1;
  }
  message("magic", tp->query_cap_name()+" points at "+ob->query_cap_name()+".", env, tp);
  message("magic", "You point at "+ob->query_cap_name()+".", tp);
  message("magic", COL+ob->query_cap_name()+" wr"+COL2+"ithe"+COL+"s in pain as "+
   ob->query_possessive()+" bl"+COL2+"oo"+COL+"d flows in reverse!"+RES, env, ({ob}) );
  message("magic", COL+"A terrible "+COL2+"bur"+COL+"n"+COL2+"ing"+COL+" pain fills your body "
   "as your bl"+COL2+"oo"+COL+"d flows in reverse!"+RES, ob);
  tp->add_mp(-BALANCE3_D->get_cost(dmg, 4, "mp"));
  if (random(100) > 50)
    tp->add_alignment(-1);
  tp->set_magic_round(); 
  ob->do_damage("none", dmg, DAMAGE_FAITH, DAMAGE_BYPASS_ARMOUR, tp);
  return 1;
}
void help() {
  write(@END
Syntax: <lifewarp [living target]>
A painful attack used by some clerics of high skill, lifewarp reverses the flow of blood within the targets body for a short period of time.  The blood then releases painful impurities throughout the body.
END);
}
int spell() {
  object o;
  o = this_player();
  if (o)
    if (o->query_subclass() == "cleric")
      if (o->query_skill("healing") >= 40*6 && o->query_skill("belief") >= 40*6)
	return 1;
  return 0;
}
