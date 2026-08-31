#include <rain.h>
#include <std.h>

inherit ROOM;
void search_rug();
void create()
{
 ::create();
 set_short("In a treehouse");
set_properties( ([ "light" : 2, "night light" : 2, "indoors" :1 ]) );
 set_long("The room has cabinets and cases all over the place. " 
          "This looks like the home of a powerful magician. "
          "There is a small cot in the corner of the room. "
          "There is a rug on the floor that seems to be hiding "
          "something.");
 set_listen("default", "You hear monkeys making noise.");
 set_smell("default", "The humid air stifils your senses.");

 set_items( ([ "rug" : "The rug is made out of tiger skin.",
               "cabinets" : "The cabinets full of potions and sort.",
               "cot" : "The cot has been neatly made.",
               "cases" : "The cases are full of wands and magicial items."
            ]) );
 set_exits( ([ "out" : ROOMS"tree"]) );
}

void search_rug()
{
 remove_search("rug");
 message("info", "You lift up the rug and find something.", this_player()); 
 message("info", (string)query_cap_name()+" finds something under the rug.", environment(this_player()), this_player());
 new(OBJ"book")->move(this_player());
}
void reset()
{
 if (!present("magician"))
   new(MOB"magician")->move(this_object());
  set_search("rug", (: search_rug :) );

}
