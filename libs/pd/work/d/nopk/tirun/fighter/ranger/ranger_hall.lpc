#include <std.h>
#include <tirun.h>
inherit HALL;

void create()
{
   object ob;
 ::create();

   set_type("fighter");

 set_short("The Ranger Hall");
 set_long("Welcome to the Ranger Hall.  "
     "This hall was created for rangers to meet and "
     "gather in.  It is here that any actions or decisions for "
     "the rangers should be made.");
set_exits( ([ "north" : ROOMS"fighter/ranger/ranger_join" ]) );
   ob = new("/std/bboard");
   ob->set_max_posts(70);
   ob->set_board_id("ranger");
   ob->set_location(ROOMS "fighter/ranger/ranger_hall");
   ob->set_id(({ "board" }));
   ob->set_short("The Ranger Board");
   ob->set_long("Rangers come here to talk amongst themselves.");
   ob->set_name("subclass board");
   ob->set_edit_ok(({"nulvect"}));
}

