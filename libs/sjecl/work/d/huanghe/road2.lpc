
#include <ansi.h>
inherit ROOM;
#include <wanted.h>

#define SHIP_TO __DIR__"road3"
void create()
{
	set("short", "大渡口");
	set("long", @LONG
这里是黄河大渡口，是通往京城的必经之路。宽阔的黄河江面上飘荡着几
只轻帆。渡口处正停着一艘渡船，几个乘客正在和船家讨论价钱。你可以由此
上(yell)船渡过黄河。
LONG);
	set("exits", ([
		"south" : __DIR__"huanghe8",
	]));
	set("outdoors", "黄河");
 
	setup();
}

void init()
{    
	add_action("do_yell", "yell");     
	add_action("du_jiang", "duhe");			
}
/*

凤飞翩翩兮，四海求凰 说：
可以yell 洪教主洪福齊天﹐受雨天其
刺猬(香囊犹在楼已空) 说：
然后就出来一艘船？
刺猬(香囊犹在楼已空) 说：
直接move到sld?
刺猬(香囊犹在楼已空) 说：
出来呢？
凤飞翩翩兮，四海求凰 说：
然後就會有條小船過來說﹐這位師兄要回神龍島麼﹐我在這裡等你多時了。
*/
int go_sld(object me)
{
	object hc;
	string str ="师兄";
		
	if(!objectp(hc=find_object(__DIR__"hc1")))
		hc=load_object(__DIR__"hc1");
		if(hc->query_temp("curstatus",1)=="run") {
			if(!objectp(hc=find_object(__DIR__"hc2")))
				hc=load_object(__DIR__"hc2");
				if(hc->query_temp("curstatus",1)=="run") {
					if(!objectp(hc=find_object(__DIR__"hc3")))
						hc=load_object(__DIR__"hc3");
						if(hc->query_temp("curstatus",1)=="run")
							return notify_fail("你喊了几声，却什么事也没有发生。\n");
                        }
                }
	if(me->query("gender")=="女性") str="师姐";
	message_vision(CYN"一位小童走过来对$N鞠了一躬说道：这位"+str+"要回神龙岛么？我在这里等你多时了。\n" NOR,me);
	message_vision(CYN"只见一艘大船已经驶进海口，$N慢慢走了进去。\n" NOR,me);	
	me->move(hc);
	hc->set_temp("curstatus","run");
	return 1;
}

int do_yell(string arg)
{
	object room, me;
	me = this_player();

	if ( (arg == "洪教主洪福齐天" || arg == "洪教主寿与天齐") && me->query("family/family_name")=="神龙教" ) {
		if ( is_wanted(me) ) return 0;
		else return go_sld(me);
	}

	if (arg == "boat") arg = "船家";
	if (arg != "船家") arg = "哇";
	if (me->query("age") < 16  )
		message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n", me);
	else if (me->query("neili") > 500)
		message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传了出去。\n", me);
	else
		message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n", me);
	if (arg == "船家") {
		if( !(room = find_object(__DIR__"boat")))
			room = load_object(__DIR__"boat");
		if( room = find_object(__DIR__"boat")) 
			if(!room->query("start")) 
				room->arrive("road2");
			else if (query("exits/enter"))
				message_vision("岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n", me);
			else 
				message_vision("江面上远远传来一声：“等等啊，这就来了～～～”\n", me);
			return 1;
	}
	else
		message_vision("江面上远远传来一阵回声：“" + arg + "～～～”\n", me);
	return 1;
}

int valid_leave(object me, string dir)
{
	object obj;
	obj = this_object();

	if(userp(me) && dir == "enter") {
		switch (MONEY_D->player_pay(me, 100)) {
			case 0:
			case 2:return notify_fail("你掏了掏腰包，却发现身上带的钱不够了。\n");
		}
		message_vision("$N掏出一两白银递给船家，纵身跃上了渡船。\n\n", me); 
		me->set_temp("side", "road2");
		/*
		if(ob = present("silver_money", me)){		  
			message_vision("$N掏出一两白银递给船家，纵身跃上了渡船。\n\n", me); 
			me->set_temp("side", "road2");
			ob->add_amount(-1);
		}
		else if(ob = present("gold_money", me)){		  
			message_vision("$N掏了半天，发现身上白银所剩无几了，只得拿出一锭黄金递给船家，纵身跃上了渡船。\n\n", me); 
			me->set_temp("side", "road2");
			ob->add_amount(-1);
		}
		else return notify_fail("你掏了掏腰包，却发现身上带的钱不够了。\n");   
		*/
	}
	return ::valid_leave(me, dir);
}

int du_jiang()
{
	object me = this_player();
	object room;
	int cost = 600;
	
	if( !(room = find_object(__DIR__"boat")) )
		room = load_object(__DIR__"boat");
	if (!living(me)) return 0;
	
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	if (me->query_skill("dodge") < 250)
		return notify_fail("你的修为不够！\n");
	if (me->query("max_neili") < 3000)
		return notify_fail("你的内力修为不够，怎能支持！？\n");
	if (me->query("neili") < 800)
		return notify_fail("你的真气不够了！\n");
	if (me->query("jingli") < 1000)
		return notify_fail("你的精力不够了！\n");

	if(me->query_encumbrance()/100 > me->query("neili") + cost)
		return notify_fail("你带这么重的包袱，走路都成问题，别说飞了！\n");

	if(query("exits/enter")) return notify_fail("有船不坐，你想扮Cool啊？\n");    
	
	if(!objectp(room = find_object(__DIR__"boat") )) return notify_fail("糟糕，船沉了！快通知巫师。\n");
	    
	if((int)room->query("exits/out") ) return notify_fail("江面太宽了，如果没有中途借力的地方根本没法飞越过去！\n"); 

	me->receive_damage("neili", 200);
	me->receive_damage("jingli", 100);
	tell_room(environment(me), HIC+me->name()+"紧了紧随身物品，紧跟着长袖飘飘，飞身跃渡黄河！\n" NOR, ({me}));
	write("你一提内息，看准了河中渡船位置，使出「一苇渡江」轻功想要飞越黄河。\n");
	me->move(__DIR__"boat");
	me->start_busy(3);
	if(me->query_encumbrance()/100 > me->query("neili") + cost
	 || me->query("neili") < 700 || me->query("jingli") < 500){
		write("你还想提气，却发现力不从心了。\n");
		tell_room(environment(me), HIC+me->name()+"长袖飘飘，从河面上飞跃过来，站在船上，大口大口喘着气！\n" NOR, ({me}));
		return 1;
	}
	tell_room(environment(me), HIC+me->name()+"长袖飘飘，从河面上飞跃过来，在船上一点，又向北跃出！\n" NOR, ({me}));
	write("你在江中渡船上轻轻一点，又提气飞纵向北岸。\n");
	me->move(SHIP_TO);
	tell_room(environment(me), HIC"只见"+me->name()+"长袖飘飘从对岸跃来，姿态潇洒地落在岸边。\n"NOR, ({me}));
	me->add("neili", -200);
	me->add("jingli", -100);
	return 1;
}
