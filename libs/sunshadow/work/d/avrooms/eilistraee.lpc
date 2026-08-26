// Eli's Room - Implemented by LoKi 2022

#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_property("no teleport",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Abandoned Temple");
   set_short("Abandoned Temple");
   set_long("This is the Abandoned Temple of Eilistraee, a house of prayer located beneath a cliffs edge, where pre-silence gods go to plot the downfall of the unsuspecting players of the world. Built upon the north facing slope of a mountain lost in the ever-changing depths of eternity, never is it subject to sunlight- for those who visit have no need or desire for the fleeting amenities of mortality. Look closer though and it might be possible to see the landscape shift the desolate ruin of what once was enlivened by the phantom touch of the moon's soft, silver caress, ghostly forms cavorting through the spectral fog- a dull echo of life's joyous vigour... now lost, its intentions flooded with the obfuscation of time. Though there is an intentionally sombre cast to this entire area, some complete bastard has nailed a sign to one of the dilapidated walls that holds a board- and someone (likely the same asshole) has set out an oversized welcome mat before the entrance- which makes no sense what so ever, on account of there being a distinct lack of points of egress.\n");
   set_smell("default","You smell fresh air.");
   set_listen("default","You hear the cries of players.");

   set_exits(([
      "library" : "/d/islands/serakii/rooms/caer/library",
      "lounge" : "/d/dagger/avalounge"
   ]));
}

void reset() {
  object ob;
  ::reset();
  if (!objectp(present(getuid(TO)+"_board"))) {
     ob = new("std/bboard");
     ob->set_name(getuid(TO)+"board");
      ob->set_id( ({ "board", "eli_board", "my board" }) );
     ob->set_board_id(geteuid(TO)+"_board");
     ob->set("short", "A pile of books made up to be a board");
     ob->set("long", "This is Eli's board... !\n");
     ob->set_max_posts(20);
     ob->set_ooc_board(1);
     ob->set_restricted_read();
     ob->set_location(base_name(TO));
     ob->move(TO);
     ob->set_property("no steal",1);
  }
}
