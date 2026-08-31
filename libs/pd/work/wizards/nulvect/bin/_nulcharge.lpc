
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^GREEN%^"
#define COL2 "%^BOLD%^%^BLUE%^"

#define CHARGE_PROP "charge_abil_data"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

// the races that can charge naturally, and the limbs they
// need in order to do so

// replaced this with standardized function calls
/*
mapping chargeraces = ([
  "centaur" :
    ([ "limbs" : ({"left fore hoof", "right fore hoof",
                   "left rear hoof", "right rear hoof",
                   "left foreleg", "right foreleg",
                   "left rear leg", "right rear leg"}) ]),
  "raknid" :
    ([ "limbs" : ({"left foreleg", "right foreleg",
                   "left rear leg", "right rear leg"}) ]),
  "weimic" :
    ([ "limbs" : ({"left front claw", "right front claw",
                   "left rear claw", "right rear claw",
                   "left foreleg", "right foreleg",
                   "left rear leg", "right rear leg"}) ]),
]);
*/

// each message is used for 100/sizeof() percent damage
// which is 16% for 6 messages (100/6 = 16.6666)
mixed *hitmsgs = ({
  ({"%^BOLD%^%^GREEN%^", "knicked", "barely"}),
  ({"%^GREEN%^", "scraped", "lightly"}),
  ({"%^ORANGE%^", "sliced", "badly"}),
  ({"%^YELLOW%^", "mutilated", "horribly"}),
  ({"%^BOLD%^%^WHITE%^", "destroyed", "terribly"}),
  ({"%^BOLD%^%^RED%^", "destroyed", "utterly"}),
});

int can_charge_swiftly(object tp);
int query_charge_race(object who);
object get_wep(object who);
void do_hit_msg(object tp, object tgt, int dmg, string limb);

int abil() {
  object tp=this_player();
  if (tp && tp->query_class() == "fighter" &&
      (tp->query_skill("riding") >= 10*5 ||
      tp->query_skill("charging") >= 10*5))
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  int swiftly = can_charge_swiftly(this_player());
  message("help",
    "Syntax: <charge [whom]>\n"+
    (swiftly ?
    "        <charge swiftly [whom]>\n" : "" )+
    "\n"
    "A fighter's ability to ride a mount and charge at an enemy. "
    "It can only be done to start combat, but can do massive damage "
    "if it hits. Those races that are too large to ride a mount "
    "can charge without one."+
    (swiftly ?
    "\n"
    "Paladins may charge swiftly into battle, reaching their foes more "
    "quickly at the cost of causing less damage." : ""),
    this_player() );
}

int can_charge_swiftly(object tp) {
  if (tp && tp->query_subclass() == "paladin")
    return 1;
  return 0;
}

int can_cast(object tp, object tgt, object wep,
object mount, int chargerace, int swiftly, int double) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot attack here.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your ethereal form would not do any damage.");

  if (!wep)
    FAIL("You must wield an axe, blunt, blade, or spear.");

  if (!tgt)
    FAIL("Charge at whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (!chargerace) {
    if (!mount)
      FAIL("You are not riding anything!");
    if (userp(mount) && !double)
      FAIL("You are not in control to charge.");
    if (tgt == mount || tgt == tp->query_mounted() || tgt == tp->query_rider())
      FAIL("That's impossible.");
  }
  else {
    string *sev = tp->query_severed_limbs();
    if (sizeof(sev)) {
      foreach (string limb in tp->query_walking_limbs()) {
	mapping tmp = RACE_D->query_limb_info(limb, tp->query_race());
	string attach = tmp["attach"];
	if (member_array(limb, sev) != -1) {
          FAIL("You cannot charge without your "+limb+"!");
	}
	if (member_array(attach, sev) != -1) {
          FAIL("You cannot charge without your "+attach+"!");
	}
      }
    }
  }

  if (tgt == tp)
    FAIL("That would be an amazing trick.");

  if (sizeof(tp->query_attackers()))
    FAIL("You are too busy fighting!");

  if (tp->query_rest_type())
    FAIL("You must stand up first!");

  if (swiftly && !can_charge_swiftly(tp))
    FAIL("You don't know how to charge swiftly.");

  if (tp->query_sp() < 100)
    FAIL("You are too tired to charge.");
  
  if (find_call_out( tp->query(CHARGE_PROP) || 0 ) != -1)
    FAIL("You are already charging!");

  return 1;
}

