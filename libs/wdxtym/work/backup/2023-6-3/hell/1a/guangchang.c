// by jjyy

inherit ROOM;

void create()
{
	set("short", "中央广场");
	set("long", "这里是空中之城的中央广场，人来人往热闹非凡。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"beijie1",
		"south" : __DIR__"nanjie1",
		"west" : __DIR__"xijie1",
		"east" : __DIR__"dongjie1",
	]));
	set("objects", (["/HELL1a/GuaiWu5/G/guais" : 5,"/HELL1a/GuaiWu1/G/guais" : 5,
	]));
	setup();
}

