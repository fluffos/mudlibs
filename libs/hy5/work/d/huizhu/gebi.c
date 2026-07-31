// Room: /d/huizhu/gebi.c

inherit ROOM;

void create()
{
	set("short", "戈壁沙漠");
	set("long", @LONG
焦热的阳光晒着茫茫的戈壁，天地之间只剩下黄色的沙，连绵起伏
的沙丘一眼望不到边。前面不远的沙地上微微随风而动的是沙漠中的铁
草，耐旱，看来你快走出这片沙漠了。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"xianei",
  "west" : __DIR__"gebi1",
]));

	setup();
	replace_program(ROOM);
}
