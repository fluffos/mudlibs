#include <config.h>
#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
   object ob;
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "Complaint Department");
    set("long",
      "This is the official "
      "Carnage complaints department. Whiners from all over the world "
      "travel to complain here. Post any gripes, questions, or "
      "comments you may have that you wish to be addressed should be "
      "put on the board here.");
   set_exits( 
             (["up" : ROOMS "adv_hall"]) );
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "complaints board", "board" }) );
    ob->set_board_id("ombud");
    ob->set_max_posts(30);
    ob->set_edit_ok( ({ "inferno" }) );
   ob->set_location(ROOMS+"ombud_hall");
   ob->set("short", "the Carnage Complaints Board");
   ob->set("long", "People of this reality come here to post their "
           "comments and questions for the immortals who control "
           "the fate of all reality.\n");
  set_property("no steal", 1);
  set_property("no attack", 1);
  set_property("no castle", 1);
}
