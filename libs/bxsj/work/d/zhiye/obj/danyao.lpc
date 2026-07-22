// danyao.c 
// by augx@sj  3/4/2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"丹药"NOR, ({ "dan yao","danyao" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗由药店老掌柜炼制的丹药，也不知有何功效。需要人送(song)给客户。\n");
		set("value", 1500);
		set("no_give", 1);
		set("no_get", 1);
	}
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
	
	if(!arg) return notify_fail("你要把丹药送给谁？\n");
	if(!(int)me->query("worker/djob"))
		return notify_fail("你要把丹药送给谁？\n");			
	if( !objectp(room = environment(environment(this_object())) ))
		return notify_fail("你要把丹药送给谁？\n");
	if( !objectp(target = present(arg, room)) )
		return notify_fail("你要把丹药送给谁？\n");
	if( me->query("worker/djob_target")!=target->query("name") )
		return notify_fail("这不是你要送货的对象！\n");
	if( me->query("worker/djob_room")!=base_name(room) )
		return notify_fail("这不是你要送货的对象！\n");
	if((int)me->query("worker/djob_far")>0) {
		if( target->query("player")!=me->query("id") )
			return notify_fail("这不是你要送货的对象！\n");
	}
	
	message_vision(HIY"$N把药店掌柜炼制的丹药送给$n。\n"NOR, me,target);
	
	me->set("worker/djob_finish",1);
	if((int)me->query("worker/djob_far")>0) target->finish();
	call_out("destroying", 1, this_object());	
	return 1;
}