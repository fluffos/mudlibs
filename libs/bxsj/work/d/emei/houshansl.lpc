// houshansl.c
// 后山树林
inherit ROOM;
#include <ansi.h>

int do_famu();
int do_duoshan();

void create()
{
	set("short", HIG "后山树林" NOR);
	set("long", @long
这里是峨嵋后山上的一片成材的树林，这里的林木茂密，有很多树木可以
用作炭材。西面是一块空地，北面是一条通往山下的一条小路。
long);
	set("outdoors", "峨眉山");
	set("exits",([
             "west":__DIR__"houshan",
             "northdown":__DIR__"houshanxl3",
	]));
	setup();
}

void init()
{
	add_action("do_famu", ({"famu", "kanshu"}));
	add_action("do_duoshan", "duoshan");
}


int do_famu()
{
	int count;
	object weapon, me=this_player();
	if( !me->query_temp("emjob2/伐木") || me->is_busy() || me->is_fighting() ) 
		return 0;
	if (!objectp(weapon = me->query_temp("weapon")) 
	 || weapon->query("id")!= "axe")
		return 0;
	count = (int)me->query_temp("emjob2/伐木");
	if ( count == random(40) && !me->query_temp("emjob2/躲闪")){
		message_vision("$N正专心地砍伐树木，突然一棵大树倒了，向$N的身上砸来。\n", me);
		me->set_temp("emjob2/躲闪", environment(me));
		remove_call_out("get_beat");
		call_out("get_beat", 10, me);
	}
	message_vision("$N举起手中的斧头，向一棵选好的大树砍去。\n", me);
	me->receive_damage("jingli", 15 + random(20) );
	me->set_temp("last_damage_from", "伐木累");
	if (me->query("potential") && random(10) > 5){
		me->improve_skill("linji-zhuang", me->query_int());
		me->add("potential", - random(2));
	}
	if ( count == 1 ) {
		message_vision("$N把砍好的炭木捆了起来收好。\n", me);
		return 1;
	}
	me->set_temp("emjob2/伐木", count - 1);
	return 1;
}

void get_beat(object me)
{
	if( me->query_temp("emjob2/躲闪") == environment(me) ) {
		message_vision("$N一个没留神，被倒下的大树砸到身上。\n", me);        
		me->delete_temp("emjob2/躲闪");
		me->unconcious();
	}
	else message_vision("一棵大树轰然倒地。\n", me);
}

int do_duoshan()
{
	object me = this_player();
	if(!me->query_temp("emjob2/躲闪")) return 0;
	remove_call_out("get_beat");
	me->delete_temp("emjob2/躲闪");
	message_vision("$N一纵身躲开了砸向自己的大树。\n", me);        
	return 1;
}
