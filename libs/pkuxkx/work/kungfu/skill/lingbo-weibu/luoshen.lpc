#include <ansi.h>
#include <char.h>
#include <combat.h>
#include <skill.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="self" ;
}

string* valid_weapon() 
{
    return ({ "all" });
}

int perform(object me)
{
    string msg;
    int i;
    object target = offensive_target(me);

    if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
        me->query("family/family_name") != "天龙寺" && me->query("chushi/last_family") != "天龙寺")
            return notify_fail("你的外功中没有这种功能。\n");

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) ) 
            return notify_fail("「洛神」只能在战斗中使用。\n");

    if( (int)me->query_skill("force",1) < 300 )
            return notify_fail("你的内功还不够火候，使不出「洛神」。\n");

    if( (int)me->query_skill("lingbo-weibu",1) < 150 )
            return notify_fail("你的凌波微步还不够火候，使不出「洛神」。\n");

    if( (int)me->query("max_neili",1) < 3000 )
            return notify_fail("你的内力修为还不够火候，使不出「洛神」。\n");

    if( (int)me->query("jingli", 1) < 500 )
            return notify_fail("你现在精力不够。\n");

    if( (int)me->query("neili", 1) < 200 )
            return notify_fail("你现在内力不够。\n");

    if (me->query_temp("lbwb/ls"))
            return notify_fail("你正在使用「洛神」。\n");

    msg = GRN "$N越走越快，按合四相八卦之势,内息随着步法不住运转,转眼间犹如雾一样,环绕$n移动！\n\n"NOR;

    me->add("neili", -(200+random(300)));
    me->add("jingli", -(100+random(50)));
    message_vision(msg, me, target);
    i = me->query_skill("lingbo-weibu", 1)/10 + me->query_int();
    i = i*2 - random(i/2);
    i = i/2;
    me->add_temp("apply/dexerity", i);
    me->add_temp("apply/dodge", i*2);
    me->set_temp("lbwb/ls", i);
    me->set_temp("active_buffer/family","天龙寺");
    me->set_temp("active_buffer/lingbo-weibu.luoshen/name", "洛神");                          //buff名称
    me->set_temp("active_buffer/lingbo-weibu.luoshen/last_time", time() + i+1 );              //持续时间
    me->set_temp("active_buffer/lingbo-weibu.luoshen/effect1", "后天身法+"+i+"点");           //效果描述1
    me->set_temp("active_buffer/lingbo-weibu.luoshen/effect2", "轻功技能+"+(i*2)+"级");       //效果描述2
    me->start_perform(2, "洛神");
    me->start_busy(random(2));
    call_out("remove_effect", 1, me, i,i);
    return 1;
}

void remove_effect(object me, int count,int dex)
{
        if (!me) return;
        if( me->query_skill_mapped("dodge") != "lingbo-weibu"
         || !me->is_fighting()
         || me->query("neili") < 100
         || count < 1){
           me->add_temp("apply/dexerity", -dex);
           me->add_temp("apply/dodge", -dex*2);
           me->delete_temp("lbwb/ls");
           me->delete_temp("active_buffer/lingbo-weibu.luoshen");
           if ( sizeof(me->query_temp("active_buffer"))==1 )
             me->delete_temp("active_buffer");
           message_vision(HIW"$N内力不济，身法慢了下来。\n"NOR, me);
           return;
        }
 call_out("remove_effect", 1 , me, count -1,dex);
}

