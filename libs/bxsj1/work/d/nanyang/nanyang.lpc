// Room: /d/nanyang/nanyang.c
// Lklv Modify 2001.10.10

inherit ROOM;
void create()
{
	set("short", "城中心");
	set("long", @LONG
这里便是南阳城中心。当年诸葛先生就住在附近的隆中卧龙岗。南阳府地
界不大，方圆不过数十里。但是因为地处南北的要道上，所以南来北往的各地
客商旅人很多。西面是一家酒楼，本地人口甚少，所以生意不是很兴旺。北面
有条大道直通汝州城。
LONG
	);
	set("outdoors", "南阳");
	set("exits", ([
		"south" : __DIR__"yidao2",
		"north" : __DIR__"yidao3",
		"west" : __DIR__"jiulou1",
	]));
	set("objects",([
		__DIR__"npc/xiao-fan" : 1,
	]));
	setup();
}