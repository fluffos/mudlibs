//xiaoyuan.c -- 小院
//Zone: 万安寺
//Created by ddid
//2009-6-17

#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", HIC"小院"NOR);
  set("long", @LONG
这里是个小院，中间有个花坛，种着各色花草，花团锦簇，看来养花
之人深谙此道。西边就是宝相精舍，万安寺的方丈应该就住在里面。南面
有个小屋，应该是存放杂物用的。西北角有颗参天古树(tree)，枝叶十分
繁茂，粗大的树干向西倾斜着，巨大的树冠几乎把宝相精舍的半边屋顶都
遮住了。
LONG
  );

  set("exits", ([     
      "south" : __DIR__"xiaowu",   
      "east" : __DIR__"wanansi-chanfangw1", 
      "west" : __DIR__"baoxiang-jingshe",       
  ]));

  set("outdoors", "luoyang");
  setup();
}

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	int n = this_player()->query_skill("dodge",1);

	object me;
	me = this_player();

	
	if( n < 100 )
		return notify_fail("以你的轻身功夫，想爬树，又要做到悄无声息，似乎很难。\n");
	
	if ( !arg || arg != "tree" )
		return notify_fail("你要干什么？\n");
	
	if( arg == "tree" )
	{
		message_vision(
									"\n$N一个旱地拔葱，跃到空中，接着身体突然不可思议地一折，\n双手在树干上一按，干净利落地爬上了大树。\n\n", me);
		remove_call_out("move_me");
		call_out("move_me", 1, me);
	}
	return 1;
}

int move_me(object me)
{
	me->move(__DIR__"shushang");
	message_vision(">", me);
	return 1;
}
