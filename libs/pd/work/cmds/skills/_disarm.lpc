
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^BOLD%^%^WHITE%^"
#define COL2 "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

#define DISARM_PROP "disarm_abil_time"
#define DISARM_USE_PROP "disarm_abil_used_time"
#define DISARM_DELAY 2

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "swashbuckler" &&
      tp->query_skill("blade") >= 26*6 &&
      tp->query_skill("defense") >= 26*5)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <disarm [who] [weapon]>\n\n"
    "Allows you to try to disarm your opponent. "
    "This is a hostile act.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps, object tgtwep, string wepname) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents you.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You are dead and cannot do that.");

  if (!tgt)
    FAIL("Disarm who?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (!sizeof(weps))
    FAIL("You can only disarm using a blade.");

  if (tp == tgt)
    FAIL("Just drop your weapon, it will look less stupid.");

  if (tp->query(DISARM_USE_PROP) > time())
    FAIL("You cannot find an opening!");

  if (!tgtwep)
    FAIL(capitalize(tgt->query_subjective())+" is not wielding "+
      (wepname ? indefinite_article(wepname) : "anything")+"!");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  if (tp->query_sp() < 40)
    FAIL("You are too tired.");

  return 1;
}

int cmd_disarm(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt, tgtwep;
  object *weps, *tgtweps;
  string wepname, dir;
  string *dirs;
  int hit, miss, cost;
  mixed dest;

  if (!abil()) return 0;

  if (str) {
    string *tmp = explode(str, " ");
    int i = sizeof(tmp);
    if (i == 1)
      tgt = present(str, env);
    else {
      for (i -= 1; i >= 0; i--) {
        if (tgt = present(implode(tmp[0..i], " "), env)) {
          wepname = implode(tmp[i+1..<1], " ");
          tgtwep = present(wepname, tgt);
          break;
        }
      }
    }
  }

  if (!tgt)
    tgt = tp->query_current_attacker();

  if (!tgtwep && tgt) {
    if (wepname)
      tgtwep = present(wepname, tgt);
    else if (sizeof(tgtweps = tgt->query_wielded()))
      tgtwep = tgtweps[random(sizeof(tgtweps))];
  }

  weps = filter(tp->query_wielded(), (: $1->query_type() == "blade" :) );

  if (!can_cast(tp, tgt, weps, tgtwep, wepname)) return 0;

  hit = tp->query_stats("dexterity");
  hit += tp->query_skill("entertainment")/2;
  hit += tp->query_skill("blade")/3;

  miss = tgt->query_stats("dexterity");
  miss += tgt->query_skill("defense")/2;
  miss += random(tgt->query_skill("perception")/3);

  if (tgt->query(DISARM_PROP) > time())
    miss = miss * 125/100;

  cost = miss/3;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->kill_ob(tgt);
  tp->add_sp(-(cost-random(10)));
  tp->set(DISARM_USE_PROP, time()+DISARM_DELAY);
  tgt->set(DISARM_PROP, time()+10);

  if (miss > hit) {
    message("combat", "You try to disarm "+tgt->query_cap_name()+
      " with your blade, but "+tgt->query_subjective()+" keeps "+
      tgt->query_possessive()+" grip.", tp);
    message("combat", tp->query_cap_name()+" tries to disarm you "
      "with "+tp->query_possessive()+" blade, but you keep your grip.", tgt);
    message("combat", tp->query_cap_name()+" tries to disarm "+
      tgt->query_cap_name()+" with a blade, but "+
      tgt->query_subjective()+" keeps "+tgt->query_possessive()+" grip.",
      env, ({ tp, tgt }) );
    return 1;
  }

  wepname = definite_article(strip_color(tgtwep->query_short()));
  wepname = replace_string(wepname, " (wielded)", "");

  message("combat", "With a "+
    COL+"de"+COL2+"f"+COL+"t s"+COL2+"p"+COL+"in"+RES+" of your "+
    COL+"blade"+RES+", you w"+COL2+"re"+RES+"nch "+
    wepname+" out of "+tgt->query_cap_name()+"'s grip!", tp);
  message("combat", "With a "+
    COL+"de"+COL2+"f"+COL+"t s"+COL2+"p"+COL+"in"+RES+" of "+
    tp->query_possessive()+" "+
    COL+"blade"+RES+", "+tp->query_cap_name()+
    " w"+COL2+"re"+RES+"nches "+
    wepname+" out of your grip!", tgt);
  message("combat", "With a "+
    COL+"de"+COL2+"f"+COL+"t s"+COL2+"p"+COL+"in"+RES+" of "+
    tp->query_possessive()+" "+
    COL+"blade"+RES+", "+tp->query_cap_name()+
    " w"+COL2+"re"+RES+"nches "+
    indefinite_article(wepname)+
    " out of "+tgt->query_cap_name()+"'s grip!", env, ({ tp, tgt }) );

  if (hit > miss*125/100) {
    dirs = env->query_exits();
    dirs = filter(dirs,
      function(string d, object room) {
        string *doors = room->query_doors_blocking_exit(d);
        if (!doors || !sizeof(doors)) return 1;
        foreach (string door in doors)
          if (room->query_closed(door))
            return 0;
        return 1;
      }, env);
    if (sizeof(dirs)) {
      dir = dirs[random(sizeof(dirs))];
      dest = env->query_exit(dir);
      switch (dir) {
        case "enter":
          dir = "through the entrance";
        break;
        case "out":
          dir = "through the exit";
        break;
        case "north": case "south":
        case "east": case "west":
        case "northwest": case "northeast":
        case "southwest": case "southeast":
          dir = "to the "+dir;
        break;
      }
      message("combat", capitalize(wepname)+" flies "+dir+"!", env);
    }
  }
  if (!dest) {
    dest = env;
    message("combat", capitalize(wepname)+" clatters to the ground.", env);
  }

  tgtwep->set_theft(1);
  tgtwep->move(dest);
  if (tgtwep) tgtwep->set_theft(0);
  
  return 1;
}

