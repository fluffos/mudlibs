#include <std.h>
#include <damage_types.h>
#include <damage.h>

#define COL "%^YELLOW%^"
#define RES "%^RESET%^"

inherit OBJECT;

int avoid;
int disarm;
int hitplayers;
int damage;
object owner;

void setup(object tp, int canpk, int diff, int dam);
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
  int party;
  object tp=this_player();
  ::init();

  if (!strlen(tp->query_long())) return;

  if (!owner) {
    remove();
    return;
  }

  add_action("try_disarm", "disarm");

  if (query_verb() == "trap") return;

  if (owner && tp != owner && owner->query_party() && tp->query_party() && owner->query_party() == tp->query_party())
    party = 1;
  
  if (tp == owner)
    message("info",COL+"You notice your trap still set."+RES,tp);
  
  else if (party || (userp(tp) && (!hitplayers || tp->query_level() < 20)) ||
           tp->query_skill("perception") > avoid+random(avoid/5)-random(avoid/5))
             message("info",COL+"As you enter, you notice a trap!\n"
               "You can try to disarm it or just leave it."+RES, tp);
  
  else {
    message("info", COL+"As you enter, you spring a trap!"+RES, tp);
    message("info", COL+"As "+tp->query_cap_name()+" enters, "+
                    tp->query_subjective()+" springs a trap!"+RES, environment(tp), tp);
  
    if (tp->query_stats("dexterity")+tp->query_skill("agility")/11 >
        avoid/2+random(avoid/10)-random(avoid/10)) {
          message("info", COL+"You jump aside just in time to avoid it."+RES, tp);
          message("info", COL+tp->query_cap_name()+" jumps out of the way "
                          "just in time."+RES,
            environment(tp), tp);
    }

    else if (owner->kill_ob(tp))
      tp->do_damage("random", damage+random(damage/10), DAMAGE_PHYSICAL | DAMAGE_PIERCE, DAMAGE_NO_SEVER, owner);

    this_object()->remove();
  }
}

int try_disarm(string str) {
  object tp=this_player();
  mixed source;
  if(!str || str != "trap")
    return notify_fail("Disarm what?\n");

  if (tp->query_stats("dexterity")+tp->query_skill("perception") > disarm+random(disarm/3)) {
    message("info","You skillfully disarm the trap.", tp);
    message("info",tp->query_cap_name()+" disarms the trap.", environment(tp), tp);
    this_object()->remove();
  }
  else if (random(100) < 20) {
    if (!owner) source = "a trap";
    else if (owner == tp) source = "a trap";
    else source = owner;
    message("info","You accidentally set off the trap at point blank range!", tp);
    message("info",tp->query_cap_name()+" accidentally sets off a trap while "
                   "trying to disarm it!", environment(tp), tp);
    tp->do_damage(tp->query_wielding_limbs(), damage*2/3+random(damage),
      DAMAGE_PHYSICAL | DAMAGE_PIERCE, DAMAGE_NO_SEVER, source);
    this_object()->remove();
  }
  else {
    message("info", "You fail to disarm the trap.", tp);
    message("info", tp->query_cap_name()+" tries to disarm a trap.", environment(tp), tp);
  }
  return 1;
}

