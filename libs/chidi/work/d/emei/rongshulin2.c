// Room: /d/emei/rongshulin2.c 榕树林


inherit ROOM;

void create()
{
	set("short", "榕树林");
	set("long", @LONG
一条绿荫小路，苍翠得绿林间点缀着许多美丽得花草，曲折有致得路旁种
满了宫粉紫荆、红花影等，每当花开花落之时，各色花瓣随着清风的吹动不时
的飘落林间，覆盖了厚厚的一层。绿树流花，美景如画。
LONG
	);

	set("exits", ([
                 "west":__DIR__"rongshulin1",
                 "north":__DIR__"yanbohu",
	]));
        set("outdoors", "emei");
	setup();
}