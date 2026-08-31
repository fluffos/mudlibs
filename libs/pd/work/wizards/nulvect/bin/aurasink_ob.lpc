
#include <std.h>

#define RES "%^RESET%^"
#define COL RES+"%^CYAN%^"
#define COL2 RES+"%^RED%^"

#define AURASINK_ID "aurasink_ob_id"

inherit OBJECT;

object owner;
int max, rounds, decay;
int ac;
int counter;

void setup(object tp, int i, int m, int r, int d);
int remove();

void setup(object tp, int i, int m, int r, int d) {
  if (!(tp && i && m && r && d)) return;
  owner=tp;
  ac=i;
  max=m;
  rounds=r;
  decay=d;
  set_heart_beat(1);
  owner->add_magic_protection(({0, ac, 0}));
}

void create() {
  ::create();
  set_weight(0);
  set_id(({AURASINK_ID}));
  counter=0;
}

void heart_beat() {
  object *tgts;
  if (!this_object()) return;
  if (!owner || environment() != owner) {
    remove();
    return;
  }

  // spell ends by wearing off
  if (rounds-- < 1) {
    message("magic", COL+"The aura dissipates around you."+RES, owner);
    message("magic", COL+"The aura dissipates around "+
                     owner->query_cap_name()+"."+RES, environment(owner), owner);
    remove();
    return;
  }

  // suck def out of attackers
  owner->clean_up_attackers();
  if (sizeof(tgts=owner->query_attackers())) {
    foreach (object tgt in tgts) {
      if (ac < max && random(100) < 50 && tgt->query_skill_bonus("defense") > -25) {
        tgt->add_skill_bonus("defense", -25, decay*2);
        ac++;
        owner->add_magic_protection(({0, 1, 0}));
        message("magic", COL+"The aura "+COL2+"consumes"+COL+" some of "+
                         tgt->query_cap_name()+"'s power."+RES, owner);
        message("magic", COL+"The aura around "+owner->query_cap_name()+
                         " "+COL2+"consumes"+COL+" some of your power."+RES, tgt);
        message("magic", COL+"The aura around "+owner->query_cap_name()+
                         " "+COL2+"consumes"+COL+" some of "+tgt->query_cap_name()+
                         "'s power."+RES, environment(owner), ({owner, tgt}));
      }
    }
  }
  
  // power bleeds off, if no power at all spell is used up
  if (++counter >= decay) {
    counter=0;
    if (ac < 1) {
      message("magic", COL+"The aura devours itself!"+RES, owner);
      message("magic", COL+"The aura around "+owner->query_cap_name()+
                       "devours itself!", environment(owner), owner);
      remove();
      return;
    }
    else {
      ac--;
      owner->add_magic_protection(({0, -1, 0}));
    }
  }
}

int remove() {
  if (owner)
    owner->add_magic_protection(({0, -ac, 0}));
  return ::remove();
}

