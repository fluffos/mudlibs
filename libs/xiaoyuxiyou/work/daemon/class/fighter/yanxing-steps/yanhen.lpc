// 雁过留痕 yanhen.c
#include <ansi.h>
inherit SSERVER;
inherit F_CLEAN_UP;
 
void remove_effect(object me, int x,int y);

int valid_perform(object me)
{
        if( me->query_level()<15 )
        	return notify_fail("你的人物等级不够。\n");
        if( me->query_skill("yanxing-steps",1)<150 )
        	return notify_fail("你轻功还不够高明。\n");	
        if(me->query_skill("dodge",1)<150) 
        	return notify_fail("你轻功还不够高明。\n");
        if( me->query_skill_mapped("dodge") != "yanxing-steps" )
		return notify_fail("你还没有施展雁行步法呢。\n");
	if( me->query("family/family_name")!="将军府" 
 	&& me->query("chushi/chushi_jjf")!="yes")
		return notify_fail("你不能使用这项技能！\n");
        if(me->query_skill_mapped("force")!="lengquan-force")
                return notify_fail("雁过留痕必须配合冷泉神功才能使用。\n");
        if( (int)me->query("force") < 200 )      
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");
	return 1;                
}
 
int perform(object me, object target)
{
        int x,y;
	if( !valid_perform(me) )
		return 0;	
	if( !target ) 
		target = me;
	if( target!=me )
		return notify_fail("雁过留痕只能对自己使用。\n");
	
	x = me->query_combat_damage();
	x/= 2;
	x+= 1;	

	y = me->query_skill("dodge");
	
        me->add("force", -100);
        message_vision(HIC"$N"HIC"长吸了一口气，顿时平心静气，对四周一举一动了如指掌。\n" NOR, me);
        me->add_temp("apply/attack",y);  
        me->add_temp("apply/combat_damage",-x);
        me->set_temp("powerup", 1);
        me->set_temp("jjf_yanhen/x",x);
        me->set_temp("jjf_yanhen/y",y);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, x,y:), me->query_skill("yanxing-steps",1)/5);
	return 1;
}
 
void remove_effect(object me, int x,int y)
{
	if( !me )  return;
        me->add_temp("apply/attack",-y);  
        me->add_temp("apply/combat_damage",x);
        me->delete_temp("powerup");
        me->delete_temp("jjf_yanhen");
        message_vision(HIC"$N"HIC"长吐了一口浊气。\n"NOR,me);
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：雁过留痕
        外功所属：雁行步法
        外功效果：一定时间内降低自身的物理伤害同时大幅度提高自身的命中率
                  不可叠加
        外功条件：
        	  将军府(出师)弟子
        	  人物等级15级	
        	  内功激发冷泉神功
                  内力200点，消耗100点
                  基本轻功等级 150 级
                  雁行步法等级 150 级
STR;
        me->start_more(str);
        return 1;
}

void remove()
{
	int x,y,i;
	object me,*usr = users();
	if( i=sizeof(usr)>0 )
	{
		while(i--)
		{
			if( !usr[i] || !environment(usr[i])
			 || !objectp(usr[i]) )
				continue;
			if( usr[i]->query_temp("jjf_yanhen") )
			{
				me = usr[i];
				x = me->query_temp("jjf_yanhen/x");
				y = me->query_temp("jjf_yanhen/y");
        			me->add_temp("apply/attack",-y);  
        			me->add_temp("apply/combat_damage",x);
        			me->delete_temp("powerup");
        			me->delete_temp("jjf_yanhen");
        			message_vision(HIC"$N"HIC"长吐了一口浊气。\n"NOR,me);
			}
		}
	}
} 