// tieqiao.c

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void set_status(int i);
int query_status();

void create()
{
	set_name("铁锹", ({ "tieqiao", "tie qiao", "qiao" }));
	set_weight(15000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄铁锹。\n");
		set("olong", "这是一柄铁锹。可以用来采矿(caikuang)。\n");
		set("value", 5000);
		set("material", "steel");
		set("wield_msg", "$N拿起一柄$n。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
		set("worker_tool",1);
	}
	set("used",75);
	set("oused",75);
	init_staff(20);
	set_status(75);
	set("stime",time());
	setup();
}

void init()
{
	add_action("do_find","xunzhao");
	add_action("do_find","find");
	add_action("do_find","caikuang");
}

void set_status(int i)
{
	int j;
	j = (int)(i*100/query("oused"));
	if(j>90) set("long",query("olong")+"看起来还是完好的。\n");
	else if(j>50) set("long",query("olong")+"看起来已经用过一段时间了。\n");
	else if(j>20) set("long",query("olong")+"看起来已经有些破损了。\n");
	else if(j>0) set("long",query("olong")+"看起来就要坏了。\n");
	else set("long",query("olong")+"看起来已经坏掉了。\n");
	set("used",i);
}

int query_status()
{
	return query("used");
}

void use()
{
	object me = environment(this_object());
	if( query_status()<=0 ) return;
	if( query_status()>2 && (time()-query("stime"))>7200 ) {
		tell_object(me,"你的"+query("name")+"似乎有些生锈了！\n");
		set_status(2);
	}
	set_status(query_status()-1);
	if( query_status()<=0 ) {
		if( objectp(me) && userp(me) )
			tell_object(me,"你的"+query("name")+"坏掉了！\n");
		broken("坏掉的");
	}
}

int do_find(string arg)
{
	object me = this_player() , room , weapon;
	int delay;

	if(arg!="kuangshi") return 0;
	if( !(int)me->query("worker/job1") ) return 0;
	if( !objectp(weapon=me->query_temp("weapon")) || weapon!=this_object() ) return 0;
	if( me->is_busy() ) return notify_fail("你正忙着呢！\n");

	message_vision(HIY"$N仔细地搜索矿石的踪迹......\n\n"NOR, me);

	room = environment(me);
	if( me->query("worker/job1_room") != base_name(room) ) {
		message_vision(HIY"可惜什么都没有找到。\n"NOR, me);
		me->start_busy(1+random(3));
	}
	else {
		message_vision(HIY"似乎有所发现.....\n"NOR, me);
		delay = 10+random(20);
		if(wizardp(me) && me->query("env/test")) delay=3;
		me->start_busy(delay);
		call_out("find_finish",delay,me);
	}

	return 1;
}

void find_finish(object me)
{
	object obj;

	if( !objectp(me) || !userp(me) ) return;

	message_vision(MAG"$N从土里挖出一块从来没有见过的矿石！\n"NOR, me);

	me->set("worker/job1_room","");
	obj = new(__DIR__"kuangshi");
	if(!obj) return;
	obj->set_level(11);
	obj->set("findby",me->query("id"));
	if( !obj->move(me) ) destruct(obj);
	use();
}
