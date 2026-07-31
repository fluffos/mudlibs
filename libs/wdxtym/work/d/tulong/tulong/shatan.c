inherit ROOM;

void create()
{
	set("short", "沙滩");
	set("long", @LONG
一片金黄色的沙滩，无边无际的大海就在眼前了。碧蓝的的海水上面涌
动的洁白的浪花，海面飘着轻轻的薄雾。茫茫的大海上没有一点帆影，极目
远眺，海天交界处蒙蒙一片，分不出哪里是海，哪里是天。海风清凉，略有
点咸味，海面微微泛着波浪。
LONG );

	set("exits", ([
		"west" : __DIR__"haian",
	]));

	set("objects", ([
		"/d/tulong/yitian/npc/liuyun" : 1,
	]));

	set("outdoors", "tulong");
	setup();
}
