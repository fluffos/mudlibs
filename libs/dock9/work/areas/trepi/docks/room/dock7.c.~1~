/* /areas/trepi/docks/dock7.c

 (emsenn and abzde)@Dock 9
 091212
 One of the docks in Trepi.

*/

inherit ROOM;

void create(){
    set_light(1);
    set_short("Dock 7");
    set_domains("trepi",({"docks"}));
    set_long("This is the Dock 7, one of the six docks in the town of  Trepi.  There were, at one point, twelve docks, as well as a second pier.  However, after a freak accident, Docks 1 through 6 were destroyed, leaving Dock 7 as the lowest numbered dock, as well as the dock closest to the town of Trepi.");
    set_items( ([
        ({"dock","dock 7"}):"This is Dock 7, one of the six docks in Trepi, and at this point, the lowest numbered dock.",
        ({"west","dock 8"}):"From a distance, you realize Dock 8 is made of cheese...",
        ({"docks"}):"There are five other docks, all to the south, west, or southwest.",
        ({"pier"}):"The pier, to the south of here, juts into Trepi Strait.",
        ({"strait","trepi strait"}):"Trepi Strait separates Trepi from the continent of Nulens, just over the horizon.",
        ({"horizon"}):"Somewhere over the horizon is a world of possibilities.  And vicious animals who hunger for your flesh.  But mostly good possibilities.  But... also vicious animals."
        ({"trepi","town","east"}):"Trepi is just to the east, separated by a short expanse of water.",
        ({"expanse","water","waters","clear waters"}):"The water below is clear, showing the pebbly beach leading up to the town.",
        ({"pebbles","beach","pebbly beach"}):"The Strait slopes upward onto dry land, covering it with the same white gravel that covers the floor of the Strait.",
        ({"gravel","white gravel"}):"The Strait bottom is white gravel, slowly progressing on its quest to become powdery white sand.",
        ({"floor","bottom","strait bottom"}):"The bottom of the strait is clearly visible thanks to the clear waters.",
      ]) );
    set_exits(([
        "south" : __DIR__ +"pier1.c",
      ]) );
}

