/* /areas/trepi/docks/room/dock11.c

 (emsenn @Dock 9
 091212
 One of the docks in Trepi.

*/

inherit ROOM;

void create(){
    set_light(1);
    set_short("Dock 11");
    set_domains("trepi",({"docks"}));
    set_long("This is the Dock 11, the second to last dock in the town of Trepi.  Actually, it could be the first, second to first, or middle dock.  It really depends on which direction you approach the docks from.  However, it is absolutely the second highest numbered of the six docks.  To the east is Dock 10, and west has Dock 12.  To the north is the pier, which connects the docks.");
    set_items( ([
        ({"dock","dock 11"}):""This is Dock 11.  One would assume that it is the eleventh dock, however due to a horrible accident, it is actually the fifth.",
        ({"docks"}):"There are docks to in every direction except south, since Trepi Strait starts there.",
        ({"dock 10","east"}):"Dock 10 is to the east.  To the east is Dock 10.",
        ({"dock 12","west"}):"Dock 12 is to the west.  To the west is Dock 12.",
        ({"pier"}):"To the north is the pier, which connects the six docks.",
        ({"town","trepi"}):"Trepi is a bit to the northeast.",
        ({"ocean","strait","besling ocean","trepi strait","waves"}):"The swaying light hitting the blue waves is dazzling and entrancing."
      ]) );
    set_chats(({
        "You detect a faint scent of cheese on the breeze coming in from the north.",
        "The waves lap gently at the docks.",
        "The bright sun on the waves is almost blinding."
        "If only you could see all the way over the horizon. But then it would no longer be a horizon."
      }));
    set_exits(([
        "north" : __DIR__ +"pier2.c",
      ]) );
}

