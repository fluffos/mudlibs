#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
int abil();
string type() { return "attack"; }
int cmd_flameclaw(string str)
{
  int a,b;
  string target_thing;
  object ob, tp;
  if (!abil()) {
    return 0;
  }
  tp = this_player();
  if ((!str || str=="") && !tp->query_current_attacker())
  {
    write("Syntax: <flameclaw [living]>");
    return 1;
  }
  if (environment(tp)->query_property("no attack"))
  {
    write("Greater powers prevent your malice.");
    return 1;
  }
  if (tp->query_current_attacker() && !str) 
    ob = tp->query_current_attacker();
  else {
    ob = present(str, environment(tp));
    if (!ob)
    {
      write("You dont see that here.");
      return 1;
    }
    if (ob==tp)
    {
      write("Attack yourself?");
      return 1;
    }
  }
  if(!living(ob))
    return notify_fail("Syntax: <flameclaw [living]>\n");
  if (tp->query_sp() < 50) 
  {
    write("You are too tired.");
    return 1;
  }
  if(tp->query_disable()) return notify_fail(
     "You're unable to summon claws of flame!\n");
  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }
  tp->set_disable();
  write("%^BOLD%^%^RED%^You summon claws of flame to smite your opponent.");
  b = random(this_player()->query_skill("claw"))/25;
  if (b > 4)
    b = 4;
  if(b < 1)
    b = 1;
  while(b--) {
    a = BALANCE3_D->get_damage( tp, ob, 3, ({ "attack", "claw", "claw" }),
     ({ "strength" }), ({ "strength", "dexterity" }) );
    a = a / 3;
    if (a < 0) {
      write("The fire on your claws fail to do any damage.");
      message("info", "The fire of "+this_player()->query_cap_name()+"'s claws "
       "do no damage to you.", ob);
      message("info", "The fire on "+this_player()->query_cap_name()+" claws "
       "fails to damage "+ob->query_cap_name()+".",
       environment(ob), ({ tp, ob }));
      return 1;
    }
    message("info", "%^ORANGE%^The fire of your claws burns "
     +ob->query_cap_name()+" badly.", tp);
    message("info", "%^ORANGE%^The fire of "+tp->query_cap_name()+
     " claws burns "+ob->query_cap_name()+" badly."
     , environment(tp), ({ tp, ob }));
    message("info", "%^ORANGE%^The fire of "+tp->query_cap_name()+
     "'s claws  burns you badly.", ob);
    target_thing = (string)ob->return_target_limb();
    ob->do_damage(target_thing, a, DAMAGE_PHYSICAL | DAMAGE_SLASH | DAMAGE_PIERCE | DAMAGE_FIRE, 0, tp);
    tp->add_sp(-(BALANCE3_D->get_cost(a, 3, "sp")));
  }
  tp->add_skill_points("claw", (a/30));
  return 1;
}
int abil() {
  object o;
  o = this_player();
  if (!o) return 0;
  if (o->query_subclass() != "red") return 0;
  if (o->query_level() < 25) return 0;
  if (o->query_skill("claw") >= 50)
    return 1;
}
void help() {
  write(@END
Syntax: <flameclaw [living]>
Powerful dragons can summon flames into their claws, causing massive damage.
END);
}
