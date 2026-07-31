// 幻化鬼影 guiying.c
#include <ansi.h>
inherit SSERVER;
inherit F_CLEAN_UP;
 
void remove_effect(object me, int amount);
void remove_effect2(object me, int amount);
 
int perform(object me, object target)
{
        int my_p,his_p;
        if( me->query_level()<10 )
        	return notify_fail("你的人物等级不够。\n");
        if( me->query_skill_mapped("dodge") != "ghost-steps" )
		return notify_fail("你还没有施展鬼影迷踪呢。\n");
	if( me->query("family/family_name")!="阎罗地府"
         && me->query("chushi/chushi_hell")!="yes" )
		return notify_fail("你不能使用这项技能！\n");
        if( me->query_skill("ghost-steps",1)<100 ) 
        	return notify_fail("你鬼影迷踪还不够高明。\n");
        if(me->query_skill_mapped("force")!="tonsillit")
                return notify_fail("幻化鬼影必须配合摄气诀才能使用。\n");
        if( me->query_skill("tonsillit",1)<100 )
        	return notify_fail("你的摄气诀不够纯熟。\n");
        if( (int)me->query("force") < 200 )      
                return notify_fail("你的内力不够。\n");
	if( me->query_temp("hell_guiying") )
		return notify_fail("你已经幻化作鬼影了。\n");
	if( !target
 	 || !target->is_character()
 	 || target->is_corpse()
 	 || target==me 
 	 || !me->is_fighting(target) )
        	return notify_fail("你要对谁使用幻化鬼影?\n");
        	
        message_vision(HIB"$N"HIB"突然加快步法，化作一团烟雾在$n"HIB"身前身后忽左忽右游走，$p眼花缭乱招招落空。\n"NOR,me,target);
        me->add("force", -50);
        his_p = me->query_skill("tonsillit",1)/10;
        my_p = me->query_skill("ghost-steps",1)/10;
        me->set_temp("hell_guiying",my_p);
	me->add_temp("apply/dodge",my_p); 
        
        if( !target->query_temp("hell_guiying2") )
        {
        	target->add_temp("apply/attack",-his_p);
        	target->set_temp("hell_guiying2",his_p);
        	target->start_call_out( (: call_other, __FILE__, "remove_effect2", target, his_p:), me->query_skill("dodge")/2);
        }	
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, my_p:),me->query_skill("dodge")/2);
	return 1;
}
 
void remove_effect(object me, int p)
{
	if( !me )  
		return;
        me->add_temp("apply/dodge", -p);
        me->delete_temp("hell_guiying");
        message_vision(HIB"$N"HIB"身影渐渐由虚化实，渐渐变回了实体。\n"NOR,me);
}

void remove_effect2(object me, int p)
{
	if( !me )  
		return;
        me->add_temp("apply/attack", p);
        me->delete_temp("hell_guiying");
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：幻化鬼影
        外功所属：鬼影迷踪
        外功效果：一定时间内增强自身的闪避率，降低对方的命中率
                  不可叠加
        外功条件：
        	  阎罗地府(出师)弟子
        	  人物等级10级	
        	  基本内功激发摄气诀
        	  基本轻功激发鬼影迷踪
                  内力200点，消耗50点
                  鬼影迷踪等级 100 级
                  摄气诀等级 100 级
STR;
        me->start_more(str);
        return 1;
}

void remove()
{
	int p,i;
	object me,*usr = users();
	if( i=sizeof(usr)>0 )
	{
		while(i--)
		{
			if( !usr[i] || !environment(usr[i])
			 || !objectp(usr[i]) )
				continue;
			if( usr[i]->query_temp("hell_guiying") )
			{
				me = usr[i];
				p = me->query_temp("hell_guiying");
        			me->add_temp("apply/dodge", -p);
        			me->delete_temp("hell_guiying");
        			message_vision(HIB"$N"HIB"身影渐渐由虚化实，渐渐变回了实体。\n"NOR,me);
			}
			else if( usr[i]->query_temp("hell_guiying2") )
			{
				me = usr[i];
				p = me->query_temp("hell_guiying2");
        			me->add_temp("apply/attack", p);
        			me->delete_temp("hell_guiying2");
			}
		}
	}
} 