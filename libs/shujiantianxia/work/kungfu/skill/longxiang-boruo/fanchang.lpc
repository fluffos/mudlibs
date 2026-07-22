// fanchang.c 梵唱

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
#include <combat_msg.h>
#include <pktime.h>

int exert(object me, object target)
{
	object obj, weapon;
	int xf, sp, ap, curser;  
	string force;

	if( !target ) target = offensive_target(me);

	weapon = me->query_temp("weapon");  

	if( !weapon || weapon->query("skill_type") != "hammer" )
		return notify_fail("你未执法器，不能凝神梵唱。\n");

	if( weapon->query_amount() < 2 && weapon->query("id") != "fenghuo lun" && weapon->query("hammer_count") < 2 )
		return notify_fail("你需要二个轮子才能击打梵唱。\n");
	
	if(!objectp(obj = me->query_temp("armor/cloth")) ||
	(
		!obj->id("shisan longxiang") && !obj->id("longxiang jiasha")
	))
		return notify_fail("你未着龙象法袍，不能凝神梵唱。\n");

	if( !objectp(target) || target == me)
		return notify_fail("你想要唱给谁听？\n");

	if( !target->is_character() || target->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if( target->query("race") != "人类")
		return notify_fail(target->query("name") + "听不懂你的咒语！\n");

	if( (int)me->query("neili") < 5000 )
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_skill("xiangfu-lun",1) < 250 )
		return notify_fail("你的降伏法功力不够！\n");

	if( (int)me->query_skill("huanxi-chan", 1) < 180 )
		return notify_fail("你的密宗心法功力不够！\n");

	if( (int)me->query_skill("longxiang-boruo", 1) < 250 )
		return notify_fail("你的龙象般若功功力不够！\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("在这里不能唱。\n");

	if( target->query_temp("cursed", 1) )
		return notify_fail("此人已被降伏！\n");
	
        if ( me->query("no_pk") && userp(target) )
                return notify_fail("你已经金盆洗手，还是不要介入江湖恩怨吧。\n");

        if ( userp(me) && target->query("no_pk") )
                return notify_fail(target->name()+ "已经金盆洗手，得饶人处且饶人吧。\n");

        if ( pktime_limit(me, target) )
                return 0;

        if( meisdummy(me,target) )
                return notify_fail("死大米，一边凉快去。\n");
               
	if( userp(me) && userp(target) ) {
                target->set_temp("other_kill/"+me->query("id"), 1);
                
                log_file("ANSUAN", 
                        sprintf("%-18s fanchan %-18s",
                                me->name(1)+"("+capitalize(getuid(me))+")",
                                target->name(1)+"("+capitalize(getuid(target))+")"
                        ),
                        this_object(),
                );
        }
                                        
	me->start_exert(5, "梵唱");
	me->add("neili", - 400 + me->query_skill("huanxi-chan", 1));
	me->receive_damage("jingli",  - 250 + me->query_skill("huanxi-chan", 1) );
	message_vision( BLU"$N摇头晃脑，击打着手中的"NOR+weapon->query("name")+BLU"，口中背诵大乘佛经，夹杂以密宗六字咒。声音阴阳顿挫，有起有伏，暗含音律。\n" NOR, me);
	tell_object(target,  "你觉得那密咒比鬼哭还难听，脑袋里一团絮乱，眼前一堆鬼影在乱跳，越发感到恐惧。\n");

	xf = me->query_skill("xiangfu-lun", 1) + me->query_skill("longxiang-boruo", 1) + me->query_skill("huanxi-chan", 1);
	xf = xf + me->query("con")*10 + me->query("str")*10;
	ap = target->query_skill("parry") + target->query_skill("force");
	ap = ap + target->query("con")*15  + target->query("int")*10; 
	sp = xf * 2 + me->query("con")*15 + me->query("str")*10;
	sp += me->query("combat_exp")/5000 + me->query("neili")/10;
	ap += target->query("combat_exp")/5000 + target->query("neili")/10;
	
	message("wizard",sprintf(HIG"测试信息：lxbr'fanchang 命中：%d，防御：%d \n"NOR,sp,ap),
		environment(me)?filter_array(all_inventory(environment(me)),(:
		$1->query("env/combat")=="verbose"
		:)):0
	);
		
	if( random(sp) > ap*3/4 && !target->query("no_sing") ) {
		message_vision(HIR"$n只觉得$N的密咒夹杂着阵阵内力汹涌而至，$n顿时头晕眼花，胸气阻塞，浑身使不出劲来。\n"NOR, me, target);
		target->remove_all_killer();
		target->start_busy(3 + random(2));
		me->set_temp("curser", 1);
		me->start_busy(1 + random(3));
		curser = me->query_skill("huanxi-chan", 1) + me->query_skill("force")/5;
		target->add_temp("apply/attack", -curser );
		target->set_temp("cursed", curser );
		target->add_temp("apply/strength", -me->query_con()/2);
		target->set_temp("cursed_str", me->query_con()/2);

		target->set("jiali", 0);
		target->apply_condition("no_enforce", (me->query_skill("huanxi-chan")/20)
			+ 1 + target->query_condition("huanxi-chan"));

		if( (int)target->query("combat_exp") > me->query("combat_exp")/2 && userp(target) ) {
			me->improve_skill("force", me->query("int")*10);
		}
		call_out("del_sung", 15 + me->query_skill("huanxi-chan", 1)/10, me, target);
		return 1;
	} else {
		if( !stringp(force = to_chinese(target->query_skill_mapped("force"))) ) force = "内功";
		message_vision(HIY"$n潜运"+force+"，催动内力与$N念出的密咒抵抗，顿时四周的声调变的更为嘈杂，难以忍受。\n"NOR, me, target);
		me->start_busy(3+random(3));
		target->start_busy(1);
		if( !target->is_killing(me) ) target->kill_ob(me);
		return 1;
	}
}

void del_sung(object me, object target)
{
	if( !target ) return;

	if( target->query_temp("cursed") ) {
		target->add_temp("apply/attack", target->query_temp("cursed"));
		target->delete_temp("cursed");		
	}
	if( target->query_temp("cursed_str") ) {
		target->add_temp("apply/strength", target->query_temp("cursed_str"));
		target->delete_temp("cursed_str");
	}
	
	if( target->query_leader() ) target->set_leader(0);
	message_vision(YEL"嘈杂的音律渐渐消失，$n慢慢恢复了精神，不在受到$N的迷惑了。\n"NOR, me, target);
}

string exert_name(){ return HIB"梵唱"NOR; }

int help(object me)
{
        write(HIB"\n龙象般若功之「梵唱」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 5000 以上；
                龙象般若功等级 250 以上；
                金刚降伏轮等级 250 以上；
                欢喜禅等级 180 以上；
                必须装备两个法轮为兵器；
                穿着龙象袈裟。

HELP
        );
        return 1;
}
