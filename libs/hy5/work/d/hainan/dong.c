// Room: /d/hainan/dong.c

inherit ROOM;

void create()
{
	set("short", "秘密山洞");
	set("long", @LONG
这是一个秘密山洞。有一个淘气的小丫头正对着你笑呢。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"underhill3",
]));
        set("objects", ([
                __DIR__"npc/xiaoyi" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
