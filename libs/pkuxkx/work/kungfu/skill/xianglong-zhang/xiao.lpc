// By Snowman@SJ
// modified by snowman 20/06/2000
// modify by looklove 2001.5.22 update help

#include <ansi.h>
#include <char.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

void check_fight(object me,object target);

string perform_name(){ return HIY"降龙啸"NOR; }

int perform(object me, object target)
{
        int skill = me->query_skill("xianglong-zhang",1)/3;

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() ||  !me->is_fighting(target) )
                return notify_fail("「降龙啸」只能在战斗中使用。\n");

        if( me->check_hand() >= 1 )
                return notify_fail("你必须双手空手才能使用「降龙啸」！\n");

        if((int)me->query_temp("xlz/xiao") )
                return notify_fail("你已经开始了「降龙啸」。\n");

        if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
             me->query_skill_mapped("force") != "huntian-qigong")
                return notify_fail("你所使用的内功不对。\n");

        if((int)me->query_skill("xianglong-zhang", 1) < 100 )
                return notify_fail("你的降龙十八掌还不够娴熟，使不出「降龙啸」来。\n");

        if((int)me->query_skill("force", "huntian-qigong") < 200 )
                return notify_fail("你的内功等级不够，使不出「降龙啸」来。\n");

        if( (int)me->query_skill("huntian-qigong", 1) < 100 )
                return notify_fail("你的混天气功等级还不够，使不出「降龙啸」绝技。\n");

        if((int)me->query_str() < 30 )
                return notify_fail("你的膂力还不够强劲，使不出「降龙啸」来。\n");

        if((int)me->query("neili") < me->query_skill("strike", "xianglong-zhang")+400 )
                return notify_fail("你的内力不够。\n");

        if (me->query_skill_prepared("strike") != "xianglong-zhang"
         || me->query_skill_mapped("strike") != "xianglong-zhang"
         || me->query_skill_mapped("parry") != "xianglong-zhang")
                return notify_fail("你现在无法使用「降龙啸」！\n");

        if(me->query("betrayer") > 0)
        {
            skill = skill/(me->query("betrayer")+1);
        }
        
        me->add("neili", -(me->query_skill("strike", 1)+200));
        me->add("jingli", -50);
        message_vision(YEL "\n$N仰天狂啸，所使降龙十八掌竟然势力大增，威不可当！源源不绝的掌力排山倒海般地压向$n！\n\n" NOR, me, target);
        if(me->query("jiali") < 50)
          me->set("jiali", 50);
        me->set_temp("xlz/xiao", skill);
        me->add_temp("apply/attack", skill);
        me->add_temp("apply/strength", skill/3);
        me->set_temp("active_buffer/family","丐帮");
        me->set_temp("active_buffer/xianglong-zhang.xiao/name", "降龙啸");                          //buff名称
        me->set_temp("active_buffer/xianglong-zhang.xiao/last_time", time() + skill/3 );            //持续时间
        me->set_temp("active_buffer/xianglong-zhang.xiao/effect1", "攻击命中+"+skill+"级");         //效果描述1
        me->set_temp("active_buffer/xianglong-zhang.xiao/effect2", "后天膂力+"+(skill/3)+"点");     //效果描述2
        call_out("check_fight", 1 , me, skill/3);
        if( me->is_fighting() ) 
        	me->start_busy(1);
        return 1;
}

void check_fight(object me, int i)
{
    int j;

    if( !objectp(me) ) return;
    if( !intp(j = me->query_temp("xlz/xiao")) ) return;

    i--;
    if( !me->is_fighting()
    ||  i < 1
    ||  me->check_hand() >= 1
    ||  me->query_skill_prepared("strike") != "xianglong-zhang"
    ||  me->query_skill_mapped("force") != "huntian-qigong"
    ||  me->query_skill_mapped("parry") != "xianglong-zhang") 
    {
        me->add_temp("apply/attack", -j);
        me->add_temp("apply/strength", -j/3);
        me->delete_temp("xlz/xiao");
        me->add("neili", -j );
        me->start_perform(2, "「降龙啸」");
        me->delete_temp("active_buffer/xianglong-zhang.xiao");
        if ( sizeof(me->query_temp("active_buffer"))==1 )
            me->delete_temp("active_buffer");
        message_vision(YEL "\n$N长啸完毕，看来好象消耗了不少的内力，降龙十八掌的威力也恢复寻常了。\n" NOR, me);
        return;
    }
    me->start_perform(1, "「降龙啸」");
    call_out("check_fight", 1, me, i);
}
int help(object me)
{
        write(HIY"\n降龙掌「降龙啸」："NOR"\n");
        write(@HELP
        短时间内可提升降龙掌威力，但同时消耗内力巨大。
        要求：  当前内力 大于掌法有效等级+400；
                降龙掌等级 100 以上；
                混天气功等级 100 以上；
                膂力 30 以上：
                激发招架为降龙掌。
HELP
        );
        return 1;
}
