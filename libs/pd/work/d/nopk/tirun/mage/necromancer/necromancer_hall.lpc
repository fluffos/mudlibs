#include <std.h>
#include <tirun.h>
inherit HALL;
void create() {
 object ob;
 ::create();
   set_type("mage");
   set_short("The necromancer subclass hall of darkness");
   set_exits(([ "out" : ROOMS "mage/necromancer/necromancer_join" ]));
   set_long("Welcome to the Necromancer Hall. "
       "Strange shadows flood the walls the ground, allowing "
       "only several select things to be seen. Small drops of blood "
       "fall every now and then from the ceiling into a gathering "
       "puddle of blood. Surrounded by bones of long dead creatures "
       "lies a board near the middle of the room.");
   set_smell("default", "The smell of death fills the room.");
   ob = new(BBOARD);
   ob->set_max_posts(100);
   ob->set_board_id("necro");
   ob->set_location(ROOMS "mage/necromancer/necromancer_hall");
   ob->set_id(({ "board" }));
   ob->set_short("The Necromancer Board of Death");
   ob->set_long("The board is lined with skulls and other various bones.");
   ob->set_name("subclass");
   ob->move(this_object());
}
