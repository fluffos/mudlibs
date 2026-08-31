
#ifndef _SAAHR_RIVER_H_
#define _SAAHR_RIVER_H_

mapping river_exits;

void river_current(object tp);
int do_swim(string str);
int can_swim(object tp);

void init() {
  ::init(); 
  add_action("do_swim","swim");
  call_out("river_current",4,this_player());
}

void river_current(object tp) {
  if (environment(tp) == this_object()) {
    message("info","%^BOLD%^%^CYAN%^The current pushes you down river.%^RESET%^",tp);
    message("info","%^BOLD%^%^CYAN%^The current pushes "+tp->query_cap_name()+
      " down river.%^RESET%^",this_object(),tp);
    tp->move_object(VPROOMS+river_exits["downriver"]);
  }
}
  
int do_swim(string str) {
  object tp=this_player();
 
  if (!str || str =="")
    return notify_fail("Swim where?\n");

  if (!(river_exits[str]))
    return notify_fail("You can't swim that direction.\n");

  if (!can_swim(tp))
    message("info","You try to swim, but don't get very far.",tp);

  else {
    message("info","You swim "+str+".",tp);
    message("info",tp->query_cap_name()+" swims "+str+".",environment(tp),tp);
    tp->move_player(river_exits[str],str);
  }

  tp->set_disable();
  tp->add_sp(-(15+random(10)));
  return 1;
}

int can_swim(object tp) {
  if (tp->query_sp() < 30)
    return 0;
  if ((tp->query_stats("strength")+
       tp->query_stats("dexterity")+
       tp->query_stats("constitution"))/3 < 40+random(50))
    return 0;
  return 1;
}

#endif

