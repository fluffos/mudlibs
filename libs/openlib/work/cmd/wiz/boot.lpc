#include <command.h>

int 
main(string arg)
{
  object victum;
  object place;

  if(!arg)
    return notify_fail("usage: boot <persom>\n");

  victum = find_player(arg);

  if(!victum)
    return notify_fail("That player isn't on-line to begin with.\n");

  if(victum == this_player())
    return notify_fail("Try using the quit command.\n");

  place = environment(victum);

  victum->move("/adm/obj/daemon/void");

  tell_room(place, "A dark mist floats in the room and forms around " +
	            victum->query_cap_name() + ".\n");

  tell_room(place, "The dark mist then floats away to another reality, "
	           "dragging " + victum->query_cap_name() + " with it.\n");

  tell_object(victum, "A dark mist comes in the room, and drags you off "
	              "with it.\n");

  tell_object(victum, "Dark mist says:  We are going to MY REALITY NOW!\n");
  tell_object(victum, "Dark mist laughs, and waves bye-bye to you.\n");

  victum->force_me("quit");

  write("Dark mist tells you:  Complete my lord.\n");

  return 1;
}
