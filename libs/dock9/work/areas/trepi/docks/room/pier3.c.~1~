/* /areas/trepi/docks/room/pier6.c

 emsenn@Dock 9
 091005
 The far west end of the southern pier in Trepi.  Has the first NPC a player will
 encounter.

*/

inherit ROOM;

void create(){
    object mob = clone_object("/areas/trepi/docks/npc/greeter_sailor.c");
    set_light(1);
    set_short("Pier, Trepi");
    set_domains("trepi",({"docks"}));
    set_long("This is pier in Trepi.  To the north and south are docks "
      "9 and 12, respectively.  Immediately to the west the pier drops off to "
      "the waters of Trepi Strait, while the east continues on into the town "
      "of Trepi, which is itself located on the island of Trepi.  It is often "
      "asked, \"Why does everything in Trepi have the word Trepi in the name?\"  "
      "The customary answer is, of course, \"Trepi.\"");
    set_items( ([
        ({"pier"}):"This is the southern pier in Trepi, implying "
          "that there is a northern pier.  There was, and oddly enough, it used "
          "to be just a bit north of here.  However, times, and weather, change, "
          "and the pier is now located several feet below water.",
        // http://buttersafe.com/2008/03/13/romance-on-the-floating-island/
        ({"trepi"}):". o O (PITREPITREPITREPITREPITREPITREPITREPITREPITREPITR)",
        ({"docks","dock"}):"There are two docks immediately adjacent to here, "
          "Dock 9 to the north and Dock 12 to the south.",
        ({"waters","water"}):"Between the slats of the pier and to the west you "
          "can see the clear waters of Trepi Strait, and the white gravel under "
          "it.",
        ({"pebbles","gravel","stone","stones","rocks","rock"}):"The floor of "
          "Trepi Strait is made of brilliant white pebbles.",
        ({"trepi strait","strait"}):"Trepi Strait is to the west, north, and "
          "south of here.",
        ({"dock 9"}):"Dock 9 is immediately to the north of here.  Something "
          "seems not quite right about it, though.",
        ({"dock 12"}):"Dock 12 is just to the south of here.",
      ]) );
    set_chats(({
        "You can hear the soft swish of the waters underneath you.",
        "You hear a subtle splash of something falling in the water.",
    }));
    set_exits(([
        "north" : __DIR__ +"dock9.c",
	"south" : __DIR__ +"dock12.c",
        "east"  : __DIR__ +"pier2.c"
      ]) );
    mob->move(this_object());
}
