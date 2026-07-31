//zhulin4.c by river

inherit ROOM;

void create()
{
	set("short", "竹林");
	set("long", @LONG
这里是一大片密密的竹林，郁郁葱葱，一眼望不到尽头。微风吹拂着竹叶，
令人尘心为之一涤，你在竹林里来回来去的走，想要找到出来的路，但是走了
半天后发现还是没有找到出来的路。
LONG
	);
	set("outdoors","武馆");
	set("exits", ([
		"west" : __DIR__"jiashan",
		"south"  : __FILE__,
		"east"  : __FILE__,
		"north" : __FILE__,
	]));
	set("no_fight",1);
	setup();
}
