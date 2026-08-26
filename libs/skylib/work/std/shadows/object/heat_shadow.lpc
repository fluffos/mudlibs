// Gototh, 16/06/99

#include <move_failures.h>

inherit "/std/effect_shadow";

int query_heat()
{
  int *enums;
  enums = this_object()->effects_matching("object.heat");
  if(!sizeof(enums))
  {
    return 0;
  }
  return this_object()->arg_of(enums[0]);
} /* query_heat() */

string query_medium_alias()
{
  int red_hot;
  if(!player->query_medium_alias())
  {
    return 0;
  }
  red_hot = player->query_property("red hot at");
  if(red_hot)
  {
    if(query_heat() > red_hot)
    {
      return "RedHot" + player->query_medium_alias();
    }
  }
  return query_medium_alias();
} /* query_medium_alias() */

string short()
{
  int red_hot;
  red_hot = player->query_property("red hot at");
  if(red_hot)
  {
    if(query_heat() > red_hot)
    {
      return "red hot " + player->short();
    }
  }
  return player->short();
} /* query_short() */


int command_control(string verb, object *in_dir, string direct, 
  string indirect, mixed *args, string format) 
{
  if(verb == "take" || verb == "get")
  {
    if(query_heat() > 80)
    {
      write("$C$" + player->the_short() +" is too hot to touch!\n");
      return 0;
    }
    if(player->move(this_player()) == MOVE_OK)
    {
      return 1;
    }
    return 0;
  }
} /* command_control() */


