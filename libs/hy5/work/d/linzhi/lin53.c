// Room: /d/linzhi/lin53.c

inherit ROOM;

void create()
{
	set("short", "高原峰道");
	set("long", @LONG
你走在高原峰道上，不时四下注视着。只见左侧不远处一群
野牦牛像是正在觅食，但好像并没有注意到你。你不由得加快了
脚步。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin52",
  "west" : __DIR__"lin54",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
