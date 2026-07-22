// Room: zhudubadian.c

inherit ROOM;

void create()
{
	set("short", "珠都巴殿");
	set("long", @LONG
大殿面阔五间，进深三间。明间重檐歇山顶，两梢见则用硬山顶。殿内功三
十六根大木柱，其金柱呈梭柱形式，两端有卷煞。主殿二三层檐下，有成排的木
雕伏兽和狮身人面泥质半圆塑像。
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"xiekemen",
		"eastdown" : __DIR__"huilang8",
		"westdown" : __DIR__"huilang7",
		"south" : __DIR__"queridian",
	]));
        set("objects", ([__DIR__"npc/wenwoer" : 1,
	]));
	setup();
}
