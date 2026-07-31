// Room: /d/village/caidi.c
// Date: Look 99/07/18

#include <room.h>
inherit ROOM;

void create()
{
       set("short","菜地");
       set("long", @LONG
这里是华山村民们赖以为生的菜地，空旷的一片，你一眼忘不到头，你走
着走着，忽然忘记了来时的路了。
LONG
     );

	set("exits", ([
		"west" : __FILE__,
		"east" : __FILE__,
		"south" : __FILE__,
		"north" : __FILE__,
	]));
	setup();
}

void init()
{
	object ob;
	int jingli;

	ob = this_player();
	jingli = ob->query("jingli");

        ob->add("jingli", -random(40));
        if(jingli < 50)
		ob->unconcious();
	ob->add_busy(random(2));
}

int valid_leave(object me, string dir)
{
	if (random(10) < 6)
		me->add_temp("mark/步数",1);
	if (random(10) > 8)
		me->add_temp("mark/步数",-1); 
        
	if (me->query_temp("mark/步数") > 9)
	{
		me->move(__DIR__"zhongxin");
		me->delete_temp("mark/步数");
		return notify_fail("你乱走了一通，居然发现自己走回了原地。\n");
	}  

	return ::valid_leave(me, dir);
}
