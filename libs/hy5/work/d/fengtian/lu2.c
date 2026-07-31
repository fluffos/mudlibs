// Room: /d/fengtian/lu2.c

inherit ROOM;

void create()
{
	set("short", "小巷");
	set("long", @LONG
由新汇路口拐进这条小巷，外面的吵杂马上少了很多，这里
光线很暗，人也很少要注意安全.
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dayuan",
  "south" : __DIR__"zhai4",
  "east" : __DIR__"lu1",
]));


        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
