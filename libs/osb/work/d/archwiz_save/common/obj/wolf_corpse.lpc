#include <config.h>

#define ASKED_HUNTER "asked_hunter"

inherit "/std/corpse";

remove_me() {
  remove();
  if (this_object()) destruct(this_object());
}

set_quest() {
  QUESTMASTER->SetPlayerQuest("rescue_riding_hood",this_player());
  QUESTMASTER->qshout("A little girl is home again! Thanks to "+
    this_player()->QueryName()+".\n");
  call_out("remove_me",1);
  return 1;
}

int do_cut(string str) {
  object ob;
  if (!this_player()) return 0;
  if (!str) return notify_fail("Cut what?\n"),0;
  if (!this_player()->Query(ASKED_HUNTER)) return notify_fail(
"You do not know what exactly you shall do now, perhaps you should\n"
"go and find the hunter to talk to him.\n"),0;
  if (str!="belly") return notify_fail(
"You should have listened to the hunter more careful.\n"),0;
  if (!ob=present("hunt\nknife",this_player())) return notify_fail(
    "With what do you wanna cut it?\n"),0;
  write(
"As you cut the belly of the wolf, a little girl happily jumps out of it. "
"She turns towards you.\n"
"Little red riding hood says: THANK YOU!!!! You've saved my life! You are the "
"nicest person I've ever met.\n"
"Then she turns around and vanishes between the bushes, running home to her "
"grandma.\n");
  tell_room(environment(),
"As "+this_player()->QueryName()+" cuts the belly of the wolf, a little girl "
"happily jumps out of it.\n"
"She turns towards "+this_player()->QueryName()+".\n"
"Little red riding hood says: THANK YOU!!!! You've saved my life! You are the "
"nicest person I've ever met.\n"
"Then she turns around and vanishes between the bushes, running home to her "
"grandma.\n",({this_player()}));
  set_quest();
  return 1;
}

create() {
  ::create();
}

init() {
  ::init();
  add_action("do_cut","cut");
}
