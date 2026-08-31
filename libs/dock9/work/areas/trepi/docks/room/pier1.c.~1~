/* /areas/trepi/docks/pier1.c

 emsenn@Dock 9
 091212
 The pier, adjacent to the town.

*/

inherit ROOM;

void create(){
    set_light(1);
    set_short("Pier");
    set_domains("trepi",({"docks"}));
    set_long("This is pier in Trepi.  To the north is the quite dull Dock 7, to the south is the uniquely sensual Dock 10, and the pier continues west.  To the east is a cargo area, full of dollies, crates, and other tools, as well as a strange-looking contraption. A man would be fishing from this pier, if there were no sign.");
    set_items( ([
        ({"dock 7"}):"To the north, Dock 7 awaits you in all its glory.",
        ({"dock 10"}):"Dock 10 allures you alluringly, with its alluringly erotic wiles, which are quite wiley. This is preferable to wirely lures, and also lirely wules.",
        ({"pier"}):"Made of old rotting wood, this pier could give way at any time. But it probably won't. Unless you jump up and down really hard",
        ({"cargo area"}):"This area is full of crates. Which are full of cargo.  There is also a very strange-looking thing over there.",
        ({"man"}):"There is no man fishing here.",
        ({"sign"}):"%^RED%^No Fishing%^RESET%^",
        ({"thing","contraption","strange-looking thing","device"}):"It is on wheels, and has a platform and pulley system attached to the front."
      ]) );
    set_chats(({
        "It's quiet here."
        "Reading the sign does nothing but make you feel like fishing."
      }));
    set_exits(([
        "north" : __DIR__ +"dock7.c",
        "south" : __DIR__ +"dock10.c",
        "west" : __DIR__ +"pier2.c",
        "east" : __DIR__ +"cargo1.c",
      ]) );
}

