// Room: 北大街/dali/beijie2.c

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
这是大理北大街，大理近百年来从无战事，一片太平盛世的模样。往北进
出的好象都是有钱财主。南面就是大理有名的云雪楼了，从里面不时传出诱人
的香味。东西连接着大理北大街。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"beijie3",
		"east" : __DIR__"beijie5",
		"south" : __DIR__"jiulou",
		"north" : __DIR__"qian",
	]));

	set("outdoors", "大理");

	setup();
}
