//beng 崩棍

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include <char.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int skill,extra,i,tar;
        object weapon,room;
        object *enemy;
        room=environment(me);
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("『崩棍』只能对战斗中的对手使用。\n");
                
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_str() < 40)
                return notify_fail("你的臂力不够，无法施展『崩棍』。\n"); 

        if( (int)me->query_skill("panlong-gun", 1)  < 200 )
                return notify_fail("你的太祖盘龙棍不够娴熟，不会使用『崩棍』。\n");

        if( (int)me->query_skill("bixue-xinfa", 1) < 200 )
                return notify_fail("你的碧血心法等级不够，不能使用『崩棍』。\n");

        if( (int)me->query("max_neili") < 2500 || (int)me->query("neili") < 1500 )
                return notify_fail("你的内力不足，无法使用『崩棍』。\n");
        /*if (room->query("juemen"))
        {
            enemy=me->query_enemy();
            tar=sizeof(enemy);
            if (tar>=9)
            {
                tar=9;
            }
            msg = HIR"$N心中默念多尔衮传授的杀威棒诀，瞬时帮影连环，风雷大作！$n周围的空气也仿佛变得凝重。\n"NOR;
            message_vision(msg, me, enemy[0]);
            skill=(int)me->query_skill("juemen-gun", 1);
            extra = (int)skill/5;
            if( (int)me->query("pin") == 1) extra += extra;
            me->add_temp("apply/attack", extra);
            me->add_temp("apply/damage", extra);
            me->add("neili", -200);
            for(i=0;i<tar;i++)
            {
                if (environment(enemy[i])!=environment(me)) 
                	continue;
                msg = HIR "$N一棍扫出一个大弧，击向$n！\n" NOR;
                message_vision(msg, me, enemy[i]);
                COMBAT_D->do_attack(me, enemy[i]);
                if (!random(5))
                {
                    COMBAT_D->do_attack(me, enemy[i]);
                }
            }
            me->add_temp("apply/attack", -extra);    
            me->add_temp("apply/damage", -extra);
            return 1;
        }*/
        msg = HIW"$N招数突变，晃身错步，猛然眼中精光四射，舞起漫天棍影，棍棒打向四方！\n"NOR;
        message_vision(msg, me, target);
                     
        me->add("neili", -200);
        
        me->start_perform(5, "崩棍");
        skill=(int)me->query_skill("panlong-gun", 1);
        extra = (int)skill/5;
        if( (int)me->query("pin") == 1) extra += extra;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        if( !target->is_busy() ) target->start_busy(1);
        msg = HIR"一棍承启，满眼风光北固楼。\n"NOR;
        if( me->is_fighting(target) )  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        msg = HIR"二棍复来，坐断东南战未休。\n"NOR;
        if( me->is_fighting(target) )  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        msg = HIR"三棍连环，八百里分麾下炙。\n"NOR;
        if( me->is_fighting(target) )  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        if( (int)me->query("pin") == 1){
                me->add("neili", -100);
                msg = HIR "四棍既出，了却君王天下事。\n" NOR;
                if( me->is_fighting(target) )  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
                if( (int)me->query("chaoting/catch_feizei") > 200){
                        me->add("neili", -100);
                        me->add_temp("apply/strength", skill/10);
                        me->add_temp("apply/dexerity", skill/10);
                        msg = RED "$N曼声吟道：一条杆棒等身齐，再打四百军州都姓赵。\n" NOR;
                        if( me->is_fighting(target) )  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
                        me->add_temp("apply/strength", -skill/10);
                        me->add_temp("apply/dexerity", -skill/10);
                }
                if (me->query("chaoting/wang"))
                {
                    
                    
                    if( me->is_fighting(target) )  
                    {
                        me->add_temp("apply/strength", skill/10);
                        me->add_temp("apply/dexerity", skill/10);
                        msg = HIY "$N大喝一声：天威难测，莫道英雄似等闲，漫天棍影将$n全身罩住！\n" NOR;
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
                        me->add_temp("apply/strength", -skill/10);
                        me->add_temp("apply/dexerity", -skill/10);
                        if (random((int)me->query_skill("bixue-xinfa",1))>target->query_skill("force",1)*2/3)
                        {
                            me->add("neili", -100);
                            target->add_busy(2+random(3));
                            msg = HIY "$n被攻了个不知所措！\n" NOR;
                        }
                    }
                }
        }
		if (me->query("safari_skill/ct_panlong") && (me->query("family/family_name")=="朝廷"))
		{
             me->add_temp("apply/strength", skill/10);
             me->add_temp("apply/damage", skill/15);
             msg = HIY "$N大喝一声：一入公门深似海，棍扫江湖恩怨休。漫天棍影齐齐打出！\n" NOR;
             COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
             me->add("neili", -200+random(100));

			if ((!me->query("chushi/done")) && (!me->query("betrayer")))
			{
				msg = HIY "$N团身前扑，棍子从身旁抽出，打向$n！\n" NOR;
               COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
	             me->add("neili", -200+random(100));

				if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
					 me->query_skill_mapped("force") != "bixue-xinfa" && me->query_skill("bixue-xinfa",1) > 1300 )			
				{
	             msg = HIY "$N一个翻滚，又翻了回来，棍子随身抽出，犹如神助！\n" NOR;
		         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
	             me->add("neili", -200+random(100));
				}
			}
            me->add_temp("apply/strength", -skill/10);
            me->add_temp("apply/damage", -skill/15);

		}
        me->add_temp("apply/attack", -extra);    
        me->add_temp("apply/damage", -extra);
        
        if((int)me->query("neili") < 0) me->set("neili", 0);
                
        me->start_busy(3+random(2));

        return 1;
}
