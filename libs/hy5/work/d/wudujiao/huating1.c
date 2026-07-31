// by mayue


inherit ROOM;

void create()
{
	set("short", "花厅");
	set("long", @LONG
这里是一个幽雅别致的花厅，四周挂着碧纱的幔帐，屋角香炉中飘着一
股奇异的香气。有一个粉红衣裙的少女正坐在窗边发呆，听见脚步声不觉瞟
了你一样，秀眉微微一颦，似乎不太高兴。
LONG
	);
//      set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"huating",
		"south" : __DIR__"huating2",
		"west" : __DIR__"huayuan1",
		"north" : __DIR__"huating3",
	]));
        set("objects", ([
                __DIR__"npc/hetieshou": 1,
	]));
    

	setup();
	//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( objectp(present("he tieshou", environment(me))) && 
		dir == "east")
		return notify_fail("何铁手拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}