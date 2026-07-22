#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill,p;
	
	if( me->query_level()<5 )
		return notify_fail("你的人物等级不够。\n");
	if( !target ) target = me;	
	if( me->query("family/family_name")!="东海龙宫"  
 	&& me->query("chushi/chushi_longgong")!="yes" )
        	return notify_fail("你不能使用这项技能！\n");
	if( target != me ) 
        	return notify_fail("你只能用龙神心法保护自己。\n");
	if( (int)me->query("force")<200 )     
        	return notify_fail("你的内力不够。\n");
	if( (int)me->query("kee")<100 )
        	return notify_fail("你的气血不足。\n");
	if( (int)me->query("sen")<100 )
        	return notify_fail("你的精神不足。\n");
	if( (int)me->query_temp("powerup") ) 
        	return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force")+15;
	p = skill/3+5;
	
	me->add("force", -100);
	me->receive_damage("kee", 50);
	me->receive_damage("sen", 50);

	message_vision(HIC"$N"HIC"微一凝神，运起龙神心法，浑身上下顿时结出了青色的龙鳞。\n" NOR, me);
	me->add_temp("apply/combat_armor", p);
	me->add_temp("apply/spells_armor", p);
	me->set_temp("powerup", 1);
	me->set_temp("sea_shield",p);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, p :), skill);
	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}

void remove_effect(object me, int p)
{
	if(me )
        {
		me->add_temp("apply/combat_armor",-p);
		me->add_temp("apply/spells_armor",-p);
		me->delete_temp("sea_shield");
		me->delete_temp("powerup");
        	tell_object(me, "你的龙神心法运行一周天完毕，龙鳞渐渐消去了。\n");  
        }
}

int help(object me)
{
string str;
if ( !me )      return 0;
str = @LONG
        内功名称：龙鳞护体
        内功所属：龙神心法
        内功效果：以龙鳞加强自身的物理与法术防御
                  战斗中使用自身busy 3 秒
        内功条件：
                  龙宫(出师)弟子
                  人物等级5级
                  内力200点，消耗100点
                  气血100点，消耗50点
                  精神100点，消耗50点
LONG;
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
			if( usr[i]->query_temp("sea_shield") )
			{
				me = usr[i];
				p = me->query_temp("sea_shield");
				me->add_temp("apply/combat_armor",-p);
				me->add_temp("apply/spells_armor",-p);
				me->delete_temp("sea_shield");
				me->delete_temp("powerup");
        			tell_object(me, "你的龙神心法运行一周天完毕，龙鳞渐渐消去了。\n");  
			}
		}
	}
} 