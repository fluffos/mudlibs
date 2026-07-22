#pragma save_binary
// Room: /d/green/house4.c

inherit ROOM;

void create()
{
	set("coor",({75,4890,10}));
	set("short", "村长的家");
	set("long",
"这是一间看起来有点不一样的民宅，屋子的中央有一个石制的炉\n"
"子，上面生著一堆火，熊熊的火光把屋内照得像白天似的光亮。\n"
"墙上挂著几幅字画，一边还放了一个木制的书架，上面整齐地排\n"
"著一些旧得不能再旧的书。炉子的旁边摆了一张手工精美的石椅，\n"
"看来像个很重要的位置。\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/green/field0",
]));
	set("objects", ([
	"/d/green/npc/oldman2" : 1,
	]) );

	setup();
	replace_program(ROOM);
}