int cmd_nulcharge(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt, mount, rider, wep;
  string tgtname;
  int delay;
  int chargerace;
  int swiftly;

  if (!abil()) return 0;

  if (str) {
    if (sscanf(str, "swiftly %s", tgtname) == 1) {
      swiftly = 1;
    }
    else {
      tgtname = str;
    }
    sscanf(tgtname, "at %s", tgtname);
    tgt = present(tgtname, env);
  }

  wep = get_wep(tp);

  if (!(mount=tp->query_riding()))
    mount = tp->query_mounting();

  chargerace = query_charge_race(tp);

  if (!can_cast(tp, tgt, wep, mount, chargerace, swiftly, 0)) return 0;

  message("combat", "You "+COL+"charge"+RES+" "+
                    (swiftly ? COL2+"swiftly"+RES : "")+
                    " toward "+tgt->query_cap_name()+".", tp);
  message("combat", tp->query_cap_name()+" "+COL+"charges"+RES+" "+
                    (swiftly ? COL2+"swiftly"+RES : "")+
                    " toward you.", tgt);
  message("combat", tp->query_cap_name()+" "+COL+"charges"+RES+" "+
                    (swiftly ? COL2+"swiftly"+RES : "")+
                    " toward "+tgt->query_cap_name()+".", env, ({tp, tgt}) );

  if (chargerace) {
    delay = 2;
    rider = tp->query_mounted();
    if (!(objectp(rider) && living(rider) && rider->query_class() == "fighter"))
      rider = 0;
  }
  else
    delay = 2;

  if (swiftly)
    delay = 1;

  tp->set_disable(delay);
  tp->add_sp(-20);
  tp->set_paralyzed(delay*2, "You are charging at your enemy!", "");
  if (rider) {
    rider->set_disable(delay);
    rider->add_sp(-10);
  }

  // save the 'handle' of this call out, to ensure you can't charge while charging
  tp->set(CHARGE_PROP,
    call_out("continue_charge", delay*2, ({tp, tgt, wep, mount, rider, chargerace, swiftly, 0}) )
  );
  
  return 1;
}

int continue_charge(mixed args) {
  object tp=args[0];
  object tgt=args[1];
  object wep=args[2];
  object mount=args[3];
  object rider=args[4];
  int chargerace=args[5];
  int swiftly=args[6];
  int double=args[7];
  object env;
  object riderwep;
  int hit, dodge, dmg, rank, cost;
  int dtype = DAMAGE_PHYSICAL;
  string *skills = ({});
  string sk;
  string limb;

  if (!tp || tp->query_ghost() || !(env=environment(tp)))
    return 0;
  
  if (!tgt || tgt->query_ghost() || environment(tgt) != env) {
    message("combat", "You trot around.", tp);
    message("combat", tp->query_cap_name()+" trots around.", env, tp);
    return 0;
  }
  
  if (!wep || wep->query_wielded() != tp) {
    message("combat", "Your weapon is gone!", tp);
    return 0;
  }
        
  if (!chargerace && !(mount && environment(mount) == env &&
      (tp->query_riding() == mount || tp->query_mounting() == mount))) {
        message("combat", "Your mount is gone.", tp);
        return 0;
  }
    
  if (!tp->kill_ob(tgt)) {
    message("combat", "You may not attack "+tgt->query_cap_name()+".", tp);
    return 0;
  }

  if (chargerace)
    sk = "charging";
  else
    sk = "riding";

  skills = ({ "attack" });
  skills += ({ wep->query_type() });
  skills += ({ sk, sk });

  switch (tp->query_subclass()) {
    case "paladin":
      skills += ({"valor", "valor"});
    break;
    
    case "antipaladin": case "berserker":
      skills += ({"ferocity"});
    break;

    case "warrior": case "ranger":
      skills += ({"discipline"});
    break;
  }

  if (tp->query_level() >= 35)
    rank=4;
  else if (tp->query_level() >= 20)
    rank=3;
  else
    rank=2;

  if (double)
    rank--;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    skills,
    ({"strength","dexterity"}),
    ({"strength"}) );

  dmg += wep->query_wc()*7;

  if (chargerace)
    dmg = dmg * 300 / 100;
  else
    dmg = dmg * 260 / 100;

  if (swiftly)
    dmg = dmg * 55 / 100;

  /*
  cost = dmg/15+random(10);
  */
  cost = BALANCE3_D->get_cost(dmg, rank, "sp") * 125 / 100;

  if (double) {
    dmg = dmg * 80 / 100;
    cost = cost * 80 / 100;
  }
  else {
    hit = tp->query_stats("dexterity")*2;
    hit += tp->query_skill(sk)*2;
    hit += tp->query_skill("attack")*3/4;
    hit += tp->query_skill("discipline")/2;
    hit += tp->query_skill("valor")/2;
    hit += random(tp->query_level()+10);

    dodge = tgt->query_stats("dexterity")*2;
    dodge += tgt->query_skill("defense")*2;
    dodge += tgt->query_skill("agility")/2;
    dodge += random(tgt->query_level());

    if (userp(tp) && userp(tgt))
      dodge = dodge * 125 / 100;
    // we called kill_ob() to put us in combat already
    if (sizeof(tgt->query_attackers()) > 1)
      dodge = dodge * 60 / 100;
  }

  if (!(double || tgt->query_paralyzed() || tgt->query_rest_type()) &&
      dodge > hit) {
        message("combat", "Your charge misses.", tp);
        message("combat", tp->query_cap_name()+"'s charge misses.", env, tp);
        return;
  }

  if (hit > dodge && hit-dodge < 150)
    dmg -= (hit-dodge) * 350 / 100;

  limb = tgt->return_target_limb();

  switch (wep->query_type()) {
    case "projectile":
      dtype |= DAMAGE_PIERCE;
    break;
    case "blade":
      dtype |= DAMAGE_SLASH;
    break;
    case "blunt":
      dtype |= DAMAGE_IMPACT;
    break;
    case "axe":
      dtype |= DAMAGE_IMPACT | DAMAGE_SLASH;
    break;
  }

  do_hit_msg(tp, tgt, dmg, limb);

  tgt->do_damage(limb, dmg, dtype, 0, tp);
  tp->add_sp(-cost);

  if (!double)
    tp->set_paralyzed(0);

  tp->add_skill_points(sk, 20+dmg/40);

  // if it was a mortal blow, make sure the limb comes off - coolness factor
  if (tgt->query_hp() < 1 && member_array(limb, tgt->query_severed_limbs()) == -1) {
    tgt->heal_limb(limb, -(tgt->query_max_dam(limb)+10));
    tgt->check_on_limb(limb);
  }

  // double charge - a fighter riding another fighter
  if (rider) {
    riderwep=get_wep(rider);
    if (can_cast(rider, tgt, riderwep, tp, 0, swiftly, 1))
      continue_charge( ({ rider, tgt, riderwep, tp, 0, 0, swiftly, 1 }) );
  }
  
}

