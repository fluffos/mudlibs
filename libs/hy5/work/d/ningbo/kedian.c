// /u/beyond/ningbo/kedian.c 客店
inherit ROOM;

void create()
{
	set("short", "客店");
	set("long", @LONG
这是宁波城里的一个小客店，客店的门口站着一位店小二，看到你走过
来，笑呵呵的向你打招呼。客店的西面是一个马厩，专门为骑马而来的过往
旅客们换马，喂马而设的。墙上挂着一个牌子(paizi)。
LONG
	);

	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "楼上雅房，每夜五两白银。\n",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
	"north" : __DIR__"ningbocheng",
        "up" : __DIR__"kedian2",
        "west" : __DIR__"majiu",
        "northeast" : __DIR__"dongqianhu",
        
	]));

	setup();
	
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("怎么着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("客官已经付了银子，怎么不住店就走了呢！
旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
