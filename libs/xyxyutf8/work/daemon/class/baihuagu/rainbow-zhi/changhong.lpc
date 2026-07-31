// 长虹经天 Changhong.c
// Cracked by 凌惊雪 4-1-2003
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit F_CLEAN_UP;

void remove_apply(object who,int attack,int dodge)
{
	if( !who )
		return;
	who->add_temp("apply/attack",-attack);
        who->add_temp("apply/dodge",-dodge);
        who->delete_temp("bhg_changhong");
	message_vision(HIC"\n$N"HIC"伤势好了大半，身形顿时恢复了灵动。\n"NOR,who);
}	

int perform(object me, object target)
{
	string msg,succ_msg;
	int damage,attack,dodge,blind,busy;

	if( me->query_level()<8 )
		return notify_fail("你的人物等级不够。\n");
	if((string)me->query("family/family_name")!="百花谷") 
        	return notify_fail("只有百花谷弟子才能使用此招！\n");
	if((int)me->query_skill("rainbow-zhi",1)<80) 
        	return notify_fail("你的「柔虹指」还不够纯熟！\n");
	if(me->query_int()<25) 
        	return notify_fail("你认穴不准，无法使出「长虹经天」！\n");
	if(me->query_con()<25) 
        	return notify_fail("你认穴不准，无法使出「长虹经天」！\n");
	if((int)me->query("force")<500 )
        	return notify_fail("你的内力不够！\n");
		
	if( !target ) target = offensive_target(me);

	if( !target
  	||!target->is_character()
  	|| target->is_corpse()
  	|| target==me)
        	return notify_fail("你要对谁施展这一招「长虹经天」？\n");
	if(!me->is_fighting(target))
        	return notify_fail("「长虹经天」只能在战斗中使用！\n");

	me->add("force", -150);
	msg= HIR"\n$N"HIR"身行变幻莫测，施展出流星雨般的"HIW"柔虹指"HIR"直点向$n"HIR"的周身大穴！\n"NOR;
	succ_msg = HIM"结果只听见一声闷哼，$N"HIM"发出的指气已击中$n"HIM"的"HIR"$l"HIM"！\n"NOR;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg);
	me->set_temp("pfm_msg",0);
	if( damage<1 )
	{
		message_combatd(HIM"但是被$n"HIM"从容化解了。\n"NOR, me, target);
		me->start_busy(1);
		return 1;
	}
	me->start_busy(2);
	if( COMBAT_D->query_message_type(me,target)==2 )
		message_vision(HIR"另外还造成了"+(damage/2+1)+"点气血损伤。\n"NOR,me,target);
	target->receive_wound("kee",damage/2+1, me,TYPE_PERFORM);
	COMBAT_D->report_status(target,1);
	if( living(target) )
	{
               	attack = (int)me->query_skill("brightjade-force",1)/10;
               	dodge = (int)me->query_skill("brightjade-force",1)/5;
               	if( random(3) && !target->is_busy() && !target->query_temp("bhg_changhong") )
		{
                	message_combatd(HIB"$N"HIB"的指力正打在$n"HIB"伤处的穴道上，$p的动作已显迟滞。\n"NOR,me,target);
                        target->add_temp("apply/attack",-attack);
                        target->add_temp("apply/dodge",-dodge);
                        target->set_temp("bhg_changhong/attack",attack);
                        target->set_temp("bhg_changhong/dodge",dodge);
                        target->start_call_out( (: call_other, __FILE__, "remove_apply",target, attack,dodge :),me->query_skill("unarmed")/10);
		}
                else if( random(3) || target->is_blind() )
		{
			message_combatd(YEL"$N"YEL"的指力正打在$n"YEL"伤处的穴道上，$p已经半身麻木苦苦支撑。\n"NOR,me,target);
			busy = me->query_skill("unarmed")/60;
			target->start_busy(busy);
		}
                else    
                {
                	message_combatd(RED"$N"RED"的指力正打在$n"RED"伤处的穴道上，$p登时浑身僵硬动弹不得！\n"NOR,me,target);
                	blind = (me->query_int()+me->query_con())/20;
                	if( blind<3 )  blind = 3;
                	if( blind>15 ) blind = 15;
                	target->start_blind(blind,HIR"\n你穴道被"+me->name()+HIR"所封，动弹不得。\n"NOR);
		}
        } 
	return 1;
}   

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        外功名称：长虹经天
        外功所属：柔虹指
        外功效果：运用指力对敌人进行气血伤害
                  有一定的几率使对手命中和闪避降低
                  有一定的几率使对手定身
                  有一定的几率使对手busy
                  成功则自身 busy 2 秒，否则则自身busy 1 秒
        外功条件：
        	  百花谷弟子
        	  人物等级8级
                  柔虹指80级
                  内力500点,消耗150点
                  后天悟性25
                  后天根骨25
LONG;
me->start_more(str);
return 1;
}       

void remove()
{
	int attack,dodge,i;
	object who,*usr = users();
	if( i=sizeof(usr)>0 )
	{
		while(i--)
		{
			if( !usr[i] || !environment(usr[i])
			 || !objectp(usr[i]) )
				continue;
			if( usr[i]->query_temp("bhg_changhong") )
			{
				who = usr[i];
				attack = who->query_temp("bhg_changhong/attack");
				dodge = who->query_temp("bhg_changhong/dodge");
				who->add_temp("apply/attack",-attack);
        			who->add_temp("apply/dodge",-dodge);
        			who->delete_temp("bhg_changhong");
        			message_vision(HIC"\n$N"HIC"伤势好了大半，身形顿时恢复了灵动。\n"NOR,who);
			}
		}
	}
} 