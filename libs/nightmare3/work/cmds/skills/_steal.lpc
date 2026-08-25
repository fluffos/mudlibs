 
/*     _steal.c
 *     Rogue ability
 *     coded by Descartes of Borg October 1992
 *     small modifications by Hanse November 1992
 *     changed to make stealing harder for non-rogues and to allow
 *     the stealing of wielded/worn objects by powerful rogues
 *     by Gregon October 1993
 *     Heavily revised by Bohemund March 1994
 *       - check for available light
 *       - removed useless variables
 *       - added a function to handle the moving of the stolen object
 *       - cleaned up messages
 *       - checked weight of item being stolen (heavier = harder)
 *       - revised the way wielded/worn items are stolen (monster now
 *         attacks when the player fails)
 *       - alignment is calculated (randomly 1-10) depending on the
 *         alignment of the victim (i.e. stealing from good beings
 *         makes you more evil and stealing from evil beings makes
 *         you good)
 *       - added defines for easier configuration
 *     Slightly modified by Bohemund March 1994
 *       - check if monster does not allow stealing
 *       - neaten up a string or two
 */

#include <std.h>
#define WEIGHT_PENALTY 20
#define INVIS_PENALTY 75
#define WIELD_PENALTY 50
#define WORN_PENALTY 75
#define NONROGUE_PENALTY 30
#define RANDOM_RANGE 120 

inherit DAEMON;

void handle_move(object ob, object tp);
 
