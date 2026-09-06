#include <rooms.h>
#include <properties.h>
#include <moving.h>


inherit "/std/room";

// Standard special exit which will move the player
int go_north()
{
  printf("go_north...\n");
  this_player()->move("/players/softbyte/house/workroom",M_GO);
  return 1;
}

// Combined special exit which will return the target room if 
// flag==EXIT_CHECK_ONLY , otherwise it behaves like a normal
// special exit
mixed go_rest(string dir,int flag)
{
  printf("go_rest: dir=%O flag=%O\n",dir,flag);
  if (flag==EXIT_QUERY_ONLY) 
    return "/players/softbyte/house/hall";
  else 
  {
    this_player()->move("/players/softbyte/house/hall",M_GO);
    return 1;
  }
}

create()
{
  ::create();

  SetIntLong(
  "A room for testing special exits.\n"
  "- north leads to Softbyte's workroom\n"
  "- east and south lead to Softbyte's hall\n");
  SetIntShort("an exit room");
  SetIndoors(1);
  SetIntLight(50);

  // The third argument indicates where the exit will lead to. This
  // is very important for aiming, farsighting, etc.
  AddExit("north",#'go_north,"/players/softbyte/house/workroom");
  // The following two commands do the same, i.e. use the function
  // go_rest to move the player as well as use this function to
  // return the target room
  AddExit("south",#'go_rest,#'go_rest);
  AddExit("east",#'go_rest);

}
