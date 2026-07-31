// by jjyy

inherit ROOM;

void create()
{
	set("short", "南空间一号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"guangchang",
		"south" : __DIR__"nanjie2",
	]));
	set("objects", (["/SJSSS8/GW1/G/guais" : 3,"/SJSSS8/GW1/G/guais1" : 5,
	]));
	setup();
}