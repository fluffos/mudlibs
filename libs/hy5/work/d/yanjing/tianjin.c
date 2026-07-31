// Room: /d/yanjing/tianjin.c

inherit ROOM;

void create()
{
	set("short", "天井中");
	set("long", @LONG
一棵老槐树枝叶斑驳地占了半个天井,上面还堆着早起没溶化的雪.
树下一口老井,用四方青石在中间挖了圆孔,就是现成的井圈.水井边老
大一个水缸,装满了清水.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kefang",
  "east" : __DIR__"zoudao",
]));
	set("no_clean_up", 0);
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
