// Room: /d/paiyun/up2.c

inherit ROOM;

void create()
{
	set("short", "上山小路");
	set("long", @LONG
这是一条上山的土路，这条土路非常宽阔，路边长满了蒿草，
路上却满是脚印马蹄印，看来经常有人经过这里。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"up1",
  "northup" : __DIR__"up3",
]));

	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
