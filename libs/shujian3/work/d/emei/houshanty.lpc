// houshanty.c
// 后山炭窑
inherit ROOM;
#include <ansi.h>

int do_shaotan();
int do_puhuo(string arg);

void create()
{
	set("short", HIR "炭窑" NOR);
	set("long", @long
这里是一座用来烧炭的炭窑。但由于峨嵋弟子吃苦耐劳，这里没有像别的
炭窑那样一片零乱、黑得一塌糊涂，而是一切都井井有条。几个峨嵋俗家弟子
在这里忙忙碌碌。
long);
	set("outdoors", "峨眉山");
	set("exits",([
		"southwest":__DIR__"houshan",
	]));
	set("objects",([
		__DIR__"npc/kydizi" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_shaotan", "shaotan");
	add_action("do_puhuo", "pu");
}

int do_shaotan()
{
	int count;
	object me=this_player();
	if( !me->query_temp("emjob2/烧炭") || me->is_busy() || me->is_fighting() ) 
		return 0;
	if( (int)me->query_temp("emjob2/伐木") != 1) 
		return 0;
	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	count = (int)me->query_temp("emjob2/烧炭");
	if ( count == random(40) && !me->query_temp("emjob2/火星")){
		message_vision("$N正专心地烧炭，突然一个"HIR"火星"NOR"迸到$N的身上。\n", me);
		me->set_temp("emjob2/火星", 1);
		remove_call_out("get_fire");
		call_out("get_fire", 10, me);
	}
	message_vision("$N把选好的木料放入窑中,仔细地观察火候。\n", me);
	me->receive_damage("jing", 10 + random(20) );
	me->set_temp("last_damage_from", "烧炭累");
	if ( count == 1 ) {
		me->delete_temp("emjob2/伐木");
		me->delete_temp("emjob2/烧炭");
		message_vision("$N把烧好的木炭从窑中取出，交给看窑弟子。\n", me);
		tell_object(me,"劳累了一番，你伸了个懒腰，虽然有些疲倦，但心里却有一股暖意。\n");
		if(me->query_skill("linji-zhuang",1)) {
			count = 10 + random( uptime() - me->delete_temp("emjob2/uptime") ) / 2;
			if (count > 40) count = random((int)me->query_skill("force") ) + (int)me->query_int();
			me->add("combat_exp",5+random(10));
			me->add("potential",1+random(2));
			me->improve_skill("linji-zhuang", 200+random(50));
			if( me->query("potential")>me->query("max_pot"))
				me->set("potential",me->query("max_pot"));
			me->delete_temp("emjob2/uptime");
			me->start_busy(1);
		}
		return 1;
	}
	me->set_temp("emjob2/烧炭", count - 1);
	return 1;
}

void get_fire(object me)
{
	if( me->query_temp("emjob2/火星") ) {
		message_vision("$N一个没留神，迸到身上火星着了起来。\n", me);        
		tell_object(me,"你赶紧在身上扑火，火虽然灭了，但你也被烧得够呛。\n");
		me->delete_temp("emjob2/火星");
		me->unconcious();
	}
}

int do_puhuo(string arg)
{
	object me = this_player();
	if(!me->query_temp("emjob2/火星")) return 0;
	if(!arg) return 0;
	if(arg == "huo" || arg == "huoxing" || arg == "fire" || arg == "fire" || arg == "火星" || arg == "火" ) {
		me->delete_temp("emjob2/火星");
		remove_call_out("get_fire");
		message_vision("$N赶紧把身上的火扑灭了。\n", me);        
	}
	return 1;
}
