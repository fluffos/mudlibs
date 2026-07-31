

inherit ROOM;

void create()
{
	set("short", "西空间一号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"guangchang",
		"west" : __DIR__"xijie2",
	]));
	set("objects", (["/SJSSS2/GW1/G/guais" : 3,"/SJSSS2/GW1/G/guais1" : 5,]));
	setup();
}