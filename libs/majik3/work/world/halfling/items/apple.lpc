#include "../path.h"
inherit ITEM;

create_item()
{
  set_name(({"apple"}));
  set_short("An apple");
  set_long("This is a bright red apple.\n");
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
  if(capitalize(what) == "Apple")
  {
    write("You eat the apple in a few bites.  It was very good.\n");
    message("standard",THIS->query_cap_name()+" chomps down a bright red "+
           "apple.\n", ENV(THIS),THIS);
    THIS->satiate_me(400);
    ob = find_object("apple");
    destruct(THOB);
    return 1;
  }
  return 0;
}
