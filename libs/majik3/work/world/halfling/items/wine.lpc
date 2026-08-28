#include "../path.h"
inherit ITEM;
int empty =0;
create_item()
{
  set_name(({"wine"}));
  set_short("A glass of wine");
  set_long("This is a glass of thick, red wine.\n");
  set_dimensions(8, 8, 15); 
  set_weight(300);         
  set_hp(10);
  set_max_hp(10);
  set_material("glass");
  set_taste("It tastes sweet.\n");
  set_smell("It smells like Merlot(tm).\n");

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
  if(!what || capitalize(what) == "Wine")
  {
    write("You sip your wine slowly and savor the taste.\n");
    message("standard",capitalize(THIS->query_name())+" sip a glass of wine "+
    "till it's empty.\n", ENV(THIS),THIS);
    THIS->hydrate_me(500);
    empty = 1;
    return 1;
  }
  return 0;
}
