// Room: /d/xingxiu/xxh1.c

inherit ROOM;

void create()
{
	set("short", "星宿海");
	set("long", @LONG
这里是星宿海边。说是海，其实是片湖泊和沼泽，地形十分险恶。
东面石壁上一道裂缝通到一个山洞。
LONG );
	set("exits", ([
	     "north"   : __DIR__"xxh2",
	     "southup" : __DIR__"tianroad2",
	     "westup"  : __DIR__"tianroad3",
	     "east"  : __DIR__"jingji/enter",
	]));
	set("objects", ([
		CLASS_D("xingxiu")+"/zhaixing" : 1,
		__DIR__"npc/gushou"  : 1,
		__DIR__"npc/haoshou" : 1,
		__DIR__"npc/boshou" : 1,
	]) );
	set("outdoors", "xingxiu");
	set("valid_startroom", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	object zhai;

	if (dir != "north" && dir != "westup")
	{
		return ::valid_leave(me, dir);
	} else
	{
		if (objectp(zhai = present("zhaixing zi", environment(me))) &&
		    living(zhai))
		{
			if (me->query("shen") > 100 && me->query("combat_exp") > 400000)
				return notify_fail("摘星子喝道：这位" +
						   RANK_D->query_respect(me) + "休走！\n");
		}
		return ::valid_leave(me, dir);
	}
}
