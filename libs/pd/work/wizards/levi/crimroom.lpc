#include <std.h>
//#define VOTE_CLOSED
inherit ROOM;
void create() {
    object board;
    ::create();
    set_properties(([ "light" : 2,  "night light" : 2,  "no steal" : 1,
        "indoors" : 1, "no magic" : 1, "no castle" : 1, "no attack" : 1 ]));
    set_short("An Office");
    set_long(
       "This is a fairly simple office.  Several desks are here and there are papers strewn about them.  Comfortable looking chairs surround the desks.");
    set_items(([
        "desks" : "The desks are large and made of nice woods.",
        "chairs" : "The chairs are plush and covered in leather.",
      ]));

    set_exits( ([
        "east" : "/d/nopk/standard/adv_inner",
      ]));
 
    board = new("std/bboard");
    board->set_name("board");
    board->set_id( ({ "board", "criminal board" }) );
    board->set_max_posts(999);
board->set_edit_ok(({"stormbringer","nightshade","daboura","nesoo","whit","levi"}));
    board->set_location("/wizards/levi/crimroom");
    board->set("short", "Records of Criminal Activities");
    board->set("long", "Please discuss infractions of the Law here.\n");
    board->set_board_id("law");
}

