
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^BOLD%^%^WHITE%^"
#define COL2 "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

#define DIVEST_PROP "divest_abil_time"
#define DIVEST_USE_PROP "divest_abil_used_time"
#define DIVEST_DELAY 2

inherit DAEMON;

string *allowed_types = ({
  "helmet", "bracers", "bracer", "gloves", "glove",
  "leggings", "shield", "ring", "necklace", "mask",
  "belt", "saddle", "blanket", "bracelet", "earrings",
  "hat", "cape", "amulet",
});

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "swashbuckler" &&
      tp->query_skill("blade") >= 35*6 &&
      tp->query_skill("entertainment") >= 35*3)
        return 1;
  return 0;
}

string type() { return "deception"; }

void help() {
  message("help",
    "Syntax: <divest [who] [armour]>\n\n"
    "In order to further entertain their onlookers, many swashbucklers learn "
    "to use their skills to remove some of their opponent's armour while "
    "fighting. This is harder than simply disarming them, but can leave them "
    "more vulnerable.\n"
    "Armour worn on the body cannot be removed this way.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps, object tgtarm, string armname) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents you.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You are dead and cannot do that.");

  if (!tgt)
    FAIL("Divest who of what?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (!sizeof(weps))
    FAIL("You must use a blade.");

  if (tp == tgt)
    FAIL("Just drop it, it will look less stupid.");

  if (tp->query(DIVEST_USE_PROP) > time())
    FAIL("You cannot find an opening!");

  if (!tgtarm)
    FAIL(capitalize(tgt->query_subjective())+" is not wearing "+
      (armname ? indefinite_article(armname) : "anything you can dislodge")+"!");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  if (tp->query_sp() < 50)
    FAIL("You are too tired.");

  return 1;
}

int cmd_divest(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt, tgtarm;
  object *weps, *tgtarmours;
  string armname, tgtname;
  int hit, miss, cost;

  if (!abil()) return 0;

  if (str) {
    if (sscanf(str, "%s of %s", tgtname, armname) == 2) {
      tgt = present(tgtname, env);
      if (tgt) tgtarm = present(armname, tgt);
    }
    else {
      string *tmp = explode(str, " ");
      int i = sizeof(tmp);
      if (i == 1)
        tgt = present(str, env);
      else {
        for (i -= 1; i >= 0; i--) {
          if (tgt = present(implode(tmp[0..i], " "), env)) {
            armname = implode(tmp[i+1..<1], " ");
            tgtarm = present(armname, tgt);
            break;
          }
        }
      }
    }
  }

  if (!tgt)
    tgt = tp->query_current_attacker();

  if (!tgtarm && tgt) {
    if (armname)
      tgtarm = present(armname, tgt);
    else {
      tgtarmours = filter(all_inventory(tgt), (:
        ($1->query_worn() == $2 && member_array($1->query_type(), $3) != -1)
      :), tgt, allowed_types);
      if (sizeof(tgtarmours))
        tgtarm = tgtarmours[random(sizeof(tgtarmours))];
    }
  }

  weps = filter(tp->query_wielded(), (: $1->query_type() == "blade" :) );

  if (!can_cast(tp, tgt, weps, tgtarm, armname)) return 0;

  hit = tp->query_stats("dexterity");
  hit += tp->query_skill("entertainment");
  hit += tp->query_skill("blade")/3;

  miss = tgt->query_stats("dexterity")*3/2;
  miss += tgt->query_skill("defense")*60/100;
  miss += random(tgt->query_skill("perception")/3);

  if (tgt->query(DIVEST_PROP) > time())
    miss = miss * 150/100;

  cost = miss*40/100;

  if (member_array(tgtarm->query_type(), allowed_types) == -1) {
    miss = hit + 100;
    cost = 40+random(10);
  }

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->kill_ob(tgt);
  tp->add_sp(-(cost-random(10)));
  tp->set(DIVEST_USE_PROP, time()+DIVEST_DELAY);
  tgt->set(DIVEST_PROP, time()+6);

  armname = remove_article(strip_color(tgtarm->query_short()));

  if (miss > hit) {
    message("combat", "You try to divest "+tgt->query_cap_name()+
      " of "+tgt->query_possessive()+" "+armname+", but you can't "
      "get it to come off.", tp);
    message("combat", tp->query_cap_name()+" tries to remove your "+armname+
      "with "+tp->query_possessive()+" blade, but "+
      tp->query_subjective()+" fails.", tgt);
    message("combat", tp->query_cap_name()+" tries to divest "+
      tgt->query_cap_name()+" of "+tgt->query_possessive()+" "+armname+
      ", but fails.", env, ({ tp, tgt }) );
    return 1;
  }

  message("combat", "You "+COL2+"sli"+COL+"p"+RES+" your "+COL+"blade"+RES+
    " smoothly past "+tgt->query_cap_name()+"'s defenses and "+
    COL+"f"+COL2+"lic"+COL+"k"+RES+" the point downward, "+
    COL2+"dis"+COL+"lo"+COL2+"dgi"+COL+"n"+COL2+"g"+RES+" "+
    tgt->query_possessive()+" "+armname+"!", tp);
  message("combat", tp->query_cap_name()+" "+COL2+"sli"+COL+"ps"+RES+
    " "+tp->query_possessive()+" "+COL+"blade"+RES+
    " smoothly past your defenses and "+
    COL+"f"+COL2+"lic"+COL+"k"+RES+" the point downward, "+
    COL2+"dis"+COL+"lo"+COL2+"dgi"+COL+"n"+COL2+"g"+RES+" "+
    "your "+armname+"!", tgt);
  message("combat", tp->query_cap_name()+" "+COL2+"sli"+COL+"ps"+RES+
    " "+tp->query_possessive()+" "+COL+"blade"+RES+
    " smoothly past "+tgt->query_cap_name()+"'s defenses and "+
    COL+"f"+COL2+"lic"+COL+"k"+RES+" the point downward, "+
    COL2+"dis"+COL+"lo"+COL2+"dgi"+COL+"n"+COL2+"g"+RES+" "+
    tgt->query_possessive()+" "+armname+"!", env, ({ tp, tgt }) );

  message("combat", capitalize(definite_article(armname))+" falls to the ground.", env);

  tgtarm->set_theft(1);
  tgtarm->move(env);
  tgtarm->set_theft(0);
  
  return 1;
}

