// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
你走在大理南大街上，这里安静极了，大理百姓走到这里，无不放慢了脚
步，以敬仰的目光向东看去，东边过去就是大理皇宫了。西边是叮叮当当地传
来一阵打铁的响声，原来是个铁匠铺，南面有个规模不大的书肆。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"nanjie2",
		"west" : __DIR__"datiepu",
		"south" : __DIR__"shudian",
		"north" : __DIR__"xijie7",
	]));
	set("incity", 1);
	set("outdoors", "大理");
	setup();
}
