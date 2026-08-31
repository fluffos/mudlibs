// object for the veil dance
// Kaknal 4-16-02
#include <std.h>
inherit OBJECT;
int dancerounds;
void para_room(object tp, int para);
int can_dance(object tp);
void start_dance();
void end_dance();
int no_drop(string str);
void init() {
  ::init();
  add_action("no_drop","give");
  add_action("no_drop","drop");
  add_action("no_drop","put");
}
void create() {
  ::create();
  set_name("veil dance");
  set_short("");
  set_long("");
  set_id(({"gypsy_dance_obj"}));
  set_weight(0);
  set_value(0);
  
}
int can_dance(object tp) {
  if (tp->query_level() < 33 ||
      tp->query_skill("entertainment") < 132) {
    return 0;
  }
  
  return 1;
}
void start_dance() {
  int i, ppl, para;
  object *inv;
  object tp;
  
  if (!userp(environment()))
    this_object()->remove();
  tp=environment();
  if (tp->query_mp() < 70) {
    message("info","You don't have the energy for this dance.",tp);
    remove();
    return 0;
  }
  if (environment(tp)->query_property("no attack")) {
    message("info","You cannot perform this dance here.",tp);
    remove();
    return 0;
  }
  if (tp->query_current_attacker()) {
    message("info","You are too busy fighting.",tp);
    remove();
    return 0;
  }
  inv=all_inventory(environment(tp));
  for (i=0, ppl=0; i<sizeof(inv); i++) {
    if (living(inv[i]) &&
        inv[i] != tp) ppl++;
  }
  if (!ppl) {
    message("info","There is no one here to dance for.",tp);
    remove();
    return 0;
  }
  dancerounds= 9+random(3);
  message("info","You take out a veil and swing it about lightly "
    "as you dance.",tp);
  message("info",tp->query_cap_name()+" begins dancing, swinging a veil "
    "around "+possessive(tp)+" body.",environment(tp),tp);
  para= 4+random(2);
  para+= tp->query_skill("entertainment")/140;
  if (para < 2) para=2;
  para_room(tp, para);
  tp->add_sp(-(40+random(10)));
  para= 5+random(3);
  para-= tp->query_skill("entertainment")/165;
  if (para < 3) para=3;
  tp->set_paralyzed(para, "You must concentrate on your dance.");
  call_out("heart_beat",2);
}
void heart_beat() {
  int para;
  object tp;
  if (!userp(environment()))
    this_object()->remove();
  tp=environment();
  if (dancerounds < 1) end_dance();
  if (!(dancerounds % 3)) {
    if (dancerounds == 3) {
      message("info","You spin and turn the veil around and around.",tp);
      message("info",tp->query_cap_name()+" spins and turns "+possessive(tp)+
        " veil around and around, entrancing you.",environment(tp),tp);
    }
    if (dancerounds == 6) {
      message("info","You turn faster, swinging your veil up and down in a "
        "twisting, intricate pattern.",tp);
      message("info",tp->query_cap_name()+" turns faster and swings "+
        possessive(tp)+" veil up and down and in circles, entrancing all "
        "onlookers.",environment(tp),tp);
    }
    if (dancerounds == 9) {
      message("info","You move your veil over your body in a rhythm that "
        "entrances your audience.",tp);
      message("info",tp->query_cap_name()+" moves "+possessive(tp)+
        " veil over "+possessive(tp)+" body in a quick, easy rhythm.",
        environment(tp), tp);
    }
    tp->add_sp(-10+random(20));
    para= 3+random(4);
    para+= tp->query_skill("entertainment")/140;
    if (para < 2) para=2;
    para_room(tp, para);
  }
  tp->add_sp(-(random(10)+3));
  dancerounds--;
  if (dancerounds % 2)
    call_out("heart_beat",2);
  else
    call_out("heart_beat",3);
}
void end_dance() {
  
  object tp=environment();
  message("combat","You toss your veil in the air as your dance ends!",tp);
  message("other_combat",tp->query_cap_name()+" tosses "+possessive(tp)+
    " veil in the air as "+possessive(tp)+" dance ends!",
    environment(tp), tp);
  remove();
  
}
void para_room(object tp, int para) {
  
  object *inv;
  int i, x;
  inv=all_inventory(environment(tp));
  for(i=0; i<sizeof(inv); i++) {
    if (living(inv[i]) &&
        inv[i] != tp) {
      x= para - inv[i]->query_stats("wisdom")/30;
      if(random(100)>69)inv[i]->set_paralyzed(x,
        "You are enchanted by the dancing of "+ tp->query_cap_name()+".",
        "You break free of the trance.");
    }
  }
}
int no_drop(string str) {
  string blah, junk;
  object tp=environment();
  if (!str) return 0;
  if (sscanf(str,"%s to %s",blah,junk) != 2)   // give thing to person
    if (sscanf(str,"%s in %s",blah,junk) != 2) // put thing in bag
      blah=str;                                // drop thing
  if (present(blah,tp) == this_object()) return 1;
  return 0;
}
