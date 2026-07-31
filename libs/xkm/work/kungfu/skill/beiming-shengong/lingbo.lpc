//Cracked by Xuanyuan
//lingbo.c   洛神凌波

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

mapping default_dirs = ([
		  "north":        "北",
		  "south":        "南",
		  "east":         "东",
		  "west":         "西",
		  "northup":      "北边",
		  "southup":      "南边",
		  "eastup":       "东边",
		  "westup":       "西边",
		  "northdown":    "北边",
		  "southdown":    "南边",
		  "eastdown":     "东边",
		  "westdown":     "西边",
		  "northeast":    "东北",
		  "northwest":    "西北",
		  "southeast":    "东南",
		  "southwest":    "西南",
		  "up":           "上",
		  "down":         "下",
		  "out":          "外",
		  "enter":        "里",
]);

int exert(object me, object target)
{

	if( !target ) target = offensive_target(me);
/*
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("洛神凌波只能对战斗中用于逃跑。\n");
*/

	if( !me->is_fighting() || !target->is_fighting())
		return notify_fail("洛神凌波只能对战斗中用于逃跑。\n");

	if( me->query_skill_mapped("force") != "beiming-shengong" )
		return notify_fail("你所用的并非北冥神功，无法施展洛神凌波！\n");

	if( me->query_skill("beiming-shengong", 1) < 60 )
		return notify_fail("你的北冥神功火候未到，无法施展洛神凌波！\n");

	if( me->query_skill("dodge",1) < 100 )
		return notify_fail("洛神凌波需要精湛的轻功根底，方能有效施展！\n");

	if( me->query_skill("lingbo-weibu",1) < 100 )
		return notify_fail("你凌波微步修为不足，还不会使用洛神凌波！\n");

	if( me->query_skill_mapped("dodge") != "lingbo-weibu" )
		return notify_fail("你所用的并凌波微步，无法施展洛神凌波\n");

	if( (int)me->query("jingli") < 400 ) 
		return notify_fail("你的精力殆尽，哪里还能跑动半步。\n");

	message_vision(HIC "\n只见$N双眼一闭，使开凌波微步，左转右晃便已跳出战圈，随便找了个方向夺路而去。\n\n" NOR, me, target);

	me->add("jingli", -250);	
	call_out("run_away",0);
	me->set_temp("lingbo",1);
	return 1;
}

void run_away()
{
	object obj, me=this_player();
	object here = environment(me);
	string *dirs,dir,dest,target_dir;
	mapping exit;
	if(!me)return;
	if(!here || !objectp(here) )return;
	if(random(16) != 0) call_out("run_away",0);
	exit = here->query("exits");
	if( !exit ) return;
	dirs = keys(exit);
	dir = dirs[random(sizeof(dirs))];
	if(!dir)return;
	dest = exit[dir];

	if( !dest )return;

	if( !(obj = find_object(dest)) )
		call_other(dest, "???");

	if( !(obj = find_object(dest)) )
		return;

	if( !wizardp(me) && obj->query("short") == "巫师休息室" )
		return;

	if( obj->query("short") == "大沙漠" || obj->query("short") == "沙漠" || obj->query("short") == "茶亭" )
		return;

	if( !undefinedp(default_dirs[dir]) )
					 target_dir = default_dirs[dir];
		  else
					 target_dir = dir;

	message( "vision", "只见"+me->name()+"迈开两腿，夺路而走，一阵狂奔，即便消失不见。\n"NOR,environment(me), ({me}));

	if( me->move(obj) ) {
			message( "vision", "只见"+me->name()+"一阵狂奔跑过来。\n" NOR,environment(me), ({me}));
	}

}
