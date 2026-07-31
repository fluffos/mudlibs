// Room: /d/datong/out_datong_n.c

inherit ROOM;

void create()
{
	set("short", "大同府北门外");
	set("long", @LONG
这里便是大同府的北门外了，斑驳的北门楼终年屹立在风沙
的侵袭下，显得十分苍凉雄壮，北门每天开门的时间很短，主要
就是为了防止更多的黄沙肆无忌惮的冲刷城中的街道。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"beimen",
   "north" : "/d/taiyuan/sroad1",
]));
/*
// gate settings
// 此部分为 gate room 所必需的设置.

	// 这是 gate room 标记.注意 GATE_ROOM 要大写.
	set( "GATE_ROOM",1 );

	// 这是 gate 的方向,注意方向是一个 mapping.
	set( "gate_dir",(["south" : __DIR__"beimen"]) );

	// 这是门关上以后看到的房间描述.
	// 规则同房间的长描述。.
	set( "close_look",@LONG
这里便是大同府的北门外了，斑驳的北门楼终年屹立在风沙
的侵袭下，显得十分苍凉雄壮，现在天色已晚，城门已经关上了。
LONG
);

	// 这是 gate 的名称,开关门时此房间内玩家看到的提示要用到.
	set( "gate_name","大同府北门" );

// end.
*/
	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
