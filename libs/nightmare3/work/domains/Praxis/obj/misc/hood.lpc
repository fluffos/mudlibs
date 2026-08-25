//  /domains/Praxis/obj/misc/hood.c
//  A hood for blinding players
//  For the Nightmare mortal law system
//  Created by Manny@Nightmare 940906

#include <std.h>

inherit OBJECT;

create() {
  ::create();
  set_name("hood");
  set_id(({"hood", "black hood" }) );
  set_short("a black hood");
  set_long("A black hood to hide the eyes of victims");
  set_prevent_drop("The hood is securly fastened to your neck");
}

init() {
  ::init();
  if(!living(environment(this_object()))) remove();
  add_action("cmd_look", "look");
  add_action("cmd_look", "peek");
  add_action("cmd_look", "give");
}

cmd_look() {
  message("my_action", "It is too dark.", this_player());
  return 1;
}

