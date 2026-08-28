//    A daemon which manages opening and shutting of shops at particular times
//    of the mud clock.  Checks every hour on the hour.  Also manages timed
//    functions in rooms such as removing the shopkeeper when it is
//    closed.
//
//    DarkeLIB 0.1
//    -Diewarzau 10/25/95

#include <clock.h>

nosave int hour;
nosave object *rooms;

void create() {
  int i;

  seteuid(getuid());
  rooms = ({});
  call_out("manage_shops", (21 - (CURRENT_MINUTE(time()) / 2)) * 20);
  return;
}

void add_room(object what) {
  rooms = distinct_array(rooms + ({ what }) );
}

void manage_shops() {
  int i;

  i = sizeof(rooms);
  while(i--)
    if(objectp(rooms[i]))
      rooms[i]->check_closed();
  call_out("manage_shops", 400);
  return;
}
