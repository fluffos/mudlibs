// Room: /d/jinghai/moon10.c

inherit ROOM;

void create()
{
	set("short", "东栈道");
	set("long", @LONG
这是一条用碎石拼铺成的道路，道路两旁整齐的排列着圆木
围墙。道路向东西两个方向笔直的伸延开去。时不时有一队队红
巾水勇鱼贯而过。向北不远处可以看见山崖下又是一道寨门。南
边是全寨的最高点，明月寨烽火台。西边不远可以看见一大块空
地。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"moon16",
  "south" : __DIR__"moon17",
  "west" : __DIR__"moon7",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
