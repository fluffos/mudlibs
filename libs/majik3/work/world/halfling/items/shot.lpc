#include "../path.h"
inherit ITEM;
int empty =0;
create_item()
{
  set_name(({"shot","glass"}));
  set_short("A shot of wiskey");
  set_long("This is a dirty shot glass of wiskey.\n");
  set_dimensions(8, 8, 15); 
  set_weight(300);         
  set_hp(10);
  set_max_hp(10);
  set_material("glass");
  set_taste("It tastes like Jack Daniels(tm).\n");
  set_listen("Your not drunk enough yet to hear the wiskey talk.\n");
  set_smell("It smells strong and gives you a shiver up your spine.\n");

}
init()
{
  add_action("do_drink","drink");
}
do_drink(string what)
{
  if(empty)
  {
    write("The shot glass is empty.\n");
    return 1;
  }
  if(!what || capitalize(what) == "Shot")
  {
    write("You close your eyes and gulp down your shot.\n");
    write("The rooms spins a little.\n");
    message("standard",capitalize(THIS->query_name())+" tilts their head "+
    "back and downs the shot in a signle gulp.\n", ENV(THIS),THIS);
    THIS->hydrate_me(150);
    empty = 1;
    return 1;
  }
  return 0;
}
