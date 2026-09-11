// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit OBJ;

void setup() {
    
    set_id("button", "按钮");
    set_long("这条按钮可能是用来打开你来路上的通道的。\n");
    set_in_room_desc("你看到就在通道一旁的墙上，有一个按钮。");
    set_size(VERY_SMALL);
}

int press(string n)
{
  this_body()->simple_action("$N按动墙上的按钮。");
  environment(this_object())->open_passage();
  return 1;
}
