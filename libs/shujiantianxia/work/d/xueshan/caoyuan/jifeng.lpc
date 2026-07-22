// Room: jifengying.c

inherit ROOM;

void create()
{
	set("short", "疾风营");
	set("long", @LONG
这里是蒙古军骑兵疾风营，共有五个千人队，面前方圆数里内支起了几百座
帐篷。不时有蒙古骑兵小队纵马弛过，看蒙古兵将衣甲鲜明，刀枪耀眼，而骑乘
之术更是甲于天下。更难得的是这数千兵将除了马蹄声和偶尔刀枪甲胄的碰撞声
以外，竟无任何嘈杂，不由得令人佩服统率的将领治军有方。
LONG
	);

	set("exits", ([
		"north" : __DIR__"shenfeng",
		"south" : __DIR__"yingmen",
	]));
	set("outdoor","大草原");
        set("objects",([
		__DIR__"../npc/zhebie" : 1,
		__DIR__"../npc/jqbing" : 3
	]));
	setup();
}
