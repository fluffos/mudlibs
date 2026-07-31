// Room: /d/menggu/caoyuan.c

inherit ROOM;

void create()
{
	set("short", "蒙古草原");
	set("long", @LONG
如海般的蒙古草原,浩淼无边,天空中苍鹰掠过,发出尖尖的哨音.身边
的牛羊缓缓的移动.西边是个小土丘,上面长满了灌木丛.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/huazheng.c" : 1,
]));
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 3 */
  "westup" : __DIR__"guanmu1",
  "south" : __DIR__"caoyuan2",
  "north" : __DIR__"caoyuan4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
