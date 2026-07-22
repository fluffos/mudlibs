// dezj.c 第二指节

inherit ROOM;

void create()
{
	set("short", "第二指节");
	set("long", @LONG
这里已到了中指峰的半山腰了，由于铁掌山排列得象手指一样，每座山峰
又分三截，就如手指的指节一般，因此这里正是位于第二指节的位置。这里离
峰顶已近，透过淡淡的云雾，似已可以看到山路的尽头了。左前方二十于丈处，
黑黝黝的似有一个洞穴(dong)，洞口砌以玉石，修建得极是齐整。
LONG);
	set("outdoors", "铁掌");
	set("exits", ([
		"south" : __DIR__"sslin-5",
		"northup" : __DIR__"shanlu-8",
		"enter" : __DIR__"dong-1",
	]));
	set("cant_hubiao", 1);
	set("objects", ([
		__DIR__"npc/mayi2" : 1,
		__DIR__"npc/mayi3" : 1,
	]));
	set("item_desc", ([
		"dong" : "一个黑黝黝的山洞。黑暗中偶尔有几点磷光闪过，好吓人！！！\n",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "enter"
	 && (present("huang lingtian", environment(me)) || present("ling zhentian", environment(me))))
		return notify_fail("麻衣长老喝道：此乃铁掌帮禁地，任何人不得入内，否则有死无生！！\n");

        return ::valid_leave(me, dir);
}