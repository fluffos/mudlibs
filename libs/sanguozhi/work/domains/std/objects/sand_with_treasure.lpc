// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <size.h>

inherit OBJ;
inherit M_DIGGABLE;
inherit M_INPUT;  // Required for M_DIGGABLE.

int number_times_dug = 0;
object  my_hole;

void setup()
{
  set_id("beach","沙滩", "sand");
  set_unit("片");
  set_attached(1);
  set_long("这儿有很多沙。\n");
  set_size(TOO_LARGE);
}


void dig(object o)
{
  switch(number_times_dug++)
    {
    case 0:
      my_hole = new("/domains/std/objects/hole");
      my_hole->move(environment(this_object()));
      this_body()->simple_action("$N动手在沙地上挖洞，一连挖了好几下。");
      my_hole->change_desc("沙地上有一个小洞。");
      break;
    case 1:
      my_hole->set_in_room_desc("沙地上有一个洞。");
    case 2:
      this_body()->simple_action("$N又把洞挖深了一些。");
      break;
    case 3:
      my_hole->change_desc("沙地上有一个大洞。");
      my_hole->change_max_capacity(VERY_LARGE);
    case 4:
      this_body()->simple_action("$N继续把洞往深挖。");
      break;
    case 5:
      my_hole->change_desc("沙地上出现了一个很大的洞。");
      my_hole->change_max_capacity(VERY_LARGE*2);
    case 6:
      this_body()->simple_action("$N又把洞挖深了一些。");
      break;
    case 7:
      this_body()->simple_action("$N动手又挖了几下，发现了一个珍宝箱！");
      QUEST_D->grant_points(this_body(), "pirate");
      break;
    case 8:
      this_body()->simple_action("$N继续把洞往深挖。");
      break;
    case 9:
    case 10:
      this_body()->simple_action("$N又把洞挖深了一些。");
      break;
    default:
      this_body()->simple_action("$N继续挖洞，但没有什么成效，那个洞又被新落下的沙土填上了一些。\n"
                                 "所有的东西都挖完了。");
      break;
                                
    }
}
