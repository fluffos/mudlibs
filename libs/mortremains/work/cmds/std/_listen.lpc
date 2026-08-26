// /cmds/std/_listen.c
// Lets a player listen in a room, or to items in a room.
// (??-??-96) Chronos modified this.
// (04-04-98) Chronos ported this to the new lib.


#include <mudlib.h>

inherit DAEMON;

#define FAIL_MSG	"You hear nothing out of the ordinary.\n"

int
cmd_listen(string str) {

mixed listen_prop;
string * to_hear;

    listen_prop = environment(this_player())->query("listen");
  if (!str) say(TPN + " listens intently.\n");

    notify_fail(FAIL_MSG);

// If the room has no listen set, this should fail.  Likewise if "listen" is
//   not a string or mapping.

    if(!listen_prop || (!stringp(listen_prop) && !mapp(listen_prop))) return 0;
    
// If "listen" is a mapping, it should be treated like this.

    if(mapp(listen_prop)) {
        to_hear = keys(listen_prop);
        if(!str) str = "default";
        if(member_array(str, to_hear) == -1) return 0;
        write(listen_prop[str]);
        return 1;
    }

// If "listen" is a string, trying to listen to something in particular fails.

    if(str) return 0;
    write(listen_prop);
    return 1;
}

string help() {
return 
@EndHelp

Usage: listen 
       listen <something>

This will allow you to listen in the room, or listen to items in a room.

EndHelp
;
}
