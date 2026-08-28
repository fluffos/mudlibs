#include "../path.h"
inherit ITEM;

create_item()
{
  set_name(({"pear"}));
  set_short("A green pear");
  set_long("This is a nice, green pear.\n");
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
  if(capitalize(what) == "Pear")
  {
    write("You gobble up the pear in a few bites.\n");
    message("standard",THIS->query_cap_name()+" scarfs down a "+
           "pear.\n", ENV(THIS),THIS);
    THIS->satiate_me(250);
    ob = find_object("pear");
    destruct(THOB);
    return 1;
  }
  return 0;
}
