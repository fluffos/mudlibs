#include "../path.h"
inherit ITEM;
int empty =0;
create_item()
{
  set_name(({"beer","glass"}));
  set_short("A glass of beer");
  set_long("A glass of the Ol' Jaffer's beer.\n");
  set_dimensions(10, 10, 30); 
  set_weight(500);         
  set_hp(10);
  set_max_hp(10);
  set_material("glass");
  set_taste("The Ol' Jaffer's brew tastes pretty damn good.\n");
  set_listen("The beer doesn't say anything to you...yet.\n");
  set_smell("It smells like a type of ale.\n");

}
init()
{
  add_action("do_drink","drink");
}
do_drink(string what)
{
  if(empty)
  {
    write("The glass is empty.\n");
    return 1;
  }
  if(!what || capitalize(what) == "Beer")
  {
    write("You slam down your beer.\n");
    message("standard",capitalize(THIS->query_name())+" grabs his glass "+
    "of beer and slams it down with a smile.\n", ENV(THIS),THIS);
    THIS->hydrate_me(250);
    empty = 1;
    return 1;
  }
  return 0;
}
