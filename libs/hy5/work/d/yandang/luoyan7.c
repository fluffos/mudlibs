// Room: /d/yandang/luoyan7.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
转过屏风,就来到练武场,你走过来时,正有几个弟子在摆拳弄腿,有
两个还在拆招练习剑法.由于来的客人比较多,有时兴致好,也会在此露
两手,不过大家都给山庄面子,有恩冤一般不会在此解决.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"luoyan10",
  "east" : __DIR__"luoyan9",
  "south" : __DIR__"luoyan6",
  "north" : __DIR__"luoyan8",
]));
	set("outdoors", "/d/yandang");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dizi.c" : 3,
]));

	setup();
	replace_program(ROOM);
}
