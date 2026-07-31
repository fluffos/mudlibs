#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int valid_cast(object me)
{
	if(me->query("family/family_name") != "将军府")
        	return notify_fail("这是将军府不传之密！\n");
	if( me->query_level()<35 )
		return notify_fail("你的人物等级不够。\n");        
        if( (int)me->query("mana") < 800 )
                return notify_fail("你的法力不够了！\n");
	if( me->query("kee")<300 )
		return notify_fail("你现在气血不足，画不了符。\n");                
	if( time()<me->query_temp("jjf_light")+10 )
		return notify_fail("你刚刚画过「神霄雷法符」。\n");
	if( me->query_skill("baguazhou",1)<350 )
		return notify_fail("你的八卦咒等级不够。\n");	
	return 1;
}	

int cast(object me, object target)
{       
	int damage;
        object seal;
	string msg,succ_msg;
	
	if( !valid_cast(me) )
		return 0;
	seal = present("paper seal",me);
	if( !seal || base_name(seal)!="/obj/paper_seal" )
		return notify_fail("你身上没有桃符纸，如何画符？\n");
	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me
 	|| !me->is_fighting(target) )  
        	return notify_fail("你要对谁祭「神霄雷法符」？\n");	
        	
        message_vision("$N咬破手指，伸手在桃符纸上画了几下。\n", me);
        me->add("mana", -300);
	me->receive_damage("kee",300,me);
	me->set_temp("jjf_light",time());
	if( seal->query_amount()<2 )
		destruct(seal);
	else	seal->add_amount(-1);	
	
	msg = HIC "$N"HIC"大喊一声“着”，手一挥，祭出了一张神霄雷法符！\n神霄雷法符「呼」地一下飞到半空，只见风云突变，几声闷雷在$n"HIC"耳边乍起。\n"NOR;
	succ_msg = HIR "$n"HIR"被雷声震的眼冒金星，心神不定，差点跌倒在地！\n" NOR;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg,0,me->query_skill("spells"));
	me->set_temp("pfm_msg",0);
	if( damage<1 )
		message_combatd(HIC"谁知$n"HIC"毫无反应。\n" NOR, me,target);
	else
	{
		if( !target->is_hunluan() )
			target->start_hunluan(me->query_skill("spells")/100,HIR"你被"+me->name()+HIR"的神霄雷法符震的手足无措。\n"NOR);
	}	
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：神霄雷法符
        法术所属：八卦咒
        法术效果：带固定伤害的法术伤害
        	  带使对方混乱效果
                  冷却时间 10 秒
        法术条件：
                  将军府弟子
        	  人物等级35级
        	  需要桃符纸
                  法力800点，消耗300点
                  气血300点，消耗300点
                  八卦咒350级
STR;
        me->start_more(str);
        return 1;
}