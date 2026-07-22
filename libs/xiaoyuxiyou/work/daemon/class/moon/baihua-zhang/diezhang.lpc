#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int valid_perform(object me)
{
        if(me->query("family/family_name") != "月宫")
        	return notify_fail("「叠掌」是月宫不传之密！\n");
	if( me->query_level()<10 )
		return notify_fail("你的人物等级不够。\n");
	if( me->query_skill("baihua-zhang",1)<100 )
		return notify_fail("你的百花掌级别还不够！\n");
	if( me->query_skill("moonforce",1)<100 )
		return notify_fail("你的圆月心法级别还不够！\n");
	if( me->query("force")<400 )
		return notify_fail("你的内力不足。\n");
	if( time()<me->query_temp("moon_diezhang")+8 )
		return notify_fail("绝招用多就不灵了。\n");		
	if( (int)me->query_temp("diezhang") )
		return notify_fail("你已经在使用叠掌了。\n");
	return 1;
}	

int perform(object me, object target)
{
	int t,lvl,p,damage;
	
	if( !valid_perform(me) )
		return 0;
		
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || target->is_corpse()
         || !me->is_fighting(target) )
                return notify_fail("你要对谁施展这一招？\n");

	me->add("force",-100);
	me->set_temp("moon_diezhang",time());
	me->set_temp("diezhang",1);
	me->reset_action();
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
	me->delete_temp("diezhang");
	me->reset_action();
	
	if( me->is_knowing("moon_diezhang")<=3 )
	{
		lvl = 20+me->is_knowing("moon_diezhang")*3;
		p = (me->query_int()+me->query_kar())/4;
		p = random(p);
		if( p>lvl
		 && time()>=me->query("family/last_diezhang")+3600 )
		{
			tell_object(me,HIY"【师门】你在战斗中福至心灵，对「叠掌」的领悟提升了！\n"NOR);
			me->set_knowing("moon_diezhang",1);
			me->set("family/last_diezhang",time());
			me->save(1);
			lvl = me->is_knowing("moon_diezhang");
			tell_object(me,HIY"【师门】你目前「叠掌」的领悟程度为 "HIR+(lvl)+HIY" ！\n"NOR);
		}
	}
		
	if( damage<1 )
		return 1;
	if( !me || !living(me) || !target 
	 || !me->is_killing(target->query("id")) ) 
		return 1;
	lvl = me->is_knowing("moon_diezhang");
	if( !userp(me) || wizardp(me) )
	{
		if( me->query_level()<40 )
			lvl = 1;
		else if( me->query_level()<60 )
			lvl = 2;
		else if( me->query_level()<90 )
			lvl = 3;
		else	lvl = 4;		
	}
	if( lvl>0 )
	{
		message_combatd(HIC"\n$N"HIC"内息运转，掌上发出阵阵潮汐之声，太阴之力生生不息，一击未完，后击又至！\n"NOR,me,target);
		message_combatd(HIR"顿时掌风化作道道气旋，将$n"HIR"双足缠缚，动弹不得！\n"NOR,me,target);
		if( (int)target->query_busy()>0 )
			target->start_busy((int)target->query_busy()+1);
		else	target->start_busy(1+random(2));	
	}
	if( lvl>1 )
	{
		message_combatd(HIG"\n$N"HIG"双掌一合，圆月心法催动太阴之力，顿时涛声不绝，震耳欲聋！\n"NOR,me,target);
		message_combatd(HIR"只见道道气旋化作点点气针，瞬间沉入$n"HIR"气海之中！\n"NOR,me,target);
		t = target->query_temp("no_exert/start")+target->query_temp("no_exert/time")-time();
		if( t>0 )
			t+= 6;
		else	t = 6;
		target->set_temp("no_exert",([
			"start" : time(),
			"time"  : t,
			"msg"	: HIY"\n你被"+me->name()+"封住了气海，内息暂时无法运作。\n"NOR,
		]));		
	}
	if( lvl>2 )
	{
		message_combatd(HIY"\n$N"HIY"双掌再分，波涛之声顿时化作惊涛骇浪，响彻天地！\n"NOR,me,target);
		message_combatd(HIR"$n"HIR"体内太阴之气立刻逆体而上，将$p泥丸宫狠狠定住！\n"NOR,me,target);
		t = target->query_temp("no_cast/start")+target->query_temp("no_cast/time")-time();
		if( t>0 )
			t+= 5;
		else	t = 5;
		target->set_temp("no_exert",([
			"start" : time(),
			"time"  : t,
			"msg"	: HIY"\n你被"+me->name()+"封住了泥丸，法术暂时无法调动。\n"NOR,
		]));		
	}
	if( lvl>3 )
	{
		message_combatd(HIY"\n$N"HIY"背后隐现圆月异象，飞快旋转，一股浓厚的太阴之气澎湃而出！\n"NOR,me,target);
		message_combatd(HIR"$n"HIR"顿时只觉周身四周空气好似凝固一般，举步维艰！\n"NOR,me,target);
		t = target->query_temp("no_perform/start")+target->query_temp("no_perform/time")-time();
		if( t>0 )
			t+= 5;
		else	t = 5;
		target->set_temp("no_perform",([
			"start" : time(),
			"time"  : t,
			"msg"	: HIY"\n你被"+me->name()+"封住了周身元气，动弹不得。\n"NOR,
		]));
		t = target->is_blind();
		if( t>0 )
			t+= 3;
		else	t = 3;	
		target->start_blind(t,HIY"\n你被"+me->name()+"封住了周身元气，动弹不得。\n"NOR);
	}
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：叠掌
        外功所属：百 花 掌
        外功效果：以太阴之气模拟潮汐之力，给予对方一击
        	  共四叠，一叠封身，二叠封气，三叠封神，四叠封元。
        	  后三叠需使用此外功的过程中触发领悟	
                  使用后冷却8秒
        外功条件：
        	  月宫弟子
        	  人物等级 10 级
                  内力400点，消耗100点
                  百 花 掌 100 级
                  圆月心法 100 级
STR;
        me->start_more(str);
        return 1;
}
