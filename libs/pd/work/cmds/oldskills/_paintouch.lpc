#include <std.h>
inherit DAEMON;
int abil();
void send_messages(object tp, object ob, string clas, string limb);
int cmd_paintouch(string str) {
    string whom, limb, clas;
    int amount, cost, healing, i;
    object tp, ob;
    string *limbs;
   tp = this_player();
  if (!abil()) {
      write("What?\n");
      return 1;
   }
    this_player()->set_magic_round(1);
    if(this_player()->query_ghost()) return 0;
    if(!str) {
        notify_fail("Paintouch whom?\n");
        return 0;
    }
    if (this_player()->query_disable())
       return notify_fail("You are busy.\n");
    if(environment(tp)->query_property("no attack")) {
        notify_fail("A magic force prevents your power.\n");
        return 0;
    }
    healing = (int)tp->query_skill("healing");
    clas = (string)tp->query_subclass();
        if(sscanf(str, "%s %s", whom, limb) != 2) {
            notify_fail("Correct syntax: <paintouch [who] [limb]>\n");
            return 0;
        }
        if(whom == "me" || whom == "myself") ob = tp;
        else ob = present(whom, environment(tp));
    if(!ob) {
        notify_fail("Paintouch whom?\n");
        return 0;
    }
    if(!living(ob)) {
        notify_fail("What? Paintouch that?\n");
        return 0;
    }
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    if(limb == "all") cost = healing;
    else if(member_array(limb, (string *)ob->query_limbs()) == -1) {
        notify_fail("You do not have a "+limb+".\n");
        return 0;
    }
    else if(limb == "head" || limb == "torso") cost = healing*2/3;
    else cost = healing/2;
    if((int)tp->query_mp() < cost) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    tp->add_mp(-cost);
    tp->set_disable();
    if(healing < 10) {
        notify_fail("You are not skilled enough to do that!\n");
        return 0;
    }
    if(limb == "all") {
        amount = (healing - ((int)ob->query_skill("defense")/2));
    }
    else {
        amount = (healing - ((int)ob->query_skill("defense")/3));
    }
    tp->add_skill_points("healing", amount/2);
    if((int)ob->query_alignment() < -140) tp->add_alignment(amount/10);
    else tp->add_alignment(-5);
    if(limb == "all") {
        limbs = (string *)ob->query_limbs();
        for(i=0; i<sizeof(limbs); i++) {
            ob->heal_limb(limbs[i], -(amount / 3));
        }
        send_messages(tp, ob, clas, limb);
    }
    else {
        if(limb == "head" || limb == "torso") ob->heal_limb(limb, -(random(amount/2)));
        else ob->heal_limb(limb, -amount/2);
        send_messages(tp, ob, clas, limb);
    }
    return 1;
}
void send_messages(object tp, object ob, string clas, string limb) {
    string what, thing;
    if(clas == "cleric") {
        thing = "prayer";
        what = "a prayer of deathly rot";
    }
    else if(clas == "monk") {
        thing = "paintouch";
        what = "the touch of pain";
    }
    else {
        thing = "nonsense";
        what = "nonsense";
    }
    if(tp == ob) {
        tell_object(tp, "You hit yourself with "+thing+".\n");
        tell_room(environment(tp), tp->query_cap_name() + " mutters "+what+".\n", ({tp}));
    }
    else {
        tell_object(tp, "You hit "+ob->query_cap_name()+"'s "+limb+" with "+thing+".\n");
        tell_object(ob, tp->query_cap_name()+" hits your "+limb+" with "+thing+".\n");
        tell_room(environment(tp), tp->query_cap_name()+" mutters "+what+".\n", ({tp, ob}));
    }
}
void help() {
    write("Syntax: <paintouch [enemy] [limb]>\n\n"
      "Concentrating chi into vital areas of your opponent with a touch, "
      "you begin to weaken their muscles causing damage to the limbs.\n"
      "Note: <all> can be used in place of <limb>\n"
    );
}
int abil() {
   object o;
   o = this_player();
   if (!o) return 0;
   if (o->query_skill("healing") < 14) return 0;
   if (o->query_subclass() != "monk") return 0;
   if (o->query_level() < 6) return 0;
  return 1;
}
