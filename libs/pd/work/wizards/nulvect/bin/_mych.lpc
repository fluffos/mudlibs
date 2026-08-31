
#include <std.h>
#include <daemons.h>

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^GREEN%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

// the races that can charge naturally, and the limbs they
// need in order to do so
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
  message("help",
    "Syntax: <charge [whom]>\n\n"
    "A fighter's ability to ride a mount and charge at an enemy. "
    "It can only be done to start combat, but can do massive damage "
    "if it hits. Those races that are too large to ride a mount "
    "can charge without one.",
    this_player() );
}

int can_cast(object tp, object tgt, object wep, object mount, int chargerace, int double) {

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
    if (sizeof(sev))
      foreach (string limb in chargeraces[tp->query_race()]["limbs"])
        if (member_array(limb, sev) != -1)
          FAIL("You cannot charge without your "+limb+"!");
  }

  if (tgt == tp)
    FAIL("That would be an amazing trick.");

  if (sizeof(tp->query_attackers()))
    FAIL("You are too busy fighting!");

  if (tp->query_sp() < 100)
    FAIL("You are too tired to charge.");
  
  return 1;
}

int cmd_mych(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt, mount, rider, wep;
  int delay;
  int chargerace;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);

  wep = get_wep(tp);

  if (!(mount=tp->query_riding()))
    mount = tp->query_mounting();

  chargerace = query_charge_race(tp);

  if (!can_cast(tp, tgt, wep, mount, chargerace, 0)) return 0;

  message("combat", "You "+COL+"charge"+RES+" toward "+
                    tgt->query_cap_name()+".", tp);
  message("combat", tp->query_cap_name()+" "+COL+"charges"+RES+
                    " toward you.", tgt);
  message("combat", tp->query_cap_name()+" "+COL+"charges"+RES+
                    " toward "+tgt->query_cap_name()+".", env, ({tp, tgt}) );

  if (chargerace) {
    delay=1;
    rider=tp->query_mounted();
    if (!(objectp(rider) && living(rider) && rider->query_class() == "fighter"))
      rider=0;
  }
  else
    delay=2;

  tp->set_disable(delay);
  tp->add_sp(-20);
  if (rider) {
    rider->set_disable(delay);
    rider->add_sp(-10);
  }

  call_out("continue_charge", delay*2, ({tp, tgt, wep, mount, rider, chargerace, 0}) );
  
  return 1;
}

int continue_charge(mixed args) {
  object tp=args[0];
  object tgt=args[1];
  object wep=args[2];
  object mount=args[3];
  object rider=args[4];
  int chargerace=args[5];
  int double=args[6];
  object env;
  object riderwep;
  int hit, dodge, dmg, rank, cost;
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

  if (double)
    rank=2;
  else if (tp->query_level() >= 35)
    rank=4;
  else if (tp->query_level() >= 20)
    rank=3;
  else
    rank=2;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    skills,
    ({"strength","dexterity"}),
    ({"strength"}) );

  if (chargerace)
    dmg += wep->query_wc()*10;
  else
    dmg += wep->query_wc()*7;

  dmg *= 2.6;

  cost = dmg/16+random(10);

  if (double) {
    dmg *= 0.6;
    cost *= 0.6;
  }
  else {
    hit = tp->query_stats("dexterity")*2;
    hit += tp->query_skill(sk)*2;
    hit += tp->query_skill("attack");
    hit += tp->query_skill("discipline")/2;
    hit += random(tp->query_level()+10);

    dodge = tgt->query_stats("dexterity")*3;
    dodge += tgt->query_skill("defense")*2;
    dodge += tgt->query_skill("agility")/2;
    dodge += random(tgt->query_level());

    if (userp(tp) && userp(tgt))
      dodge *= 1.5;
    // we called kill_ob() to put us in combat already
    if (sizeof(tgt->query_attackers()) > 1)
      dodge *= 0.6;
  }

  if (!(double || tgt->query_paralyzed() || tgt->query_rest_type()) &&
      dodge > hit) {
        message("combat", "Your charge misses.", tp);
        message("combat", tp->query_cap_name()+"'s charge misses.", env, tp);
        return;
  }

  if (hit > dodge && hit-dodge < 150)
    dmg -= (hit-dodge)*2.2;

  limb = tgt->return_target_limb();

  do_hit_msg(tp, tgt, dmg, limb);

  tgt->do_damage(limb, dmg);
  tp->add_sp(-cost);

  // if it was a mortal blow, make sure the limb comes off - coolness factor
  if (tgt->query_hp() < 1 && member_array(limb, tgt->query_severed_limbs()) == -1) {
    tgt->heal_limb(limb, -(tgt->query_max_dam(limb)+10));
    tgt->check_on_limb(limb);
  }

  // double charge - a fighter riding another fighter
  if (rider) {
    riderwep=get_wep(rider);
    if (can_cast(rider, tgt, riderwep, tp, 0, 1))
      continue_charge( ({ rider, tgt, riderwep, tp, 0, 0, 1 }) );
    if (query_notify_fail())
      message("info", identify(query_notify_fail()), tp);
  }
  
}

int query_charge_race(object who) {
  if (living(who) && member_array(who->query_race(), keys(chargeraces)) != -1)
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
    sort = sort_array(filt,
      (: $1->query_wc() > $2->query_wc() ? -1 :
        ($2->query_wc() > $1->query_wc() ? 1 : 0) :) );
    ret = sort[0];
  }

  message("info", identify(ret), this_player() );
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
