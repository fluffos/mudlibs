// Room: /jingzhou/jzyamen
// 980830 congw 

inherit ROOM;

void create()
{
	set("short", "荆州衙门");
	set("long", @LONG
这里是衙门大门，两扇朱木大门紧紧关闭着。“肃静”“回避”的牌子分放两头石
狮子的旁边。前面有一个大鼓，显然是供小民鸣冤用的。几名衙役在门前巡逻。
LONG
	);

	set("exits", ([
		"south" : __DIR__"ymzhengting",
		"north" : __DIR__"xidajie1",
	]));

	set("objects", ([
		__DIR__"npc/yayi" : 4,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("ya yi", environment(me))) && dir == "south")
		return notify_fail("衙役喝道：“威……武……。”\n");
	return ::valid_leave(me, dir);
}
