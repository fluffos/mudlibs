// Room: /d/tianshui/minju.c

inherit ROOM;

void create()
{
	set("short", "院子");
	set("long", @LONG
这里是一个典型的民居小院，院子右边是一个磨盘，靠着磨
盘有一口井，几只老母鸡在院子里大摇大摆的走着。院子里收拾
得很干净，可地上却有几滴血迹。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"wroad2",
  "north" : __DIR__"minju2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/hen" : 2,
]));

	set("cannot_build_home",1);

	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}
