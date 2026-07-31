// Room: /d/yanjing/hualou.c

inherit ROOM;

void create()
{
	set("short", "画楼");
	set("long", @LONG
楼的四边开了许多半扇的窗户,镂花的窗楞蒙着淡绿帛罗纱,屋角的
红木小厨中是一套套的精致茶具,边上的红泥小火炉边用白铜盒子盛了些
白细炭条,一座小巧楼梯通向上层.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huayuan",
  "up" : __DIR__"hualou1",
]));
	set("objects", ([ /* sizeof() == 2 */
//  __DIR__"npc/clone/clothxiaohuolu.c" : 1,
  __DIR__"npc/binu.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
