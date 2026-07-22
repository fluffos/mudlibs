inherit ROOM;

void create()

{
  set("short","长廊");
set("long",@LONG
      "这里是白虎堂的长廊。两边一片狼籍,看样子刚被洗劫一场,遍地横尸，残不忍赌。\n"
LONG
     );
  set("exits",([
     "north" : __DIR__"baistep1",
      "south" : __DIR__"baihutang",
     ]));
       set("objects", ([ /* sizeof() == 3 */
]));

        set("channel_id", "大驿道");
        set("outdoors", "taishan");

  setup();
}
void init()
{
    add_action("do_move", "move");
}
int do_move(string arg)
{
    object paper;
        if( !arg || arg=="" ) return 0;
      if( arg=="popo" ) {
        message_vision("$N轻轻的推了推书桌，沉重的书桌似乎根本没动...，突然从书桌和\n"
        "墙壁之间飘落出一张纸。\n", this_player());
       paper = new("/d/wudujiao/obj/hanshasheying");
       add("box_count",-1);
paper->set("own_name",this_player()->query("id"));
        remove_call_out ("give_hssy");
        call_out ("give_hssy", 900); // 15 分钟

        paper->move(this_player());
paper=new("/clone/misc/mask");
       paper->move(this_player());
paper=new("/d/city3/obj/jinshejian");
       paper->move(this_player());
        return 1;
        }
    return 0;
}


