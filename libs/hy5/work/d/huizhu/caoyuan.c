// Room: /d/huizhu/caoyuan.c

inherit ROOM;

void create()
{
	set("short", "草原");
	set("long", @LONG
美丽的草原就在你的面前，成群的牛羊围绕在你身边，远处天地交际
处不时有大片的烟尘涌起，刹那间就塞满了天地，那是戈壁中时而出现的
龙卷风。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/huizhushaonv.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 4 */
  "southup" : __DIR__"xiepo",
  "north" : __DIR__"caoyuan1",
  "west" : __DIR__"caoyuan2",
  "east" : __DIR__"caoyuan3",
]));
    set_temp("wayao2",2);
	setup();
	replace_program(ROOM);
}
