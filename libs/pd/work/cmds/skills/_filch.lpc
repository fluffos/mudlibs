// steal an object from a container
// rewritten by Nulvect 20080329, original author unknown

#include <std.h> 
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int sortitems(object, object, int);

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "thief" &&
      tp->query_skill("stealing") >= 20*6)
        return 1;
  return 0;
}

string type() { return "deception"; }

void help() {
  message("help",
    "Syntax: <filch from [whose] [bag]>\n\n"
    "This command will allow a thief to attempt to steal "
    "from a container that someone is carrying. Smarter thieves can "
    "usually grab the more valuable things first.",
    this_player());
}

int can_cast(object tp, object tgt, object bag, string bagname) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no steal") || tp->query_arena())
    FAIL("Some force prevents your mischief.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You don't even have a body.");

  if (!tgt)
    FAIL("Filch from whom?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("That would be pointless.");

  if (tgt->is_player()) {

    // FAIL("You may not steal from players.");

    if (!interactive(tgt))
      FAIL("You may not steal from link-dead players.");

    if (tp->is_player()) {

      if (wizardp(tgt) && !wizardp(tp))
        FAIL("You would surely be punished for such insolence.");

      if (tp->query_level() < 20)
        FAIL("You are protected from PK, so "+tgt->query_subjective()+
             "is protected from your sticky fingers.");

      if (tgt->query_level() < 20)
        FAIL("You may not steal from newbies.");

      if (!tp->ok_to_kill(tgt))
        FAIL("You may not steal from "+tgt->query_objective()+".");
    }
  }

  if (!bag)
    FAIL(capitalize(tgt->query_subjective())+" does not have "+
         (strlen(bagname) ? indefinite_article(bagname) : "any bags")+".");

  if (tp->clean_up_attackers())
    FAIL("You are too busy fighting!");

  if (tp->query_sp() < 40)
    FAIL("You are too tired to filch properly.");

  return 1;
}

int cmd_filch(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt, bag, item;
  object *allbags, *allitems;
  string who, bagname, what;
  string mymsg, yourmsg, theirmsg;
  int rank, steal, exp, kill, outlaw, perc, stealskill, stolen, gotitem;
  int tmp;

  exp = gotitem = kill = outlaw = stealskill = stolen = 0;

  if(!abil()) return 0;

  if (str) {
    if (str[0..4] == "from ") str = str[5..<1];
    if (sscanf(str, "%s's %s", who, bagname) == 2) {
      tgt = present(who, env);
      if (tgt)
        bag = present(bagname, tgt);
    }
    else
      tgt = present(str, env);
  }

  if (tgt && !bag) {
    allbags = filter(all_inventory(tgt), (: $1->is_bag() :) );
    if (sizeof(allbags))
      bag = allbags[random(sizeof(allbags))];
  }

  if (!can_cast(tp, tgt, bag, bagname)) return 0;

  tp->set_disable(1);
  tp->add_sp(-(20+random(20)));
  tp->add_alignment(-(3+random(4)));

  rank = 3;

  steal = BALANCE3_D->get_steal(tp, tgt, rank,
    ({ "stealing", "stealing", "stealing",
       "stealth", "agility", "perception" }),
    ({ "dexterity", "dexterity", "dexterity", "charisma", "intelligence" }) );

  steal = steal*4/3;

  if (steal > 20) steal = 20+(steal-20)/3;

  allitems = filter(all_inventory(bag), (:
    (!($1->query_property("no steal")) && $1->get())
  :) );

  tmp = 100 - (
    (tp->query_skill("perception")-100)/2 + tp->query_stats("intelligence")
  );
  if (tmp < 0) tmp = 0;
  allitems = sort_array(allitems, (: sortitems :), tmp);

  // the 3 random()s make it much more likely to get items near index 0,
  // where sort_array above (hopefully) puts lighter and more valuable
  // items based on your perception / intel
  if (sizeof(allitems)) {
    item = allitems[random(random(random(sizeof(allitems)+2)))];
    what = remove_article(strip_color(item->query_short()));
    steal -= item->query_weight();
  }
  else
    steal -= 5;

  bagname = remove_article(strip_color(bag->query_short()));

  if (steal < -9) {
    mymsg = "You fail to steal anything from "+
      tgt->query_cap_name()+"'s "+bagname+".\n"
      "You are not sure if anyone noticed.";
    yourmsg = "You catch "+tp->query_cap_name()+
      " trying to steal something from your "+bagname+"!\n"
      "Luckily, "+tp->query_subjective()+" failed.";
    theirmsg = tp->query_cap_name()+" brushes up against "+
      tgt->query_cap_name()+"'s "+bagname+".";
    perc = 40;
    outlaw = 1;
    kill = 1;
  }

  else if (steal < 0) {
    mymsg = "You fail to steal anything from "+
      tgt->query_cap_name()+"'s "+bagname+".\n"
      "You are not sure if anyone noticed.";
    yourmsg = "You feel someone's hand in your "+bagname+"!";
    perc = 20;
    if (steal < -4)
      outlaw = 1;
    if (random(100) < 40) {
      theirmsg = tp->query_cap_name()+" brushes up against "+
        tgt->query_cap_name()+"'s "+bagname+".";
      kill = 1;
      outlaw = 1;
    }
  }

  else if (steal < 6) {
    gotitem = 1;
    if (steal+70 < tgt->query_skill("perception")) {
      yourmsg = "You feel someone brush up against your "+bagname+".";
      perc = 10;
      if (random(100) < 35)
        kill = 1;
    }
  }

  else
    gotitem = 1;

  if (gotitem) {
    if (!sizeof(allitems)) {
      mymsg = "You feel around in "+tgt->query_cap_name()+"'s "+bagname+
              ", but it is empty!";
      exp = tp->query_steal_exp(tp, tgt) / (2+tp->query_stolen(tgt));
      stolen = 1;
      stealskill = steal*3;
    }
    else {
      if (!strlen(mymsg))
        mymsg = "You successfully steal "+indefinite_article(what)+
                " from "+tgt->query_cap_name()+"'s "+bagname+".\n";
      if (!strlen(yourmsg))
        mymsg += capitalize(tgt->query_subjective())+" does not even notice!";
      else
        mymsg += "You are not sure if anyone noticed.";
      exp = tp->query_steal_exp(tp, tgt) / (1+tp->query_stolen(tgt));
      if (item->query_weight() > bag->query_weight()/2)
        stolen = 2;
      else
        stolen = 1;
      stealskill = steal*7;
      if (item->move(tp)) {
        mymsg += "\n\nIt is too heavy for you to carry, and you drop it!";
        yourmsg += tp->query_cap_name()+" drops "+indefinite_article(what)+".";
        theirmsg += tp->query_cap_name()+" drops "+indefinite_article(what)+".";
        item->move(env);
      }
    }
  }
  else {
    exp = tp->query_steal_exp(tp, tgt)/6;
    stolen = 3;
    stealskill = 5+random(10);
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


int sortitems(object a, object b, int tmp) {
  int aw = a->query_weight();
  int bw = b->query_weight();
  mapping acv = a->query_curr_value();
  mapping bcv = b->query_curr_value();
  int agv = (acv && acv["gold"] ? acv["gold"] : 0);
  int bgv = (bcv && bcv["gold"] ? bcv["gold"] : 0);
  aw -= agv;
  bw -= bgv;
  
  aw -= bw;
  aw = aw + random(tmp) - random(tmp);

  if (aw < 0) return -1;
  else if (aw > 0) return 1;
  else return 0;
}
