
#include <std.h>
#include <daemons.h>

#define COL "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

mapping types = ([
  "axe" : ([
    "verb" : "hacked",
    "color" : "%^BOLD%^%^RED%^",
  ]),
  "blade" : ([
    "verb" : "slashed",
    "color" : "%^BOLD%^%^WHITE%^",
  ]),
  "blunt" : ([
    "verb" : "mauled",
    "color" : RES+"%^ORANGE%^",
  ]),
  "knife" : ([
    "verb" : "sliced",
    "color" : RES+"%^RED%^",
  ]),
  "flail" : ([
    "verb" : "lashed",
    "color" : RES+"%^MAGENTA%^",
  ]),
  "projectile" : ([
    "verb" : "slashed",
    "color" : "%^YELLOW%^",
  ]),
  "ranged" : ([
    "verb" : "struck",
    "color" : RES+"%^GREEN%^",
  ]),
]);

int do_hit(object tp, int hit, object *tgts, object *weps, object *quivers);
int get_arrow(object *quivers);

int abil() {
  object tp=this_player();
  if (tp && member_array(tp->query_subclass(),
      ({"warrior", "ranger", "paladin", "antipaladin"}) ) != -1 &&
      tp->query_skill("attack") >= 6*40)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <whirl>\n\n"
    "This attack can hit several foes at once as a fighter "
    "spins and strikes with his weapons.",
    this_player() );
}

int can_cast(object tp, object *tgts, object *weps) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your attack.");

  if (tp->query_disable() || tp->query_magic_round() || tp->query_casting())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You whirl around until you look like a ghostly cloud.");

  if (!sizeof(tgts))
    FAIL("You are not fighting anybody!");

  if (!sizeof(weps))
    FAIL("Your fists would not do much damage that way.");

  if (tp->query_rest_type())
    FAIL("You have to stand up first.");

  return 1;
}

int cmd_whirl(string str) {
  object tp=this_player();
  object env=environment(tp);
  object *tgts;
  object *weps;
  object *quivers;
  int max;

  if (!abil()) return 0;

  weps = tp->query_wielded();

  tp->clean_up_attackers();
  tgts = tp->query_attackers();
  
  if (!can_cast(tp, tgts, weps)) return 0;

  // add another hit for every 10 levels of maxed attack
  max = 2;
  max += (tp->query_skill("attack")-(6*40))/(6*10);
  if (max > sizeof(tgts)+1)
    max = sizeof(tgts)+1;

  message("combat", "You ready yourself for the attack!\n"
                    "You "+COL+"W"+RES+"H"+COL+"I"+RES+"R"+COL+"L"+RES+
                    " around quickly!", tp);
  message("combat", tp->query_cap_name()+" "+
                    COL+"W"+RES+"H"+COL+"I"+RES+"R"+COL+"L"+RES+"S"
                    " around quickly!", env, tp);
  
  quivers = filter(all_inventory(tp), (: ($1->is_quiver() && $1->query_arrows()) :) );

  for (int i=0; i < max; i++)
    if (!do_hit(tp, i, tgts, weps, quivers))
      break;

  return 1;
}

int do_hit(object tp, int hit, object *tgts, object *weps, object *quivers) {
  object wep;
  object tgt;
  object *bows;
  string verb, col;
  string type, skill, what;
  int tmp;
  int st, sw;
  int dmg, rank, cost;

  if (!tp || !(st = sizeof(tgts)) || !(sw = sizeof(weps)) ) return 0;

  tmp = hit;
  while (tmp >= st)
    tmp = tmp - st;

  tgt = tgts[tmp];
  
  tmp = hit;
  while (tmp >= sw)
    tmp = tmp - sw;

  wep = weps[tmp];

  bows = filter(weps, (: $1->query_type() == "ranged" :) );

  if (member_array(wep, bows) != -1 && !get_arrow(quivers)) {
    weps -= bows;
    if (!sizeof(weps)) {
      message("combat", "You are out of arrows!", tp);
      return 0;
    }
    else
      wep = weps[random(sizeof(weps))];
  }

  if (!tgt || !wep) return 0;

  switch (tp->query_subclass()) {
    case "warrior": case "ranger":
      skill = "discipline";
    break;
    case "paladin":
      skill = "valor";
    break;
    case "antipaladin":
      skill = "ferocity";
    break;
  }

  type = wep->query_type();

  dmg = BALANCE3_D->get_damage(tp, tgt, 4,
    ({ "attack", "attack", "double wielding", type, skill }),
    ({ "strength", "dexterity" }),
    ({ "strength", "dexterity" }) );

  dmg += wep->query_wc()*20;

  if (type == "ranged") {
    dmg *= 0.55;
    cost = dmg/15;
    what = "arrow";
  }
  else {
    dmg *= 0.35;
    cost = dmg/13;
    what = wep->query_name();
  }

  if (tp->query_sp() < cost) {
    message("info", "You are too tired.", tp);
    return 0;
  }
  tp->add_sp(-cost);

  verb = types[type]["verb"];
  col = types[type]["color"];

  message("combat", tgt->query_cap_name()+" is "+col+verb+RES+
                    " by your "+what+"!", tp);
  message("combat", "You are "+col+verb+RES+" by "+
                    tp->query_cap_name()+"'s "+what+"!", tgt);
  message("combat", tgt->query_cap_name()+" is "+col+verb+RES+" by "+
                    tp->query_cap_name()+"'s "+what+"!",
                    environment(tp), ({ tp, tgt }) );

  tgt->do_damage(tgt->return_limb(), dmg);
  if (tgt->query_hp() < 1)
    tgt->heart_beat();
  if (!tgt)
    tgts -= ({ tgt });

  return 1;
}

int get_arrow(object *quivers) {
  foreach (object q in quivers) {
    if (q->use_arrow())
      return 1;
    else
      quivers -= ({q});
  }
  return 0;
}

