// Room: /open/dt/beimen.c

inherit ROOM;

void create()
{
	set("short", "大同府北门");
	set("long", @LONG
大同是关内最接近塞外的一座城市，骑快马从大同府的北门
出发，只需顿饭的工夫，便到了天下闻名的雁门关了。斑驳的北
门楼终年屹立在风沙的侵袭下，显得十分苍凉雄壮，北门每天开
门的时间很短，主要就是为了防止更多的黄沙肆无忌惮的冲刷城
中的街道。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jinyangjie1",
  "north" : __DIR__"out_datong_n",
]));
/*
// gate settings
// 此部分为 gate room 所必需的设置.

	// 这是 gate room 标记.注意 GATE_ROOM 要大写.
	set( "GATE_ROOM",1 );

	// 这是 gate 的方向,注意方向是一个 mapping.
	set( "gate_dir",(["north" : __DIR__"out_datong_n"]) );

	// 这是门关上以后看到的房间描述.
	// 规则同房间的长描述。.
	set( "close_look",@LONG
大同是关内最接近塞外的一座城市，骑快马从大同府的北门
出发，只需顿饭的工夫，便到了天下闻名的雁门关了。现在天色
已晚，城门已经关上了。
LONG
);

	// 这是 gate 的名称,开关门时此房间内玩家看到的提示要用到.
	set( "gate_name","大同府北门" );

// end.
*/
	set("outdoors","datong");

	set("objects",([
	__DIR__"npc/guard" : 3,
]));

	setup();
	replace_program(ROOM);
}
