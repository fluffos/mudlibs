
#include <std.h>
#include <rooms.h>
#include <saahr.h>

int do_swim(string str);
int can_swim(object tp);

void init() {
  add_action("do_swim", ({"swim"}) + (this_object()->query_exits() || ({}) ) );
}

int do_swim(string str) {
  object tp=this_player();
  string verb=query_verb();
  string dir;
  object toroom;
 
  if (verb == "swim") {
    if (!str || str =="")
      return notify_fail("Swim where?\n");
    else
      dir=str;
  }
  else
    dir=verb;

  if (tp->query_disable())
    return notify_fail("You can't swim that fast!\n");

  if ((toroom=load_object( this_object()->query_exit(dir) || "" )) == load_object(ROOM_VOID))
    return notify_fail("You can't swim in that direction.\n");

  if (!can_swim(tp))
    message("info","You try to swim, but don't get very far.",tp);

  else {
    message("mout","You swim "+dir+".",tp);
    message("mout",tp->query_cap_name()+" swims "+dir+".",environment(tp),tp);
    message("min", tp->query_cap_name()+" swims in.", toroom);
    tp->move(toroom,dir);
    tp->describe_current_room(1);
  }

  toroom=0;
  tp->set_disable();
  tp->add_sp(-(15+random(10)));
  return 1;
}

int can_swim(object tp) {
  if (tp->query_sp() < 30)
    return 0;
  if ((tp->query_stats("strength")+
       tp->query_stats("dexterity")+
       tp->query_stats("constitution"))/3 < 30+random(30))
    return 0;
  return 1;
}

