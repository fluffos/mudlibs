// Room: /d/fengtian/cross.c

inherit ROOM;

void create()
{
	set("short", "十字路口");
	set("long", @LONG
这是新汇路，威远路，祥马街交汇的一个十字路口，所以人
来人往的比较嘈杂，实际上这里更象个小广场，路当中的转盘上
是一片绿地，绿地上有一些石墩，不少人座在那里休息。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"xm4",
  "west" : __DIR__"wy3",
  "east" : __DIR__"wy4",
  "north" : __DIR__"xh1",
]));
        set("objects",([
        	__DIR__"npc/jinbing" :5,        	
        "/clone/misc/dache" : 1 
        ]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
