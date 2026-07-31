//魔焰闪空斩
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{
	int p,damage,i;
	object *enemy,seal;
	string msg,succ_msg;
	
	if( me->query_level()<60 )
		return notify_fail("你的人物等级不够。\n");      
	if(me->query("family/family_name")!="蜀山派")
        	return notify_fail("你不是蜀山弟子，不能使用这项技能！\n");
        if((int)me->query("mana") < 500 )
                return notify_fail("你的法力不够！\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("你无法集中精力！\n");
	if((int)me->query_skill("tianshi-fufa", 1) <600)
		return notify_fail("你的天师符法不够娴熟。\n");
	if( time()<me->query_temp("shushan_zhan")+5 )
		return notify_fail("你不能频繁使用「魔焰闪空斩」。\n");
	seal = present("paper seal",me);
	if( !seal || base_name(seal)!="/obj/paper_seal" )
		return notify_fail("你身上没有桃符纸，如何施「魔焰闪空斩」？\n");
		
	me->clean_up_enemy();                
 	if( !me->is_fighting() ) 
                return notify_fail("「魔焰闪空斩」只能在战斗中使用。\n");
	enemy = me->query_enemy();
	if( !intp(i=sizeof(enemy)) 
	 || i<1 )
		return notify_fail("「魔焰闪空斩」只能战斗中使用。\n");
	if( seal->query_amount()<i )
		return notify_fail("你身上的桃符纸不够"+chinese_number(i)+"张。\n");			
		
	message_vision(HIR"\n$N"HIR"一脸肃杀之气，抬手仍出一叠天师符「呼」地一下飞到半空！\n"NOR,me);
	msg = HIR"但见天师符霞光一闪，转眼间组成"+chinese_number(i+1)+"个相互重叠的阵符，在半空中滴溜溜直转！\n"NOR;
	message_combatd(msg,me);			
        me->add("mana", -300);
        me->set_temp("shushan_zhan",time());
        me->set_temp("pfm_msg",1);
        me->receive_damage("sen", 200);
        if( seal->query_amount()<i )
        	destruct(seal);
        else	seal->add_amount(-i);	
        damage = 2500;
        damage+= ((int)me->query_skill("tianshi-fufa,1")-600)/30;
        //符水	符类法术伤害+5%
	if( me->query_skill("fushui",2)>100 )
	{
		p = (me->query_skill("fushui",1)-100)/150+5;
		damage = damage*(100+p)/100;
	}
	
	msg = HIY"\n阵符上金光一闪，虚空中顿现一把丈许巨刃，开天辟地般斩向$n"HIY"！\n"NOR;
	succ_msg = HIR"$n"HIR"胆战心惊，只能眼睁睁的看着巨刃凌空劈下，顿时溅起一片血花！\n"NOR;
	for(i=0;i<sizeof(enemy);i++)
	{
		target = enemy[i];
		if( !target || !target->is_character()
         	  || target->is_corpse()
         	  || target==me
         	  || !me->is_fighting(target) )
			continue;
		message_combatd(msg,me,target);	
		damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,0,succ_msg,0,damage,"kee");
		if( damage<1 )
		{
			message_combatd(HIC"$n"HIC"朝$N"HIC"哈哈一笑：米粒之珠，也放光华？却是轻松闪过。\n"NOR,me,target);
			me->add_temp("shushan_zhan",1);
		}
	}
	me->delete_temp("pfm_msg");
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：魔焰闪空斩
        法术所属：天师符法
        法术效果：对在场的全体敌人进行带固定伤害的符攻击
        	  使对方气血减少
                  冷却时间 5 秒，每未命中一个增加 1 秒冷却
        法术条件：
                  蜀山派弟子
        	  人物等级60级
        	  需要桃符纸
                  法力500点，消耗300点
                  精神300点，消耗200点
                  天师符法600级
STR;
        me->start_more(str);
        return 1;
}
