// Room: /d/hainan/road3.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
鹅卵石铺成的一条小径,路的尽头是个小小的尼庵,阵阵木鱼声从庵 
中传来.使这地方充满一片详和气氛.路边有个老尼在慢慢地扫地. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"road2",
  "north" : __DIR__"baiyunan",
]));
	set("outdoors", "/d/hainan");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/man1":1,
		__DIR__"npc/man2":1,
__DIR__"npc/dizi.c" : 4,
  __DIR__"npc/laonigu.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
