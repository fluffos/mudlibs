#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill,p;
	
	if( me->query_level()<30 )
		return notify_fail("你的人物等级不够。\n");
	if( !target ) target = me;	
	if( me->query("family/family_name")!="东海龙宫" )  
        	return notify_fail("你不能使用这项技能！\n");
	if( target != me ) 
        	return notify_fail("你只能用龙神心法保护自己。\n");
	if( (int)me->query("force")<500 )     
        	return notify_fail("你的内力不够。\n");
	if( (int)me->query("kee")<300 )
        	return notify_fail("你的气血不足。\n");
	if( me->query_temp("powerup") )
	{ 
		if( me->query_temp("powerup")=="jin" )
        		return notify_fail("你已经在运功中了。\n");
        	else	return notify_fail("你已使用了龙神心法的其他奥妙。\n");
        }	

	skill = me->query_skill("force")+15;
	p = skill/10+25;
	
	me->add("force", -300);
	me->receive_damage("kee", 200);

	message_vision(HIR"$N"HIR"仰天发出一声龙吟般的长啸，浑身顿时煞气滔天，双眸发出血色，竖立的瞳仁散发着妖异的光芒。\n" NOR, me);
	me->add_temp("apply/combat_damage", p);
	me->add_temp("apply/spells_damage", p);
	me->set_temp("powerup","jin");
	me->set_temp("sea_jin",p);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, p :), skill);
	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}

void remove_effect(object me, int p)
{
	if(me )
        {
		me->add_temp("apply/combat_damage",-p);
		me->add_temp("apply/spells_damage",-p);
		me->delete_temp("powerup");
		me->delete_temp("sea_jin");
        	tell_object(me, HIC"你的龙神心法运行一周天完毕，渐渐恢复了人形。\n"NOR);  
        }
}

int help(object me)
{
string str;
if ( !me )      return 0;
str = @LONG
        内功名称：苍龙劲
        内功所属：龙神心法
        内功效果：以苍龙劲加强自身的物理与法术攻击
                  战斗中使用自身busy 3 秒
                  不可与其他增益型状态叠加
        内功条件：
                  龙宫弟子
                  人物等级30级
                  内力500点，消耗300点
                  气血300点，消耗200点
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
			if( usr[i]->query_temp("sea_jin") )
			{
				me = usr[i];
				p = me->query_temp("sea_jin");
				me->add_temp("apply/combat_damage",-p);
				me->add_temp("apply/spells_damage",-p);
				me->delete_temp("powerup");
				me->delete_temp("sea_jin");
        			tell_object(me, HIC"你的龙神心法运行一周天完毕，渐渐恢复了人形。\n"NOR);  
			}
		}
	}
} 