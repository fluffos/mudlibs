// A simple room for our voting box
//
// Creation : 8 Sep 1997 by Eilan

#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <rooms.h>
#include <secure/wizlevels.h>
#include <moving.h>

inherit "/std/room";

varargs void create()
{
  ::create();
  SetIntShort("Voting room");
  SetIntLong(
"Standing in a small room you notice a large desk in front of you. On the\n"
"desk you can see a little box with some ingravings on it.\n"
"Some couches are standing around the desk where you can have a little\n"
"break or where you can deeply think about your vote.\n" //
"here you can TAKE one of the VOTING boxes. Do not vote here anymore.\n");

  AddDetail( ({"room","small room"}), #'IntLong);
  AddDetail( ({"desk","large desk","wooden desk"}),
"This desk is made of strong wood. You can see a box standing on it.\n");
  AddDetail( ({"couch","couches","some couches"}),
"There are standing some couches around the desk. They look very comfortable.\n");

  //AddItem("/obj/wizard_voting");
  AddItem("/obj/tool/voter",REFRESH_REMOVE,5);
}

int allow_enter (int method, mixed extra) {
  if (!IS_IMMORTAL(previous_object())) {
    tell_object(previous_object(),
      "You are not allowed to enter this voting room!\n");
    return ME_NO_ENTER;
  }
  return ME_OK;
}
