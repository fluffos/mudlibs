// wdroad8.c 黄土路
// by Xiang
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "沼泽");
	set("long", @LONG
这是一片沼泽地，中间似乎被人踩出一条小路。
LONG	);
  
	set("exits", ([
		"southup" : __DIR__"vroad2",
		"northup" : __DIR__"vroad4"
	]));

  set("outdoors", "wudang");
	
	setup();
}

void init()
{
	object ob=this_player();
	
	if ( time()-ob->query_temp("wudang/vroad2")>60 )
	{
		ob->start_busy(random(2)+2);
		ob->set_temp("wudang/vroad2",time());
		message_vision("$N走着走着就陷进了一处沼泽当中，艰难地从沼泽中拔出来。\n", ob);
	}
}