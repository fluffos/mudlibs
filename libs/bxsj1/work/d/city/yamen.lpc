// Room: /d/city/yamen.c

inherit ROOM;

void create()
{
	set("short", "衙门大门");
	set("long", @LONG
这里是衙门大门，两扇朱木大门紧紧关闭着。“肃静”“回避”的牌子分
放两头石狮子的旁边。前面有一个大鼓，显然是供小民鸣冤用的。几名衙役在
门前巡逻。俗话说：新官上任三把火，这位刚上任的知府大人就在衙门口前摆
放了一块“百姓鸣冤板”，供百姓陈述冤情。
LONG
	);

	set("exits", ([
		"south" : __DIR__"guangchangbei",
		"north" : __DIR__"menlang",
	]));

	set("objects", ([
		__DIR__"npc/yayi" : 4,
	]));

	set("coor/x",100);
	set("incity",1);
	setup();
	call_other("/clone/board/towiz_b", "???");
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("ya yi", environment(me))) && dir == "north"){
		if( me->query_condition("killer"))
			return notify_fail("衙役喝道：“你是谁？快快离开这里。”\n");
		if( !objectp(present("tiebu wenshu", me)) )
			return notify_fail("衙役喝道：“威……武……。”\n");
	}
	return ::valid_leave(me, dir);
}
