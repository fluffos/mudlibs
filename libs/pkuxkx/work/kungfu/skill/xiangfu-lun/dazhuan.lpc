// 5lun_npc.c
// Created by snowman@SJ
// Modified by snowman@SJ 28/11/2000
// Modified by snowman@SJ 27/04/2001

#include <ansi.h>
#include <char.h>
inherit F_SSERVER;

string perform_name(){ return HIY"五轮大转"NOR; }

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null";
}

int perform(object me)
{
        object obj, weapon;
        weapon = me->query_temp("weapon");  
    
        if( !me->is_fighting() )
                return notify_fail("「五轮大转」只能对战斗中的对手使用。\n");

        if ( (int)me->query_skill("longxiang-boruo", 1) < 180 )
                return notify_fail("你的内功等级不够，不能使用「五轮大转」。\n");
    
        if ( (int)me->query_skill("xiangfu-lun", 1) < 180 )
                return notify_fail("你的金刚降伏轮法不够娴熟，使不出「五轮大转」。\n");
    
        if ( objectp(obj = me->query_temp("dazhuan_npc")) && present(obj, environment(me)) ) {
                message_vision(HIC "\n$N将手一伸，轰轰之声大作，召回了飞舞着的五轮！\n"NOR, me);
                obj->die();
                me->start_perform(2 + random(2), "「五轮大转」");
                return notify_fail("你收回了正在使用的「五轮大转」。\n");
        }
        
        if ( !objectp(weapon) || weapon->query("skill_type") != "hammer" )
/*         || me->query_skill_mapped("hammer") != "xiangfu-lun") */
                return notify_fail("你现在无法使用「五轮大转」。\n");
/*
        if( weapon->query_amount() < 5 && weapon->query("id") != "fenghuo lun" && weapon->query("hammer_count") < 5 )
                return notify_fail("你需要五个轮子才能使用「五轮大转」。\n");
*/
        if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) &&
            me->query_skill_mapped("force") != "longxiang-boruo" )
                return notify_fail("你目前的内功无法支持你使用「五轮大转」。\n");

        if ( (int)me->query("max_neili") < 3800 )
                return notify_fail("你现在内力太弱，不能使用「五轮大转」。\n");

        if ( (int)me->query("neili") < 1000 )
                return notify_fail("你现在真气太弱，不能使用「五轮大转」。\n");

        message_vision(HIC "\n$N纵跃退後，立时呜呜、嗡嗡、轰轰之声大作，金光闪闪，银光烁烁，五只轮子从五个不同方位飞袭出来！

                        "HIG"※※※ "HIY"五 轮 大 转 "HIG"※※※ \n\n"NOR, me);
                                                                     
        me->start_busy(1);
        me->add("neili", -300);
  
        obj = new(__DIR__"npc/5lun_npc");
        if( obj->move(environment(me)) ){
                me->set_temp("dazhuan_npc", obj);
                me->add_temp("apply/parry", 100);
                me->add_temp("apply/armor_vs_force", 200);
                weapon->unequip();
                weapon->move(obj);
                obj->set_master_player(me, weapon);
        }
        else write(HIR"\n「五轮大转」出错！请通知巫师： Obj cannot move to environment()\n\n"NOR);
        return 1;
}

int help(object me)
{
	write(HIY"\n降伏轮之「五轮大转」：\n\n"NOR);
        write(@HELP
	当年密宗金轮法王横扫西域，威镇草原，一手藏密金刚降伏轮使得出神入化！
        此「五轮大转」绝技乃法王得意之作，全由龙象之力以御气操作，法轮飞舞旋
        转，如飞龙降世，金刚开山！当世可挡之人寥寥无几！
        
        要求：  龙象般若功等级 180 以上；
                金刚降伏轮法等级 180 以上；
                最大内力 3800 以上；
                内力 1000 以上；
                手握五轮。
HELP
        );
        return 1;
}



