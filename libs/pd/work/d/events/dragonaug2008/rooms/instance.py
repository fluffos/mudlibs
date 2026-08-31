#include <std.h>
#include <dragonevent.h>
#include <rest.h>
#include <rooms.h>

inherit DAEMON;
inherit ROOM;

mapping roomInstances = ([ ]);


object get_instance_room(string id) {
  object newRoom;
  if(roomInstances[id]) return roomInstances[id];
  newRoom = new(DRAG_ROOMS"battleroom");
  roomInstances[id] = newRoom;
  return newRoom;
}

string* query_instances_tracked() { return keys(roomInstances); }

int use_exit(string str) {
    string verb, st;
    int dd;

    if(str) return 0;
    if(this_player()->query_paralyzed()) {
        notify_fail("You are unable to move.\n");
        return 0;
    }
    if( this_player()->query_disable() &&
      sizeof(this_player()->query_attackers()) ) {
        write("You can not exit while doing something else.");
        return 1;
    }
    if(!(verb = query_verb())) return 0;
    if(query_exit(verb) == ROOM_VOID) {
        write("Error:  Set to VOID.  Notify creator of room.\n");
        return 1;
    }

    if (!this_player()->query_mobile()) {
      message("info", "You cannot walk!", this_player());
      return 1;
    }
    if ( this_player()->query_rest_type() )
        switch( this_player()->query_rest_type() )
    {
    case REST:
        this_player()->force_me("stand");
        break;
    case SIT:
        this_player()->force_me("stand");
        break;
    case LAY:
        this_player()->force_me("stand");
        break;

    }

    if (function_exists("exit_blocked", this_object()) && this_object()->exit_blocked(verb)) return 1;

    if(!perform_pre_exits(verb)) return 1;
    this_player()->move_player(DRAG_ROOMS"instance.c"->get_instance_room(this_player()->query_name()+"%"+query_exit(verb)), verb);
    //if (sizeof(this_player()->query_followers())) this_player()->move_followers(this_object(), verb);
    perform_post_exits(verb);
    return 1;
}
