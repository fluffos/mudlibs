/* /areas/trepi/room/dock9.c

 emsenn@Dock 9
 091005
 One of the docks in Trepi.

*/

inherit ROOM;

void create(){
    set_light(1);
    set_short("Dock 12");
    set_domains("trepi",({"docks"}));
    set_long("This is the Dock 12, one of the six docks in the town of "
      "Trepi.  This dock marks the southwestern corner of the town, and gives "
      "a very nice view of the smooth light blue waters of Trepi Strait.  To "
      "the north is a pier, which branches off into other similar docks.  The "
      "place has an uncanny stillness to it.");
    set_items( ([
        ({"dock","dock 12"}):"This is just one of many docks that allow for "
          "ships to easily land and disembark from the town.",
        ({"Trepi","town"}):"The town of the Trepi is to the northeast from here.",
        ({"corner"}):"This is the southwestern corner of town.  While you could "
          "probably go further southwest from here, you'd end up quite soggy.",
        ({"waters","water","strait","trepi strait"}):"The Strait is to the "
          "west of here.  The waters are a dynamic blue shade.",
        ({"pier"}):"The fairly long pier is to the north of here.",
        ({"docks"}):"There are five other docks in Trepi, all connected to the "
          "pier."
      ]) );
    set_chats(({
        "Nothing much happens here.",
        "A complete lack of events occur.",
        "Something may have just happened!  Unfortunately, if it did, it was "
          "drowned out by the overwhelming abundance of nothing occuring.",
      }));
    set_exits(([
	"north" : __DIR__ +"pier3.c",
      ]) );
}
