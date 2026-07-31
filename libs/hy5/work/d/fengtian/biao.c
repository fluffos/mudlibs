// Room: /d/fengtian/biao.c

inherit ROOM;

void create()
{
	set("short", "威远镖局");
	set("long", @LONG
大门上飘舞这一面杏黄旗在风中猎猎作响，旗上大大的两个
字“威远”，门口有一张长凳几个镖局的堂子手座在那里聊天，
镖局内不时有人进进出出。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xm1",
]));
	set("cannot_build_home",1);

	set("outdoors", "fengtian");

	set("objects",([
	__DIR__"npc/tangzi" : 4,
	__DIR__"npc/biaoshi" : 2,
]));

	setup();
	replace_program(ROOM);
}
