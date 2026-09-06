


//   Written by Calidron for Walraven
//   6/02

#include <const.h>

int main(string args) {
  int *targcoords, targx, targy;
  int x = this_player()->query_x();
  int y = this_player()->query_y();
  object room = environment(this_player()), dest_obj;
  string dest;
  float distance;

  if( !args ) {
     notify_fail("What do you want to fire upon?\n");
     return 0;
  }
  if (sizeof(args) >= 3 && args[0..2] == "at ") {
    args = args[3..];
    if (sscanf(args,"%d,%d",targx,targy) == 2) {
     targcoords=({targx,targy});  // need to add height of z
    } else {
      object target = present(args,room);
      if (!target)
        if (target = find_object(args)) {
          // allow people to fire between rooms later
          while (environment(target) != room)
            target = environment(target);
        } else {
          msg("You can't hit that from here!");
          return 1;
        }
      targx = target->query_x();
      targy = target->query_y();
      dest_obj = target;
    }
  }

  return 1;
}
