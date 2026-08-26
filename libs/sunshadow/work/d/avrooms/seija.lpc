//Seija's workrook - LoKi Jan 2022

#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_property("no teleport",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Seija's Workroom");
   set_short("%^C045%^S%^C231%^e%^C045%^i%^C231%^j%^C045%^a's Workroom%^CRST%^");
   set_long("%^C231%^This immense landscape seems an impossibility, given that "+
      "it is contained within pale stone walls barely visible in the distance. "+
      "A vast swath of land opens here, a fr%^C045%^i%^C231%^gid tundr%^C045%^a%^C231%^ "+
      "at the northernmost point is a %^C006%^blur%^C231%^ through the "+
      "endless %^C038%^s%^C231%^no%^C014%^w%^C231%^s%^C038%^t%^C231%^orm%^C014%^s%^C231%^. "+
      "Directly to the south is the complete opposite, %^C020%^mirages%^C231%^ "+
      "and %^C029%^oasis%^C231%^ blend together in the grueling heat of "+
      "a %^C003%^desert%^C231%^. A %^C248%^rocky shoreline%^C231%^ travels the "+
      "eastern edge of the land, which seems %^C231%^to border a %^C075%^massive ocean%^C231%^, "+
      "waves clashing against it as a constant %^C123%^breeze%^C231%^ %^C231%^flows from the "+
      "east towards the %^C060%^mountainous west%^C231%^. A breathtaking %^C059%^mountain "+
      "range%^C231%^ stands on the western border with %^C251%^snow-covered%^C231%^ peaks "+
      "dipping into %^C043%^rich valleys%^C231%^ that fade quickly from view. The four "+
     "unique areas being so %^C231%^close together causes many natural pheonomena that ebb and "+
      "flow, dancing %^C231%^around each other, no element ever gaining the upper hand. In "+
      "the direct %^C231%^center of the land sits an %^C241%^altar%^C231%^ that shifts from a "+
      "mammoth %^C245%^granite rock%^C231%^ %^C231%^hewn from the bones of the world to a "+
      "molten %^C196%^pillar of fire%^C231%^ and %^C196%^magma%^C231%^ only %^C231%^to be "+
      "sucked up into a vast maelstrom of %^C111%^water%^C231%^ and %^C159%^ice%^C231%^. "+
      "The only constant %^C231%^is a glowing image of a %^C075%^scimitar%^C231%^ suspended "+
      "above the altar and the %^C231%^breathless silence that envelops the "+
      "immediate area around it.%^CRST%^\n");

   set_smell("default","%^C110%^You smell the %^C159%^fresh scent%^C110%^ of the %^C062%^ocean%^CRST%^.");
   set_listen("default","%^C186%^You hear the %^C190%^wind%^CRST%^.");

   set_exits(([
      "lounge" : "/d/dagger/avalounge",
     "items" : "/d/dagger/wiz_store2",
     "loki" : "/realms/loki/workroom",
   ]));

}

void reset() {
   object ob;
   ::reset();
   if (!objectp(present("seija_board"))) {
      ob = new("std/bboard");
      ob->set_name("Seija board");
      ob->set_id( ({ "board", "Seija_board", "my board" }) );
      ob->set_board_id("seija_board");
      ob->set("short", "%^C159%^Seija's Board%^CRST%^");
      ob->set("long", "%^C159%^A noteboard stuck with notes.%^CRST%^\n");
      ob->set_max_posts(30);
      ob->set_ooc_board(1);
      ob->set_restricted_read();
      ob->set_location(base_name(TO));
      ob->move(TO);
      ob->set_property("no steal",1);
   }
}

