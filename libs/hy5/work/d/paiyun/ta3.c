// Room: /d/paiyun/ta3.c

inherit ROOM;

void create()
{
	set("short", "哨塔");
	set("long", @LONG
粗糙的树木搭起的哨塔，一个简陋的木梯通往上一层。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu5",
  "up" : __DIR__"ta3up",	
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
