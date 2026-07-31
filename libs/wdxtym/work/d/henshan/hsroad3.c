// Room: /d/henshan/hsroad3.c 黄土路

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。西面不远
就是衡阳县城了。
LONG );
	set("outdoors", "hengyang");

	set("exits", ([
		"northeast": __DIR__"hsroad2",
		"west"     : __DIR__"hengyang",
	]));

	setup();
}
