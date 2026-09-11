// Updated by tset on 2 Feb 1998
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
   
void setup()
{  
  set_attached(1);
  set_unit("座");
  set_light(10);
  set_id("bridge","小桥");
  set_long("一座小桥横跨在河上。");
}
   
void cross()
{
  if(environment(this_body())->get_area() == "huayin")
  {
    write("你朝南面走上小桥。\n");
    this_body()->move(__DIR__"southbridge");
    this_body()->do_game_command("look");
    this_body()->other_action("$N朝南面过桥而去了，离开了你的视线。\n");
  }
  else if(environment(this_body())->get_area() == "southbridge")
  {
    write("你朝北面走上小桥。\n");
    this_body()->move(__DIR__"southopen");
    this_body()->do_game_command("look");
    this_body()->other_action("$N朝北面过桥而去了，离开了你的视线。\n");
  }
  else
  {   
    write("你走上小桥，但不知道该往那儿走才对，于是又退了回来。\n");
    this_body()->other_action("$N打算过桥去了，但不一会儿又转回来了。\n");
  }
}
