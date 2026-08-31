
#include <std.h>
#include <daemons.h>
#include <dirs.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^BLUE%^"
#define COL2 "%^BOLD%^%^GREEN%^"

#define JUGGLING_BALL DIR_CLASS_CMDS+"/obj/pocket/ball"
#define JUGGLING_TEXT \
COL+"j"+COL2+"u"+COL+"g"+COL2+"g"+COL+"l"+COL2+"e"+RES
#define JUGGLE_CHUCK_COLORS ({\
  "blue", "green", "cyan", "orange", "magenta",\
})

#define JUGGLE_PROP "juggle_abil_time"
#define JUGGLE_TIME 10

inherit DAEMON;

void hit_target(mixed *arr);

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "jester" &&
      tp->query_skill("entertainment") >= 14*6)
        return 1;
  return 0;
}

string type() { return "deception"; }

void help() {
  message("help",
    "Syntax: <juggle [for whom]>\n\n"
    "An entertaining ability for jesters, they juggle "
    "several items for a while to catch everybody's attention. "
    "They can then throw things at their target to catch "
    "him off guard.\n\n"
    "Many things can be juggled, including knives, swords, axes, "
    "flames, and some food.",
    this_player() );
}

int can_cast(object tp, object tgt, object *obs) {
  int x;

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your mischief.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Ooh, scary, a juggling ghost.");

  if ((x = sizeof(tp->query_wielding_limbs())+1 - sizeof(obs)) > 0)
    FAIL("You need "+cardinal(x)+" more thing"+(x==1?"":"s")+" to juggle!");

  if (tgt) {
    if (!tgt->is_living())
      FAIL("That is not alive.");
    if (tgt == tp)
      FAIL("Juggle for yourself?");
    if (!tp->ok_to_kill(tgt))
      FAIL("You cannot attack "+tgt->query_cap_name()+".");
  }

  if (tp->clean_up_attackers())
    FAIL("You are too busy fighting!");

  if (tp->query_sp() < 60)
    FAIL("You are too tired to juggle.");

  return 1;
}


int cmd_juggle(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object *livs, *obs;
  int hit;
  string how, mymsg;

  if (!abil()) return 0;

  if (str)
    sscanf(str, "for %s", str);

  if (str)
    tgt = present(str, env);

  obs = filter(all_inventory(tp),
  function(object ob) {
    if (base_name(ob) == JUGGLING_BALL)
      return 1;
    if (ob->query_property("juggle"))
      return 1;
    if (ob->is_weapon() && !ob->query_wielded() &&
    member_array(ob->query_type(), ({ "knife", "axe", "blade" }) ) != -1)
      return 1;
    if (ob->query_lit())
      return 1;
    if (ob->is_food())
      return 1;
    return 0;
  } );

  if (!can_cast(tp, tgt, obs)) return 0;

  switch (tp->query_level()) {
    case 1..20: how = " clumsily"; break;
    case 21..30: how = " gracefully"; break;
    case 31..40: how = " skillfully"; break;
    default: how = " masterfully"; break;
  }

  message("info", "You "+JUGGLING_TEXT+" things"+how+"!", tp);
  message("info", tp->query_cap_name()+" starts to "+JUGGLING_TEXT+
      " things"+how+"!", env, tp);

  hit = tp->query_skill("entertainment");
  hit += tp->query_stats("charisma")*3;
  if ((int)tp->query(JUGGLE_PROP)+JUGGLE_TIME > time())
    hit /= 2;
  
  livs = filter(all_inventory(env) - ({ tp }),
  function(object ob, string party) {
    string p;
    if (!ob->is_living())
      return 0;
    if (strlen(party) && strlen(p = ob->query_party()) && p == party)
      return 0;
    return 1;
  }, tp->query_party() );

  foreach (object liv in livs) {
    int miss;

    miss = liv->query_skill("perception");
    miss += liv->query_stats("intelligence")*3;

    if (miss+random(25)-random(10) > hit)
      livs -= ({ liv });

  }

  if (sizeof(livs)) {
    mymsg = "The audience seems to like it";
    livs->set_paralyzed(2,
      "You can't take your eyes off of "+tp->query_cap_name()+
      "'s juggling!");
    if (tgt && member_array(tgt, livs) != -1) {
      mymsg += "!";
      call_out("hit_target", 2, ({ tp, tgt, obs }) );
      tp->set_paralyzed(4, "You are juggling.", "");
    }
    else {
      if (tgt) mymsg += ", but "+tgt->query_cap_name()+" is not entertained.";
      else mymsg += "!";
      tp->set_paralyzed(2, "You are juggling.", "You finish juggling.");
    }

  }
  else {
    mymsg = "Nobody seems to be very entertained.";
    tp->set_paralyzed(2, "You are juggling.", "You finish juggling.");
  }

  message("info", mymsg, tp);
  tp->add_sp(-(35+random(25)));
  tp->set(JUGGLE_PROP, time());

  return 1;
}

void hit_target(mixed *arr) {
  object tp = arr[0];
  object tgt = arr[1];
  object *obs = arr[2];
  object env;
  int max, dmg, tmp;
  string *randcolors = JUGGLE_CHUCK_COLORS;

  if (!tp) return;

  env = environment(tp);
  if (!tgt || environment(tgt) != env) {
    message("info", "Your target is not here!", tp);
    return;
  }

  tp->kill_ob(tgt);

  max = sizeof(obs);
  tmp = sizeof(tp->query_wielding_limbs());
  if (tmp > 2 && max > 6) max = 6;
  else if (max > 5) max = 5;

  if (tp->query_level() < 25) max -= 1;
  if (random(200) > 140) max -= 1;

  dmg = BALANCE3_D->get_damage(tp, tgt, 2,
    ({ "entertainment" }),
    ({ "dexterity", "strength" }) );
  dmg /= 6;

  foreach (object ob in obs[0..max-1]) {
    int wc;
    string what;
    string col;
    int dtype, dflags;

    what = indefinite_article(strip_color(ob->query_short()));
    random(5);
    col = randcolors[random(sizeof(randcolors))];
    col = "%^"+upper_case(col)+"%^";
    if (random(15) < 8) col = "%^BOLD%^"+col;
    col = RES+col;

    message("combat", "You "+col+"chuck"+RES+
      " "+what+" at "+tgt->query_cap_name()+"!", tp);
    message("combat", tp->query_cap_name()+" "+col+"chucks"+RES+
      " "+what+" at you!", tgt);
    message("combat", tp->query_cap_name()+" "+col+"chucks"+RES+
      " "+what+" at "+tgt->query_cap_name()+"!", env, ({ tp, tgt }) );

    if (ob->is_weapon()) {
      wc = ob->query_wc()*2;
      dtype = ob->query_damage_type();
      dflags = ob->query_damage_flags();
    }
    else if (ob->query_lit()) {
      wc += random(30);
      dtype = DAMAGE_PHYSICAL | DAMAGE_IMPACT | DAMAGE_FIRE;
      dflags = DAMAGE_NO_SEVER;
    }
    else {
      wc += 10 - absolute_value(8 - ob->query_weight());
      dtype = DAMAGE_PHYSICAL | DAMAGE_IMPACT;
      dflags = DAMAGE_NO_SEVER;
    }
    
    tgt->do_damage("target", dmg+wc, dtype, dflags, tp);
    tp->add_sp(-(12+random(6)));

    if (ob->move(tgt) || random(100) < 50)
      ob->move(env);

  }

  tp->remove_paralyzed();
  tp->set_disable();

}

