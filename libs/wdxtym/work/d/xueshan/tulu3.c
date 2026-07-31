//      Designed by secret (秘密)
inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条不起眼的土路。尘埃泛起的远方，北边波光
潋滟的一大片幽蓝水光处，就是著名的圣湖。
LONG );
	set("outdoors", "xueshan");
	set("exits", ([
		"south" : __DIR__"tulu2",
		"north" : __DIR__"shenghu",
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
