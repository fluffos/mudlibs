//xicedian.c	西侧殿
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
		"southeast" : __DIR__"dadian1",
		"northeast" : __DIR__"houdian",
	]));
 	   set("item_desc",([
  	      "gate"	:"这道门上着锁。\n",
 	   ]));

        set("no_task",1);
	setup();
}

void init()
{
	add_action("do_unlock","unlock");
        add_action("do_enter","enter");
}
int do_enter(string arg)
{
        object me = this_player();
       if (!arg||arg!="gate") return notify_fail("你要去哪里？\n");
       if (me->query("family/master_id")!="dongfang bubai") return notify_fail("这门岂是你随便进的？\n");
                me->move(__DIR__"xiaowu");
                return 1;
}               

int do_unlock()
{
	object me = this_player();
	object key;

	if ( objectp(key = present("door key",me)))
	{
		message_vision("$N掏出一把钥匙开了锁，一闪身跳了进去，顺手把门关上了。\n",me);
		tell_room(__DIR__"xiaowu",me->query("name") + "鬼鬼祟祟地开门走了进来，立刻关上了门。\n");
		me->move(__DIR__"xiaowu");
		return 1;
	}
	tell_object(me,"你没有打开这把锁的钥匙。\n");
	return 1;
}		
