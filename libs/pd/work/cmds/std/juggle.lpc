// object for jester juggle command
// Kaknal 4-20-02
#include <std.h>
inherit OBJECT;
object juggler;
object *things;
int time;
int stop(string str);
int toss_it(string str);
int no_drop(string str);
void set_juggling(object tp, object *jugg);
string extra_look() {
  if (juggler)
    return "%^YELLOW%^"+juggler->query_cap_name()+
      " is juggling things high in the air!%^RESET%^\n";
  else
    return "";
}
void init() {
  ::init();
  add_action("stop","stop",1);
  add_action("stop","sleep",1);
  add_action("toss_it","toss");
  add_action("no_drop","give");
  add_action("no_drop","drop");
  add_action("no_drop","put");
}
void create() {
  ::create();
  set_name("juggling");
  set_short("");
  set_long("");
  set_id(({"jester_juggling_obj"}));
  set_weight(0);
  set_value(0);
}
void set_juggling(object tp, object *jugg) {
  juggler=tp;
  things=jugg;
  time=0;
  call_out("do_juggle",2);
}
void do_juggle() {
  int i, ent;
  string j;
  if (environment() != juggler || !juggler)
    remove();
  if (juggler->query_current_attacker()) {
    message("juggle","Your juggling is interrupted by combat.",
      juggler);
    remove();
  }
  
  juggler->add_sp(-(1+random(2)));
  ent= juggler->query_skill("entertainment");
  
  if (time > (5+random(3)+ent/50)) {
    if (juggler->query_stats("dexterity")/3+
        juggler->query_skill("entertainment")/15 < time+random(3)) {
      message("juggle","%^CYAN%^You slip up and drop everything you "
        "were juggling!%^RESET%^", juggler);
      message("juggle","%^CYAN%^"+juggler->query_cap_name()+
        " foolishly drops everything "+nominative(juggler)+
        " was juggling.%^RESET%^", environment(juggler), juggler);
      if (!random(5)) {
        j= things[random(sizeof(things))]->query_short();
        message("juggle","%^ORANGE%^"+capitalize(j)+" conks you "
          "on the head!%^RESET%^", juggler);
        message("juggle","%^ORANGE%^"+capitalize(j)+" conks "+
          juggler->query_cap_name()+" on the head!%^RESET%^",
          environment(juggler), juggler);
        juggler->add_hp(-(20+random(10)));
      }
      for (i=0;i<sizeof(things);i++) {
        things[i]->move(environment(juggler));
      }
      remove();
      return;
    }
    else {
      j= things[random(sizeof(things))]->query_short();
      message("juggle","%^BOLD%^%^WHITE%^You throw "+j+" high in the air, "
        "and expertly catch it again!%^RESET%^",juggler);
      message("juggle","%^BOLD%^%^WHITE%^"+juggler->query_cap_name()+
        " juggles "+possessive(juggler)+" "+j+" high in the air!%^RESET%^",
        environment(juggler), juggler);
     juggler->add_skill_points("entertainment",time);
    }
  }
  time++;
  call_out("do_juggle",3);
}
int toss_it(string str) {
  string what, who, limb;
  object tgt, item, *items;
  int i, ent, tdex, dam, miss;
  if (!str || sscanf(str, "%s at %s", what, who) != 2) {
    message("juggle","Toss what at who?",juggler);
    return 1;
  }
  if (! tgt=present(who,environment(juggler))) {
    message("juggle","You don't see that here.",juggler);
    return 1;
  }
  if (tgt == juggler) {
    message("juggle","Anything for the audience, huh?",juggler);
    return 1;
  }
  if (!living(tgt)) {
    message("juggle","You can't hurt that, it's not alive.",juggler);
    return 1;
  }
  if (environment(juggler)->query_property("no attack")) {
    message("juggle","You cannot attack here.",juggler);
    return 1;
  }
  if (member_array(item=present(what,juggler), things) == -1 &&
      what != "all") {
    message("juggle","You are not juggling that.",juggler);
    return 1;
  }
  if (!juggler->kill_ob(tgt)) {
    message("juggle",tgt->query_cap_name()+" can't be attacked by you yet.",
      juggler);
    return 1;
  }
  ent= juggler->query_skill("entertainment");
  tdex= tgt->query_stats("dexterity");
  dam= ent/4;
  if (time > 20) time=20;
  // juggling it longer builds up more momentum
  dam+= time*10;
  if (what == "all")
    items=things;
  else
    items=({ item });
  for (i=0, miss=0; i<sizeof(items); i++) {
    // if the target is fast enough we might miss
    if (ent/3 - tdex*4/3 + random(15) < 0) {
      message("juggle","%^CYAN%^You toss "+items[i]->query_short()+
        " at "+tgt->query_cap_name()+", but miss.%^RESET%^",juggler);
      message("juggle","%^CYAN%^"+juggler->query_cap_name()+
        " tosses "+items[i]->query_short()+" at you, but misses.%^RESET%^",tgt);
      message("juggle","%^CYAN%^"+juggler->query_cap_name()+
        " tosses "+items[i]->query_short()+" at "+tgt->query_cap_name()+
        ", but misses.%^RESET%^",environment(tgt), ({ juggler, tgt }) );
      items[i]->move(environment(tgt));
      continue;
    }
    message("juggle","%^BOLD%^%^CYAN%^You toss "+items[i]->query_short()+
      " and hit "+tgt->query_cap_name()+"!%^RESET%^",juggler);
    message("juggle","%^BOLD%^%^CYAN%^"+juggler->query_cap_name()+
      " tosses "+items[i]->query_short()+" and hits you!%^RESET%^",tgt);
    message("juggle","%^BOLD%^%^CYAN%^"+juggler->query_cap_name()+
      " tosses "+items[i]->query_short()+" and hits "+tgt->query_cap_name()+
      "!%^RESET%^",environment(tgt), ({ juggler, tgt }) );
    // the weight contributes to damage
    // weapons and flaming objects do more damage too
    dam+= items[i]->query_weight()/3;
    if (items[i]->is_weapon())
      dam+= random(5+random(items[i]->query_wc()))*2;
    if (items[i]->query_lit())
      dam+= 40;
    juggler->add_sp(-(2+random(2)));
    // each item randomly stays on the target or falls to the ground
    if (random(2)) {
      items[i]->move(environment(tgt));
    }
    else {
      if (items[i]->move(tgt) != 0) {
        items[i]->move(environment(tgt));
      }
    }
  }
  dam+= random(dam/7);
  dam-= tgt->query_skill("defense")/2;
  juggler->add_sp(-(dam/50));
  limb=tgt->return_target_limb();
  tgt->do_damage(limb, dam);
  tgt->check_on_limb(limb);
  remove();
  
  return 1;
}
int stop(string str) {
  object tp=this_player();
  if (!str || str != "juggling")
    return 0;
  
  message("juggle","You stop juggling.",tp);
  message("juggle",tp->query_cap_name()+" stops juggling.",
    environment(tp), tp);
  // we let this fall through so you still go to sleep
  if (query_verb() == "sleep") {
    remove();
    return 0;
  }
  remove();
  return 1;
}
int no_drop(string str) {
  string blah, junk;
  object tp=environment();
  if (!str) return 0;
  if (sscanf(str,"%s to %s",blah,junk) != 2)   // give thing to person
    if (sscanf(str,"%s in %s",blah,junk) != 2) // put thing in bag
      blah=str;                                // drop thing
  if (present(blah,tp) == this_object()) return 1;
  if (member_array(present(blah,tp), things) != -1) {
    message("juggle","You are juggling that!",tp);
    return 1;
  }
  return 0;
}
