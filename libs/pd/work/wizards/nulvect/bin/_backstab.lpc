#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^BLUE%^"
#define COL2 "%^RED%^"

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp &&
      member_array(tp->query_subclass(), ({ "assassin", "thief" }) ) != -1 &&
      tp->query_skill("murder") >= 5 && tp->query_skill("agility") >= 5)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <backstab [victim] [limb]>\n\n"
    "This silent attack lets an assassin stab his victim before "
    "the victim knows he's even there. Thieves have some skill "
    "at backstabbing as well, since they excel at sneaking around.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps, string limb) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You are a ghost.");

  if (!sizeof(weps))
    FAIL("You need to use a knife for that.");

  if (!tgt)
    FAIL("Backstab who?");

  if (!living(tgt))
    FAIL("You stab it, but it doesn't respond.");

  if (tp == tgt)
    FAIL("A rather difficult way to kill yourself.");

  if (tp->query_rest_type())
    FAIL("You need to be standing first.");

  if (limb && !tgt->query_is_limb(limb))
    FAIL(capitalize(tgt->query_subjective())+
         " does not have "+a_or_an(limb)+" "+limb+".");

  if (sizeof(tp->query_attackers()))
    FAIL("You are already in combat.");

  if (member_array(tgt, tp->query_hunted()) != -1 ||
      member_array(tgt, tp->query_attackers()) != -1)
        FAIL("You have lost the element of surprise!");

  if (userp(tgt) && !interactive(tgt))
    FAIL("You cannot attack a link-dead player.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  if (tp->query_sp() < 50)
    FAIL("You are too tired.");

  return 1;
}

int cmd_backstab(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object *weps;
  int caught, stealth, perc;
  string limb;

  if (!abil()) return 0;

//  if (str) tgt = present(str, env);

  if (str) {
    string *tmp = explode(str, " ");
    int i = sizeof(tmp);
    if (i == 1)
      tgt = present(str, env);
    else {
      for (i -= 2; i >= 0; i--) {
        if (tgt = present(implode(tmp[0..i], " "), env)) {
          limb = implode(tmp[i+1..<1], " ");
          break;
        }
      }
    }
  }

  weps = filter(tp->query_wielded(), (: $1->query_type() == "knife" :) );

  if (!can_cast(tp, tgt, weps, limb)) return 0;

  perc = tgt->query_skill("perception")*4/3;
  perc += tgt->query_stats("intelligence");
  perc += tgt->query_stats("wisdom");

  stealth = tp->query_skill("stealth");
  stealth += tp->query_skill("agility")*4/9;
  stealth += tp->query_stats("dexterity")*3/5;
  if (tp->query_invis())
    stealth *= 1.5;
  else if (tp->use_stealth(15))
    stealth += 50;

  caught = perc - stealth;
  if (caught < 0) caught = 0;
  else if (caught < 10) caught = 10;
  
  if (caught)
    message("combat", tp->query_cap_name()+" attempts to "
                      +COL+"sneak behind"+RES+" you unnoticed!", tgt);

  message("combat", "You "+COL+"sneak around"+RES+" behind "+
                    tgt->query_cap_name()+".", tp);

  tp->set_disable();
  tp->set_paralyzed(6, "You are trying to stab someone.");
  tp->add_alignment(-5);
  tp->add_sp(-5);
  call_out("finish_backstab", 2, ({ tp, tgt, weps, caught, limb }) );

  return 1;
}

