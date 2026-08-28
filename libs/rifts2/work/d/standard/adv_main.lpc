#include <config.h>

inherit "/std/room";

void create() {
    object ob;
    
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The Meeting Hall of the Immortals");
    set("long", "This room reminds you right off of a small cafe'. There are tables and chairs in rows with waste bins at the end of each. The floor is intriguingly enough made of imported spanish tiles. The decor is severly lacking here and the food services suck!  The best part about the entire place is near the back corner where the BAR IS! Please, no drinking while on duty and don't forget.. YOUR MOTHER DOESN'T WORK HERE, CLEAN UP AFTER YOURSELF!     Post general Immortal concerns on this bulletin board.");
    
    add_exit("/d/standard/post", "west");

    ob = new("/std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "reality board" }) );
    ob->set_board_id("immortal");
    ob->set_max_posts(30);
    ob->set_location("/d/standard/adv_main");
    ob->set("short", "Wiz Board");
    ob->set("long", "Posts any notes concerning the mud which do "
            "not belong out in a public forum among players "
            "here for immortal discussion.\n");
    set_property("no steal", 1);
}

int receive_objects() {

  if(!previous_object()->is_player())
    return 1;
  if(!wizardp(previous_object())) {
    message("my_action", "Only Wizards are allowed in this hall\n", this_player());
    return 0;
  }
  return 1;
}
