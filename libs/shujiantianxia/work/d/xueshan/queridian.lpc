// Room: queridian.c

inherit ROOM;

void create()
{
	set("short", "却日殿");
	set("long", @LONG
大殿面阔九间，进深五间，单檐四柱，耸立在高台上。殿内并列七坐佛像，
连莲坐高约八米。梁架和内槽斗拱上有彩画，四壁有壁画，画了十佛，八菩萨，
十八罗汉等等，形象逼真，栩栩如生。
LONG
	);

	set("exits", ([
		"north" : __DIR__"zhudubadian",
		"eastdown" : __DIR__"huilang6",
		"westdown" : __DIR__"huilang5",
		"south" : __DIR__"dadian",
	]));
        set("objects", ([CLASS_D("xueshan") + "/mohebasi" : 1,
	]));
	setup();
}
