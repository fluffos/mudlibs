inherit ROOM;

void create()
{
	set("short", "康府大院");
	set("long", @LONG
这是一个宽大的练武场，有几个武师在这里练功。其中一个秃顶和尚，
东走走，西看看，好象是这儿的领头。还有一个身材瘦高的武师，两手别
在腰后，似乎也有一身好武功。东面是一个小一些的练武场。北面是后院。
西边有个武器库。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"wuqiku",
		"east" : __DIR__"wuchang",
		"north" : __DIR__"kang3",
		"south" : __DIR__"kang1",
	]));
	set("objects", ([
		__DIR__"npc/shenzhao" : 1,
		__DIR__"npc/qi" : 1,
	]));
	set("no_npc",1);
	set("coor/x", -180);
	set("coor/y", 4081);
	set("coor/z", 0);
	setup();
	//replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	object ob;
	if ( objectp(present("qi yuankai", environment(me))) && 
		dir == "east")
		return notify_fail("齐元凯拦住了你的去路。\n");

	if ( objectp(present("shen zhao", environment(me))) && 
		dir == "east")
		return notify_fail("神照上人拦住了你的去路。\n");

	if ( !present("zhangmen ling", this_player()) && 
		dir == "east")
		return notify_fail("几名士兵拦住了你，没有掌门人令牌不让进。\n");

	return ::valid_leave(me, dir);
}
                                                                                                                                      