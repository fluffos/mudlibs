// Room: /d/paiyun/ta1.c

inherit ROOM;

void create()
{
	set("short", "哨塔");
	set("long", @LONG
粗糙的树木搭起的哨塔，一个简陋的木梯通往上一层。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lu1",
  "up" : __DIR__"ta1up",	
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
