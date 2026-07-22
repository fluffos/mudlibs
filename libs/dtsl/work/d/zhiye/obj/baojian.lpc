// baojian.c 定制宝剑
// by augx@sj  9/11/2001

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIY"定制宝剑"NOR, ({ "dingzhi baojian","baojian","sword","jian" }));
	set_weight(9000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄由客人定制的精钢剑。需要人送(song)给客户。\n");
		set("value", 1500);
		set("no_give", 1);
		set("no_get", 1);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(25);
	setup();
}

void init()
{
	add_action("do_give","song");
}

void destroying(object obj)
{     
	if (!obj) return;
	destruct(obj);
}

int do_give(string arg)
{
	object me = this_player() , room , target;
	
	if(!arg) return notify_fail("你要把宝剑送给谁？\n");
	if(!(int)me->query("worker/job2"))
		return notify_fail("你要把宝剑送给谁？\n");			
	if( !objectp(room = environment(environment(this_object())) ))
		return notify_fail("你要把宝剑送给谁？\n");
	if( !objectp(target = present(arg, room)) )
		return notify_fail("你要把宝剑送给谁？\n");
	if( me->query("worker/job2_target")!=target->query("name") )
		return notify_fail("这不是你要送货的对象！\n");
	if( me->query("worker/job2_room")!=base_name(room) )
		return notify_fail("这不是你要送货的对象！\n");
	if((int)me->query("worker/job2_far")>0) {
		if( target->query("player")!=me->query("id") )
			return notify_fail("这不是你要送货的对象！\n");
	}
	
	message_vision(HIY"$N把刚刚打造好的定制宝剑送给$n。\n"NOR, me,target);
	
	me->set("worker/job2_finish",1);
	if((int)me->query("worker/job2_far")>0) target->finish();
	call_out("destroying", 1, this_object());	
	return 1;
}