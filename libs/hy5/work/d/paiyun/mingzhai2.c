// Room: /d/paiyun/mingzhai2.c

inherit ROOM;

void create()
{
	set("short", "木板房");
	set("long", @LONG
这是一间原木搭成的大房子，房子里摆放着几张大木床，看
样子是山匪平时休息的地方。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu8",
]));
set("objects", ([
	"/clone/money/gold":1,
	"/clone/money/silver":5,	
	"/d/qianjin/npc/funu":2,		
       ]) );
	setup();
	replace_program(ROOM);
}
