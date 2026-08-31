#include <std.h>
#include <radyne.h>
inherit HALL;

void create() {
 object ob;
 ::create();
   set_type("fighter");
   set_short("The antipaladin hall");
   set_long("Welcome to the Antipaladin Hall.  "
     "This hall was created for antipaladins to meet and "
     "gather in.  It is here that any actions or decisions for "
     "the antipaladins should be made.");
   set_exits( ([ "down" : ROOMS"fighter/antipaladin/antipaladin_join" ]) );
   ob = new("/std/bboard");
   ob->set_max_posts(70);
   ob->set_board_id("antipaladin");
   ob->set_location(ROOMS "fighter/antipaladin/antipaladin_hall");
   ob->set_id(({ "board" }));
   ob->set_short("The Antipaladin Board");
   ob->set_long("Antipaladins come here to talk amongst themselves.");
   ob->set_name("subclass board");
}
