#include <std.h>
#include <radyne.h>
inherit HALL;
void create()
{
 object ob;
 ::create();
   set_type("fighter");
 set_short("The Berserker Hall");
 set_long("%^WHITE%^%^BOLD%^Welcome to the Berserker Hall.\n%^RESET%^  "
     "This hall was created for berserkers to meet and "
     "train.  It is here that any actions or decisions for "
     "the berserkers should be made. You may <train [skill] [amount]>,"
     " to improve your skills. You also can <improve [stat]>, to "
     "improve your stats. Lastly, you may <advance> to request to be "
     "promoted to the next level.");
 set_exits( ([ "out" : ROOMS"fighter/berserker/berserker_join" ]) );
   ob = new("/std/bboard");
   ob->set_max_posts(70);
   ob->set_board_id("berserker");
   ob->set_location(ROOMS "fighter/berserker/berserker_hall");
   ob->set_id(({ "board" }));
   ob->set_short("The Berserker Board");
   ob->set_long("Berserkers come here to post to other berserkers.");
   ob->set_name("subclass board");
}
