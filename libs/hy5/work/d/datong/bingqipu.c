// Room: /open/dt/bingqipu.c

inherit ROOM;

void create()
{
	set("short", "兵器铺");
	set("long", @LONG
习武之人没有不希望拥有一件称手的兵器的，而无论你需要
什么样的兵器，在这家兵器铺里多半可以的找。刀、枪、剑、戟、
判官笔、雷公铛....各种造形各异的兵器在架上闪耀着冷森的光
芒。即便是一时找不到合手的兵器，只要你给出兵器的形状、重
量，在三天之内店主人就可以帮你打造出来。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huayanlu1",
]));

	set("objects",([
	__DIR__"npc/weaponboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
