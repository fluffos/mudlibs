// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OUTDOOR_ROOM;

void setup()
{
    string m = "这里的山壁过于陡峭，你无法攀登，要绕路才能过。";
    string o = "你会被淹死的！\n";
  set_brief("沙滩");
  set_area ("pirate");
  set_long("潮水欢快地拍打着沙岸，一旁的山壁直接伸展到了海里，没有可供漫步的沙滩。"); 
  set_exits( ([
               "northeast" :  m,
               "northwest" :  m,
               "north" : m,
               "west" : m,
               "east" : m,
               "south" : o,
               "southeast" : o,
               "southwest" : o,
               ]) );


  add_item( "tide", "潮水", "这里的潮水也看不出个所以然来，但如过你跋涉于其中，你会有所感觉。");

  add_item("mountains", "山壁",
           ([
             "adjs" : "陡峭的", // Can also use an array...
             "look" : "这里的崖壁太陡峭了，无法攀登。",
             "climb" : "这里的崖壁太陡峭了，无法攀登。" 
             ]));
               
  set_hidden_exits("northeast","northwest","south","southeast","southwest", 
                   "north", "west", "east");
  set_objects( ([
                 "/domains/std/objects/sand_castle" : 1,
                 "/domains/std/objects/sand_with_treasure" : 1,
                 "/domains/std/objects/welcome_sign" : 1,
                 "/domains/std/objects/ocean" : 1,

  ]) );
}

mixed wade(string str)
{
  switch(str)
    {
    case 0:
      write("[在水里]\n");
    case "water":
    case "waves":
    case "surf":
    case "ocean":
      write ( "你走入海水中，水底的暗流很强，可你还是保持了平衡。\n"
              "你朝东方行去，那边没有什么沙滩，但那座山看上去似乎有点意思。\n");
      this_body()->other_action("$N淌水行走了一会儿，就朝东面去了，离开了你的视线。");
      this_body()->move(__DIR__ "outside_cave");
      QUEST_D->grant_points(this_body(),"pirate:foundCave");
      this_body()->do_game_command("look");
      this_body()->other_action("$N淌着海水，朝你这边走来。\n");
      return 1;
    default:
      return "多愚蠢的想法啊!\n";
    }
}

