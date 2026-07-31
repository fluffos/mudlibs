//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "祭祀大屋");
	set("long", @LONG
这是乌撒部的祭祀大屋，颇为宽敞。屋子正中一张竹台，台上摆
放着一排竹制牌位，上书乌蛮族祖先之名。牌位后的墙上挂有大幅兽
皮，上绘龙形花纹，似是该族的图腾。一位老祭司常年守在祭台前，
负责全族的祭司活动。
LONG
        );

	set("exits", ([
		"out" : __DIR__"minov43",
		]));

	set("objects", ([
		__DIR__"npc/wyjisi.c" : 1,
		]));

	set("cost", 2);
	setup();
}