void finish_backstab(mixed *args) {
  object tp = args[0];
  object tgt = args[1];
  object *weps = args[2];
  int caught = args[3];
  string limb = args[4];
  object env, knife;
  int rank, dmg, cost, wc, tmp;
  float mod;
  string lname, kname;
  string *limbs, *skills, *stats, *extra;

  if (!tp) return;

  tp->set_paralyzed(0);

  if (!(env = environment(tp))) return;

  if (!tgt || environment(tgt) != env) {
    message("info", "Your victim is not here.", tp);
    return;
  }

  if (!tp->kill_ob(tgt)) {
    message("info", "You cannot attack "+tgt->query_cap_name()+".", tp);
    return;
  }

  //use the highest WC of all wielded knives
  knife = sort_array(weps,
         (: $1->query_wc() > $2->query_wc() ? 1 : 0 :)
  )[0];
  wc = knife->query_wc();
  kname = knife->query_name();
  if (!strlen(kname)) kname = "knife";

  if (caught &&
      tgt->query_stats("dexterity")*3/4 +
      random(tgt->query_stats("dexterity")/4+caught*2) >
      tp->query_stats("dexterity") + 5) {
        message("combat", "Your "+kname+" misses its mark as "+
                          tgt->query_cap_name()+" dodges aside!", tp);
        message("combat", tp->query_cap_name()+" tries to stab you from behind, "
                          "but you easily dodge "+tp->query_possessive()+" "+
                          kname+".", tgt);
        message("combat", tp->query_cap_name()+" misses a sneak attack "
                          "against "+tgt->query_cap_name()+"!",
                          env, ({ tp, tgt }) );
        return;
  }

  if (!limb || random(200) >
      tp->query_stats("dexterity")/2 + tp->query_skill("perception")/5) {
        // try to get a limb with one of these words in the name
        limbs = regexp(tgt->query_limbs(), "torso|body|abdomen|head");
        if (!sizeof(limbs))
          limb = tgt->return_target_limb();
        else
          limb = limbs[random(sizeof(limbs))];
  }
  switch (limb) {
    case "head": lname = "neck"; break;
    case "torso": lname = "back"; break;
    default: lname = limb;
  }

  switch (tp->query_level()) {

    case 1..19:
      rank = 2;
      skills = ({ "murder", "murder", "agility", "knife" });
      stats = ({ "strength", "dexterity" });
      extra = ({});
    break;

    case 20..39:
      rank = 3;
      skills = ({ "murder", "murder", "murder",
                  "agility", "agility", "knife" });
      stats = ({ "strength", "dexterity", "dexterity" });
      extra = ({ "strength", "dexterity", "dexterity", "intelligence" });
    break;

    default: // 41..*
      rank = 4;
      skills = ({ "murder", "murder", "murder",
                  "agility", "agility", "knife" });
      stats = ({ "strength", "dexterity", "dexterity" });
      extra = ({ "strength", "dexterity", "dexterity",
                 "dexterity", "intelligence" });

  }
  if (sizeof(tp->query_wielded()) > 1)
    skills += ({ "double wielding" });
  
  dmg = BALANCE3_D->get_damage(tp, tgt, rank, skills, stats, extra);

  if (tp->query_level() < 20)
    mod = 1.3;
  else {
    /*
    int l;
    if (userp(tp) && userp(tgt))
      l = tgt->query_stats("dexterity")/6;
    else
      l = 6;
    */
    tmp = tp->query_stats("dexterity")*4/3*(2+rank);
    tmp += tp->query_skill("murder")*3/4;
    /*
    mod = tmp / (
      (tgt->query_stats("dexterity")/2 + tgt->query_skill("defense")/9)*l
    );
    */
    mod = tmp / (tgt->query_stats("dexterity")*5.0);
    if (mod < 1.3) mod = 1.3;
    if (mod > 1.5) mod = 1.5 + (mod-1.5)/2.5;
    if (mod > 1.9) mod = 1.9 + (mod-1.9)/2.0;
  }

  dmg += wc*20;
  dmg *= mod;

  if (regexp(limb, "hand|claw|paw|foot|hoof|fang|teeth|horn|tail"))
    dmg /= 2;
  else if (regexp(limb, "arm|leg|wing"))
    dmg = dmg*3/4;

  cost = log(pow(dmg, 3))+dmg/50-random(6);

  dmg -= tgt->query_ac(limb)*25;
  dmg -= caught*15;

  message("combat", "Your "+kname+" "+COL2+"sinks deeply"+RES+" into "+
                    tgt->query_cap_name()+"'s "+lname+"!", tp);
  message("combat", capitalize(a_or_an(kname))+" "+kname+" "+
                    COL2+"sinks deeply"+RES+" into your "+lname+"!", tgt);

  tp->add_sp(-cost);
  tp->add_skill_points("murder", dmg/20);

  if (dmg >= tgt->query_max_hp())
    dmg = tgt->query_max_hp()*3/4 + dmg/5 + random(dmg/5);


  tgt->do_damage(limb, dmg);

  if (random(100) < wc*2)
    tgt->add_bleeding(random(dmg/7));

  // second hit depends on agility
  tmp = tp->query_skill("agility");
  if (tmp > 300) tmp = 300+(tmp-300)/3;

  // bonus to chance for second hit
  switch (tp->query_subclass()) {
    case "assassin": tmp += 0; break;
    case "thief": tmp += 80; break;
    default: tmp += 0;
  }

  if (rank > 2 && random(1200) < tmp) {
    dmg /= 3+random(2);
    message("combat", "In a "+COL2+"flash"+RES+", you "+
                      "pl"+COL+"ung"+RES+"e"
                      " your "+kname+
                      " into "+tgt->query_cap_name()+" again!",tp);
    message("combat", "A second "+COL2+"flash"+RES+" of "
                      "p"+COL2+"ai"+RES+"n and st"+COL+"ee"+RES+"l "+
                      COL2+"rips"+RES+" through your "+lname+"!", tgt);
    tgt->do_damage(limb, dmg);
  }

  if (tgt->query_hp() < 1)
    tgt->heart_beat();
  
}
