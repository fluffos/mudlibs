// object for the sword dance
// Kaknal 4-16-02
// changed to daggers/fang stomry 5/21/2002
#include <std.h>
inherit OBJECT;
int dancerounds;
int can_dance(object tp);
void start_dance();
void end_dance();
int no_drop(string str);
void init() {
  ::init();
  add_action("no_drop","unwield");
  add_action("no_drop","give");
  add_action("no_drop","drop");
  add_action("no_drop","put");
}
void create() {
  ::create();
  set_name("dance of the fang");
  set_short("");
  set_long("");
  set_id(({"gypsy_dance_obj"}));
  set_weight(0);
  set_value(0);
  
}
int can_dance(object tp) {
  if (tp->query_level() < 28 ||
      tp->query_skill("entertainment") < 112) {
    return 0;
  }
  
  return 1;
}
void start_dance() {
  int i, daggers;
  object *inv;
  object tp;
  
  if (!userp(environment()))
    this_object()->remove();
  tp=environment();
  inv=all_inventory(tp);
for (i=0, daggers=0; i<sizeof(inv); i++) {
    if (inv[i]->is_weapon() &&
        inv[i]->query_type() == "knife" &&
        inv[i]->query_wielded()) daggers++;
  }
  if (!daggers) {
    message("info","You cannot perform the dance of the fang without a knife!",tp);
    remove();
    return 0;
  }
  if (!tp->query_current_attacker()) {
    message("info","You are not fighting anything.",tp);
    remove();
    return 0;
  }
  if (environment(tp)->query_property("no attack")) {
    message("info","You cannot perform this dance here.",tp);
    remove();
    return 0;
  }
  dancerounds= tp->query_stats("dexterity")/4;
  dancerounds+= tp->query_stats("constitution")/12;
  dancerounds+= tp->query_skill("entertainment")/20;
  if (dancerounds < 3) dancerounds=3;
  if (dancerounds > 7) dancerounds=9+random(dancerounds-2);
  if (dancerounds > 10) dancerounds=12+random(dancerounds*3/4);
  tp->add_sp(-(55+random(30)));
  tp->set_disable();
  message("dance","You weave your fang through the air as you begin to dance.",tp);
  message("dance",tp->query_cap_name()+" weaves "+possessive(tp)+" dagger like a fang through the air as "+nominative(tp)+" begins to dance.",environment(tp), tp);
  call_out("heart_beat",2);
}
void heart_beat() {
  object tp;
  object tgt;
  string part;
  int dam, noatt;
  if (!userp(environment()))
    this_object()->remove();
  tp=environment();
  if (dancerounds < 1) {
     end_dance();
     return;
  }
  if (tp->query_sp() < 40) {
    end_dance();
    return;
  }
  if (dancerounds % (4+random(2)) &&
      tp->query_current_attacker()) {
    tgt=tp->query_current_attacker();
    message("combat","%^YELLOW%^You bend around and, finding an opening, take a quick slice at "+tgt->query_cap_name()+" with your fang!%^RESET%^",tp);
    message("combat","%^YELLOW%^"+tp->query_cap_name()+" bends "+possessive(tp)+" arm around and takes a slice at you with "+possessive(tp)+" fang!%^RESET%^", tgt);
    message("other_combat","%^YELLOW%^"+tp->query_cap_name()+" bends "+possessive(tp)+" arm around and takes a slice at "+tgt->query_cap_name()+" with "+possessive(tp)+" fang!%^RESET%^",
      environment(tp), ({ tp, tgt }) );
    dam= tp->query_stats("dexterity")/3;
    dam+= tp->query_skill("entertainment")/3;
    dam+= tp->query_skill("attack")/7;
    dam+= random(tp->query_skill("entertainment")/10);
    dam-= tgt->query_skill("defense")/2;
    dam-= tgt->query_stats("constitution")/6;
    dam-= tgt->query_stats("dexterity")/4;
   if (dam <= 9) dam=10;
    tp->add_sp(-(random(20)+15));
    tgt->add_hp(-dam);
  }
  else if (!random(2)) {
    part=({"head","torso","neck","hand","arm"})[random(5)];
    message("combat","%^ORANGE%^You dance carefully, balancing your fang on your "+part+".%^RESET%^",tp);
    message("other_combat","%^ORANGE%^"+tp->query_cap_name()+"dances carefully while balancing "+possessive(tp)+" fang on "+possessive(tp)+" "+part+".%^RESET%^",environment(tp),tp);
    tp->add_sp(-(random(5)+3));
  }
  if (!tp->query_current_attacker()) noatt++;
  if (noatt >= 7+random(2)) {
    end_dance();
    return;
  }
  dancerounds--;
  if (dancerounds % 2)
    call_out("heart_beat",2);
  else
    call_out("heart_beat",3);
}
void end_dance() {
  
  object tp=environment();
  message("combat","You step lightly out of your dance and grasp your fang firmly again.",tp);
  message("other_combat",tp->query_cap_name()+" grasps "+possessive(tp)+" fang firmly as "+nominative(tp)+" steps out of "+possessive(tp)+" dance.", environment(tp), tp);
  remove();
  
}
int no_drop(string str) {
  string blah, junk;
  object tp=environment();
  object wep;
  if (!str) return 0;
  if (sscanf(str,"%s to %s",blah,junk) != 2)   // give thing to person
    if (sscanf(str,"%s in %s",blah,junk) != 2) // put thing in bag
      blah=str;                                // drop thing
  if ((wep=present(blah,tp)) == this_object()) return 1;
  if (wep->query_wielded() == environment() &&
      wep->query_type() == "knife") {
    message("info","You cannot discard your knife during the fang dance!",
      this_player());
    return 1;
  }
  return 0;
}
