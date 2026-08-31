#include <std.h>
#include "/domains/labyrinth/defs.h"
inherit DAEMON;

void clean_labrys();
void warn_labrys(int stage);

void create() {
    set_no_clean(1);
    warn_labrys(1);
}

void warn_labrys(int stage) {
    object *players;
    int i;
    string msg;

    switch(stage) {
    case 1: {
            msg = "You hear a faint sound of wind blowing somewhere.";
            break;
        }
    case 2: {
            msg = "The wind whistles and moans through the corridors of "+
            "the Labyrinth.";
            break;
        }
    case 3: {
            msg = "The wind howls, dinning in your ears.  You hear "+
            "the faint sound of screaming.";
            break;
        }
    case 4: {
            msg = "The wind builds to a terrible shriek.";
            clean_labrys();
            break;
        }
    case 5: {
            msg = "The sound of the wind dies away.";
            break;
        }
    }
    i = sizeof(players = users());
    while(i--) {
        if(environment(players[i])) {
            if(environment(players[i])->query_labrys()) {
                message("labrys",""+msg+"",players[i]);
            }
        }
    }
    if(stage<5) {
        call_out("warn_labrys",20,stage+1);
    }
}

void clean_labrys() {
    string *roomlist;
    object *userrooms, *rooms, *players;
    int i, j;
    i = sizeof(players = users());
    userrooms = ({ });
    while(i--) {
        userrooms += ({ environment(players[i]) });
    }
    i = sizeof(roomlist = get_dir(ROOM_DIR));
    while(i--) {
        rooms = children(ROOM_DIR+roomlist[i]);
        j = sizeof(rooms);
        while(j--) {
            if(rooms[j]) {
                if(member_array(rooms[j],userrooms)==-1) {
                    all_inventory(rooms[j])->remove();
                    rooms[j]->remove();
                }
            }
        }
    }
    call_out("warn_labrys",370,1);
}

