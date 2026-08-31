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
#include <std.h> 
inherit DAEMON;
int abil();

string type() { return "deception"; }

void make_outlaw(object tp) {
  if (file_name(environment(tp))[0..9] == "/d/freepk/")
    return;
  tp->add_outlaw("theft", 1);
}

int cmd_steal(string str) {
    object *inv;
    object victim, tp, ob;
    string what, whom;
    int i, skip, which;
    int steal, anti, x;
    int align_formula;
 
    if(this_player()->query_ghost()) {
        notify_fail("You cannot do that in your immaterial state.\n");
         return 0;
    }
if(this_player()->query_arena() == 1) {
       notify_fail("A magic force prevents you from doing that!\n");
       return 0;
    }
    if(environment(this_player())->query_property("no steal")) {
       notify_fail("A magic force prevents you from doing that!\n");
       return 0;
    }
if(environment(this_player())->query_property("no attack")) {
       notify_fail("A magic force prevents you from doing that!\n");
       return 0;
    }
    if(!str) {
       notify_fail("Steal what from whom?\n");
       return 0;
    }
    if(this_player()->query_disable()) return 1;
    if(sscanf(str, "%s from %s", what, whom) != 2) {
       notify_fail("Steal what from whom?\n");
       return 0;
    }
    if(this_player()->query_current_attacker()) {
        notify_fail("You can't steal while in combat!\n");
        return 0;
    }
    tp = this_player();
    victim = present(whom, environment(tp));
    if(!victim) {
       notify_fail(capitalize(whom)+" is not here!\n");
       return 0;
    }
    if(!living(victim)) {
       notify_fail(capitalize(whom)+" is not a living thing!\n");
       return 0;
    }
    //if(victim->is_player()) return 0;
    if(victim->is_player() && !interactive(victim)) {
        notify_fail("You cannot steal from link-dead players.\n");
        return 0;
    }
    tp->set_disable();
    if(wizardp(victim) && !wizardp(this_player())) {
        notify_fail("Ooooh, no.. You do NOT want to try that!\n");
        this_player()->set_paralyzed(5, "You fear the gods now, don't you?");
        return 0;
    }
    if((int)victim->query_level() <= 20 &&
       victim->is_player()) {
        notify_fail("Alas, it would be too easy!\n");
        return 0;
    }
    if(this_player()->query_level() < 20 && victim->is_player()) {
      notify_fail("You are protected from PK, and as such, they are protected from your sticky fingers.\n");
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
        notify_fail("You fail to steal "+victim->query_cap_name()+
           "'s "+ob->query_name()+
           ".\nYou are unsure if anyone noticed the attempt.\n");
        return 0;
    }
    steal = tp->query_skill("stealing") + tp->query_stats("charisma")/4
      + tp->query_stats("dexterity")/4;
    anti = victim->query_skill("perception") +
      victim->query_stats("dexterity") + (victim->query_level());
    steal -= anti;
    if(steal < 0) steal = 1;
    x = random(101) + 30;
// The next couple lines simple makes the player remove/unwield
// the item if it is wielded/worn -- no one sees the unwield/remove
      if(ob->query_worn()) {
        ob->set_theft(1);
        victim->force_me("remove " + ob->query_id()[0]);
        if (!ob) {
          message("steal","You almost got it, but it vanished!",tp);
          return 1;
        }
        ob->set_theft(0);
        steal -= 20;
       }
      if(ob->query_wielded()) {
        ob->set_theft(1);
        victim->force_me("unwield " + ob->query_id()[0]);
        if (!ob) {
          message("steal","You almost got it, but it vanished!",tp);
          return 1;
        }
        ob->set_theft(0);
        steal -= 15;
       }
// If the theft is unoticed, exp is given based upon success.
    if((string)tp->query_subclass()!="thief") steal /= 2;
    if(steal > x) {
       write("You successfully steal "+victim->query_cap_name()+"'s "+ob->query_name()+".\n"+capitalize((string)victim->query_subjective())+" does not even notice!");
        tp->add_alignment(- ((int)victim->query_alignment())/100);
        if((string)tp->query_class() != (string)victim->query_class())
           tp->add_skill_points("stealing", 10);
           tp->add_exp(800);
       if(ob->move(tp)) {
           write("You cannot carry that!\nYou drop "+ob->query_name()+".");
           say(tp->query_cap_name()+" drops "+ob->query_name()+".", tp);
           ob->move(environment(tp));
       }
       return 1;
    }
    x -= steal;
    if(x<10) {
       write("You successfully steal "+victim->query_cap_name()+"'s "+ob->query_name()+".\nYou are not sure if anyone noticed.");
       tell_room(environment(tp), tp->query_cap_name()+" steals a "+ob->query_name()+" from "+victim->query_cap_name()+".", ({ victim, tp }));
       tp->add_alignment( align_formula );
       if((string)tp->query_class() != (string)victim->query_class())
           tp->add_skill_points("stealing", 8);
           tp->add_exp(500);
       victim->add_skill_points("perception", x);
       if(ob->move(tp)) {
           write("You cannot carry that!\nYou drop "+ob->query_name()+".");
           say(tp->query_cap_name()+" drops "+ob->query_name()+".", tp);
           ob->move(environment(tp));
       }
       return 1;
    }
    if(x<20) {
       write("You successfully steal "+victim->query_cap_name()+"'s "+ob->query_name()+".\nYou are not sure if anyone noticed.");
       tell_object(victim, "You feel someone brush against you.");
       tell_room(environment(tp), tp->query_cap_name()+" slyly brushes by "+victim->query_cap_name()+" and steals a "+ob->query_name()+"",  ({ tp, victim }));
       tp->add_alignment( align_formula );
       if((string)tp->query_class() != (string)victim->query_class())
           tp->add_skill_points("stealing", 6);
           tp->add_exp(300);
       victim->add_skill_points("perception", x);
       if(ob->move(tp)) {
           write("You cannot carry that!\nYou drop "+ob->query_name()+".");
           say(tp->query_cap_name()+" drops "+ob->query_name()+".", tp);
           ob->move(environment(tp));
       }
       return 1;
    }
    if(x<30) {
       write("You successfully steal "+victim->query_cap_name()+"'s "+ob->query_name()+".\nYou are not sure if anyone noticed.");
       tell_object(victim, tp->query_cap_name()+" just stole your "+ob->query_name()+"!");
       tell_room(environment(tp), tp->query_cap_name()+" steals a "+ob->query_name()+" from "+victim->query_cap_name()+".", ({victim, tp}));
       tp->add_alignment( align_formula );
       if((string)tp->query_class() != (string)victim->query_class())
           tp->add_skill_points("stealing", 5);
           tp->add_exp(100);
       if(victim->is_player())
            make_outlaw(tp);
       victim->add_skill_points("perception", x);
       if(!victim->is_player()) victim->force_me("kill "+tp->query_name());
       if(ob->move(tp)) {
           write("You cannot carry that!\nYou drop "+ob->query_name()+".");
           say(tp->query_cap_name()+" drops "+ob->query_name()+".", tp);
           ob->move(environment(tp));
       }
       return 1;
    }
    if(x < 40) {
        write("You fail to steal "+victim->query_cap_name()+"'s "+ob->query_name()+", but no one notices the attempt.");
       if((string)tp->query_class() != (string)victim->query_class())
           tp->add_skill_points("stealing", 4);
          if(victim->is_player())
            make_outlaw(tp);
           victim->add_skill_points("perception", x);
       return 1;
    }
    if(x < 50) {
       write("You fail to steal "+victim->query_cap_name()+"'s "+ob->query_name()+".\nYou are unsure if anyone noticed the attempt.");
       tell_room(environment(tp), tp->query_cap_name()+" attempts to steal something from "+victim->query_cap_name()+".", ({ victim, tp }));
       if((string)tp->query_class() != (string)victim->query_class())
          if(victim->is_player())
            make_outlaw(tp);
           tp->add_skill_points("stealing", 3);
           victim->add_skill_points("perception", x);
       return 1;
    }
    if(x < 60) {
       write("You fail to steal "+victim->query_cap_name()+"'s "+ob->query_name()+".\nYou are unsure if anyone noticed the attempt.");
       tell_room(environment(tp), tp->query_cap_name()+" slyly brushes by "+victim->query_cap_name()+".", ({victim, tp}));
       tell_object(victim, "You feel someone brush against you.");
       if((string)tp->query_class() != (string)victim->query_class())
          if(victim->is_player())
            make_outlaw(tp);
           tp->add_skill_points("stealing", 2);
           victim->add_skill_points("perception", x);
       return 1;
    }
    write("You fail to steal "+victim->query_cap_name()+"'s "+ob->query_name()+".\nYou are unsure if anyone noticed the attempt.");
    tell_room(environment(tp), tp->query_cap_name()+" attempts to steal something from "+victim->query_cap_name()+", but fails.", ({victim, tp}));
    tell_object(victim, tp->query_cap_name()+" just tried to steal a "+ob->query_name()+" from you!\nLuckily, "+tp->query_subjective()+" failed!");
    if((string)tp->query_class() != (string)victim->query_class())
       tp->add_skill_points("stealing", 1);
      if(victim->is_player())
            make_outlaw(tp);
       victim->add_skill_points("perception", x);
    if(!victim->is_player()) victim->force_me("kill "+tp->query_name());
    return 1;
}
 
void help() {
message("Ninfo", "Syntax: <steal [item] from [being]>\n"+
"The steal command allows you to steal objects from other players and\n"+
"monsters.  A fight can automatically ensue if a monster becomes aware of\n"+
"your attempt.  And you never know what a player might do.  The command is\n"+
"sometimes successfull, and sometimes the victim or others might notice, \n"+
"or sometimes no one will notice at all.  It all depends on your ability\n"+
"to steal.\n", this_player());
}
int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "thief" && tp->query_skill("stealing") >= 8*6)
    return 1;
  return 0;
}
