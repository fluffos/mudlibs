// Room: /d/yandang/jiedao.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
芙蓉镇的街道一向是平平整整,虽然这街道已有数百年的历史,无数
的人从这条街道走过,但石板路还是一成没变,唯有上面浅浅的脚印述说
着过去的一切.街道的东面就是杂货铺.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xieyin.c" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"jiedao1",
  "north" : __DIR__"jiedao2",
  "east" : __DIR__"cahuopu",
   //"west" : "/u/legato/simiao",
]));
	set("outdoors", "/d/yandang");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
