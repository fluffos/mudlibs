// Room: /d/paiyun/chufang.c

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
厨房里到处是炖野味的清香，看样子排云寨的厨子肯定是一
流的，看看灶台上和锅里的菜你的口水都流下来了，你忍不住向
那盘炖山鸡靠上去。
LONG
	);
set("objects", ([
	"/clone/food/jitui":1,
        "/clone/food/baozi":1,
       "/clone/food/jiudai":1,
       //"/p/obj/table":1,
       ]) );
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dayuan",
]));
	setup();
	replace_program(ROOM);
}
