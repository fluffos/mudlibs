// road.c 桃源大道

inherit ROOM;

void create()
{
	set("short","桃源大道");
	set("long",@LONG
这是通往各位英雄隐居之地「桃源山庄」的一条大道上，大道两旁种
满了密密麻麻的杨柳树，柳条儿迎风飘舞，鸟儿穿梭于柳树之间，十分欢
快。只见大道的东西两面隐约的坐落着几座宅院，那便是武林列传英雄们
的居住之地。
LONG
);
	set("exits",([
		"north"  :__DIR__"road_1",
		"south"  :__DIR__"road_3",
		"east": __DIR__"road_2e",
		"west": __DIR__"road_2w",
	]));
	setup();
	replace_program(ROOM);
}
