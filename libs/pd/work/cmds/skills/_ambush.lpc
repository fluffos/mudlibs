
#include <std.h>
#include <daemons.h>
#include <rooms.h>
#include <damage_types.h>
#include <damage.h>

#define RES "%^RESET%^"
#define COL RES+"%^BLUE%^"
#define COL2 "%^BOLD%^%^BLUE%^"

#define FAIL(s) return notify_fail(s+"\n")
#define RETFAIL(s) return message("info", s, tp)

#define AMBUSH_OB "/cmds/skills/obj/ambush_ob"
#define COMMAND_OB "/cmds/skills/obj/command"
#define AMBUSH_OB_ID "ambush_ob"
#define AMBUSH_CMD_ID "ambush_cmd"

#define AMBUSH_PROP "ambush_abil_ob"
#define AMBUSH_TIME "ambush_abil_time"

inherit DAEMON;

void ambush_off(object tp);

object *who = ({});

mapping wepmods = ([
  "axe" : 20,
  "blade" : 20,
  "blunt" : 26,
  "flail" : 12,
  "knife" : 40,
  "projectile" : 32,
  "ranged" : 42
]);

int abil() {
  object tp = this_player();

  if (tp->query_subclass() == "assassin" &&
      tp->query_skill("murder") >= 21*6 &&
      tp->query_skill("perception") >= 21*4)
        return 1;

  if (tp->query_subclass() == "scout" &&
      tp->query_skill("murder") >= 35*2 &&
      tp->query_skill("perception") >= 35*6)
        return 1;

  if (tp->query_subclass() == "ranger" &&
      tp->query_skill("perception") >= 35*5 &&
      tp->query_skill("discipline") >= 35*5)
        return 1;

  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <ambush (who)>\n\n"
    "This is the ability to hide in a room and hit somebody "
    "with a surprise attack as soon as he enters. Any weapon "
    "will work, though some are better suited than others.\n"
    "You can use <ambush> with no arguments to ambush the next "
    "living thing that enters.",
    this_player() );
}

int can_cast(object tp, string tgt, object *wep) {
  object tmp;

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You can't hurt anyone as a ghost!");

  if (!sizeof(wep))
    FAIL("Ambushing with your bare hands wouldn't do much.");

  if (strlen(tgt) && objectp(tmp = find_player(tgt)) && interactive(tmp)) {

    if (tmp == tp)
      FAIL("But you already know that you're here!");

    if (!tmp->query_invis(tp) && !tp->ok_to_kill(tmp))
        FAIL("You may not attack "+tmp->query_cap_name()+".");

  }

  if (tp->clean_up_attackers())
    FAIL("You are too busy fighting!");

  if (tp->query_riding())
    FAIL("You can't ambush while riding!");

  if (sizeof(tp->query_riders()))
    FAIL("You are far too encumbered by your riders!");

  if (tp->query_sp() < 40)
    FAIL("You are too tired.");

  if (tp->query(AMBUSH_PROP))
    FAIL("You are already trying to ambush someone!");

  return 1;
}

int cmd_ambush(string str) {
  object tp = this_player();
  object env = environment(tp);
  object ob, cmd;

  if (!abil()) return 0;

  if (!can_cast(tp, str, tp->query_wielded())) return 0;

  if (!(ob = new(AMBUSH_OB)) || !(cmd = new(COMMAND_OB)))
    FAIL("An error has occurred. Please contact a staff member.");

  ob->set_id(({AMBUSH_OB_ID}));
  ob->set_owner(tp);
  ob->set_who(str);
  ob->move(env);
  ob->set_start(1);

  cmd->set_id(cmd->query_id()+({AMBUSH_CMD_ID}));
  cmd->set_catchall(1);
  cmd->set_function(this_object(), "check_command");
  cmd->move(tp);

  tp->set(AMBUSH_PROP, ob);
  tp->add_sp(-5);
  who += ({ tp });
  set_heart_beat(1);

  message("combat", "You cr"+COL+"ouc"+RES+"h d"+COL+"ow"+RES+"n "
    "and prepare to "+COL2+"ambush"+RES+" "+
    (strlen(str) ? capitalize(str) : "somebody")+".", tp);

  if (!tp->use_stealth(3))
    message("combat", tp->query_cap_name()+
      " cr"+COL+"ouch"+RES+"es d"+COL+"ow"+RES+"n.", env, tp);

  return 1;
}

void heart_beat() {
  foreach (object p in who) {
    object ob;
    if (!p) { who -= ({ p }); continue; }
    ob = p->query(AMBUSH_PROP);
    if (!objectp(ob) || environment(p) != environment(ob) ||
        p->query_current_attacker() || p->query_ghost()) {
          ambush_off(p);
    }
  }
  if (!sizeof(who)) set_heart_beat(0);
}

void ambush_off(object tp) {
  object ob;
  if (!tp) return;
  who -= ({ tp });
  ob = tp->query(AMBUSH_PROP);
  if (ob) ob->remove();
  ob = present(AMBUSH_CMD_ID, tp);
  if (ob) ob->remove();
  tp->set(AMBUSH_PROP, 0);
}

