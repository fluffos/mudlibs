// Room: /u/xiaozhen/biaoju.c

inherit ROOM;

void create()
{
	set("short", "日月镖局");
	set("long", @LONG
这里便是闻名关内外的日月镖局了，左右石坛上各插着一根
两丈多高的旗杆，右首旗子上用金线绣着太阳，用银线绣着月亮，
底下绣着一只猛虎。左首旗上绣着“日月镖局”四个刚劲有力的
黑字。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"biaoju2",
  "south" : __DIR__"eroad2",
]));
	set("objects",([
	__DIR__"npc/bfighter.c" : 1,
	__DIR__"npc/bfighter1.c" : 2,
]));
	setup();
	replace_program(ROOM);
}
