//火魂附身
//requirement:huomoforce,huoyun-qiang all over 60
#include <ansi.h>
inherit SSERVER;
inherit F_CLEAN_UP;
 
void remove_effect(object me, int p);
 
int perform(object me, object target)
{
	object weapon;
	int p;
        
        if(me->query("family/family_name")!="火云洞")
  		return notify_fail("「火魂附身」只有火云洞门人才可以用！\n");
	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");
	
	if( !target )
		target = me;	
	if( me->is_fighting(target) || target->is_fighting(me) )
		return notify_fail("他现在是你的对手。\n");
	if( target->query_temp("powerup") )
		return notify_fail((target==me?"你":"对方")+"已经被祝福了，不能再使用「火魂附身」。\n");	
	if( target->is_fighting() && target!=me )
		return notify_fail("对方现在正忙呢。\n");	
	if( me->query_skill("huomoforce",1)<200 
	 || me->query_skill_mapped("force")!="huomoforce" )
		return notify_fail("你的火魔心法不够纯熟。\n");
	if( me->query_skill("huoyun-qiang",1)<200 
	 || me->query_skill_mapped("spear")!="huoyun-qiang" )
		return notify_fail("你的枪法不够纯熟。\n");
        if( (int)me->query("force") < 300 )      
                return notify_fail("你的内力不够。\n");
	
	if( me==target )
		message_vision(HIR"$N"HIR"哞的一声吼，运力于臂，枪上加力，要枪一摆，只见$P四周烈火重重，火焰像一条巨龙般盘旋在其四周。\n" NOR, me);
	else	message_vision(HIR"$N"HIR"哞的一声吼，运力于臂，枪上加力，朝$n"HIR"一指，只见$p四周烈火重重，火焰像一条巨龙般盘旋在其四周。\n" NOR, me,target);
	if( me->query_skill("huoyun-qiang",1)<350 )
 		p = target->query_combat_damage()/10+1;
 	else if( me->query_skill("huoyun-qiang",1)<500 )
 		p = target->query_combat_damage()*3/20+1;
 	else	p = target->query_combat_damage()/5+1;
 	me->add("force", -150);
 	target->add_temp("apply/combat_damage",p);
 	target->set_temp("powerup",1);
 	target->set_temp("kusong_huohun",p);
 	call_out("remove_effect", me->query_skill("huoyun-qiang",1)/15,target,p);
 	me->start_busy(3);
	return 1;
}
 
void remove_effect(object me, int p)
{
	if( me )
	{
        	me->add_temp("apply/combat_damage", -p);
        	me->delete_temp("powerup");
        	me->delete_temp("kusong_huohun");
        	message_vision(HIR"$N"HIR"周身的火龙渐渐淡去了。\n"NOR,me);
	}
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：火魂附身
        外功所属：火云枪
        外功效果：一定时期内使对象物理攻击提高10%
                  火云枪350级提高15%
                  火云枪500级提高20%
                  自身busy 3 秒
                  不能与增益性状态叠加
        外功条件：
        	  火云洞弟子
        	  人物等级20级	
        	  内力300点，消耗150点
                  火云枪 200 级
                  火魔心法 200 级
STR;
        me->start_more(str);
        return 1;
}