int query_charge_race(object who) {
  /*
  if (living(who) && member_array(who->query_race(), keys(chargeraces)) != -1)
    return 1;
  */
  if (living(who) && RACE_D->query_rideable(who->query_race()))
    return 1;
  return 0;
}

object get_wep(object who) {
  object ret;
  object *filt;
  object *sort;
  
  // this does a reverse sort on purpose to put the highest WC at sort[0]
  if (who && sizeof(who->query_wielded())) {
    filt = filter(who->query_wielded(),
      (: member_array($1->query_type(),
        ({ "axe", "blade", "blunt", "projectile" }) ) != -1 :) );
    if (sizeof(filt))
      sort = sort_array(filt,
        (: $1->query_wc() > $2->query_wc() ? -1 :
          ($2->query_wc() > $1->query_wc() ? 1 : 0) :) );
    if (sizeof(sort))
      ret = sort[0];
  }

  return ret;

}

void do_hit_msg(object tp, object tgt, int dmg, string limb) {

  int perc;
  int msgperc;
  int s, x;
  string *arr;

  if (!(tp && tgt && limb)) return;

  // what percentage of the victim's hp are we doing in damage??
  // grab a msg from the list, higher percent damage = higher msg
  perc = percent(dmg, tgt->query_hp());
  s = sizeof(hitmsgs);
  msgperc = 100/s;
  x = perc/msgperc;
  // x can be < 0 for second hit on a double charge
  if (x >= s || x < 0) x = s - 1;

  arr = hitmsgs[x];
   
  message("combat", "Your charge "+arr[0]+arr[1]+"%^RESET%^ "+
                    tgt->query_cap_name()+" "+arr[0]+arr[2]+"%^RESET%^ "
                    "in the "+limb+".", tp);
  message("combat", tp->query_cap_name()+"'s charge "+
                    arr[0]+arr[1]+"%^RESET%^ you "+
                    arr[0]+arr[2]+"%^RESET%^ in the "+limb+".", tgt);
  message("combat", tp->query_cap_name()+"'s charge "+
                    arr[0]+arr[1]+"%^RESET%^ "+tgt->query_cap_name()+" "+
                    arr[0]+arr[2]+"%^RESET%^ in the "+limb+".",
                    environment(tp), ({tp, tgt}) );
}
