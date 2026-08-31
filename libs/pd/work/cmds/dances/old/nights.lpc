// object for the dance of a thousand nights
// Kaknal 4-16-02
#include <std.h>
// should be same as in _perform.c
#define DANCEDIR "/cmds/dances/"
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
  set_name("dance of a thousand nights");
  set_short("");
  set_long("");
  set_id(({"gypsy_dance_obj"}));
  set_weight(0);
  set_value(0);
  
}
int can_dance(object tp) {
  if (tp->query_level() < 18 ||
      tp->query_skill("entertainment") < 70) {
    return 0;
  }
  
  return 1;
}
void start_dance() {
  object tp;
  
  if (!userp(environment()))
    this_object()->remove();
  tp=environment();
  if (tp->query_mp() < 50) {
    message("info","You don't have the energy for this dance.",tp);
    remove();
    return 0;
  }
  if (environment(tp)->query_property("no attack")) {
    message("info","A magical force prevents you from performing this dance.",
      tp);
    remove();
    return 0;
  }
  if (present("thousand-nights-ghost-image",environment(tp))) {
    message("info","You are not ready for this dance again so soon.",tp);
    remove();
    return 0;
  }
  dancerounds= 3;
  tp->add_sp(-(40+random(10)));
  tp->set_paralyzed(1+random(3),"You are too busy dancing.");
  message("dance","You sway back and forth in a mystical dance.",tp);
  message("dance",tp->query_cap_name()+" sways back and forth as "+
    nominative(tp)+"starts to dance.", environment(tp), tp);
  call_out("heart_beat",2);
}
void heart_beat() {
  object tp;
  if (!userp(environment()))
    this_object()->remove();
  tp=environment();
  if (dancerounds < 1) end_dance();
  if (dancerounds == 2) {
    message("info","You kick your legs and hop about as you dance wildly! ",
      tp);
    message("info",tp->query_cap_name()+" kicks "+possessive(tp)+" legs and "
      "hops about as "+nominative(tp)+" dances wildly!", environment(tp), tp);
  }
  tp->add_sp(-(random(6)+3));
  dancerounds--;
  if (dancerounds % 2)
    call_out("heart_beat",2);
  else
    call_out("heart_beat",3);
}
void end_dance() {
  
  int i, max;
  object ghost;
  object tp=environment();
  message("combat","You throw your arms out to your sides as you "
    "finish your dance!",tp);
  message("other_combat",tp->query_cap_name()+" throws "+possessive(tp)+
    " arms out to "+possessive(tp)+" sides as "+nominative(tp)+
    " finishes the dance!", environment(tp), tp);
  max= 1+((tp->query_level()-18)/13);
  if (max > 3) max=3;
  for (i=0; i<max; i++) {
    ghost=new(DANCEDIR"ghost-image");
    ghost->set_owner(tp);
    ghost->move(environment(tp));
    tp->add_mp(-(50+random(30)));
  }
  if (max == 1)
    message("info","%^BOLD%^%^WHITE%^A ghostly spirit materializes "
      "from nowhere!%^RESET%^",environment(tp));
  else
    message("info","%^BOLD%^%^WHITE%^Ghostly spirits materialize "
      "from nowhere!%^RESET%^",environment(tp));
  tp->add_sp(-(30+random(10)));
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
