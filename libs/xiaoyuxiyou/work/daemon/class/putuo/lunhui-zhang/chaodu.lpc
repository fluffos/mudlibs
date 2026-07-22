// 超生渡化 Chaodu.c
// Last updated By 凌惊雪 12-14-2002
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int valid_perform(object me)
{
	if( me->query_level()<35 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name")!="南海普陀山")
    		return notify_fail("不是佛门弟子,不懂这佛门奥义！\n");
	if((int)me->query_skill("lunhui-zhang", 1) < 300)
    		return notify_fail("你的轮回杖修为还不够，使用这一招会有困难！\n");
	return 1;	
}

int perform(object me, object target)
{
	string msg;
	int extra,lvl;

	if( !valid_perform(me) )
		return 0;
			
	if( !target ) target = offensive_target(me);
	if( !target
 	 || !target->is_character()
 	 || target->is_corpse()
 	 || target==me 
 	 || !me->is_fighting(target) )
     		return notify_fail("超生渡化只能对战斗中的对手使用。\n");
	if( time()-(int)me->query_temp("putuo_chaodu") < 6 )
		return notify_fail("你刚刚使过超渡绝招，还是歇会儿吧。\n");
	if( me->query("force")<3000 )
    		return notify_fail("你的内力不够。\n");
	extra =(int)me->query_skill("lunhui-zhang", 1)/10;
	if((int)me->query_spi()>40) 
    		extra +=me->query("spi");
	if((int)me->query_spi()>50) 
    		extra +=(int)me->query_skill("buddhism", 1)/10;

	me->add_temp("apply/attack", extra);    
	me->add_temp("apply/combat_damage", extra);

	me->add("force",-200);
	msg = HIR "$N"HIR"缓缓说道:佛曰,以杀止杀!我今天就大开杀戒.代表佛来惩罚你们这些顽恶之徒!\n" NOR;
	message_vision(msg, me, target);
	me->set_temp("putuo_chaodu",time());

	lvl = me->query_level();
	msg =  HIY "天理循环，报应不爽！\n"NOR;
	if( random(lvl)>40 )
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,"头部");
	else	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);	

	msg =  HIC "\n天网恢恢，疏而不漏！\n"NOR;
	if( random(lvl)>50 )
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,"头部");
	else	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);	

	
	msg =  HIG "\n放下屠刀，立地成佛！\n"NOR;
	if( random(lvl)>60 )
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,"头部");
	else	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);	


	msg =  HIW "\n$n"HIW"好象已经到了极乐世界．．．．\n"NOR;
	if( random(lvl)>70 )
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,"头部");
	else	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);	

	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/combat_damage", -extra);
	return 1;
}

int help(object me)
{
string str;
if ( !me )      return 0;
str = @LONG
        外功名称：超生渡化
        外功所属：轮回杖法
        外功效果：短期内提升自身的攻击力，连续攻击敌人四次
        	  随着等级的提高有一定的几率进行要害攻击
                  使用后冷却6秒
        外功条件：
                  普陀弟子
                  人物等级35级	
                  内力4000点，消耗200点
                  轮回杖法300级
LONG;
me->start_more(str);
return 1;
}

