
#include <std.h>
#include <daemons.h>
#include <rest.h>

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_class() == "wanderer" &&
      tp->query_level() >= 2)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <trip who>\n\n"
    "This is an easy to learn wanderer attack. The wanderer "
    "drops to the ground and spins, tripping his attacker.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You don't have a body.");

  if (!tgt)
    FAIL("Trip who?");

  if (tp == tgt)
    FAIL("You trip and fall down.");

  if (tgt->query_rest_type())
    FAIL(tgt->query_cap_name()+" is already on the ground!");
  
  if (tp->query_sp() < 20)
    FAIL("You are too tired.");

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_trip(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int hit, miss, dmg, rank;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 1,
    ({ "attack", }), ({ "dexterity" }) );
  dmg /= 3;

  hit = tp->query_stats("dexterity")+10;
  miss = tgt->query_stats("dexterity")/2;
  miss += random(miss);
  miss += random(25);

  hit -= miss;

  if (hit < 1) {
    message("combat", "You spin at "+tgt->query_cap_name()+
      ", miss "+tgt->query_objective()+" and fall to the ground.", tp);
    message("combat", tp->query_cap_name()+" tries to trip you, "
      "but misses and falls to the ground.", tgt);
    message("combat", tp->query_cap_name()+" tries to trip "+
      tgt->query_cap_name()+", "
      "but misses and falls to the ground.", env, ({ tp, tgt }) );
    tp->set_rest_type(SIT);
  }
  else {
    message("combat", "You spin around on the ground and trip "+
        tgt->query_cap_name()+", "+tgt->query_subjective()+
        " lands with a thud!", tp);
    message("combat", tp->query_cap_name()+" spins around on the ground "
        "and trips you, you land with a thud!", tgt);
    message("combat", tp->query_cap_name()+" spins around on the ground "
        "and trips "+tgt->query_cap_name()+", "+tgt->query_subjective()+
        " lands with a thud!", env, ({ tp, tgt }) );
    tgt->do_damage(tgt->return_limb(), dmg);
    tgt->set_rest_type(SIT);
    tgt->set_paralyzed(random(2), "You are sitting.");
  }

  tp->add_sp(-(dmg/6));
  tp->set_disable(1);

  return 1;
}

