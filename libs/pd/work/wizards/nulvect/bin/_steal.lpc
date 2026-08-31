//     _steal.c
//     Rogue ability
//     coded by Descartes of Borg October 1992
//     small modifications by Hanse November 1992
//     changed to make stealing harder for non-rogues and to allow
//     the stealing of wielded/worn objects by powerful rogues
//     by Gregon October 1993
//  [*]Small changes made by the -(Inferno)-    ->
//     Non rogues may no longer steal, and stealing of worn/wielded
//     items has been fixed and modified, and exp added-*-Stormbringer
//
//     rewritten for cleaner code and using balance daemon
//     Nulvect 20080315

#include <std.h> 
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "thief" &&
      tp->query_skill("stealing") >= 8*6)
        return 1;
  return 0;
}

string type() { return "deception"; }

void help() {
  message("help",
    "Syntax: <steal [item] from [who]>\n\n"
    "This lets you try to steal an item from someone. If you get "
    "caught, you may be attacked or branded an outlaw. Your ability "
    "to steal is very important to avoid being noticed, and sneaking "
    "around helps too.",
    this_player());
}

int can_cast(object tp, object tgt, object item) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no steal") || tp->query_arena())
    FAIL("Some force prevents your mischief.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You cannot do that in your immaterial state.");

  if (!tgt || !item)
    FAIL("Steal what from whom?");

  if (!living(tgt))
    FAIL("That isn't alive.");

  if (tgt == tp)
    FAIL("You swipe it out of one pocket and stuff it in another.");

  if (tgt->is_player()) {

    // FAIL("You cannot steal from players.");

    if (!interactive(tgt))
      FAIL("You cannot steal from link-dead players.");

    if (tp->is_player()) {

      if (wizardp(tgt) && !wizardp(tp))
        FAIL("You would surely be punished for such insolence.");

      if (tp->query_level() < 20)
        FAIL("You are protected from PK, so "+tgt->query_subjective()+
             " is protected from your sticky fingers.");

      if (tgt->query_level() < 20)
        FAIL("You may not steal from newbies.");

    }
  }

  if (tgt->query_property("no steal"))
    FAIL("You cannot steal from "+tgt->query_objective()+".");

  if (item->query_property("no steal") || !item->get())
    FAIL("You cannot steal that.");

  if (tp->clean_up_attackers())
    FAIL("You are too busy fighting!");

  if (tp->query_sp() < 35)
    FAIL("You are too tired.");

  return 1;
}

int cmd_steal(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt, item;
  string who, what;
  string mymsg, yourmsg, theirmsg;
  int steal, kill, outlaw, perc, stealskill, exp, stolen, gotitem, rank;

  kill = outlaw = perc = stealskill = stolen = exp = gotitem = 0;
  mymsg = yourmsg = theirmsg = "";

  if (!abil()) return 0;

  if (str && sscanf(str, "%s from %s", what, who) == 2)
    tgt = present(who, env);
  if (tgt)
    item = present(what, tgt);

  if (!can_cast(tp, tgt, item)) return 0;

  tp->set_disable(1);
  tp->add_sp(-(30+random(10)));
  tp->add_alignment(-(3+random(3)));

  rank = 1 + tp->query_level()/14;
  if (rank > 4) rank = 4;

  steal = BALANCE3_D->get_steal(tp, tgt, rank,
    ({ "stealing", "stealing", "stealing", "stealth" }),
    ({ "charisma", "dexterity" }) );

  if (steal > 15) steal = 15+(steal-15)/3;

  if (item->query_wielded() || item->query_worn())
    steal /= 2;

  steal -= item->query_weight();

  // recycle this var
  what = remove_article(strip_color(item->query_short()));

  if (steal < -11) {
    mymsg = "You fail to steal "+tgt->query_cap_name()+"'s "+what+".\n"
      "You are not sure if anyone noticed.";
    yourmsg = "You catch "+tp->query_cap_name()+
      " trying to steal your "+what+"!\n"
      "Luckily, "+tp->query_subjective()+" failed.";
    theirmsg = tp->query_cap_name()+" brushes up against "+
      tgt->query_cap_name()+".";
    perc = 50;
    outlaw = 1;
    kill = 1;
  }
 
  else if (steal < -1) {
    mymsg = "You fail to steal "+tgt->query_cap_name()+"'s "+what+".\n"
      "You are not sure if anyone noticed.";
    yourmsg = "You feel someone trying to take your "+what+"!";
    perc = 25;
    if (steal < -5)
      outlaw = 1;
    if (random(100) < 50) {
      kill = 1;
      outlaw = 1;
    }
  }

  else if (steal < 6) {
    gotitem = 1;
    if (steal+50 < tgt->query_skill("perception")) {
      yourmsg = "You feel someone brush up against you.";
      perc = 15;
      if (random(100) < 40)
        kill = 1;
    }
  }

  else
    gotitem = 1;

  if (gotitem) {
    if (!strlen(mymsg))
      mymsg = "You successfully steal "+tgt->query_cap_name()+"'s "+what+".\n";
    if (!strlen(yourmsg))
      mymsg += capitalize(tgt->query_subjective())+" does not even notice!";
    else
      mymsg += "You are not sure if anyone noticed.";
    exp = tp->query_steal_exp(tp, tgt) / (1+tp->query_stolen(tgt));
    if (item->query_weight() > 18)
      stolen = 2;
    else
      stolen = 1;
    stealskill = steal*6;
    //set_theft makes it show no messages when unequipping
    item->set_theft(1);
    item->unequip();
    if (!item)
      mymsg = "The "+what+" suddenly vanishes.";
    else {
      item->set_theft(0);
      if (item->move(tp)) {
        mymsg += "\n\nIt is too heavy for you to carry, and you drop it!";
        yourmsg += tp->query_cap_name()+" drops "+indefinite_article(what)+".";
        theirmsg += tp->query_cap_name()+" drops "+indefinite_article(what)+".";
        item->move(env);
      }
    }
  }
  else {
    exp = tp->query_steal_exp(tp, tgt)/7;
    stolen = 3;
    stealskill = 10+random(8);
  }

  if (tp->query_arena()) {
    outlaw = 0;
    exp = 0;
    stolen = 0;
    //ARENA_D->set_stolen(tp, tgt, item);
  }

  tp->add_exp(exp);
  tp->add_stolen(tgt, stolen);
  tp->add_skill_points("stealing", stealskill);
  tp->use_stealth(11);

  if (kill && tgt->is_monster())
    mymsg = replace_string(mymsg, "\nYou are not sure if anyone noticed.", "");

  message("info", mymsg, tp);
  if (strlen(yourmsg))
    message("info", yourmsg, tgt);
  if (strlen(theirmsg))
    message("info", theirmsg, env, ({ tp, tgt }) );

  if (tgt->is_player()) {
    if (outlaw)
      tp->caught_theft();
    if (perc > 0)
      tgt->add_skill_points("perception", perc);
  }

  if (kill && tgt->is_monster()) {
    tgt->force_me("kill "+tp->query_name());
    tgt->kill_ob(tp);
  }

  return 1;
}

