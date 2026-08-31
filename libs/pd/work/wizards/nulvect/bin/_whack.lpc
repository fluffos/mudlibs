
#include <std.h>
#include <daemons.h>

#define RES "%^RESET%^"
#define COL RES+"%^GREEN%^"
#define COL2 "%^BOLD%^%^GREEN%^"
#define COL3 "%^BOLD%^%^CYAN%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "jester" &&
      tp->query_skill("blunt") >= 23*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <whack [who]>\n\n"
    "This is a favorite attack of the jester. Using a blunt object, "
    "one can deftly whack his opponent and perhaps make him drop "
    "something.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You're dead!");

  if (!tgt)
    FAIL("Whack who?");

  if (!tgt->is_living())
    FAIL("That wouldn't be any fun.");

  if (tgt == tp)
    FAIL("Bonk.");

  if (!sizeof(weps))
    FAIL("You must use a blunt object for this.");

  if (tp->query_sp() < 50)
    FAIL("You are too tired.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_whack(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt, wep;
  object *weps;
  string wepname;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  weps = filter(tp->query_wielded(), (: $1->query_type() == "blunt" :) );

  if (!can_cast(tp, tgt, weps)) return 0;

  wep = weps[random(sizeof(weps))];
  wepname = remove_article(strip_color(wep->query_short()));
  wepname = replace_string(wepname, " (wielded)", "");

  message("combat", "You spin your "+wepname+" around.", tp);
  message("combat", tp->query_cap_name()+" spins "+tp->query_possessive()+
    " "+wepname+" around.", env, tp);

  tp->set_disable(2);

  call_out("do_whack_hit", 2, ({ tp, env, tgt, wep, wepname }) );

  return 1;
}

void do_whack_hit(mixed *args) {
  object tp = args[0];
  object env = args[1];
  object tgt = args[2];
  object wep = args[3];
  string wepname = args[4];
  object item;
  object *ai;
  int rank, dmg, cost;
  string limb, myverb, theirverb, itemname;

  if (!tp) return;

  if (environment(tp) != env) return;
  if (!tgt || environment(tgt) != env) {
    message("info", "Your opponent is not here!", tp);
    return;
  }
  if (!wep) {
    message("info", "Your weapon has vanished!", tp);
    return;
  }
  if (!tp->kill_ob(tgt)) {
    message("info", "You cannot attack "+tgt->query_cap_name()+".", tp);
    return;
  }

  if (tp->query_level() >= 50) rank = 3;
  else rank = 2;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "blunt", "attack" }),
    ({ "dexterity", "strength" }),
    ({ "strength", "dexterity" }) );

  dmg = dmg*18/10;

  cost = dmg/9;

  if (tp->query_sp() < cost) {
    message("info", "You are too tired to continue.", tp);
    return;
  }

  limb = tgt->return_target_limb();

  if (tp->query_stats("dexterity") < tgt->query_stats("dexterity")) {
    dmg /= 3;
    myverb = "just "+COL+"gr"+COL3+"a"+COL2+"z"+COL+"e"+RES;
    theirverb = "just "+COL+"gr"+COL3+"a"+COL2+"z"+COL+"es"+RES;
  }
  else {
    myverb = COL+"W"+COL2+"HA"+COL3+"C"+COL+"K"+RES;
    theirverb = COL+"W"+COL2+"HA"+COL3+"C"+COL+"KS"+RES;
    if (random(1000) < 250) {
      ai = filter(all_inventory(tgt), (:
        (!$1->query_wielded() && !$1->query_worn() &&
         !$1->query_property("keep") &&
         !$1->drop() && !$1->give())
      :) );
      if (sizeof(ai)) {
        ai = sort_array(ai,
        function(object a, object b) {
          mapping tmp;
          int vala, valb;

          tmp = a->query_curr_value();
          if (sizeof(tmp))
            vala = tmp["gold"] || 0;

          tmp = b->query_curr_value();
          if (sizeof(tmp))
            valb = tmp["gold"] || 0;

          if (vala < valb) return -1;
          else return 1;
        } );
        item = ai[random(random(random(sizeof(ai)+4)))];
      }
    }
  }

  message("combat", "You swing your "+wepname+" and "+myverb+
    " "+tgt->query_cap_name()+" in the "+limb+"!", tp);
  message("combat", tp->query_cap_name()+" swings "+
    indefinite_article(wepname)+" and "+theirverb+
    " you in the "+limb+".", tgt);
  message("combat", tp->query_cap_name()+" swings "+
    indefinite_article(wepname)+" and "+theirverb+
    " "+tgt->query_cap_name()+".", env, ({ tp, tgt }) );

  tgt->do_damage(limb, dmg);
  tp->add_sp(-cost);

  if (item) {
    itemname = indefinite_article(strip_color(item->query_short()));
    message("info", "You wince and drop "+itemname+".", tgt);
    message("info", tgt->query_cap_name()+" winces and drops "+itemname+".",
        env, tgt);
    item->move(env);
  }

}
