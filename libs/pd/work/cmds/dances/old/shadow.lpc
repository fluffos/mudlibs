// object for the dance of the shadows
// Kaknal 4-16-02
#include <std.h>
inherit OBJECT;
int dancerounds;
int can_dance(object tp);
void start_dance();
void heart_beat();
void end_dance();
int no_drop(string str);
void init() {
  ::init();
  add_action("no_drop","give");
  add_action("no_drop","drop");
  add_action("no_drop","put");
  add_action("stop_dance","stop");
}
void create() {
  ::create();
  set_name("dance in the shadows");
  set_short("");
  set_long("");
  set_id(({"gypsy_dance_obj"}));
  set_weight(0);
  set_value(0);
  
}
int can_dance(object tp) {
  if (tp->query_level() < 5 ||
      tp->query_skill("entertainment") < 100) {
    return 0;
  }
  
  return 1;
}
void start_dance() {
  int dex;
  object tp;
  
  if (!userp(environment()))
    this_object()->remove();
  tp=environment();
  dex= tp->query_skill("stealth")/10;
  dancerounds= tp->query_skill("entertainment")/10;
  dancerounds+= dex;
  dancerounds+= random(5);
  if (dancerounds < 5) dancerounds=5;
  tp->add_sp(-(10+random(5)));
  tp->set_disable();
  message("dance","%^BOLD%^%^BLACK%^You begin to move slowly moving your arms about yourself.  You slowly begin to fade!%^RESET%^",tp);
  message("dance","%^BOLD%^%^BLACK%^"+tp->query_cap_name()+" dances slowly moving "+possessive(tp)+" arms about in a slow rhythm and begins to fade!%^RESET%^", environment(tp), tp);
  tp->set_invis();
  call_out("heart_beat", 8);
}
// note that this is not the built-in heart_beat function, we use call_out's
void heart_beat() {
  object tp;
  if (!userp(environment()))
    this_object()->remove();
  tp=environment();
  if (dancerounds < 1) {
    end_dance();
    return;
  }
  
  if (tp->query_sp() < 10) {
    end_dance();
    return;
  }
  if (dancerounds % (2+random(2))) {
    message("combat","%^BOLD%^%^BLACK%^You continue to dance in the shadows.%^RESET%^",tp);
  }
  tp->add_sp(-(random(5)+3));
  dancerounds--;
  // a normal heart_beat (aka combat round) is 2.5 seconds, we do this
  //  as 2 or 3 seconds to keep it synched up with combat
    call_out("heart_beat",8);
}
void end_dance() {
  
  object tp=environment();
  tp->set_invis();
  
  message("combat","You slowly bring your dance to an end.",tp);
  message("other_combat",tp->query_cap_name()+" ends "+possessive(tp)+" dance.", environment(tp), tp);
  tp->add_sp(-(10+random(5)));
  tp->set_disable();
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
int stop_dance(string str) {
 if (!str || str=="") return 0;
 if (str!="dance") return 0;
     end_dance();
 return 1;
}
