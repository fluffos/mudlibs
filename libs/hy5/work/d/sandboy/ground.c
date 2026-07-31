// Room: /d/sandboy/ground.c

inherit ROOM;

void create()
{
	set("short", "晒谷场");
	set("long", @LONG
黄泥夯实的一片晒谷场,场边堆了几个稻草堆,旁边一个大碌砘,看来有
好几百斤重.向东看,是一颗高大的榕树,北面有户人家.
LONG
	);
set("valid_startroom",1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"home",
  "east" : __DIR__"undertree",
  "west" : __DIR__"daotian2",
  "south" : __DIR__"road2",
]));
	set("outdoors", "/d/jiangnan");
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/kid.c" : 1,
  __DIR__"npc/kid1.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
