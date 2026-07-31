// ziqi.c 紫气东来
// looo/2001/6/21/update
#include <ansi.h>

inherit F_SSERVER;
string query_name() { return "紫气"ZJBR"东来"; }
void remove_effect(object me, int amount);

int exert(object me, object target)
{
        object weapon;
        string msg;
        int d_count, count, qi, maxqi, skill;

        if( me->query_temp("ziqi") )
                return notify_fail(HIG"你已经在运起紫气东来了。\n");

        if( me->query("neili")<200 )
                return notify_fail("你的内力还不够！\n");

        if( (int)me->query_skill("force") < 150)
                 return notify_fail("你的紫霞神功的修为不够，不能使用紫气东来! \n");

        //必须有兵器。加兵器威力
        if( !objectp(weapon=me->query_temp("weapon")) ||
            weapon->query("skill_type") != "sword" )
                return notify_fail("你没有剑.怎么用紫气东来呀? \n");

        msg = MAG "$N" MAG "猛吸一口气,脸上紫气大盛!!手中的兵器隐隐透出一层紫光..\n" NOR;

        qi=me->query("qi");
        maxqi=me->query("max_qi");
        skill = (int)me->query_skill("zixia-shengong", 1);

        if(qi > (maxqi * 0.4))
        {
                message_combatd(msg, me);
                me->add_temp("apply/damage", skill*2);
                me->add_temp("apply/sword", skill/10);
                me->set_temp("ziqi", 1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill/2);

                me->add("neili", -150);
        }
        else{
                msg = HIR "$N" HIR "拼尽毕生功力想提起紫气东来，但自己受伤太重，没能成功!\n" NOR;
                message_combatd(msg, me);
        }

        return 1;
}

void remove_effect(object me, int amount)
{
        if( me->query_temp("ziqi") )
        {
                me->add_temp("apply/damage", -amount*2);
                me->add_temp("apply/sword", -amount/10);
                me->delete_temp("ziqi");
                tell_object(me, HIY "你的紫气东来运行完毕,紫气渐渐隐去.\n" NOR);
        }
}