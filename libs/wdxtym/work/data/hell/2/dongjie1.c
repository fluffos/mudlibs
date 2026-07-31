// by jjyy

inherit ROOM;

void create()
{
	set("short", "东街一号");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"guangchang",
		"east" : __DIR__"dongjie2",
	]));
	set("objects", ([		"/HELL2/GuaiWu5/G/guais" : 10,
	]));
	setup();
}
