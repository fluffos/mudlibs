#include <ansi.h>

string find_snow(object);

string snow(object me)
{
	if( me->query_temp("block_msg/all"))
		return 0;
	//cant look while blocked
	
	if( random(20)<1 )
	{
		tell_object(me, HIR"突然间，你被积雪闪耀着的刺眼的光芒灼伤，只觉头痛欲裂，眼前什么也看不到了！\n"NOR);
		tell_room(environment(me), HIW + me->query("name") + "突然间步履摇晃，似乎什么也看不到了！\n"NOR, me);
		me->receive_damage("jing", 50);
		me->set_temp("block_msg/all",1);
		call_out("unblock", 40+random(40), me);
	}
	//snow blindness
	
	if( random(4)<1 )
		return find_snow(me);
	//can walk snow to improve dodge
	
	switch(random(3)) {
		case 0: return WHT"环顾四周，到处都是白皑皑的积雪。\n"NOR;
		case 1: return WHT"雪，雪，还是雪。\n"NOR;
		case 2: return WHT"洁白的雪地上零星的散落着几朵脚印。\n"NOR;
	}
}

void unblock(object me)
{
	me->delete_temp("block_msg/all");
	tell_object(me, HIG"慢慢的，你发现自己可以睁开眼了，只是眼睛似有砂子，疼痛流泪。\n"NOR);
	return;
}

string find_snow(object me)
{
	int skill = me->query_skill("dodge", 1);
	
	if( skill < 50 )
		return WHT"积雪厚厚的一层，若不是有前人踩出的路，只怕每一步都会陷下去无法前进。\n"NOR;
	if( skill > 200 )
		return WHT"积雪虽厚，你却毫不在意，施展出绝顶轻功，踏雪无痕。\n"NOR;
	
	add_action("walk_snow", "walk");
	return YEL"你突然发现在路旁的一片积雪上行走(walk)似乎可以用来练习轻功。\n"NOR;
}

int walk_snow(string arg)
{
	object me = this_player();
	
	if( !arg )
		return notify_fail("好好的路上走来走去干什么？\n");
	if( arg != "snow" && arg != "雪" && arg != "积雪" )
		return notify_fail("你要在哪里行走？\n");
	if( me->is_busy() )
		return notify_fail("你正忙着呢！\n");
		
	tell_object(me, "你提一口气，在积雪上小心的走了起来。\n");
	me->receive_damage("qi", 50);
	me->improve_skill("dodge", 4 * me->query("neili"));
	me->start_busy(6);
	
	call_out("destroy_snow", 6, me);
	
	return 1;
}

int destroy_snow(object me)
{
	me->improve_skill("dodge", 14 * me->query_skill("dodge", 1));
	tell_object(me, "你一路走下来，看着脚印回想方才的步法，轻功水平提高了！\n");
	remove_action("walk_snow", "walk");
	
	return 1;
}