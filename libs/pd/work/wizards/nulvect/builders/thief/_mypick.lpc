//      _pick.c
//      Rogue ability
//      created 04 November 1992 by Descartes of Borg
//      almost completely rewritten by Nulvect 2006-07-12
#include <std.h>
#include <money.h>

#define CURRENCIES ({"platinum","gold","electrum","silver","copper"})

inherit DAEMON;

int do_pick(object tp, object ob, int steal, int resist);

int abil() {
  object tp=this_player();
  if (tp->query_class() == "rogue" &&
      tp->query_skill("stealing") >= 15) return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <pick [living]>\n\n"
    "The ability to pickpocket from someone, perhaps getting some money.\n"
    "If a player catches you, you may be branded an outlaw.",
    this_player() );
}

void make_outlaw(object tp) {
  if (file_name(environment(tp))[0..9] == "/d/freepk/")
    return;
  if (wizardp(tp))
    message("info","If you weren't immortal, you'd have gained a theft offense.",tp);
  else
    tp->add_outlaw("theft", 1);
}

int cmd_mypick(string str) {
    object ob, tp;
    int level;
    int steal, resist;
    int stolen;
    int gotmoney;
    
    tp = this_player();

    if (!abil())
      return 0;

    if(tp->query_ghost())
        return notify_fail("You cannot do that in your immaterial state.\n");

    if(environment(tp)->query_property("no steal"))
        return notify_fail("A magic force prevents you from doing that.\n");

    if(!str)
        return notify_fail("Pick whom?\n");

    if(tp->query_current_attacker())
        return notify_fail("You can't do that while in combat!\n");

    ob = present(str, environment(tp));
    if(!ob) ob = parse_objects(environment(tp), str);
    if(!ob)
        return notify_fail("No "+str+" here!\n");

    if(!living(ob))
        return notify_fail(capitalize(str)+" is not a living thing!\n");

/*
    if (ob->is_player()) {
      return notify_fail("You may not steal from players.\n");
*/

    if (ob->is_player()) {
      if(tp->query_level() < 20)
        return notify_fail("You are protected from PK, and as such, "
                           "they are protected from your sticky fingers.\n");
      if(ob->query_level() < 20)
        return notify_fail("You may not steal from newbies.\n");
    }

    if(wizardp(ob) && tp->is_player())
        return notify_fail("That is not advisable.\n");

    if(ob->is_player() && !interactive(ob))
      return notify_fail("You may not steal from link-dead players.\n");

    if(ob==tp)
        return notify_fail("You cannot pick your own pocket!\n");

    if(tp->query_disable())
        return notify_fail("You are too busy to try to pick!\n");

    tp->set_disable();
    
    level = tp->query_level();
    
    if (!(stolen = ob->query_property("stolen"))) stolen=0;
    
    steal = tp->query_skill("stealing")/12;
    steal += tp->query_skill("stealth")/15;
    steal += tp->query_stats("dexterity")/3;
    steal += tp->query_stats("charisma")/4;
    steal += tp->query_property("stealth")/25;
    if (tp->query_invis()) steal+=10;
    if (level < 10) steal+=level*2;
    else if (level < 15) steal+=level;
    else if (level < 20) steal+=level/2;
    
    resist = ob->query_skill("perception")/5;
    resist += ob->query_stats("dexterity")/2;
    resist += ob->query_stats("intelligence")/2;
    resist += stolen;
    resist += random(7);

    message("debug","steal: "+steal+", resist: "+resist, tp);
    
    steal -= resist;

    if (steal < -7) {
      message("info","You utterly fail to pick "+ob->query_cap_name()+"'s pocket.",tp);
      message("info","You catch "+tp->query_cap_name()+" trying to pick your pocket!",ob);
      message("info","You notice "+tp->query_cap_name()+" brush up against "+
                     ob->query_cap_name()+".", environment(tp), ({tp, ob}) );
      ob->add_skill_points("perception",30);
      if (ob->is_player())
        make_outlaw(tp);
      else
        ob->force_me("kill "+tp->query_name());
    }
    
    else if (steal < 5) {
      message("info","You fail to pick "+ob->query_cap_name()+"'s pocket.",tp);
      message("info","You feel a hand in your pocket.",ob);
      ob->add_skill_points("perception",15);
      if (steal < 0) {
        if (ob->is_player())
          make_outlaw(tp);
        else 
          ob->force_me("kill "+tp->query_name());
      }
    }
    
    else if (steal < 12) {
      if (gotmoney=do_pick(tp, ob, steal, resist))
        message("info","You pick some coins from "+ob->query_cap_name()+"'s pocket.",tp);
      else
        message("info",ob->query_subjective()+" seems to be broke!",tp);
      if (ob->query_skill("perception") > 50+steal) {
        message("info","You feel someone brush up against you.",ob);
        if (ob->is_monster())
          ob->force_me("kill "+tp->query_name());
      }
    }
    
    else {
      if (gotmoney=do_pick(tp, ob, steal, resist))
        message("info","You pick some coins from "+ob->query_cap_name()+"'s pocket.",tp);
      else
        message("info",ob->query_subjective()+" seems to be broke!",tp);
    }

    tp->add_alignment(-(5+random(5)));
    if (!gotmoney)
      ob->set_property("stolen", stolen+(resist*8/7));
    else
      ob->set_property("stolen", stolen+(resist*4/7));

    message("debug","stolen: "+ob->query_property("stolen"),tp);
    
    return 1;
}

int do_pick(object tp, object ob, int steal, int resist) {
  int gotit, c;
  mapping coins = ([ "all" : 0 ]);

  foreach (string curr in CURRENCIES) {
    if (ob->query_money(curr)) {
      coins["all"] += ob->query_money(curr);
      coins[curr] = ob->query_money(curr);
      message("debug",curr+": "+coins[curr],tp);
    }
  }

  if (coins["all"] == 0) {
    if (ob->is_monster())
      tp->add_exp((ob->query_exp()/2)/5);
    else
      tp->add_exp((ob->query_level()*1000)/5);
    return 0;
  }
     
  gotit = (coins["all"]*steal/4)/(resist);
  if (gotit > coins["all"]*3/5 && coins["all"] > 500)
    gotit = coins["all"]*3/5;

  if (ob->is_monster())
    tp->add_exp((ob->query_exp()/2)/3+gotit/2);
  else
    tp->add_exp((ob->query_level()*1000)/3+gotit/2);

  if (tp->query_skill("stealing")+tp->query_skill("perception") > 300) {
    while (gotit > 0) {
      message("debug","while1 "+gotit,tp);
      foreach (string curr in keys(coins)-({"all"}) ) {
        message("debug","foreach1 "+gotit,tp);
        c = random(gotit)+20;
        switch (curr) {
          case "platinum": c+=50; break;
          case "gold": c+=35; break;
          default:
        }
        if (c > coins[curr]) c=coins[curr];
        if (c > gotit) c=gotit;
        ob->add_money(curr, -c);
        tp->add_money(curr, c);
        gotit-=c;
      }
    }
  }

  else {
    while (gotit > 0) {
      message("debug","while2 "+gotit,tp);
      foreach (string curr in keys(coins)-({"all"}) ) {
        message("debug","foreach2 "+gotit,tp);
        c = random(gotit)+20;
        switch (curr) {
          case "copper": c+=50; break;
          case "silver": c+=35; break;
          default:
        }
        if (c > coins[curr]) c=coins[curr];
        if (c > gotit) c=gotit;
        ob->add_money(curr, -c);
        tp->add_money(curr, c);
        gotit-=c;
      }
    }
  }
  return 1;
}

