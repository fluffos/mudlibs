// Room: /d/yanjing/qianting.c

inherit ROOM;

void create()
{
	set("short", "前厅");
	set("long", @LONG
白玉石的地面那是一尘不染,两盏高脚盘龙琉璃灯分列,红木柱子间四
盏灯笼风摇频摆,正中猛虎下山图气势威猛.一个纹足瑞金兽在厅角焚着龙
蜒安神香,两边更有婢女伺立.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wanyankang.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"qianyuan",
  "west" : __DIR__"huilang",
  "north" : __DIR__"zhongyuan",
]));

	setup();
	replace_program(ROOM);
}
