// wdroad8.c 黄土路
// by Xiang
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "乡间小路");
	set("long", @LONG
这是湖北汉江岸边的一条乡间小路，两边稻田连片，远处江水
滚滚，北面似乎是一个沼泽地。
LONG	);
  
	set("exits", ([
		"south" : __DIR__"vroad1",
		"northdown" : __DIR__"vroad3"
	]));

  set("outdoors", "wudang");
	
	setup();
}

void init()
{
	object ob=this_player();
	
	if ( time()-ob->query_temp("wudang/vroad1")>60 )
	{
		ob->start_busy(random(2)+2);
		ob->set_temp("wudang/vroad1",time());
		message_vision("$N走着走着就陷进了一处沼泽当中，艰难地从沼泽中拔出来。\n", ob);
	}
}