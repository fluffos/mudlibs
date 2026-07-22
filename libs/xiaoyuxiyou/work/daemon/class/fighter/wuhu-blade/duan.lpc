#include <ansi.h>
#include <combat.h>
#include <skill.h>
#include <weapon.h>
inherit SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int i,j,extra,n;
        
        if( me->query_level()<20 )
        	return notify_fail("你的人物等级不够。\n");
        
        if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me
 	|| !me->is_fighting(target) )
                return notify_fail("「残魂断肢」只能在战斗中使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if( (int)me->query("force") < 50 )
                return notify_fail("你的内力不足以施展「残魂断肢」！\n");
        if( (int)me->query_skill("blade") < 200 
         || me->query_skill_mapped("blade") != "wuhu-blade")
		return notify_fail("你的「五虎断门刀」还不到家，无法使用「残魂断肢」！\n");
        msg = HIY"$N"HIY"满脸杀意逼人，大喝一省：残魂断肢！\n" NOR;
        extra=me->query_skill("blade");
        me->add_temp("apply/attack",extra); 
        message_vision(msg,me,target);
        me->add("force",-50);
        j = me->query_skill("wuhu-blade",1)/50;
        if( j>10 )
        	j = 10;
        n=0;	
        for(i=1;i<=j;i++)
        {
        	if( !me || !target || !living(me) || !me->is_fighting(target) )
        		break;
        	if( me->query("force")<30 )
        		break;
                switch(i)
                {
                        case 1:
                                msg =  REV HIY "第"+chinese_number(i)+"刀"NOR REV HIR"残肢令出人断肠  "NOR"\n" NOR;n++;
                                break;
                        case 2:
                                msg =  REV HIY "第"+chinese_number(i)+"刀"NOR REV HIR"千里绝杀人茫茫  "NOR"\n" NOR;n++;
                                break;
                        case 3:
                                msg =  REV HIY "第"+chinese_number(i)+"刀"NOR REV HIR"鹧鸪原上使人愁  "NOR"\n" NOR;n++;
                                break;
                        case 4:
                                msg =  REV HIY "第"+chinese_number(i)+"刀"NOR REV HIR"祸其萧墙手足残  "NOR"\n" NOR;n++;
                                break;
                        case 5:
                                msg =  REV HIY "第"+chinese_number(i)+"刀"NOR REV HIR"誓斩唐王玉阶前  "NOR"\n" NOR;n++;
                                break;
                        case 6:
                                msg =  REV HIY "第"+chinese_number(i)+"刀"NOR REV HIR"唤来蚩尤裂海齿  "NOR"\n" NOR;n++;
                                break;
                        case 7:
                                msg =  REV HIY "第"+chinese_number(i)+"刀"NOR REV HIR"刑天去首气不馁  "NOR"\n" NOR;n++;
                                break;
                        case 8:
                                msg =  REV HIY "第"+chinese_number(i)+"刀"NOR REV HIR"八方风雨血长安  "NOR"\n" NOR;n++;
                                break;
                        case 9:
                                msg =  REV HIY "第"+chinese_number(i)+"刀"NOR REV HIR"九天恨意只为谁  "NOR"\n" NOR;n++;
                                break;
                        case 10:
                                msg =  REV HIY "第"+chinese_number(i)+"刀"NOR REV HIR"十绝杀阵困唐王  "NOR"\n" NOR;n++;
                                break;
			default : break;
                }
                me->add("force",-30);
        	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_PERFORM,msg);
        }
        
        if(random(me->query("kar"))>35 && me->query("force")>me->query("force_factor") && me->query("force")>50
         && me->is_fighting(target) )
        {
                me->add_temp("apply/attack",extra*3); 
                me->add("force",-50);
                n++;
                if( n<10 )
                	msg =  REV HIY "第"+chinese_number(i)+"刀"NOR REV HIR"大唐元吉破魔刀  "NOR"\n" NOR;
                else	msg =  REV HIY+chinese_number(n)+"刀"NOR REV HIR"大唐元吉破魔刀  "NOR"\n" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_PERFORM,msg);
                
                if( ( me->is_knowing("jjf_wuhu") || !userp(me)) 
                 &&me->query("force")>me->query("force_factor")
                 && me->query("force")>100 )
                {
                        me->start_busy(2);
                        me->add_temp("apply/attack",extra*4);
                        n++;
                        if( n<10 )
                        	msg =  REV HIY "第"+chinese_number(i)+"刀"NOR REV HIR"无 回 刀        "NOR"\n" NOR;
                        else	msg =  REV HIY+chinese_number(n)+"刀"NOR REV HIR"无 回 刀        "NOR"\n" NOR;
                        me->add("force",-100);
                        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_PERFORM,msg);
                        me->add_temp("apply/attack",-extra*4); 
                }
                else	me->start_busy(3);
                me->add_temp("apply/attack",-extra*3); 
        }
        me->add_temp("apply/attack",-extra); 
        return 1;
}

int help(object me)
{
string str;     
if( !me )      return 0;
str = @LONG
        外功名称：残魂断肢
        外功所属：五虎断门刀
        外功效果：连续攻击对方
                  自身busy 2 - 3 秒
        外功条件：
        	  人物等级20级
                  内力50点，消耗50点，每次攻击扣除内力30点
                  基本刀法200级并激发五虎断魂刀
LONG;
me->start_more(str);
return 1;
} 