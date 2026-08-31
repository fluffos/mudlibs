#include <std.h>
#include <tirun.h>
inherit HALL;
void create() {
 object ob;
 ::create();
   set_type("mage");
   set_short("The Wizard Hall");
   set_exits(([ "out" : ROOMS "mage/wizard/wizard_join" ]));
   set_long("%^BOLD%^%^WHITE%^Welcome to the Wizard Hall!%^RESET%^\n The air is cold "
            "in here from the usage of many powerful magics. "
            "The room is dull and has no life to it other than "
            "the single board near the farthest wall away from the "
            "entrance. You may <train [skill] [amount]>, to train "
            "your skills. You can also <improve [stat]>, to improve "
            "a stat. Lastly, you can <advance> to request to be promoted "
            "to the next level.");
   ob = new(BBOARD);
   ob->set_max_posts(70);
   ob->set_board_id("wizard");
   ob->set_location(ROOMS "mage/wizard/wizard_hall");
   ob->set_id(({ "board" }));
   ob->set_short("The Wizard Board");
   ob->set_long("Wizards come here to post amongst themselves.");
   ob->set_name("subclass");
}
