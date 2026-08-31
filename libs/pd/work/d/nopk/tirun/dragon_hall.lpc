#include <std.h>
#include <tirun.h>
inherit HALL;
void create() {
  object ob, statue;
  ::create();
  set_type("dragon");
    set_properties( ([ "indoors" : 0]) );
  set("short", "The Palace of the Dragons");
  set("long",
      "Welcome to the Palace of the Dragons!\n"
      "This huge castle rests magically upon a gigantic cloud.  "
      "The only way in or out would be to fly a great distance.  "
      "In this hall, a dragon may <advance>, <cost>, <list (number)>, "
      "<improve stat>, <train skill amount>, and <roll stats>.  A "
      "statue of a dragon towers above the Palace.");
    set_exits( 
          ([ "red" : ROOMS"dragon/red_hall",
               "blue" : ROOMS"dragon/blue_hall",
               "black" : ROOMS"dragon/black_hall",
               "white" : ROOMS"dragon/white_hall",
          ]) );
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bulletin board", "dragon board" }) );
    ob->set_board_id("dragon_board");
    ob->set_max_posts(99);
    ob->set_location(ROOMS"dragon_hall");
    ob->set("short", "Grand Board of the Dragonkin");
    ob->set("long",
        "The golden board has many parchments magically attached to it with "
        "information specifically for the other dragonkin in this reality.\n");
    statue = new("std/object");
    statue->set_name("statue");
    statue->set_id(({"dragon statue", "statue"}));
    statue->set_prevent_get("It would be impossible to lift such a thing!");
    statue->set_short("%^BOLD%^%^YELLOW%^Statue of Valor");
    statue->set_long("This is the statue of Valor, the leader of all dragonkin. "
        "He first founded their palace in the sky, a haven from the petty squabbles "
        "of mortal men.  He has since passed away, and this statue was erected in his "
        "memory.");
    statue->move(this_object());
}
void init() {
 ::init();
   add_action("go_red", "red");
   add_action("go_blue", "blue");
   add_action("go_black", "black");
   add_action("go_white", "white");
}
int go_red() {
   if (this_player()->query_subclass() != "red" && !wizardp(this_player()))
     { write("You cannot enter this place."); return 1; }
   return 0;
}
int go_blue() {
   if (this_player()->query_subclass() != "blue" && !wizardp(this_player()))
     { write("You cannot enter this place."); return 1; }
   return 0;
}
int go_black() {
   if (this_player()->query_subclass() != "black" && !wizardp(this_player()))
     { write("You cannot enter this place."); return 1; }
   return 0;
}
int go_white() {
   if (this_player()->query_subclass() != "white" && !wizardp(this_player()))
     { write("You cannot enter this place."); return 1; }
   return 0;
}
