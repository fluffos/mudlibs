// Room: /open/dt/fangjudian.c

inherit ROOM;

void create()
{
	set("short", "防具店");
	set("long", @LONG
这是一家专门销售和定做防具的店铺，听说满城的兵丁用的
铠甲、头盔全都是从这里买去的，朝廷中配给的盔甲根本无人问
津。在千军万马冲突撕杀的时候，一副好的铠甲可就是兵士们的
护身符啊，所以有很多各地的武林人士都到这里订做合身的防具。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jinyangjie2",
]));

	set("objects",([
	__DIR__"npc/armorboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
