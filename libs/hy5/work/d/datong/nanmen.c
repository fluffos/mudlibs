// Room: /open/dt/nanmen.c

inherit ROOM;

void create()
{
	set("short", "大同府南门");
	set("long", @LONG
高大威严的南门楼耸立在你的面前，一队官兵迈着整齐的步
伐从你身边走过，他们就是威镇边塞的大将李如风手下的精兵。
几名差役正拦住一名客商盘问着什么，他们身后的城墙上贴着几
张告示，看来是官府正在办案。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lukou",
  "south" : __DIR__"out_datong_s",
]));
/*
// gate settings
// 此部分为 gate room 所必需的设置.

	// 这是 gate room 标记.注意 GATE_ROOM 要大写.
	set( "GATE_ROOM",1 );

	// 这是 gate 的方向,注意方向是一个 mapping.
	set( "gate_dir",(["south" : __DIR__"out_datong_s"]) );

	// 这是门关上以后看到的房间描述.
	// 规则同房间的长描述。.
	set( "close_look",@LONG
这里就是高大威严的大同府南门，现在天色已晚，城门已经
关上了。
LONG
);

	// 这是 gate 的名称,开关门时此房间内玩家看到的提示要用到.
	set( "gate_name","大同府南门" );

// end.
*/
	set("outdoors","datong");

	set("objects",([
	__DIR__"npc/guard" : 1,
]));

	setup();
	replace_program(ROOM);
}
