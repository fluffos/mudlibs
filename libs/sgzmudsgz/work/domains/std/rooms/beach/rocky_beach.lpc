// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OUTDOOR_ROOM;


void
setup()
{
    string m = "这里的山壁过于陡峭，你无法攀登，要绕路才能过。\n";
    string o = "你会被淹死的！\n";
  set_brief("石滩");
  set_area ("pirate");
  set_long("这里没有多少沙，相反到处都是大大小小的碎石和石堆。群山和"
           "海洋包围着你，但你可以涉水离开这里。");
  set_exits( ([
               "west" : m,
               "northeast" :  m,
               "northwest" :  m,
               "north" : m,
               "east" : m,
               "south" : o,
               "southeast" : o,
               "southwest" : o,
               ]) );

  add_item("mountains", "steep mountains", "群山",
           ([
             "look" : "这里的崖壁太陡峭了，无法攀登。",
             "climb" : "这里的崖壁太陡峭了，无法攀登。"
             ]));

  add_item( "sand", "beach", "沙滩", "沙地", "此处沙不多，石头倒不少。");
               
  set_hidden_exits("northeast","northwest","south","southeast","southwest", 
                   "north", "east", "west");
  set_objects( ([
                 "/domains/std/objects/ocean" : 1,
                 "/domains/std/objects/debris" : 1,
                 ]));
}


mixed wade(string str)
{
  if(!str)
    {
      str = "water";
      write("[在水里]\n");
    }
  switch(str)
    {
    case "water":
    case "waves":
    case "surf":
    case "ocean":
      write ("你在海中跋涉，又回到了岩洞入口。\n\n"); 
      this_body()->other_action("$N涉水离开了。\n");
      this_body()->move(__DIR__ "outside_cave");
      this_body()->do_game_command("look");
      this_body()->other_action("$N淌着水朝你这边走了过来。\n");
      return 1;
    default:
      return "多愚蠢的想法啊!\n";
    }
}

