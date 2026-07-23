// quanzhen-jian zhuo
// liu 2002
/*
郝大通久战不下，虽然未落丝毫下风，但想自己是武林中久享盛名的宗匠，若与这小女子
战到百招以上，纵然获胜，也已脸上无光，不由得焦躁起来，剑法忽变，自快转慢，招式
虽然比前缓了数倍，剑上的劲力却也大了数倍。初时剑锋须得避开绸带的卷引，此时威力
既增，反而去削斩绸带。
*/

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        string weapon;
        int skill, att;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「浊」字诀只能对战斗中的对手使用。\n");

        if( !me->query_temp("sanqing") )
                return notify_fail("不先使用一剑化三清，无法继续使用「浊」字诀！\n");

        if( me->query_temp("quanzhen/zhuo") )
                return notify_fail("你正在使用「浊」字诀！\n");

        if( me->query_skill_mapped("force") != "xiantian-gong" )
                return notify_fail("你所用的并非先天功，无法施展「浊」字诀！\n");

        skill =  ( me->query_skill("quanzhen-jian") / 2 + me->query_skill("force") ) / 6;

        if( me->query("neili") <= skill*3 )
                return notify_fail("你的内力不够使用「浊」字诀！\n");
        if( me->query("jingli") <= skill )
                return notify_fail("你的精力不够使用「浊」字诀！\n");
        if( me->query("jing") <= skill )
                return notify_fail("你的精不够使用「浊」字诀！\n");

        weapon = me->query_temp("weapon");

        me->set_temp("apply/damage", me->query_temp("apply/damage",1)+skill);

        message_vision(HIR "\n$N久战不下，虽然未落丝毫下风，却不由得焦躁起来，剑法忽变，自快转慢，招式虽然比前缓了数倍，剑上的劲力却也大了数倍。\n" NOR, me, target);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->add("neili", -skill*3 );
        me->add("jingli", -skill );

        me->set_temp("sanqing",0);
		me->set_temp("sanqing_busy",1);
        me->set_temp("quanzhen/zhuo",10);
        remove_call_out("checking");
        call_out("checking", 1, me);

        return 1;
}

void checking(object me)
{
        int skill =  ( me->query_skill("quanzhen-jian") /2 + me->query_skill("force") ) / 6;

        if(!me->is_fighting() || !living(me) || me->is_ghost()
        || me->query_skill_mapped("sword") != "quanzhen-jian" || me->query_skill_mapped("force") != "xiantian-gong" 
        || !objectp(me->query_temp("weapon")) || me->query_temp("quanzhen/zhuo") <= 0 || !me->query_temp("quanzhen/zhuo"))
        {
                message_vision(HIG"\n$N将内劲收归丹田，剑劲也渐渐弱了下来。\n"NOR, me);
                me->delete_temp("quanzhen/zhuo");
				call_out("receive_sanqing", 10 + random(20) , me);
                me->set_temp("apply/damage", me->query_temp("apply/damage",1)-skill);
                return ;

        }

        me->add_temp("quanzhen/zhuo",-1);
        call_out("checking", 1, me);

        return;
}
void receive_sanqing(object me)
{
        if ( !me ) return;

        me->delete_temp("sanqing_busy");
        tell_object(me, HIG"\n你经脉运转如常，气血已不如之前翻腾无极。\n"NOR); 
}
