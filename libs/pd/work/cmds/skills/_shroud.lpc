#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
void help() {
  write(@END
Syntax: <shroud [victim]>
This powerful pyromancer attack spell creates a shroud of flame about
the victim's body. The flame burns the victim just before it disapears.
See also: sear
END);
}
int spell() {
  object o;
  o = this_player();
  if (o && o->query_subclass() == "pyromancer" && o->query_level() >= 50)
    if (o->query_skill("pyromancy") >= 6*50)
      return 1;
}
string type() { return "attack"; }
int cmd_shroud(string str) {
  int dmg;
  object ob, tp, env;
  tp = this_player();
  env = environment(tp);
  if (!str) ob = tp->query_current_attacker();
  else ob = present(str, env);
  if(!spell()) return 0;
  if (!ob) {
    if (str)
      notify_fail("You do not see that here.\n");
    return 0;
  }
  if (this_player()->query_busy())
    return notify_fail("You are busy.\n");
  if (tp->query_level() < 50)
    return notify_fail("You cannot cast this.\n");
  if (env->query_property("no attack") || env->query_property("no magic"))
    return notify_fail("Greater powers prevent your malice.\n");
  if (!living(ob))
    return notify_fail("Syntax: <shroud [living]>\n");
  if (ob == tp)
    return notify_fail("You want to enshroud yourself in flames?\n");
  if (tp->query_mp() < 85) 
    return notify_fail("Your spell fails, due to lack of magic.\n");
  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }
  dmg = BALANCE3_D->get_damage( tp, ob, 4, ({ "magic attack", "pyromancy" }),
   ({ "intelligence" }), ({"pyromancy", "magic attack"}) );
  dmg = dmg * 1.2;
  if (dmg < 20) {
    write("Your spell fails.");
    tell_room(env, tp->query_cap_name()+"'s spell fails.", ({ tp }));
    return 1;
  }
  tell_room(env, "%^BOLD%^%^RED%^"+tp->query_cap_name()+" creates "
   "a %^RESET%^%^BOLD%^shroud%^RED%^ of %^YELLOW%^flame%^RED%^ around "+ob->query_cap_name()+"!%^RESET%^", ({ ob, tp }));
  write("%^BOLD%^%^RED%^You create a %^RESET%^%^BOLD%^shroud%^RED%^ of %^YELLOW%^flames%^RED%^ around "
   +ob->query_cap_name()+"!%^RESET%^");
  tell_object(ob, "%^BOLD%^%^RED%^"+tp->query_cap_name()+" creates "
   "a %^RESET%^%^BOLD%^shroud%^RED%^ of %^YELLOW%^flame%^RED%^ around you!%^RESET%^");
  tp->add_mp(-BALANCE3_D->get_cost(dmg, 4, "mp"));
  ob->do_damage("all", dmg, DAMAGE_MAGIC | DAMAGE_FIRE, DAMAGE_NO_SEVER, tp);
  tp->set_magic_round();
  return 1;
}
