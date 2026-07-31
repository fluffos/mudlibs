//dayuan.c
inherit ROOM;

void create()
{
	set("short", "武馆前院");
	set("long", @LONG
从前厅出来就看见这个大院子了，东西两边都是练武场，不少人在这里习
武强身，这里很吵，乱烘烘的，你不时看见有扛着东西的，挑着水的匆匆而过，
北面上了台阶就是武馆大厅了。
LONG
	);

	set("exits", ([
		"south"   : __DIR__"qianting",
		"northup" : __DIR__"dating",
		"east"    : __DIR__"shilu4",
		"west"    : __DIR__"shilu3",
	]));
	set("no_fight",1);

	set("objects", ([
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	/*
	if (!me->query("离馆"))
		return notify_fail("请选择门派。\n");*/
	if (me->query_temp("wgmeet"))
                return notify_fail("你先回答了冯坦的问题再离开也不迟啊！\n");
	if (me->query_temp("wgquestion"))
                return notify_fail("你先回答了冯坦的问题再离开也不迟啊！\n");
	
	return ::valid_leave(me, dir);
}