int check_command(string str) {
  object tp = this_player();
  object env = environment(tp);
  int off = 0;

  if (!strlen(str)) return 0;

  if (env->query_exit(str) != ROOM_VOID)
    off = 1;

  if (env->query_exit(env->query_full_direction(str)) != ROOM_VOID)
    off = 1;

  str = tp->query_alias(str);
  if (strlen(str) && env->query_exit(str) != ROOM_VOID)
    off = 1;

  if (off)
    call_out("ambush_off", 0, tp);

  return 0;
}

// this returns an int, which is unused, so I can use RETFAIL
int do_ambush(object tp, object tgt) {
  int dmg, rank, hit, miss, cost;
  string *skills;
  string type, wepname;
  object *weps, *quivers;
  object wep;

  if (!tp || !tgt) return 0;

  ambush_off(tp);

  if (environment(tgt) != environment(tp))
    RETFAIL("Your victim has eluded you!");

  if (tp->query_riding())
    RETFAIL("You can't ambush while riding!");

  if (sizeof(tp->query_riders()))
    RETFAIL("You are too encumbered by your riders to ambush!");

  if (tp->query_busy())
    RETFAIL("You are too busy to ambush!");

  if (tp->query_ghost())
    RETFAIL("Your ethereal form can't hurt anyone.");

  if (tp->query_current_attacker())
    RETFAIL("You are too busy fighting to ambush!");

  message("combat", "You see "+tgt->query_cap_name()+" coming and prepare "
      "to ambush "+tgt->query_objective()+"!", tp);

  if (!tp->ok_to_kill(tgt))
    RETFAIL("You can't attack "+tgt->query_cap_name()+".");

  weps = sort_array(tp->query_wielded(),
    (: $1->query_wc() > $2->query_wc() ? 1 : 0 :)
  );
  if (!sizeof(weps))
    RETFAIL("You realize you're not wielding anything!");

  wep = weps[0];
  type = wep->query_type();
  if (type == "ranged") {
    quivers = filter(all_inventory(tp), (: ($1->is_quiver() && $1->query_arrows()) :) );
    if (!sizeof(quivers)) {
      weps = filter(weps, (: $1->query_type() != "ranged" :) );

      if (!sizeof(weps))
        RETFAIL("You realize you have no arrows to shoot!");

      wep = weps[0];
      type = wep->query_type();
    }
  }
  if (type == "ranged")
    wepname = "arrow";
  else
    wepname = wep->query_name();
  
  hit = tp->query_stats("dexterity")*3;
  hit += tp->query_skill("perception");
  hit += tp->query_skill("murder");
  hit += tp->query_skill("discipline");
  if (tp->use_stealth(3))
    hit += 40;
  if (tp->query_invis(tgt))
    hit += 80;

  miss = tgt->query_stats("dexterity")*3;
  miss += tgt->query_skill("perception");
  miss += tgt->query_skill("defense")/2;
  miss += tgt->query_skill("agility")*3/4;

  switch (tp->query_subclass()) {
    case "ranger":
      skills = ({ "discipline" });
    break;
    case "scout":
      skills = ({ "agility", "murder", "perception" });
    break;
    case "assassin":
      skills = ({ "agility", "murder" });
    break;
  }
  skills += ({ "perception", type });

  // careful of this part if reqs are lowered below level 20
  rank = tp->query_level()/10;
  if (rank > 4) rank = 4;
  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    skills,
    ({ "dexterity" }),
    ({ "dexterity", "strength" })
  );

  dmg += (wep->query_wc() * wepmods[type]);

  if (tp->query_subclass() == "assassin")
    dmg = dmg*160/100;
  else
    dmg = dmg*150/100;

  cost = BALANCE3_D->get_cost(dmg, rank, "sp") * 120 / 100;

  if (tp->query_sp() < cost)
    RETFAIL("You are too tired.");

  if (!tp->kill_ob(tgt))
    RETFAIL("You can't attack "+tgt->query_cap_name()+".");

  if (type == "ranged")
    quivers[0]->use_arrow();

  if (hit < miss + random(35) - random(35)) {
    tp->add_sp(-cost/3);
    message("combat", "You narrowly escape being struck by "+
        a_or_an(wepname)+" "+wepname+"!", tgt);
    RETFAIL("You miss completely!");
  }

  tp->add_sp(-cost);

  message("combat", "Your "+COL2+wepname+RES+" str"+COL+"ik"+RES+"es "+
      tgt->query_cap_name()+" in the side!", tp);
  message("combat", "You are "+COL2+"suddenly "+COL+"struck"+COL2+
      " in the "+COL+"side"+RES+" with "+
      a_or_an(wepname)+" "+wepname+"!", tgt);

  tgt->do_damage("target", dmg, DAMAGE_PHYSICAL | wep->query_damage_type(), wep->query_damage_flags(), tp);
  tp->set(AMBUSH_TIME,  ({ time(), tgt }) );

  return 1;
}

