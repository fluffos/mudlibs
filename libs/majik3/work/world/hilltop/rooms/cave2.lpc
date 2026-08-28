// DATE        : Sun Feb  8 19:10:59 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : yorkaturr

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Cave");
  set_long (
    "You are surrounded by darkness. Your heels touching the ground"
  + " you stand on and the moisture gathering on your forehead are"
  + " the only possible hints of where you are. A cave maybe? Gent"
  + "le tinkling of flowing water can be heard from somewhere deep"
  + "er in the cavern.");

  add_exit ("south", ROOM_PATH + "cave1");
  add_exit ("northwest", ROOM_PATH + "cave4");
  add_exit ("east", ROOM_PATH + "cave3");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
