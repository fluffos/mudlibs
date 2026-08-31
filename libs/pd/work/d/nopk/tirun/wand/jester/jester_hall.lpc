#include <std.h>
#include <tirun.h>
inherit HALL;
void create() {
 object ob;
 ::create();
   set_type("wanderer");
   set_short("The Jester Hall");
   set_long("%^BOLD%^%^WHITE%^Welcome to the Jester Hall!\n%^RESET%^" 
            "Pictures of "
     "clowns, kings, and other people having fun and making fools of "
     "themselves in general fill the walls. The walls and ground are "
     "many various colours, ranging from green to purple to red to blue."
     "You may <train [skill] [amount]>, to train your skills. You can "
     "also <improve [stat]>, to improve your stats. Lastly, you may "
     "<advance> to request to be promoted to the next level.");
   ob = new(BBOARD);
   ob->set_max_posts(95);
   ob->set_board_id("jester");
   ob->set_location(ROOMS "wand/jester/jester_hall");
   ob->set_id(({ "board" }));
   ob->set_short("The Jester Board of Jokes");
   ob->set_long("Jesters come here to post amongst themselves.");
   ob->set_name("subclass");
   set_exits(([ "out" : ROOMS "wand/jester/jester_join" ]));
}
