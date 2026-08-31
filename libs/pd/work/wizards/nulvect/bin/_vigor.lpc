#include <std.h>

#define COL "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"
#define COL2 RES+"%^ORANGE%^"

inherit DAEMON;

void help() {
  message("help",
      "Syntax: <vigor [living]>\n"
      "A cleric of moderate skill can grant more vigor to those around him, "
      "causing them to use less energy for physical activities.",
      this_player());
}

int spell() {
  object tp=this_player();
  if (tp->query_subclass() == "cleric" &&
      tp->query_skill("healing") >= 100) return 1;
  return 0;
}

string type() { return "healing"; }

int can_cast(object tp, object tgt) {

  if (!tgt)
    return notify_fail("You don't see that here.\n");

  if (!living(tgt))
    return notify_fail("That is not alive.\n");

  if (environment(tp)->query_property("no magic"))
    return notify_fail("You cannot cast that here.\n");
  
  if (tgt->query_property("vigor"))
    return notify_fail(capitalize(tgt->query_subjective())+
        " is already invigorated.\n");
  
  return 1;
}

void devigor(mixed *args) {
  if (!(args[0])) return;
  args[0]->set("vigor_spell",0);
  message("magic",COL+"The invigorating feeling leaves you."+RES,
      args[0]);
}

int cmd_vigor(string str) {
  object tp=this_player();
  object tgt;
  int h, f, wis, cost, amt, len;
  
  if (!spell()) return 0;

  if (!str || str == "") return notify_fail("Cast it on who?\n");

  if (str == "me") tgt=tp;

  else if (!(tgt=present(str,environment(tp))))
    return notify_fail("You don't see "+str+" here.");
  
  if (!can_cast(tp, tgt)) return 0;

  h=tp->query_skill("healing");
  f=(tp->query_skill("faith")/2 + tp->query_skill("belief")*3/2)/2;
  wis=tp->query_stats("wisdom");
  
  amt=(h+f/2+wis)/15;
  len=h/2+wis/2;
  cost=(h+f/2+wis)*2/3;

  if (tp->query_mp() < cost)
    return notify_fail("You don't have enough mana for that.\n");
  
  tp->add_mp(-(cost+random(10)));
  tgt->set("vigor_spell",amt);
  call_out("devigor",len,({tgt}));

  if (tp == tgt) {
    message("magic",COL+"A "+COL2+"s"+RES+COL+"of"+COL2+"t"+RES+COL+
                        " l"+COL2+"igh"+RES+COL+"t glows around you, "
                        "invigorating you."+RES,tp);
    message("magic",COL+"A "+COL2+"s"+RES+COL+"of"+COL2+"t"+RES+COL+
                        " l"+COL2+"igh"+RES+COL+"t glows around "+
                        tp->query_cap_name()+"."+RES,
        environment(tp),tp);
  }
  else {
    message("magic",COL+"You grasp "+tgt->query_cap_name()+
                     " gently and a "+COL2+"s"+RES+COL+"of"+COL2+"t"+RES+COL+
                     " l"+COL2+"igh"+RES+COL+"t flows into "+
                     tgt->query_objective()+", invigorating "+
                     tgt->query_objective()+"."+RES,tp);
    message("magic",COL+tp->query_cap_name()+
                    " grasps you gently and a "+COL2+"s"+RES+COL+"of"+COL2+"t"+RES+COL+
                    " l"+COL2+"igh"+RES+COL+"t flows into you, "
                    "invigorating you."+RES,tgt);
    message("magic",COL+tp->query_cap_name()+" grasps "+
                    tgt->query_cap_name()+" gently and "
                    "a "+COL2+"s"+RES+COL+"of"+COL2+"t"+RES+COL+
                    " l"+COL2+"igh"+RES+COL+"t flows between them."+RES,
                    environment(tp),({tp,tgt}));
  }

  return 1;
}

