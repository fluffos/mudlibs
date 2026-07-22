// 离火三重
// yangwl 1/10/2001  可以加上门派限制
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        
        if( me->query_level()<25 )
        	return notify_fail("你的人物等级不够。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
         || ( weapon->query("skill_type")!="spear" && weapon->query("use_apply_skill")!="spear" ) )
		return notify_fail("你使用的武器不对。\n");
	if( me->query("kee")<200 )
		return notify_fail("你气血不畅。\n");			
	if( me->query("family/family_name")!="火云洞" 
	 && me->query("chushi/chushi_kusong")!="yes")
		return notify_fail("你不能使用这项技能！\n");
	if(me->query("force") < 300)
		return notify_fail("你的真气不够，不要勉强了！\n"); 
	extra = me->query_skill("huoyun-qiang",1);               
        if(extra < 250)
		return notify_fail("你的火云枪法还不够纯熟！\n");
	if( me->query_skill("huomoforce",1)<250 )
		return notify_fail("你的火魔心法不够熟练。\n"); 
	
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail(HIR"「离火三重」"NOR"只能对战斗中的对手使用。\n");
        
	me->add("force",-150);
	me->receive_damage("kee",100,me);
              
        me->add_temp("apply/attack",extra/10);
        me->add_temp("apply/combat_damage",extra/3);
        msg = HIR"$N"HIW"手中$w"HIR"突然像着火一般，“砰”地炸出一团紫红色的火焰，绕着通红透亮的枪身燃烧起来！！“刷”地拉出一道火红中映着紫焰的流光，哗啦啦地就是一片遮天的火舌，往$n"HIR"的头上盖去！\n"NOR;
        me->set_temp("pfm_msg",1);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_PERFORM,msg,0,"头部");
        me->set_temp("pfm_msg",0);
        
        msg = HIR"\n$N"HIR"全身真气外放，衣衫冉冉飘动，双眸倏转妖红！\n"NOR;
        me->set_temp("pfm_msg",1);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_PERFORM,msg);
        me->set_temp("pfm_msg",0);
        
        msg = HIR"\n$N"HIR"手中$w"HIR"内所有阳气已是内燃敛收，放出肉眼难以直视的青白光华！\n"NOR;
        me->set_temp("pfm_msg",1);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_PERFORM,msg);
        me->set_temp("pfm_msg",0);
        
        me->add_temp("apply/attack",-extra/10);
        me->add_temp("apply/combat_damage",-extra/3);

        me->start_busy(2);
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：离火三重
        外功所属：火云枪
        外功效果：给予对方三次高伤害的物理攻击
                  自身busy 2 秒
        外功条件：
        	  火云洞(出师)弟子
        	  人物等级25级	
        	  内力300点，消耗150点
        	  气血200点，消耗100点
                  火云枪 250 级
                  火魔心法 250 级
STR;
        me->start_more(str);
        return 1;
}