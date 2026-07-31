// Room: /d/yandang/luoyan9.c

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
这是一条青石板铺成的大道,落雁山庄名镇武林,每天慕名前来的武
林人士络绎不绝,路两边林木森森,林中楼阁隐隐,神仙景地,从此地向
北,就是山庄的兵器库.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"luoyan17",
  "north" : __DIR__"luoyan16",
  "west" : __DIR__"luoyan7",
]));
	set("outdoors", "/d/yandang");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/puren.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
