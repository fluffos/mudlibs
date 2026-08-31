
#include <std.h>

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^BLUE%^"
#define COL2 "%^BOLD%^%^WHITE%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp &&
      (tp->query_subclass() == "assassin" ||
      tp->query_subclass() == "scout") &&
      tp->query_skill("perception") >= 60 &&
      tp->query_skill("murder") >= 45)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <evaluate [whom]>\n\n"
    "This is the ability of some rogues to look a potential enemy over "
    "and determine which body parts are poorly protected.",
    this_player() );
}

int can_cast(object tp, object tgt) {
  if (!tp) return 0;

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (!tgt)
    FAIL("Evaluate whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("Planning on stabbing yourself?");

  return 1;
}

int cmd_evaluate(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  mapping bod;
  string *limbs;
  string rep;
  
  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);

  if (!can_cast(tp, tgt)) return 0;

  bod = tgt->query_body_mapping();

  // lowest ac limb at limbs[0]
  limbs = sort_array(keys(bod),
    function (string a, string b, object tgt) {
      if (tgt->query_ac(a) > tgt->query_ac(b))
        return 1;
      if (tgt->query_ac(a) < tgt->query_ac(b))
        return -1;
      else
        return 0;
    }, tgt);

  // if multiple limbs with lowest ac, keep them all
  limbs = filter(limbs, 
    function(string a, int ac, object tgt) {
      if (tgt->query_ac(a) <= ac) return 1;
      else return 0;
    }, tgt->query_ac(limbs[0]), tgt);

  switch (sizeof(limbs)) {
    case 1:
      rep = RES+limbs[0]+COL+" is";
    break;

    case 2:
      rep = RES+implode(limbs, " and ")+COL+" are";
    break;

    default:
      rep = RES+implode(limbs[0..<2], ", ")+" and "+limbs[<1]+COL+" are";
  }

  if (sizeof(limbs) == sizeof(tgt->query_limbs()))
    rep = "entire body"+COL+" is";

  rep = tgt->query_possessive()+" "+rep;

  message("info", "You look "+COL+"over"+RES+" "+tgt->query_cap_name()+
                  " and try to "+COL+"evaluate"+RES+" "+tgt->query_possessive()+
                  " armouring.", tp);
  message("info", tp->query_cap_name()+" seems to look you over.", tgt);
  message("info", tp->query_cap_name()+" seems to look "+
                  tgt->query_cap_name()+" over.", env, ({tp, tgt}) );

  message("info", COL+"You see that "+COL2+rep+COL+" vulnerable."+RES, tp);
  
  tp->set_disable();
  
  return 1;
}
