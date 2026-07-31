#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{
	string msg,succ_msg;
	int damage;
	
	if( me->query_level()<30 )
		return notify_fail("你的人物等级不够。\n");
        if(me->query("family/family_name")!="陷空山无底洞"
        && me->query("chushi/chushi_wdd")!="yes")
		return notify_fail("你不能使用这项技能！\n");
	if( (int)me->query("mana") < 500 )
                return notify_fail("你的法力不够。\n");
	if( me->query_skill("yaofa",1)<300 )
		return notify_fail("你的妖法等级不够。\n");
	if( me->query("sen")<300 )
		return notify_fail("你现在精神不济。\n");
			
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
     		return notify_fail("你要对谁施展这一招？\n");
     	
     	me->add("mana",-200);
     	me->receive_damage("sen",150);
     				
	msg = "$N深深地吸了一口气,突然吐出一团五彩斑斓的桃花瘴，翻腾游拽飞向$n！\n";
	succ_msg = "$n只觉一阵天旋地转,差点没晕了过去。\n";
	me->set_temp("pfm_msg",1);
	me->set_temp("pfm_color",HIR);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg,0,me->query_skill("spells"));
	me->set_temp("pfm_msg",0);
	me->set_temp("pfm_color",0);
	if( damage<1 )
		message_combatd(HIC"$n"HIC"识得美丽背后的危险，忙闪开一旁，躲开了这团瘴气。\n"NOR,me,target);
	else	target->receive_wound("sen",damage/2+1,me,TYPE_CAST);
	me->start_busy(2);
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：桃花瘴
        法术所属：妖法
        法术效果：给予对方精神前后限的打击
        	  自身busy 2 秒
        法术条件：
                  无底洞(出师)弟子
        	  人物等级30级
                  法力500点，消耗200点
                  精神300点，消耗150点
                  妖法300级
                  
STR;
        me->start_more(str);
        return 1;
}