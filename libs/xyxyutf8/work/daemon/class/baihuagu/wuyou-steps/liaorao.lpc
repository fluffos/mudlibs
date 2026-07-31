#include <ansi.h>
inherit SSERVER;
inherit F_CLEAN_UP;
 
void remove_effect(object me, int dodge,int re_damage)
{
	if( !me )  return;
        me->add_temp("apply/re_combat_effdamage", -re_damage);  
        me->add_temp("apply/re_spells_effdamage", -re_damage);  
        me->add_temp("apply/dodge",-dodge); 
        me->delete_temp("powerup");
        me->delete_temp("bhg_liaorao");
        me->set_temp("bhg_liaorao_time",time());
        message_vision(HIG"$N"HIG"渐感气力不支，不得不放慢脚步，周身的飞花渐渐散去。\n"NOR,me);
}

int valid_perform(object me)
{
        if( me->query_level()<20 )
        	return notify_fail("你的人物等级不够。\n");
	if( me->query("family/family_name")!="百花谷"
         && me->query("chushi/chushi_bhg")!="yes" )
		return notify_fail("你不能使用这项技能！\n");
        if( me->query_skill("dodge",1)<200
         || me->query_skill("wuyou-steps",1)<200 )
        	return notify_fail("你轻功还不够高明。\n");
        if(me->query_skill_mapped("force")!="brightjade-force")
                return notify_fail("百花缭绕必须配合明玉神功才能使用。\n");
        if( me->query_skill("force",1)<200
         || me->query_skill("brightjade-force",1)<200 )
        	return notify_fail("你的明玉神功不够纯熟。\n");
	return 1;                
}
 
int perform(object me, object target)
{
        int re_damage,dodge;

	if( !target ) 
		target = me;
	if( time()<me->query_temp("bhg_liaorao_time")+5 )
		return notify_fail("绝招用多就不灵了。\n");	
	if( !valid_perform(me) )
		return 0;	
        if( (int)me->query("force") < 200 )      
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");

        dodge = me->query_skill("dodge")/10;            
        re_damage=me->query_skill("force")/20;
        me->add("force", -100);
        message_vision(HIG"$N"HIG"略一提气，运起轻功，迎风起舞，只见片片飞花渐渐聚集过来，围绕在$P的周身盘旋。\n" NOR, me);
        me->add_temp("apply/re_combat_effdamage", re_damage);  
        me->add_temp("apply/re_spells_effdamage", re_damage);  
        me->add_temp("apply/dodge",dodge); 
        me->set_temp("powerup", 1);
        me->set_temp("bhg_liaorao/re_damage",re_damage);
        me->set_temp("bhg_liaorao/dodge",dodge);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, dodge,re_damage:), me->query_skill("wuyou-steps",1));
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：百花缭绕
        外功所属：无忧步法
        外功效果：一定时间内增强自身的闪避率，以及后限伤害反弹基数
                  不可叠加
                  状态结束后冷却5秒
        外功条件：
        	  百花谷(出师)弟子
        	  人物等级20级	
                  内力200点，消耗100点
                  基本轻功200级
                  无忧步法200级
                  基本内功200级
                  明玉神功200级
STR;
        me->start_more(str);
        return 1;
}

void remove()
{
	int i,re_damage,dodge;
	object me,*usr = users();
	if( i=sizeof(usr)>0 )
	{
		while(i--)
		{
			if( !usr[i] || !environment(usr[i])
			 || !objectp(usr[i]) )
				continue;
			if( usr[i]->query_temp("bhg_liaorao") )
			{
				me = usr[i];
				re_damage = me->query_temp("bhg_liaorao/re_damage");
				dodge = me->query_temp("bhg_liaorao/dodge");
        			me->add_temp("apply/re_combat_effdamage", -re_damage);  
        			me->add_temp("apply/re_spells_effdamage", -re_damage);  
        			me->add_temp("apply/dodge",-dodge); 
        			me->delete_temp("powerup");
        			me->delete_temp("bhg_liaorao");
        			me->set_temp("bhg_liaorao_time",time());
        			message_vision(HIG"$N"HIG"渐感气力不支，不得不放慢脚步，周身的飞花渐渐散去。\n"NOR,me);
			}
		}
	}
}