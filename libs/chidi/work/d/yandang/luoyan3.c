// Room: /d/yandang/luoyan3.c

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
这是一条青石板铺成的大道,落雁山庄名镇武林,每天慕名前来的武
林人士络绎不绝,路两边林木森森,林中楼阁隐隐,神仙景地,从此向东,是
山庄的门房.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"luoyan2",
  "north" : __DIR__"luoyan4",
  "east" : __DIR__"menfang",
]));

	setup();
	replace_program(ROOM);
}
