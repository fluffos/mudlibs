#include <const.h>
#include <alias.h>
#include <const/exitsconst.h>

main(str) {
   string dir, dest;
   object room, exit_ob;
   string etype;
   int xexit, yexit;

   WIZ_CHECK

   if( !str || (sscanf(str, "%s %s %s", dir, dest, etype) != 3 && sscanf(str, "%s %s", dir, dest) != 2) ) {
      notify_fail("==> [Format] dig direction room_name [exit_type]\n");
      return 0;
   }

   if( !etype && !(etype = this_player()->query_env_var("dig_type")) ) {
      notify_fail("No exit_type was specified. To set a default type, set dig_type.\nFor example, 'set dig_type=outdoors' and try again.\n");
      return 0;
   }

   if( !legal_filename(dest) || member(dest, '/') >= 0 ) {
      notify_fail("Not a legal room name. Try something else. If a room by that name already exists, rename it.\n");
      return 0;
   }

   room = environment(this_player());
   if(!room) return 0;

   if( exit_ob = present("exit_"+dir, room) ) {
      destruct(exit_ob);
   }

   if( !find_room(dest, environment(room)) ) {
      string room_name, room_loc;
      object new_room, new_room_loc;

      room_name = explode( dest, ";" )[<1];
      room_loc = implode(explode( dest, ";" )[..<2], ";");

      if( room_loc != "" ) {
         new_room_loc = find_room( room_loc, environment(room) );
         if( !new_room_loc ) {
            notify_fail("I can't find " + room_loc + ", so don't know where to put the room. Giving up.\n");
            return 0;
         }
      }
      else
         new_room_loc = environment(room);

      new_room = clone_object("/world/room");
      new_room->move(new_room_loc);
      new_room_loc->reset_room_map();
      new_room->set_name( room_name );
      new_room->set_short( "New room '"+room_name+"'");
      new_room->set_long( "This room is undescribed. It was created by " + this_player()->query_cap_name() + ".");
   }

   // Exit types which have no coordinates will ignore this.
   // Exit types which do have coordinates will be a little more
   // convenient to work with.
   xexit = this_player()->query_x();
   yexit = this_player()->query_y();
   xexit += ([ "west":-1, "east":1 ])[dir];
   yexit += ([ "north":-1, "south":1 ])[dir];


   exit_ob = clone_object( etype );
   exit_ob->move(room);
   // Setting coord before dir & link means that the heuristic for positioning
   // the inverse exit is more likely to work.
   exit_ob->set_coord( MAKE_C(xexit, yexit, this_player()->query_z()) );
   exit_ob->set_dir( dir );
   exit_ob->set_link( dest );
   exit_ob->exit_action();

   return 1;
}
