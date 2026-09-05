// Room: /d/beijing/kangqin/majiu.c
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIC"王府马厩"NOR);
	set("long",
MAG"这里是王府的马厩。康亲王酷爱宝马，花了很多精力
和金钱收罗了不少好马。地上铺了一层干草，靠墙的饲料
槽总是满的。离饲料槽不远处是个池子，可以洗马。旁边
有块沙地，可供马夫遛马。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"west" : __DIR__"neijiu",
 	 "north" : __DIR__"zhoulang9",
]));
        create_door("west", "小门", "east", DOOR_CLOSED);
        set("objects",([
                "/d/beijing/npc/zaohongma":1,
                "/d/beijing/npc/huangbiaoma":1,
                "/d/beijing/npc/ziliuma":1,
        ]));

	setup();
}
void init()
{
    add_action("do_xima","xi");
}

int do_xima(string arg)
{
	int times;
	object ma;
	object me=this_player();
	if (!arg || (arg != "ma" && arg != "马"))
		return notify_fail("你要洗什么？\n");
	if (!me->query_temp("xima/in_job"))
		return notify_fail("康亲王没有让你来洗马吧？\n");


    if (!objectp(ma = present("ma",environment(me))) || !ma->is_trainee())
		return notify_fail("这里没有马，你洗什么啊？\n");
		if (me->query("qi") < 15)
		return notify_fail("你太累了，先休息一会儿再洗吧？\n");
	if (!me->is_busy() )
	{
	times = 5 * ( 1 + random(8) );
    	me->start_busy(times);
    	write("你拿起洗马的用具，开始洗马......\n");
    	call_out("end_xima",5, me);
    	return 1;
	}
	return 0;
}



void end_xima( object me )
{
    if (!living(me)) return;
    if ( me->is_busy() )
    {
		tell_object( me, "你去换了一桶水接着干活......\n");
		call_out("end_xima",5,me);
	}
	else
	{
		object chengyao;
		int ereward,breward;
		write("不知过了多久，你终于洗完了马，赶快去向康亲王汇报吧。\n");
		write("你直起腰，深深地吸了一口气。\n");
		me->add("qi", -10);
		me->set_temp("xima/ok",1);
	}
    return;
}