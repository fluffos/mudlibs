//      hubian1.c 湖边小路
inherit ROOM;

void create()
{
	set("short", "湖边小路");
	set("long", @LONG
这是圣湖边的小路。路侧的湖水极为清澈。阳光下映
着白顶雪山显出一片蓝幽幽的宁静。
LONG );
	set("outdoors", "xueshan");
	set("exits", ([
		"east" : __DIR__"hubian2",
		"west" : __DIR__"shenghu",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (! playerp(me))
		return ::valid_leave(me, dir);

	if (random(3))
	{
		write("你突然发现眼前的景象有些迷乱。\n");
		return -1;
	}
	return ::valid_leave(me, dir);
}
