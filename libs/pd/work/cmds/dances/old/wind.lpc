// object for the dance of the wind
// Kaknal 4-16-02
#include <std.h>
inherit OBJECT;
int dancerounds;
int can_dance(object tp);
void start_dance();
void heart_beat();
void end_dance();
void set_die();
int no_drop(string str);
void init() {
  ::init();
  add_action("no_drop","give");
  add_action("no_drop","drop");
  add_action("no_drop","put");
}
void create() {
  ::create();
  set_name("dance of the wind");
  set_short("");
  set_long("");
  set_id(({"gypsy_dance_obj"}));
  set_weight(0);
  set_value(0);
  
}
int can_dance(object tp) {
  if (tp->query_level() < 5 ||
      tp->query_skill("entertainment") < 15) {
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
  dex= tp->query_level()/3 + random(3);
  
  tp->add_stat_bonus("dexterity",dex);
  dancerounds= tp->query_stats("dexterity")/6;
  dancerounds+= tp->query_stats("constitution")/7;
  dancerounds+= random(3);
  if (dancerounds < 3) dancerounds=3;
  tp->add_sp(-(10+random(5)));
  tp->set_disable();
  message("dance","You begin a graceful dance.",tp);
  message("dance",tp->query_cap_name()+" begins to dance gracefully.",
    environment(tp), tp);
  call_out("heart_beat", 2);
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
    message("combat","%^CYAN%^You spin and dance like the wind!%^RESET%^",tp);
    message("combat","%^CYAN%^"+tp->query_cap_name()+" dances about, "
      "spinning and laughing merrily!%^RESET%^", environment(tp), tp);
    tp->add_stat_bonus("dexterity",random(5)-random(3));
    tp->fix_vital_bonus();
  }
  
  tp->add_sp(-(random(3)+1));
  dancerounds--;
  // a normal heart_beat (aka combat round) is 2.5 seconds, we do this
  //  as 2 or 3 seconds to keep it synched up with combat
  if (dancerounds % 2)
    call_out("heart_beat",2);
  else
    call_out("heart_beat",3);
}
void end_dance() {
  
  object tp=environment();
  tp->add_stat_bonus("dexterity",-tp->query_stat_bonus("dexterity"));
  
  message("combat","You slowly bring your dance to an end.",tp);
  message("other_combat",tp->query_cap_name()+" ends "+possessive(tp)+
    " dance.", environment(tp), tp);
  tp->fix_vital_bonus();
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
void set_die() {
  object tp=environment();
  tp->add_stat_bonus("dexterity",-tp->query_stat_bonus("dexterity"));
  tp->fix_vital_bonus();
  remove();
}
