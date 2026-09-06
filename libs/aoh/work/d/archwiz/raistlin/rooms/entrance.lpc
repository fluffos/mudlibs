inherit "/std/room";
#include <moving.h>

void create() {

    ::create();

    SetIntShort("The Entrance of the McDonalds");
    SetIntLong(
        "You stand in the entrance hall of the biggest McDonalds you "
        + "have ever seen.\n"
        + "To the south you can see the counter, where many guests order "
        + "their meals and drinks.\n"
        + "To the north, you can leave this impressing place.\n");

AddDetail("sign","You see a beautiful sign.\n");
    AddExit("north","+archwiz/common/room/city/southave2");
    AddExit("south","+archwiz/raistlin/rooms/stand1");
}


/*
    remove the comments around the "room is modified()" code
    below to prevent changes you have done to this room to
    to be lost by using the room maker
*/
room_is_modified() {
    return 1;
}

/*
 make your additions below this comment, do NOT remove this comment
--END-ROOM-MAKER-CODE--
*/
