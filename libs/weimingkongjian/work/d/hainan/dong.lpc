// Room: /d/hainan/dong.c

inherit ROOM;

void create()
{
	set("short", "秘密山洞");
	set("long", @LONG
这是一间什麽也没有的空房间。
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
