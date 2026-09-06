// 01-12-98, Kieve
// 02-09-98, Kieve.  Added emotion ability for 20k gc. catch_feeling()
#include <treasure.h>
#include <daemons.h>
#include <room_defs.h>

// This was basically ripped off /areas/s/virtual/world/objects/obelisk_stone
// Kudos to The coder.

// This was made for moonshadow  100k + 20k for the query_long() modification
//  Moonshadow has explicitly requested that no one else be given
// this stone. Please respect her wishes.
// 20k more were collected to allow emotions to this object.

#define TP        this_player()
#define ENV(xx)   environment(xx)

void create_treasure() {
    set_name("moonstone");
    set_id(({ "stone", "small stone", "moonstone" }));
    set_short("A Moonstone");
    // long is from query_long()
    set_weight(0);
    set_value(0);
}

int drop() { return 1; }
int get()  { return 0; }

string query_long() {
    string long;
    string phase;
    long = "This is a glowing stone representing the beauty of Malerana. "+
    "Malerana, also known as the silver wanderer, emits dim white "+
    "light to the darkness of nights. It is an important part to the "+
    "lives of living kind, and symbolizes their magic and desity.";
    // This was partially quoted from /complex/nature.c

    //     It is symbol of greedyness, evil and undeads. When malerana is full,
    //     beware the werevolves!
    // hehe Moonshadow doesn't know this, but then only coders could.
    // Ironic in a way. =)

    if(NATURE_D->query_moon()  &&  ENV(TP)  &&
      (ENV(TP)->query(ROOM_WD) & WD_OUTDOORS))
	long += " Sensing Malerana above, it vibrates softly.";
    phase = NATURE_D->query_malerana_phase();
    long += " You sense Malerana to be a "+phase+" presence.";
    return long;
}

int catch_show(object shower, object showee) {
    showee->tell_me(query_long());
    return 1;
}

int catch_feeling(string verb, string arg) {
    return 1;
}

string query_auto_load() {
    string fname;
    sscanf(object_name(this_object()), "%s#%~d", fname);
    return fname+":";
}
