#include <std.h>
inherit DAEMON;
int spell();
void send_messages(object tp, object ob, string clas, string limb);
int cmd_heal(string str) {
    string whom, limb, clas;
    int amount, cost, healing, i, wisdom;
    object tp, ob;
    string * limbs;
   if (!spell()) {
      write("What?\n");
      return 1;
   }
    if(!str) {
        notify_fail("Heal whom?\n");
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
    healing = (int)tp->query_skill("healing")/2;
    healing += (int)tp->query_level()/3;
    healing += (int)tp->query_skill("faith")/4;
     
    clas = (string)tp->query_subclass();
    if(str == "me" || str == "myself") ob = tp;
    else ob = present(str, environment(tp));
    if(!ob) {
        if(sscanf(str, "%s %s", whom, limb) != 2) {
            notify_fail("Correct syntax: <heal [who] [(limb)]\n");
            return 0;
        }
        if(whom == "me" || whom == "myself") ob = tp;
        else ob = present(whom, environment(tp));
    }
    if(!ob) {
        notify_fail("Heal whom?\n");
        return 0;
    }
    if(!limb) cost = healing/4;
    else if(limb == "all") cost = healing/3;
    else if(member_array(limb, (string *)ob->query_limbs()) == -1) {
        notify_fail("That limb is missing!\n");
        return 0;
    }
    else cost = healing/5;
    if(ob != tp) cost = random(cost);
    if((int)tp->query_mp() < cost) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    tp->add_mp(-cost);
    amount = (healing);
    if(amount > 800) {
       log_file("hmmm", this_player()->query_name()+" healing "+ob->query_short()+" "+amount+"\n");
       amount = 800;
    }
    this_player()->set_magic_round(2);
    if(tp == ob) tp->add_skill_points("healing", amount/6);
    else {
        tp->add_skill_points("healing", amount/2);
        tp->add_alignment(amount/5);
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
        ob->add_hp(amount/2);
        send_messages(tp, ob, clas, 0);}
    }
    else {
        ob->heal_limb(limb, amount);
      if (tp->query_hp() < 1) {
        ob->set_hp(1);
        send_messages(tp, ob, clas, 0);}
      else{   
        ob->add_hp(amount/3);
        send_messages(tp, ob, clas, 0);}
    }
    this_player()->set_disable();
    return 1;
}
void send_messages(object tp, object ob, string clas, string limb) {
    string what, thing;
    if(clas == "monk" || clas == "cleric") {
        thing = "prayer";
        what = "a prayer of healing";
    }
    else if(tp->query_class() == "mage") {
        thing = "magic";
        what = "a spell of healing";
    }
    else {
        thing = "nonsense";
        what = "nonsense";
    }
    if(tp == ob) {
     tell_object(tp, "You heal your own wounds through " + thing + ".");
     tell_room(environment(tp), tp->query_cap_name() +" mutters " + what + ".", ({ tp }) );
    }
    else {
      tell_object(tp, "You heal " + ob->query_cap_name() +"'s wounds through " + thing + ".");
      tell_object(ob, tp->query_cap_name() + " heals your wounds through " + thing + ".");
      tell_room(environment(tp), tp->query_cap_name() + " mutters " + what + ".", ({ tp, ob }) );
    }
}
void help() {
    write("Syntax: <heal [player] [(limb)]>\n\n"+
        "Heals the player named.  If no limb is given, then\n"+
        "it heals hp.  Otherwise it heals the limb named.  The arg \"all\"\n"+
        "is a valid arg for the limb.\n");
}
int spell() {
   object tp;
   tp = this_player();
   if (!tp) return 0;
   if (!alignment_ok(tp)) return 0;
   if (tp->query_level() < 2) return 0;
   if (tp->query_subclass() != "cleric" && tp->query_subclass() != "monk")
     return 0;
   return 1;
}
