#include "../path.h"
inherit ITEM;

create_item()
{
  set_name(({"tomato"}));
  set_short("A small tomato");
  set_long("This is small, white tomato.\n");
  set_dimensions(5, 5, 5); 
  set_weight(10);         
  set_hp(10);
  set_max_hp(10);
  set_material("glass");
  set_taste("It tastes like dirt.\n");
  

}
init()
{
  add_action("do_eat","eat");
}
do_eat(string what)
{
  object ob;
  if(capitalize(what) == "Tomato")
  {
    write("You eat the tomato. The dirt on it dries your mouth out.\n");
    message("standard",THIS->query_cap_name()+" eats a small "+
           "tomato.\n", ENV(THIS),THIS);
    THIS->satiate_me(5);
    THIS->hydrate_me(-100);
    ob = find_object("tomato");
    destruct(THOB);
    return 1;
  }
  return 0;
}
