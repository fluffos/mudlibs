#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 object ob;
 ::create();

 set_property("no teleport", 1);


   set_short("The hall of light");
   set_long("Welcome into the monk's subclass hall of light. This "
      "hall was created so that monks of a similar believe could gather "
      "together and speak among themselves, if needed. The doorway leads "
      "back into the monk's hall.");
   set_exits(([ "out" : ROOMS"monk_hall" ]));
   ob = new(BBOARD);
   ob->set_board_id("monk_light");
   ob->set_id(({"board", "light" }));
   ob->set_long("The board of light.");
   ob->set_short("the board of light");
   ob->set_name("board");
   ob->set_location(ROOMS"monk/light");
   ob->set_max_posts(70);
}
