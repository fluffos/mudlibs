// Updated by tset on 2 Feb 1998
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
   
void setup()
{  
  set_attached(1);
  set_unit("座");
  set_light(10);
  set_id("bridge","小木桥");
  set_long("看上去年久失修的小木桥，风吹过时发出一阵「咿呀咿呀」的声音，不禁让人有些担心。\n
你可以试试 (cross bridge)。");
}
   
void cross()
{
  if(environment(this_body())->get_area() == "eastside")
  {
    write("\n你抬脚走上了小木桥，一步一惊心地慢慢挪着。\n\n");
    this_body()->move(__DIR__"ground");
    this_body()->do_game_command("look");
    this_body()->other_action("\n$N小心翼翼地走过了小木桥，到了对岸的小木屋前。\n\n");
  }
  else if(environment(this_body())->get_area() == "westside")
  {
    write("\n你犹豫不决地走上了小木桥，心里直打颤。\n\n");
    this_body()->move(__DIR__"plain");
    this_body()->do_game_command("look");
    this_body()->other_action("\n$N回头眷恋地望了一眼，迟迟疑疑过了桥。\n\n");
  }
  else
  {   
    write("\n走在小木桥上，直觉得脚下一阵发软，差点掉了下去，连忙又退了回来。\n\n");
    this_body()->other_action("\n$N似乎正要过桥，不知为什么又退了回来。\n\n");
  }
}
