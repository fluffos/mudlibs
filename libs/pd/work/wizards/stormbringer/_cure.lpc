#include <std.h>
inherit DAEMON;
int spell();
void send_messages(object tp, object ob, string clas, string limb);
int cmd_cure(string str) {
    string whom, limb, clas;
    int amount, cost, healing, i;
    object tp, ob;
    string * limbs;
   if (!spell()) {
      notify_fail("What?\n");
      return 0;
   }
    if(!str) {
        notify_fail("Cure whom?\n");
        return 0;
    }
    tp = this_player();
    if(tp->query_disable()) {
        notify_fail("You are in the middle of something else.\n");
        return 0;
    }
    if(!alignment_ok(this_player())) {
        notify_fail("You have betrayed the source of your powers.\n");
        return 0;
    }
    healing = (int)tp->query_skill("healing");
    clas = (string)tp->query_subclass();
    if(str == "me" || str == "myself") ob = tp;
    else ob = present(str, environment(tp));
    if(!ob) {
        if(sscanf(str, "%s %s", whom, limb) != 2) {
            notify_fail("Correct syntax: <cure [who] [(limb)]\n");
            return 0;
        }
        if(whom == "me" || whom == "myself") ob = tp;
        else ob = present(whom, environment(tp));
    }
    if(!ob) {
        notify_fail("Cure whom?\n");
        return 0;
    }
    if(!limb) cost = healing*2/3;
    else if(limb == "all") cost = healing;
    else if(member_array(limb, (string *)ob->query_limbs()) == -1) {
        notify_fail("That limb is missing!\n");
        return 0;
    }
    else cost = healing/3;
    if(ob != tp) cost = random(cost);
    if((int)tp->query_mp() < cost) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    tp->add_mp(-cost);
    amount = (healing*((int)ob->query_level()))/10;
    if(amount > 400) {
       log_file("hmmm", this_player()->query_name()+" healing "+ob->query_short()+" "+amount+"\n");
       amount = 400;
    }
    if(clas == "paladin"){
      amount = amount/2;
    }
    this_player()->set_magic_round(2);
    if(tp == ob) tp->add_skill_points("healing", amount/6);
    else {
        tp->add_skill_points("healing", amount/2);
        tp->add_alignment("healing", amount/5);
    }
    if(!limb) {
      if (tp->query_hp() < 1) {
        ob->set_hp(1);
        send_messages(tp, ob, clas, 0);}
      else{   
        ob->add_hp(amount);
        send_messages(tp, ob, clas, 0);}
    }
    else if(limb == "all") {
        limbs = (string *)ob->query_limbs();
        for(i=0; i<sizeof(limbs); i++) {
          ob->heal_limb(limbs[i], (amount/2));
        }
      if (tp->query_hp() < 1) {
        ob->set_hp(1);
        send_messages(tp, ob, clas, 0);}
      else{   
        ob->add_hp(amount);
        send_messages(tp, ob, clas, 0);}
    }
    else {
        ob->add_hp(amount/4);
      if (tp->query_hp() < 1) {
        ob->set_hp(1);
        send_messages(tp, ob, clas, 0);}
      else{   
        ob->add_hp(amount);
        send_messages(tp, ob, clas, 0);}
    }
    tp->set_disable();
    return 1;
}
void send_messages(object tp, object ob, string clas, string limb) {
    string what, thing;
    if(clas == "cleric" || clas == "paladin") {
        thing = "prayer";
        what = "a prayer of healing";
    }
    else if(clas == "blue") {
        thing = "magic";
        what = "a spell of healing";
    }
    else {
        thing = "nonsense";
        what = "nonsense";
    }
    if(tp == ob) {
        tell_object(tp, "You cure your own wounds through "+thing+".");
        tell_room(environment(tp), tp->query_cap_name() + " mutters "+what+".", ({tp}));
    }
    else {
        tell_object(tp, "You cure "+ob->query_cap_name()+"'s wounds through "+thing+".");
        tell_object(ob, tp->query_cap_name()+" cures your wounds through "+thing+".");
        tell_room(environment(tp), tp->query_cap_name()+" mutters "+what+".", ({tp, ob}));
    }
}
void help() {
    write("Syntax: <cure [player] [(limb)]>\n\n"+
        "Cures the player named to a degree depending on your skill level.  If no\n"+
        "limb is given, it heals hp.  Otherwise it heals the limb named.  The
arg \"all\"\n"+
        "is a valid arg for the limb.\n");
}
int spell() {
   object tp;
   tp = this_player();
   if (tp->query_level() < 7) return 0;
   if (tp->query_skill("healing") < 50) return 0;
   if (tp->query_subclass() != "cleric" && tp->query_subclass() != "paladin" && tp->query_subclass() != "blue")
      return 0;
   return 1;
}
