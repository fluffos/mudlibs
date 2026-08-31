#include <std.h>

inherit MONSTER;

int* boundaries;
int canFly;

int check_sky(object);

void create() {
  ::create();
  canFly = 1;
  set_die( (: check_sky :) );
}

void move_around() {
  /*
    string *exits, exit;
    if(!this_object()) return;
    if (environment(this_object())->query_exits()==({})) return;
    if(environment(this_object()))
      exits = (string*)environment(this_object())->query_exits();
    else exits = 0;
    if (exits)   exit = exits[random(sizeof(exits))];
    if (exits)
      this_object()->force_me(exit);
  */
  string exit;
  if(!this_object()) return;
  if(base_name(environment(this_player())) != "/std/room/sky_room")
    return ::move_around();
  switch (random(6)) {
  case 0: exit = "west"; break;
  case 1: exit = "east"; break;
  case 2: exit = "north"; break;
  case 3: exit = "south"; break;
  case 4: exit = "up"; break;
  case 5: exit = "down"; break;
  default: exit = "land";
  }

  if(environment(this_object())->query_coords()[0] >= boundaries[0]
   && environment(this_object())->query_coords()[0] <= boundaries[1] 
   && environment(this_object())->query_coords()[1] >= boundaries[2]
   && environment(this_object())->query_coords()[1] <= boundaries[3]
   && environment(this_object())->query_coords()[2] >= boundaries[4]
   && environment(this_object())->query_coords()[2] <= boundaries[5]) {
    //monster is within its boundaries

    if( ( exit == "west" && environment(this_object())->query_coords()[0]-1 >= boundaries[0] )
     || ( exit == "east" && environment(this_object())->query_coords()[0]+1 <= boundaries[1] )
     || ( exit == "north" && environment(this_object())->query_coords()[1]-1 >= boundaries[2] )
     || ( exit == "south" && environment(this_object())->query_coords()[1]+1 <= boundaries[3] )
     || ( exit == "down" && environment(this_object())->query_coords()[2]-1 >= boundaries[4] )
     || ( exit == "up" && environment(this_object())->query_coords()[2]+1 <= boundaries[5] ))
      this_object()->force_me(exit);
  }
  else { message("info", capitalize(query_short())+" has strayed out of its territory and has a heart attack out of fear.", environment(this_object())); this_object()->die(); return; }
  moving=0;
}

//mob must stay inside a sky box with the west corner a, east corner b, north corner c, south corner d
varargs void set_boundaries(int westMin, int eastMax, int northMin, int southMax, int downMin, int upMax) {
  if(nullp(westMin)) westMin = 0;
  if(nullp(eastMax)) eastMax = 500;
  if(nullp(northMin)) northMin = 0;
  if(nullp(southMax)) southMax = 500;
  if(nullp(downMin)) downMin = 0;
  if(nullp(upMax)) upMax = 0;
  boundaries = ({ westMin, eastMax, northMin, southMax, downMin, upMax });
}


int query_flying_mob() { return canFly; }
void set_flying_mob(int i) { canFly = i; }

int check_sky(object trashObj) {
  if(base_name(environment(this_object())) != SKY_ROOM)
    return 1;
  set_property("no corpse", 1);
  set_die(capitalize(query_short())+" has been mortally wounded and plummets towards the earth.");
  return 1;
}
