// Room: /d/fengtian/lukou.c

inherit ROOM;

void create()
{
	set("short", "路口");
	set("long", @LONG
这里是一个小小的路口，由于靠近盛京的南门，来往的人流
不断，到是非常的热闹，向南看盛京府的南门遥遥在望，北面一
直走就是盛京的中心地带了。
LONG
	);

	set("outdoors", "fengtian");

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"kd5",
  "south" : __DIR__"guanlu2",
  "east" : __DIR__"kd4",
  "north" : __DIR__"xm1",
]));

	setup();
	replace_program(ROOM);
}
