// Room: /d/new_taohua/qianting.c

inherit ROOM;

void create()
{
	set("short", "前厅");
	set("long", @LONG
厅前一侧有一石碑，上书“非桃花岛弟子不得入内，否则后果自负”。
厅中央有一块木牌，此乃桃花岛弟子留言。 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "north": __DIR__"dating",
  "south" : __DIR__"taijie3",
  "east" : __DIR__"nvpuroom",
  "west" : __DIR__"nanpuroom",
]));
	

	setup();
	replace_program(ROOM);
}
