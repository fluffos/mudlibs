// Room: /d/fengtian/ji1.c

inherit ROOM;

void create()
{
	set("short", "怡红院");
	set("long", @LONG
即使在寒冷的东北仍然还是少不了声色犬马，怡红院地处闹
市自然也就生意兴隆，怡红院的二楼是包房，有不少才色双全的
佳人，听说最近更从京城来了一位当红歌妓，不知你有没有福气
见到她。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wy5",
]));

	set("objects",([
	__DIR__"npc/mama" : 1,
]));

	setup();
	replace_program(ROOM);
}
