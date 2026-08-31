#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define COL "%^CYAN%^"
#define RES "%^RESET%^"

inherit SONG;

void finish();
mapping weapons = ([
  "knife" : ({}),
  "blunt" : ({}),
  "blade" : ({})
]);

int dance() {
  object tp=this_player();
  if (tp->query_subclass() == "gypsy" &&
      tp->query_skill("entertainment") >= 5*13 &&
      tp->query_skill("attack") >= 4*13)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <perform spinning dervish [for whom]>\n\n"
    "The spinning dervish dance is more of an attack than a dance. "
    "The performer has to take a moment to focus, then unleashes "
    "a spinning flurry of attacks against a certain foe.",
    this_player() );
}

void create() {
  ::create();
  set_dance_name("spinning dervish");
  set_auto(1);
  set_type("attack");
  set_target_required(1);
  set_max_rounds(2);
}

int check() {
  object tp=this_object()->query_caster();
  object wep;
  int i=0;

  if (!tp) return 0;

  foreach (object thing in tp->query_wielded()) {
    if (thing->is_weapon() &&
        member_array(thing->query_type(), keys(weapons)) != -1) {
          weapons[thing->query_type()] += ({thing});
          i++;
    }
  }

  if (!i)
    return notify_fail("You need a knife, sword, or blunt weapon for that.\n");

  if (tp->query_sp() < 40)
    return notify_fail("You are too tired.\n");

  return 1;
}

void performance(int round) {
  object tp=this_object()->query_caster();

  switch (round) {
    case 1:
      tp->set_disable();
      message("dance", "You "+COL+"grip"+RES+" your weapons in preparation.", tp);
    break;
  }
}

void finish() {
  object tp=this_object()->query_caster();
  object tgt=this_object()->query_target();
  object env=environment(tp);
  int dmg;
  int amt;
  int dtype;

  if (!tgt || environment(tgt) != env) {
    message("dance", "Your target isn't here.", tp);
    return;
  }

  if (env->query_property("no attack")) {
    message("dance", "You cannot attack here.", tp);
    return;
  }

  message("dance", "In a blur, you "+COL+"dash"+RES+" at "+
                   tgt->query_cap_name()+" and "+COL+"whirl"+RES+
                   " on your toes!", tp);
  message("dance", "In a blur, "+tp->query_cap_name()+" "+COL+"dashes"+RES+
                   " at you and "+COL+"whirls"+RES+" on "+
                   tp->query_possessive()+" toes!", tgt);
  message("dance", "In a blur, "+tp->query_cap_name()+" "+COL+"dashes"+RES+
                   " at "+tgt->query_cap_name()+" and "+COL+"whirls"+RES+
                   " on "+tp->query_possessive()+" toes!", env, ({tp,tgt}));

  amt = tp->query_stats("dexterity") +
        tp->query_skill("entertainment");
  amt = 1+(amt/100);
  if (amt > 4) amt=4;

  foreach (string type in keys(weapons)) {
    foreach (object wep in weapons[type]) {
      string verb;
      switch (type) {
        case "knife": verb = "slices"; dtype = DAMAGE_SLASH; break;
        case "blade": verb = "slashes"; dtype = DAMAGE_SLASH; break;
        case "blunt": verb = "smashes"; dtype = wep->query_damage_type(); break;
      }
      message("dance", "Your "+wep->query_name()+" "+COL+verb+RES+" into "+
                       tgt->query_cap_name()+"!", tp);
      message("dance", tp->query_cap_name()+"'s "+wep->query_name()+" "+
                       COL+verb+RES+" into you!", tgt);
      message("dance", tp->query_cap_name()+"'s "+wep->query_name()+" "+
                       COL+verb+RES+" into "+tgt->query_cap_name()+"!",
                       env, ({tp, tgt}) );
      dmg = BALANCE3_D->get_damage(tp, tgt, amt,
        ({"entertainment", "entertainment", "attack", type}),
        ({"dexterity"}),
        ({"strength", "dexterity"}) );
      dmg = dmg * 4 / (3+(sizeof(filter(tp->query_wielded(), (: member_array($1->query_type(), keys(weapons)) != -1 :) ))));
      // gets less damage per hit the more weapons you wield
      //dmg = dmg*4/5;
      dmg += wep->query_wc()*6;
      tgt->do_damage("target", dmg, DAMAGE_PHYSICAL | DAMAGE_DANCE | dtype, 0, tp);
      tp->add_sp(-(dmg/8));
    }
  }

}


