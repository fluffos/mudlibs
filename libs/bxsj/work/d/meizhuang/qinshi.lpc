// Room: /d/meizhuang/qinshi.c
// By Lklv 2001.9.11

inherit ROOM;

void create()
{
	set("short", "琴室");
	set("long", @LONG

这是一间琴室，房间不是很大，但是很别致，三把竹椅，一张茶几，靠墙
的位置有张竹床，床头的几上放有一张瑶琴，旁边壁上挂着一根玉萧，房间里
弥漫着一股檀香的味道。
LONG
	);
	set("exits", ([
		"south" : __DIR__"huilang19",
		"north" : __DIR__"neishi",
	]));

        set("objects", ([
                __DIR__"npc/huang" : 1,
        ]));

	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("huangzhong gong", environment(me))) && dir == "north")
		return notify_fail("黄钟公皱了皱眉道：没事请不要乱闯。\n");

	return ::valid_leave(me, dir);
}
