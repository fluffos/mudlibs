// lane@SJ 2005.5.20 fixed bug

#include <ansi.h>
inherit ROOM;
#define SHIP_TO __DIR__"jiangbei"
#define BOAT __DIR__"duchuan"

void create()
{
	set("short", "澜沧江边");
	set("long", @LONG
你一眼望出去，之见前面怒涛汹涌，水流湍急，竟是一条大江(river）。
江岸山石壁立，嶙峋巍峨，看这情势，已是到了澜沧江畔。江面有十来丈高，
但要走到江岸，却也着实不易。 
LONG);

	set("exits", ([
		"west" : __DIR__"xishuang",
	]));

	set("item_desc", ([
		"river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
	]));

	set("outdoors", "大理");
	set("coor/x",-300);
	set("coor/y",-530);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_yell", "yell");
        add_action("du_jiang", "dujiang");
}

int do_yell(string arg)
{
	object room, me;
	me = this_player();

	if( arg == "boat" ) arg = "船家";
	if( arg != "船家" ) arg = "哇";
	if( me->query("age") < 16 )
		message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n", me);
	else if( me->query("neili") > 500 )
		message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传了出去。\n", me);
	else
		message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n", me);
	if( arg == "船家" ) {
		if( room = load_object(BOAT) )
		if( !room->query("start") )
			room->arrive("jiangnan");
		else if( query("exits/enter") )
			message_vision("岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n", me);
		else message_vision("江面上远远传来一声：“等等啊，这就来了～～～”\n", me);
	} else {
		message_vision("江面上远远传来一阵回声：“" + arg + "～～～”\n", me);
		message_vision("忽然凌空飞来一脚，将$N踢了一个跟头，一个老艄公喝道：“此处禁止喧哗！”\n", me);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if( dir == "enter" ) {
		if( me->query("can_ride") ) return 0;
		if( me->query_temp("ride_horse") )
			return notify_fail("骑马上船，你不怕船翻了？\n");
		me->set_temp("side", "jiangnan");
	}

	return ::valid_leave(me, dir);
}

int du_jiang()
{
	object me = this_player();
	object room;
	int cost = 600;

	if( !living(me) ) return 0;

	room = load_object(BOAT);

	if( me->is_busy() || me->is_fighting() )
		return notify_fail("你正忙着呢！\n");

	if( me->query_temp("ride_horse") )
		return notify_fail("骑在马上你不能施展「一苇渡江」的绝技 ！\n");

	if( me->query_skill("dodge") < 270 )
		return notify_fail("你的修为不够！\n");

	if( me->query("max_neili") < 3500 )
		return notify_fail("你的内力修为不够，怎能支持！？\n");

	if( me->query("neili") < 1000 )
		return notify_fail("你的真气不够了！\n");

	if( me->query("jingli") < 1200 )
		return notify_fail("你的精力不够了！\n");

	if( me->query_encumbrance()/100 > me->query("neili") + cost )
		return notify_fail("你带这么重的包袱，走路都成问题，别说飞了！\n");

	if( query("exits/enter") ) return notify_fail("有船不坐，你想扮Cool啊？\n");

	if( room->query("exits/out") ) return notify_fail("江面太宽了，如果没有中途借力的地方根本没法飞越过去！\n");

	me->receive_damage("neili", 300);
	me->receive_damage("jingli", 150);
	tell_room(environment(me), HIC+me->name()+"紧了紧随身物品，紧跟着长袖飘飘，飞身跃渡澜沧江！\n" NOR, ({me}));
	write("你一提内息，看准了江中渡船位置，使出「一苇渡江」轻功想要飞越澜沧江。\n");
	me->move(BOAT);
	me->start_busy(3);
	if( me->query("neili") < 1000 || me->query("jingli") < 1200 ) {
		write("你还想提气，却发现力不从心了。\n");
		tell_room(environment(me), HIC+me->name()+"长袖飘飘，从江面上飞跃过来，站在船上，大口大口喘着气！\n" NOR, ({me}));
		return 1;
	}
	tell_room(environment(me), HIC+me->name()+"长袖飘飘，从江面上飞跃过来，在船上一点，又向对岸跃出！\n" NOR, ({me}));
	write("你在江中渡船上轻轻一点，又提气飞纵向对岸。\n");
	me->move(SHIP_TO);
	tell_room(environment(me), HIC"只见"+me->name()+"长袖飘飘从对岸跃来，姿态潇洒地落在岸边。\n"NOR, ({me}));
	me->receive_damage("neili", 300);
	me->receive_damage("jingli", 150);
	return 1;
}
