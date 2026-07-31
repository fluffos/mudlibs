// Room: /d/paiyun/lu1.c

inherit ROOM;

void create()
{
	set("short", "石道");
	set("long", @LONG
进入排云寨的山门就来到了这条完全由鹅卵石铺就的小路，
沿着这条石路，远远的你可以看见一些山高处的建筑，石路两旁
是排云寨的哨塔，一些卫兵在路边换岗。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"ta1",
  "south" : __DIR__"door",
  "east" : __DIR__"ta2",
  "north" : __DIR__"lu2",
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
