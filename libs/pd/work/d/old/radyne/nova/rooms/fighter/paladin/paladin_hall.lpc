#include <std.h>
#include <radyne.h>
inherit HALL;
void create()
{
 object ob;
 ::create();
   set_type("fighter");
 set_short("The Paladin Hall");
 set_long("Welcome to the Paladin Hall.  "
     "This hall was created for paladins to meet and "
     "gather in.  It is here that any actions or decisions for "
     "the paladins should be made.");
set_exits( ([ "up" : ROOMS"fighter/paladin/paladin_join" ]) );
   ob = new("/std/bboard");
   ob->set_max_posts(70);
   ob->set_board_id("paladin");
  ob->set_location(ROOMS "fighter/paladin/paladin_hall");
   ob->set_id(({ "board" }));
   ob->set_short("The Paladin Board");
   ob->set_long("Paladins come here to discuss amongst themselves.");
   ob->set_name("subclass board");
}
