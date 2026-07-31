// Room: /d/chengdu/ruin2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "丐帮分舵");
	set("long", @LONG
这里是一栋破旧大宅的正厅，北面的墙壁跟屋顶已经整个坍塌了，
凉飕飕的冷风从北边的缺口直灌进来，另你觉得意外的是，这里清扫得
相当整洁，地上用乾草整整齐齐地铺著一个床(bed)。
LONG	);
	set("exits", ([
		"east": __DIR__"ruin1"
	]));

	set("objects", ([
		CLASS_D("gaibang")+"/obj/jiaohuaji" : 1,
		__DIR__"npc/obj/food/jitui" : 1,
		__DIR__"npc/obj/food/jiudai": 1,
	]));
	set("coor/x", -8080);
	set("coor/y", -3040);
	set("coor/z", 0);
	setup();
}

