// liangong.c 北练功室
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "北练功室");
	set("long", @LONG
这座石室形状甚是奇特，前窄後宽，成为梯形，东边半圆，西边
却作三角形状，原来这是以前重阳祖师的练功室，前窄练掌，後宽使
拳，东圆研剑，西角发镖。南面有个小门洞，通向里面的练功室。
LONG
	);

	set("exits", ([
		"east"  : __DIR__"zhengting",
		"south" : __DIR__"liangong2",
	]));
	set("objects", ([
		"/clone/npc/mu-ren" : 4,
	]));
	set("for_family", "古墓派");
	setup();
}
