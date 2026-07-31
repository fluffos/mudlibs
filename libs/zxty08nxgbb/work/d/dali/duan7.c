// Room: /d/dali/duan7.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：20时44分11秒。

inherit ROOM;

void create()
{
	set("short", "王府花园");
	set("long", @LONG
这里是镇南王府的后花园，这里虽然规模远较皇宫的御花园
小，但这里的每品茶花都显然是经过精心培育，款款惹人喜爱。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"duan6",
]));

        set("objects", ([
        __DIR__"npc/yahuan" : 1,
        __DIR__"npc/jiading" : 1,
]));

	setup();
}

