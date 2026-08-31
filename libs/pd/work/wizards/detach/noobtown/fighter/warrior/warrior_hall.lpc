#include <std.h>
#include <radyne.h>

inherit HALL;

void create()
{
 object ob;
 ::create();
 set_type("fighter");
 set_short("The Warrior Hall");
 set_long("%^BOLD%^%^WHITE%^Welcome to the Warrior Hall.%^RESET%^\n"
     "This hall was created for warriors to meet and "
     "to train in.  It is also here that any actions or decisions for "
     "the warriors should be made. You may <train [skill] [amount]>, "
     "to train your skills. You also can <improve [stat]>, to improve "
     "your stats. Lastly, you may <advance> to ask to be promoted "
     "to the\nnext level.");
   set_exits( ([ "out" : ROOMS"fighter/warrior/warrior_join" ]) );
   ob = new("/std/bboard");
   ob->set_max_posts(95);
   ob->set_board_id("warrior");
   ob->set_location(ROOMS "fighter/warrior/warrior_hall");
   ob->set_id(({ "board" }));
   ob->set_short("The Warrior Board");
   ob->set_long("Warriors come here to discuss things amongst themselves.");
   ob->set_name("subclass board");
}
