// object for the dance of the blue oasis
// Kaknal 4-16-02
#include <std.h>
inherit OBJECT;
int dancerounds;
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
  set_name("dance of the blue oasis");
  set_short("");
  set_long("");
  set_id(({"gypsy_dance_obj"}));
  set_weight(0);
  set_value(0);
}
int can_dance(object tp) {
  if (tp->query_level() < 15 ||
      tp->query_skill("entertainment") < 53) {
    return 0;
  }
  return 1;
}
void start_dance() {
  object tp;
  if (!userp(environment()))
    this_object()->remove();
  tp=environment();
  if (tp->query_mp() < 70) {
    message("info","You don't have the energy for this dance.",tp);
    remove();
    return 0;
  }
  if (tp->query_alignment() < -1350) {
    message("info","You can't quite get into the good spirit "
      "of the dance.",tp);
    remove();
    return 0;
  }
  if (tp->query_current_attacker()) {
    message("info","You are too busy fighting.",tp);
    remove();
    return 0;
  }
  if (environment(tp)->query_property("no magic")) {
    message("info","A magical force prevents you from performing this dance.",
      tp);
    remove();
    return 0;
  }
  dancerounds= 4;
  tp->add_sp(-(35+random(10)));
  tp->set_disable();
  message("dance","You begin a slow, flowing dance.",tp);
  message("dance",tp->query_cap_name()+" begins a slow, flowing dance.",
    environment(tp), tp);
  call_out("heart_beat",2);
}
void heart_beat() {
  object tp;
  if (!userp(environment()))
    this_object()->remove();
  tp=environment();
  if (dancerounds < 1) end_dance();
  if (dancerounds == 4) {
    message("info","You step carefully in a circle, stretching your "
      "body and arms outward as you dance.",tp);
    message("info",tp->query_cap_name()+" dances slowly in a circle, "
      "stretching "+possessive(tp)+" body and arms outward.",
      environment(tp), tp);
  }
  if (dancerounds == 2) {
    message("info","You swing your arms around slowly and wrap them "
      "around your waist as you turn.",tp);
    message("info",tp->query_cap_name()+" swings "+possessive(tp)+
      " arms around and wraps them around "+possessive(tp)+" waist "
      "as "+nominative(tp)+" turns.", environment(tp), tp);
  }
  tp->add_sp(-(random(3)+1));
  dancerounds--;
  if (dancerounds % 2)
    call_out("heart_beat",2);
  else
    call_out("heart_beat",3);
}
void end_dance() {
  int i, heal;
  object *inv;
  object tp=environment();
  message("combat","You raise your arms to the sky as you slowly bring "
    "your dance to an end.",tp);
  message("other_combat",tp->query_cap_name()+" raises "+possessive(tp)+
    " arms to the sky as "+nominative(tp)+" finishes the dance.",
    environment(tp), tp);
  message("info","%^BOLD%^%^BLUE%^You feel a little better.%^RESET%^",
    environment(tp));
  heal= tp->query_skill("entertainment")/2;
  heal+= tp->query_stats("wisdom")/3;
  inv=all_inventory(environment(tp));
  for (i=0; i<sizeof(inv); i++) {
    if (inv[i] == tp)
      inv[i]->add_hp(heal*2/3);
    else if (userp(inv[i]))
      inv[i]->add_hp(heal);
  }
  tp->add_sp(-(10+random(heal/5)));
  tp->add_mp(-(10+random(heal/4)));
  remove();
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
