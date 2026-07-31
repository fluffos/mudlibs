// Room: /d/hainan/caodi.c

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
一骗青青草地,露珠芬芳,时有白色小兔从你脚下蹿过.彩蝶纷飞,微 
风轻送,眼前美景无限.前面不远的地方有一条小路. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road1",
  "southwest" : __DIR__"outtree2",
]));
	set("outdoors", "/d/hainan");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/hudie.c" : 2,
  	__DIR__"npc/dizi.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
