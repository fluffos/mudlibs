#include "../path.h"
inherit ITEM;

create_item()
{
  set_name(({"strawberry"}));
  set_short("A fresh strawberry");
  set_long("This is a fresh, ripe strawberry.\n");
  set_dimensions(5, 5, 5); 
  set_weight(10);         
  set_hp(10);
  set_max_hp(10);
  set_material("glass");
  set_taste("It tastes ripe and very juicy.\n");
  

}
init()
{
  add_action("do_eat","eat");
}
do_eat(string what)
{
  object ob;
  if(capitalize(what) == "Strawberry")
  {
    write("You eat the strawberry and some juice runs down you chin.\n"+
           "Mmmm that was good!\n");
    message("standard",THIS->query_cap_name()+" munches a big red "+
           "strawberry.\n", ENV(THIS),THIS);
    THIS->satiate_me(150);
    ob = find_object("strawberry");
    destruct(THOB);
    return 1;
  }
  return 0;
}
