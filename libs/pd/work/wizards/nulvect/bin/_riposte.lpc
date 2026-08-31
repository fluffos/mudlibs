
#include <std.h>

#define RIPOSTE_OB "/cmds/skills/obj/riposte_ob"
#define BAIL(s) return notify_fail(s);

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp &&
      tp->query_subclass() == "swashbuckler" &&
      tp->query_skill("attack") >= to_int(4.5*20) &&
      tp->query_skill("defense") >= 5*20 &&
      tp->query_skill("blade") >= 6*20) return 1;
  return 0;
}

void help() {
  object tp=this_player();
  message("help","\nSyntax: <riposte [living]>\n"
                 "A tricky move, a skilled swashbuckler can watch for "
                 "an attack, then dodge it and counterattack with his sword.",
                 tp);
}

int ok_cast(object tp, object tgt) {

  if (tp->query_rest_type())
    BAIL("You must be standing to do that.\n");

  if (!tgt)
    BAIL("You do not see that here.\n");
  
  if (member_array(tgt,tp->query_attackers()) == -1)
    BAIL("You are not fighting "+tgt->query_objective()+"!\n");
  
  if (tp == tgt)
    BAIL("How in the world did this happen?\n");

  if (!sizeof(filter(tp->query_wielded(), (: $1->query_type() == "blade" :) ) ) )
    BAIL("You need to use a sword for that.\n");

  if (tp->query("riposte"))
    BAIL("You can only concentrate on one opponent at a time!\n");

  return 1;
}
  
int cmd_riposte(string str) {

  object tp=this_player();
  object tgt;
  object rip;
  
  if (!abil()) return 0;

  if (tp->query_disable() || tp->query_casting())
    BAIL("You are busy.\n");

  if (!str || str == "")
    tgt=tp->query_current_attacker();
  else
    tgt=present(str,environment(tp));

  if (!ok_cast(tp,tgt))
    return 0;

  rip=new(RIPOSTE_OB);
  rip->move(tgt);
  rip->setup(tp);

  message("info", "You watch for an opening in "+
                  tgt->query_cap_name()+"'s defenses...", tp);

  tp->add_sp(-(5+random(10)));
  tp->set_disable(1);

  return 1;
}


