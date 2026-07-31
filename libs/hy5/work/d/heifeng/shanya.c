// Room: /d/heifeng/shanya.c

inherit ROOM;

void create()
{
	set("short", "半山崖");
	set("long", @LONG
这里是黑风寨后面的一处小山崖，一道清澈的泉水从这里流
淌而下。四周绿树掩映，空气清新，真是一处神仙所在，上面有
一个小小的茅草屋。
LONG
	);

	set("outdoors", "heifeng");

	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shanquan",
  "north" : __DIR__"maowu",
]));

	setup();
	replace_program(ROOM);
}
