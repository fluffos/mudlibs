// void add_sp(int x) {
//   ...
//   if (x < 0 && v=this_object()->query_property("vigor")) {
//     y=x+v;
//     if (x < -10 && y > -10)
//       x=-10;
//     else
//       x=y;
//   }
//   ...
#include <std.h>

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

void devigor(object tgt) {
  tgt->remove_property("vigor");
  message("magic","%^CYAN%^The invigorating feeling leaves you.%^RESET%^",
      tgt);
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
  f=tp->query_skill("faith");
  wis=tp->query_stats("wisdom");
  
  amt=(h+f/2+wis)/11;
  len=h/4+wis/2;
  cost=h+f/2+wis;

  if (tp->query_mp() < cost)
    return notify_fail("You don't have enough mana for that.\n");
  
  tp->add_mp(-(cost+random(10)));
  tgt->set_property("vigor",amt);
  call_out("devigor",len,tgt);

  if (tp == tgt) {
    message("magic","%^CYAN%^A soft light glows around you, invigorating you.%^RESET%^",tp);
    message("magic","%^CYAN%^A soft light glows around "+tp->query_cap_name()+".%^RESET%^",
        environment(tp),tp);
  }
  else {
    message("magic","%^CYAN%^You grasp "+tgt->query_cap_name()+
                     " gently and a soft light flows into "+
                     tgt->query_objective()+", invigorating "+
                     tgt->query_objective()+".%^RESET%^",tp);
    message("magic","%^CYAN%^"+tp->query_cap_name()+
                    " grasps you gently and a soft light flows into you, "
                    "invigorating you.%^RESET%^",tgt);
    message("magic","%^CYAN%^"+tp->query_cap_name()+
                    " grasps "+tgt->query_cap_name()+
                    " gently and a soft light flows between them.",
                    environment(tp),({tp,tgt}));
  }

  return 1;
}

