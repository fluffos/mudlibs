#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"客栈后院"NOR);
	set("long",
CYN"这里客店后院。一阵阵打斗之声从东面的厢房中传来，
其中夹杂着一个女子的声音。房门的板壁(wall)不住的震动，似乎
客房四周的板壁都要被刀风掌力震坍一般。西首也是厢房，不时有
人探头出来观望。北面是客店大门。\n"NOR
 );
        set("no_sleep_room",1);
	set("exits", ([
		"west" : __DIR__"kedian4",
		"east" : __DIR__"kedian3",
		"north" : __DIR__"kedian",
	]));
	set("item_desc", ([
		"wall" : "\n这是一堵木墙，板壁不过一寸来厚，被震得摇摇晃晃。\n",
	]));
	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	int i;
	object room;

	if(!( room = find_object(__DIR__"kedian3")) )
		room = load_object(__DIR__"kedian3");

	if(!objectp(present("lama", room)))
	return ::valid_leave(me, dir);

	if (dir == "east" )
	{
        i = (int) random(me->query_skill("dodge")+me->query("dex")*10+me->query("con")*5);
	if(i < 300)
        return notify_fail(
	"\n你一步踏进客房，突觉一股力道奇大的劲风激扑出来，将你一撞，\n"+
	"你登时立足不稳，腾腾腾到退三步，一交坐倒。\n");
        me -> receive_damage ("qi",50,"被一股劲风吹倒摔");
        me -> receive_wound  ("qi",50,"被一股劲风吹倒摔");
	}
	return ::valid_leave(me, dir);
}

void init()
{
add_action("do_thrust","thrust");
add_action("do_thrust","ci");
add_action("do_thrust","stab");
}

int do_thrust(string arg)
{
	object room, me, man, weapon;
	me = this_player();
	if( !arg || arg!="wall" ) return notify_fail("你要刺什么？\n");

	if(	!objectp(weapon = me->query_temp("weapon"))
		&& !objectp(weapon = me->query_temp("secondary_weapon"))
		|| (	weapon->query("skill_type") != "sword"
                        && weapon->query("skill_type") != "blade" && weapon->query("skill_type") != "dagger") )
	return notify_fail("不用刀剑恐怕不行吧！\n");

	if(!( room = find_object(__DIR__"kedian3")) )
		room = load_object(__DIR__"kedian3");

	message_vision( "\n$N走到墙边，抽出兵刃，对准木板狠狠地一戳。\n",this_player());

	if(!present("bi shou" , this_player()))
	message_vision( "结果$N笃的一声，兵刃插入寸许，再也刺不进半分。\n",this_player());
        else
	{
	if(objectp(room))
        {
		if(!present("lama",room))
		{
		message_vision( "只听噗的一声，匕首轻轻穿过木板，但隔壁没什么动静，看来没什么危险了。\n",this_player());
	        message("vision", "忽然一柄匕首从墙外戳了进来。\n",room );
		}
		else
		{
		message_vision( "只听噗的一声，匕首轻轻穿过木板，房中立时传来一声惨叫。\n",this_player());
                me->add_temp("hastrystab",1);
		message("vision", "忽然一个喇嘛惨叫一声倒了下去。\n",room );
		if(objectp(man=present("lama",room))) man->die();
		}
	}
	return 1;

    	}
	return 1;
}

