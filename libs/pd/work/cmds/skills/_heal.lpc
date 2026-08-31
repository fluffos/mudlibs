#include <std.h>

#define COL "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

inherit DAEMON;

int spell();
void send_messages(object tp, object ob, string clas, string limb);

string type() { return "healing"; }

int cmd_heal(string str) {
  string whom, limb, clas;
  int amount, cost, healing, i, wisdom;
  object tp, ob;
  string * limbs;
  if (!spell()) {
    return 0;
  }
  if(!str) {
    notify_fail("Heal whom?\n");
    return 0;
  }
  tp = this_player();
  if(tp->query_busy()) {
    notify_fail("You are in the middle of something else.\n");
    return 0;
  }
  if(!alignment_ok(this_player())) {
    notify_fail("You have betrayed the source of your powers.\n");
    return 0;
  }
  if(this_player()->query_ghost())
    return notify_fail("You cannot speak without a body.\n");
  healing = (int)tp->query_skill("healing")/2;
  healing += (int)tp->query_level()/3;
  healing += (int)tp->query_skill("faith")/4;
  healing += tp->query_skill("belief")/4;
  healing += tp->query_stats("wisdom")/3;

  clas = (string)tp->query_subclass();
  if(str == "me" || str == "myself") ob = tp;
  else ob = present(str, environment(tp));
  if(!ob) {
    if(sscanf(str, "%s %s", whom, limb) != 2) {
      notify_fail("Heal whom?\n");
      return 0;
    }
    if(whom == "me" || whom == "myself") ob = tp;
    else ob = present(whom, environment(tp));
  }
  if(!ob) {
    notify_fail("Heal whom?\n");
    return 0;
  }
  if(!limb) cost = healing/2;
  else if(limb == "all") cost = healing*3/4;
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
  amount = (healing);
  if(amount > 800) {
    log_file("hmmm", this_player()->query_name()+" healing "+ob->query_short()+" "+amount+"\n");
    amount = 800;
  }
  this_player()->set_magic_round(1);
  if(tp == ob) tp->add_skill_points("healing", amount/3);
  else {
    tp->add_skill_points("healing", amount/2);
    tp->add_alignment(5+amount/5);
    tp->add_exp(amount/4);
  }
  if(!limb) {
    ob->add_hp(amount);
  }
  else if(limb == "all") {
    limbs = (string *)ob->query_limbs();
    for(i=0; i<sizeof(limbs); i++) {
      ob->heal_limb(limbs[i], (amount/2));
    }
    ob->add_hp(amount/2);
  }
  else {
    ob->heal_limb(limb, amount);  
    ob->add_hp(amount/3);
  }
  send_messages(tp, ob, clas, limb);
  return 1;
}
void send_messages(object tp, object ob, string clas, string limb) {
  string what, where, thing;
  if(clas == "monk" || clas == "cleric") {
    thing = "prayer";
    what = "a prayer of healing";
  }
  else {
    thing = "magic";
    what = "a spell of healing";
  }
  if (!limb) where = "wounds";
  else if (limb == "all") where = "limbs";
  else where = limb;
  if(tp == ob) {
    tell_object(tp, COL+"You heal your own "+where+" through " + thing + "."+RES);
    tell_room(environment(tp), COL+tp->query_cap_name() +" mutters " + what + "."+RES, ({ tp }) );
  }
  else {
    tell_object(tp, COL+"You heal " + ob->query_cap_name() +"'s "+where+" through " + thing + "."+RES);
    tell_object(ob, COL+tp->query_cap_name() + " heals your "+where+" through " + thing + "."+RES);
    tell_room(environment(tp), COL+tp->query_cap_name() + " mutters " + what + "."+RES, ({ tp, ob }) );
  }
}
void help() {
  message("help",
   "Syntax: <heal [who]>\n"
   "        <heal [who] [limb]>\n\n"
   "Sometimes a feat of prayer and sometimes of magic, this is the ability "
   "to heal someone. Normally it heals their life force, but it can "
   "also be directed at a specific limb, or \"all\" for all limbs.",
   this_player() );
}
int spell() {
  object tp = this_player();
  if (tp->query_subclass() == "cleric")
    return 1;
  if (member_array(tp->query_subclass(), ({ "monk", "paladin", "antipaladin" }) ) != -1 && tp->query_skill("healing") >= 25)
    return 1;
  return 0;
}
