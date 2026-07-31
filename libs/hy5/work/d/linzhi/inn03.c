// Room: /d/linzhi/inn03.c

inherit ROOM;

void create()
{
	set("short", "二楼过道");
	set("long", @LONG
这里是客店二楼过道，一个伙计站在那里，看见你走来热情
的打着招呼。在他背后有一个楼梯通向三楼客房，西边是一个较
高级的餐厅，是宴请朋友用的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"inn01",
  "up" : __DIR__"inn05",
  "west" : __DIR__"inn04",
]));

	setup();
	replace_program(ROOM);
}
