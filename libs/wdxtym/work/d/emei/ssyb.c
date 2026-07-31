//Room: ssyb.c 舍身崖壁
//Date: Oct. 21 1997 by That

inherit ROOM;
void create()
{
      set("short","舍身崖壁");
      set("long",@LONG
你终于游到崖壁。抬头上望，微见天光。壁面潮湿，裂缝中微有水渗
出。脚下是污浊的臭水，四周的景物都看不清。向东就是你来时的水潭。
LONG);
      set("outdoors","emei");
      set("objects", ([
	  __DIR__"npc/frog" : 1,
      ]) );
      set("exits",([ /* sizeof() == 1 */
	  "east"  : __DIR__"st8", 
      ]));
      set("no_clean_up", 0);
      set("no_fight",1);
      setup();
}

void init()
{
    add_action("do_climb","climb");
}

int do_climb()
{
    object me;
    me = this_player();
    message("vision", me->name()+"使劲爬上去，花了九牛二虎之力。\n", environment(me), ({me}) );
    me->move(__DIR__"gudelin1");
    message("vision", me->name()+"花了九牛二虎之力，到了这个地方，却不知道在哪里？\n", environment(me), ({me}) );
    return 1;
}
