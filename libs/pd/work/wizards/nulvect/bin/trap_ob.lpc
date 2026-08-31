#include <std.h>

inherit OBJECT;

int avoid;
int disarm;
int hitplayers;
int damage;
object owner;

void setup(object tp, int canpk, int diff, int dam);
void init();
int try_disarm(string str);

void create() {
  ::create();
  set_short("");
  set_long("A trap made of sinew and wood.");
  set_id(({"trap", "trap_ob_id"}));
  set_weight(100);
  set_prevent_get("It would go off if you took it!");
  owner = 0;
  hitplayers = avoid = disarm = damage = 0;
}

void setup(object tp, int canpk, int diff, int dam) {
  owner = tp;
  hitplayers = canpk;
  avoid = diff;
  disarm = diff*3/4;
  damage = dam;
}

void init() {
  object tp=this_player();
  ::init();
  add_action("try_disarm", "disarm");

  if (query_verb() == "trap") return;
  
  if (tp == owner)
    message("info","You notice your trap still set.",tp);
  
  else if ((userp(tp) && (!hitplayers || tp->query_level() < 20)) ||
           tp->query_skill("perception") > avoid+random(avoid/10)-random(avoid/10))
             message("info","As you enter, you notice a trap!\n"
               "You can try to disarm it or just leave it.", tp);
  
  else {
    message("info", "As you enter, you spring a trap!", tp);
    message("info", "As "+tp->query_cap_name()+" enters, "+
                    tp->query_subjective()+" springs a trap!", environment(tp));
  
    if (tp->query_stats("dexterity")+tp->query_skill("agility")/11 >
        avoid/2+random(avoid/10)-random(avoid/10)) {
          message("info", "You jump aside just in time to avoid it.", tp);
          message("info", tp->query_cap_name()+" jumps out of the way just in time.",
            environment(tp));
    }

    else if (owner->kill_ob(tp))
      tp->damage(damage + random(damage/10));

    this_object()->remove();
  }
}

int try_disarm(string str) {
  object tp=this_player();
  if(!str || str != "trap")
    return notify_fail("Disarm what?\n");

  if (tp->query_stats("dexterity")+tp->query_skill("perception") > disarm+random(disarm/15)) {
    message("info","You skillfully disarm the trap.", tp);
    message("info",tp->query_cap_name()+" disarms the trap.", environment(tp));
    this_object()->remove();
  }
  else if (random(100) < 20) {
    message("info","You accidentally set off the trap at point blank range!", tp);
    message("info",tp->query_cap_name()+" accidentally sets off a trap while "
                   "trying to disarm it!", environment(tp));
    tp->damage(damage*2/3+random(damage));
    this_object()->remove();
  }
  else {
    message("info", "You fail to disarm the trap.", tp);
    message("info", tp->query_cap_name()+" tries to disarm a trap.", environment(tp));
  }
  return 1;
}

