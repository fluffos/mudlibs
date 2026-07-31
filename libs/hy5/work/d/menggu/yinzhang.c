// Room: /d/menggu/yinzhang.c

inherit ROOM;

void create()
{
	set("short", "铁木真营帐");
	set("long", @LONG
蒙古人以游牧为生,赶了牲口东迁西徙,追逐水草,并无定居,用毛毡搭
搭成帐篷以蔽风雪,就叫做蒙古包。这虽然是铁木真的住处,却依然质朴无
华,只是比寻常所用大了数倍不止.
LONG
	);
set("valid_startroom",1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tiemuzhen.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road",
]));

	setup();
	replace_program(ROOM);
}
