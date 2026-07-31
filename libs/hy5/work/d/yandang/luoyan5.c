// Room: /d/yandang/luoyan5.c

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
这是一条青石板铺成的大道,落雁山庄名镇武林,每天慕名前来的武
林人士络绎不绝,路两边林木森森,林中楼阁隐隐,神仙景地,从此地向
北,可到落雁山庄的大厅.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"luoyan4",
  "north" : __DIR__"luoyan6",
]));
	set("outdoors", "/d/yandang");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xielin.c" : 1,
     "/d/hainan/npc/man2.c" : 1,
       __DIR__"npc/dizi" : 4,
]));

	setup();
	replace_program(ROOM);
}