int cmd_steal(string str) {
  object *inv, victim, tp, ob;
  string what, whom;
  int i, skip, which, steal, x, align_formula;

/* Various checking */

  tp = this_player();
  if(tp->query_ghost()) {
    notify_fail("You cannot do that in your immaterial state.\n");
    return 0;
  }
  if(environment(tp)->query_property("no steal")) {
    notify_fail("A magic force prevents you from doing that!\n");
    return 0;
  }
  if(!str) {
    notify_fail("Steal what from whom?\n");
    return 0;
  }
  if(tp->query_disable()) return 1;
  if(sscanf(str, "%s from %s", what, whom) != 2) {
    notify_fail("Steal what from whom?\n");
    return 0;
  }
  if(tp->query_current_attacker()) {
    notify_fail("You cannot do that while in combat!\n");
    return 0;
  }
  victim = present(whom, environment(tp));
  if(!victim) {
    notify_fail(capitalize(whom)+" is not here!\n");
    return 0;
  }
  if(!living(victim)) {
    notify_fail(capitalize(whom)+" is not a living thing!\n");
    return 0;
  }
  if(victim->is_player() && !interactive(victim)) {
    notify_fail("You cannot steal from link-dead players.\n");
    return 0;
  }
  tp->set_disable();
  if(creatorp(victim)) {
    notify_fail(victim->query_cap_name()+" glares at you hard.\n");
    return 0;
  }
  if((int)victim->query_level() == 1) {
    notify_fail("Let the newbie alone!\n");
    return 0;
  }
  if(victim->query_property("no steal")) {
    notify_fail((string)victim->query_cap_name()+" cannot be "
		"stolen from!\n");
    return 0;
  }
  if(total_light(tp) < -1) {
    notify_fail("It is too dark.\n");
    return 0;
  }
  ob = present(what, victim);
  if(victim == tp) {
    notify_fail("Steal from yourself?\n");
    return 0;
  }
  if(!ob) {
    inv = all_inventory(victim);
    if(sscanf(what, "%s %d", what, which) != 2) {
      notify_fail(capitalize(whom)+" does not have that!\n");
      return 0;
    }
    for(i=0, skip=0; i<sizeof(inv) && !ob; i++) {
      if(inv[i]->id(what)) {
	skip ++;
	if(skip == which) ob = inv[i];
      }
    }
    if(!ob) {
      notify_fail(capitalize(whom)+" does not have that!\n");
      return 0;
    }
  }
  
  if(!ob->get()) {
    notify_fail("You cannot steal that!\n");
    return 0;
  }
  if(ob->query_property("no steal")) {
    write((string)victim->query_cap_name()+"'s "+(string)ob->query_name()+
	  " cannot possibly be stolen.");
    return 1;
  }

/* Calculations */

  steal = (int)tp->query_skill("stealing");
  steal -= (int)victim->query_stats("dexterity");
  x = random(RANDOM_RANGE);
  if((int)victim->query_alignment() >= 0)
    align_formula = -random(10);
  else align_formula = random(10);
  if(ob->query_wielded()) steal -= WIELD_PENALTY;
  if(ob->query_worn()) {
    if((string)ob->query_type() == "armour" || 
       (string)ob->query_type() == "body armour") {
      notify_fail("That would be impossible!\n");
      return 0;
    }
    steal -= WORN_PENALTY;
  }
  if(victim->query_invis()) steal -= INVIS_PENALTY;
  if((int)ob->query_weight() > 800) steal -= WEIGHT_PENALTY;
  if((string)tp->query_class() != "rogue") steal -= NONROGUE_PENALTY;
  x -= steal;

/* Display messages */

  if(x < 0) {
    write("You successfully steal "+victim->query_cap_name()+"'s "
	  +ob->query_name()+".\n"+capitalize(nominative(victim))+" does "
	  "not even notice!");
    tp->add_alignment(align_formula);
    if((string)tp->query_class() != (string)victim->query_class())
      tp->add_skill_points("stealing", 10);
    handle_move(ob, tp);
    return 1;
  }
  if(x < 10) {
    write("You successfully steal "+victim->query_cap_name()+"'s "+
	  ob->query_name()+".\nYou are not sure if anyone noticed.");
    tell_room(environment(tp), tp->query_cap_name()+
	      " steals a "+ob->query_name()+" from "+
	      victim->query_cap_name()+".", ({ victim, tp }) );
    tp->add_alignment( align_formula );
    if((string)tp->query_class() != (string)victim->query_class())
      tp->add_skill_points("stealing", 8);
    handle_move(ob, tp);
    return 1;
  }
  if(x < 20) {
    write("You successfully steal "+victim->query_cap_name()+"'s "+
	  ob->query_name()+".\nYou are not sure if anyone noticed.");
    tell_object(victim, "You feel someone brush against you.");
    tell_room(environment(tp), tp->query_cap_name()+" slyly brushes "
	      "by "+victim->query_cap_name()+" and steals a "+
	      ob->query_name()+"",  ({ tp, victim }) );
    tp->add_alignment( align_formula );
    if((string)tp->query_class() != (string)victim->query_class())
      tp->add_skill_points("stealing", 6);
    handle_move(ob, tp);
    return 1;
  }
  if(x < 30) {
    write("You successfully steal "+victim->query_cap_name()+"'s "+
	  ob->query_name()+".\nYou are not sure if anyone noticed.");
    tell_object(victim, tp->query_cap_name()+" just stole your "+
		ob->query_name()+"!");
    tell_room(environment(tp), tp->query_cap_name()+" steals a "+
	      ob->query_name()+" from "+victim->query_cap_name()+".", 
	      ({ victim, tp }) );
    tp->add_alignment( align_formula );
    if((string)tp->query_class() != (string)victim->query_class())
      tp->add_skill_points("stealing", 5);
    if(!victim->is_player()) victim->kill_ob(tp, 0);
    handle_move(ob, tp);
    return 1;
  }
  if(x < 40) {
    write("You fail to steal "+victim->query_cap_name()+"'s "+
	  ob->query_name()+", but no one notices the attempt.");
    if((string)tp->query_class() != (string)victim->query_class())
      tp->add_skill_points("stealing", 4);
    return 1;
  }
  if(x < 50) {
    write("You fail to steal "+victim->query_cap_name()+"'s "+
	  ob->query_name()+".\nYou are unsure if anyone noticed the attempt.");
    tell_room(environment(tp), tp->query_cap_name()+" attempts to steal "
	      "something from "+victim->query_cap_name()+".", 
	      ({ victim, tp }) );
    if((string)tp->query_class() != (string)victim->query_class())
      tp->add_skill_points("stealing", 3);
    return 1;
  }
  if(x < 60) {
    write("You fail to steal "+victim->query_cap_name()+"'s "+
	  ob->query_name()+".\nYou are unsure if anyone noticed the attempt.");
       tell_room(environment(tp), tp->query_cap_name()+" slyly brushes by "+
		 victim->query_cap_name()+".", ({ victim, tp }) );
    tell_object(victim, "You feel someone brush against you.");
    if((string)tp->query_class() != (string)victim->query_class())
      tp->add_skill_points("stealing", 2);
    return 1;
  }
  write("You fail to steal "+victim->query_cap_name()+"'s "+  
	ob->query_name()+".\nYou are unsure if anyone noticed the attempt.");
  tell_room(environment(tp), tp->query_cap_name()+" attempts to steal "
	    "something from "+victim->query_cap_name()+
	    ", but fails.", ({ victim, tp }) );
  tell_object(victim, tp->query_cap_name()+" just tried to steal a "+
	      ob->query_name()+" from you!\nLuckily, "+
	      nominative(tp)+" failed!");
  if((string)tp->query_class() != (string)victim->query_class())
    tp->add_skill_points("stealing", 1);
  if(!victim->is_player()) victim->kill_ob(tp, 0);
  return 1;
}
 
void handle_move(object ob, object tp) {
  if(ob->move(tp)) {
    write("You cannot carry that!\nYou drop "+ob->query_name()+".");
    say(tp->query_cap_name()+" drops "+ob->query_name()+".", tp);
    ob->move(environment(tp));
  }
}

void help() {
  message("help", "Syntax: <steal [item] from [being]>\n"
	  "The steal command allows you to steal objects from other "
	  "players and monsters.  A fight can automatically ensue if "
	  "a monster becomes aware of your attempt.  And you never "
	  "know what a player might do.  The command is sometimes "
	  "successfull, and sometimes the victim or others might notice, "
	  "or sometimes no one will notice at all.  It all depends "
	  "on your ability to steal, the lighting, and other factors.\n", 
	  this_player());
}
