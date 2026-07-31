// Room: /d/fengtian/lu1.c

inherit ROOM;

void create()
{
	set("short", "小巷");
	set("long", @LONG
由新汇路口拐进这条小巷，外面的吵杂马上少了很多，这里
光线很暗，人也很少要注意安全。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lu2",
  "east" : __DIR__"xh3",
  "north" : __DIR__"zhai3",
]));

	set("objects",([
"/clone/npc/man" : 1,
]));

        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
