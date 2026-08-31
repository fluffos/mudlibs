// wind dance rewritten by Nulvect 2006-08-28
#include <std.h>
#include <daemons.h>

#define COL "%^CYAN%^"
#define RES "%^RESET%^"

inherit SONG;

void finish();

int dance() {
  object tp=this_player();
  if (tp->query_subclass() == "gypsy" &&
      tp->query_skill("entertainment") >= 5*5)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <perform dance of the zephyrs>\n\n"
    "A flowing dance that brings the gypsy's body in tune "
    "with the wind spirits. He becomes much faster for the "
    "duration.",
    this_player());
}

void create() {
  ::create();
  set_dance_name("dance of the zephyrs");
  set_auto(0);
  set_type("beneficial");
  set_target_required(0);
  set_max_rounds(3);
}

int check() {
  object tp=this_object()->query_caster();

  if (!tp) return 0;

  if (tp->query_sp() < 20)
    return notify_fail("You are too tired.\n");

  if (tp->query_stat_bonus("dexterity") > 0)
    return notify_fail("You already seem to be faster than usual.\n");

  return 1;
}

void performance(int round) {
  object tp=this_object()->query_caster();
  object env=environment(tp);
  object tgt;
  int amt, now, peak;

  if (round == 1) {
    int r;
    r = 6;
    r += tp->query_stats("dexterity")/25;
    r += tp->query_stats("constitution")/30;
    r += tp->query_skill("entertainment")/60;
    if (r > 20) r = 20 + tp->query_level()/20;
    if (r%2 == 0) r++;
    set_max_rounds(r);
    message("dance", "You begin to flow with the wind.", tp);
    message("dance", tp->query_cap_name()+" begins a flowing dance.",
                     env, tp);
    return;
  }

  if (tp->query_sp() < 20) {
    finish();
    remove();
    return;
  }

  peak = query_max_rounds()/2+1;
  if (round > peak)
    now = query_max_rounds()-round;
  else
    now = round;
  amt = tp->query_skill("entertainment")/5;
  amt += 10;
  amt = amt/2 + to_int(to_float(amt/2)*(to_float(now)/to_float(peak)));

  tp->add_stat_bonus("dexterity",amt,4);
  
  tp->add_sp(-(3+amt/12));

  if (!(round%2)) {
    message("dance", "You "+COL+"twirl"+RES+" and "+COL+"flow"+RES+
                     " with the wind!", tp);
    message("dance", tp->query_cap_name()+" "+COL+"twirls"+RES+
                     " and "+COL+"flows"+RES+" with the wind!", env, tp);
  }
  
}

void finish() {
  object tp=this_object()->query_caster();
  message("dance", "You gracefully step out of the dance.",tp);
  message("dance",tp->query_cap_name()+" gracefully steps out of "+
                  tp->query_possessive()+" dance.", environment(tp), tp);
}


