#include <std.h>

inherit ROOM;

void init() {
  ::init();
  add_action("do_graze", "graze");
}

int do_graze(string str) {
  object tp = this_player();

  if (tp->query_race() != "centaur") {
    return notify_fail("That does not sound appetizing to you.\n");
  }

  if (str && str != "on grass") {
    return notify_fail("You cannot graze on that.\n");
  }


  write("%^GREEN%^As you stare at the grass something suddenly snaps "
   +"in your head and you launch yourself at it, chewing madly.%^RESET%^");
  tell_room(environment(this_player()), "%^GREEN%^"
   +tp->query_cap_name()+" stares at the grass longingly. Suddenly "
   +tp->query_subjective()+" leaps at the grass starts tearing it apart with "
   +tp->query_posessive()+" teeth, chewing madly.", ({ tp }));
  tp->set_paralyzed(10, "%^RED%^Must... Eat... Grass!!!!%^RESET%^");
  call_out("done_grazing", 10, tp);

  return 1;
}

int done_grazing() {
  this_player()->add_hp(100);
  this_player()->add_sp(100);
  this_player()->add_mp(100);
  this_player()->add_stuffed(150);
}
