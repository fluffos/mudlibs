// 5:51 PM 9/4/00 balanced dungeonware.net
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
void help() {
  write(@END
Syntax: <sear [victim]>
This pyromancer attack spell was named after it's purpose; it sears
the pyromancer's opponent.
See also: burn, scald
END);
}
int spell() {
  object o;
  o = this_player();
  if (o && o->query_subclass() == "pyromancer" && o->query_level() >= 36)
    return 1;
}
string type() { return "attack"; }
int cmd_sear(string str) {
  int dmg;
  object ob, tp, env;
  tp = this_player();
  env = environment(tp);
  if (!str) ob = tp->query_current_attacker();
  else ob = present(str, env);
  if(!spell()) return 0;
  if (!ob) {
    if (str)
      notify_fail("You do not see "+str+" here.\n");
    return 0;
  }
  if (tp->query_level() < 36)
    return notify_fail("You cannot cast this.\n");
  if (env->query_property("no attack") || env->query_property("no magic"))
    return notify_fail("Greater powers prevent your malice.\n");
  if (this_player()->query_busy())
    return notify_fail("You are busy.\n");
  if (!living(ob))
    return notify_fail("Syntax: <sear [living]>\n");
  if (ob == tp)
    return notify_fail("Sear yourself?\n");
  if (tp->query_mp() < 250) 
    return notify_fail("Your spell fails, due to lack of magic.\n");
  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }
  dmg = BALANCE3_D->get_damage( tp, ob, 3, ({ "magic attack", "pyromancy", "pyromancy" }),
   ({ "intelligence" }), ({"pyromancy"}) );
  if (dmg < 1) {
    write("Your spell fails.");
    tell_room(env, tp->query_cap_name()+"'s spell fails.", ({ tp }));
    return 1;
  }
  tell_room(env, "%^BOLD%^%^RED%^"+tp->query_cap_name()+" s%^RESET%^ORANGE%^ea%^BOLD%^%^RED%^rs "
   +ob->query_cap_name()+"!%^RESET%^", ({ ob, tp }));
  write("%^BOLD%^%^RED%^You s%^RESET%^ORANGE%^ea%^BOLD%^%^RED%^r "+ob->query_cap_name()+"!%^RESET%^");
  tell_object(ob, "%^BOLD%^%^RED%^"+tp->query_cap_name()+" s%^RESET%^ORANGE%^ea%^BOLD%^%^RED%^rs you!%^RESET%^");
  tp->add_mp(-BALANCE3_D->get_cost(dmg, 3, "mp"));
  tp->set_magic_round();
  ob->do_damage("target", dmg, DAMAGE_MAGIC | DAMAGE_FIRE, 0, tp);
  return 1;
}
