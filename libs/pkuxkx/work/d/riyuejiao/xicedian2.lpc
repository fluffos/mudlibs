//xicedian2.c	西侧殿
//by bing
#include <room.h>
inherit ROOM;

void create()
{
	set("short","西侧殿");
	set("long",@LONG 
这里是成德殿的西侧殿，是教主和教中长老们议事的地方。
只见当中摆着一张金銮座，上铺锦绣日月的垫子，旁边两排太
师椅相对摆开。左边有一扇门(gate)。
LONG
	);
	set("exits", ([
		"southeast" : __DIR__"dadian2",
		"northeast" : __DIR__"houdian2",
	]));
 	   set("item_desc",([
  	      "gate"	:"这道门上着锁。\n",
 	   ]));

        set("no_task", 1);
	setup();
}

void init()
{
	add_action("do_unlock","unlock");
}

int do_unlock()
{
	object me = this_player();
	object key;
	if (key = present("door key",me))
	{
		message_vision("$N拿出一把钥匙在锁眼里使劲的拧，最后还是没打开，钥匙倒断了。\n",me);
		message_vision("$N白费了20两金子，嘿嘿......\n",me);
		destruct(key);
	}
	else tell_object(me,"你没有打开这把锁的钥匙。\n");
	return 1;
}		
