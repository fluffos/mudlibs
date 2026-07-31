// lengquan.c 
// By bbba
// By CQwiz更新完善
#include <ansi.h>
inherit F_CLEAN_UP;
int exert(object me)
{
        int skill;
        string picture;

        if((int)me->query("neili") < 1500 ) 
                return notify_fail("你的内力不够。\n");

        if((int)me->query_temp("lqsg/lq")) 
                return notify_fail("你已经在运功中了。\n");

        if((int)me->query_skill("lengquan-shengong",1 ) < 200)
                return notify_fail("你的冷泉神功等级不够，还不能完全发挥神功威力。\n");

        if( me->query_skill_mapped("force") != "lengquan-shengong")
                return notify_fail("你现在不能使用冷泉。\n");

        skill = (int)me->query_skill("lengquan-shengong", 1);
        if (skill > 350) skill = 350+ (skill-350)/5;
        me->add("neili", -(200+ random(200)));
        message_vision(HIW"$N将体内寒气聚集丹田,全身如坠冰窖,面色也从红变白,不一会,只感觉周身布满充盈的寒气。\n" NOR, me);

        me->add_temp("apply/intelligence", skill/8);
        me->add_temp("apply/dexerity", skill/8);

        if (skill > 200) {
          me->add_temp("apply/attack", skill/5);
          me->add_temp("apply/damage", skill/8);
        }
        if( skill >350)
        {
             me->add_temp("apply/dodge", skill/8);
             me->add_temp("apply/parry", skill/8);
             me->add_temp("apply/armor", skill/8);
        }

        me->set_temp("lqsg/lq", skill);
        me->start_call_out( (: call_other, this_object(), "remove_effect", me :), skill);
        if( me->is_fighting() ) me->start_busy(1+random(2));
        me->start_exert(2,"冷泉");
        return 1;
}

void remove_effect(object me, int count)
{       
        int skill;
        if(!objectp(me)) return;
        if(objectp(me)
        && me->query_temp("lqsg/lq")
        && me->query_skill_mapped("force") == "lengquan-shengong"
        && count){   
                call_out("remove_effect", 1, me, --count);
                return;
        }
        skill = me->query_temp("lqsg/lq");
        me->add_temp("apply/intelligence", -skill/8);
        me->add_temp("apply/dexerity", -skill/8);
        if (skill > 200)
        {
            me->add_temp("apply/attack", -skill/5);
            me->add_temp("apply/damage", -skill/8);
        }
        if(skill > 350)
        {
           me->add_temp("apply/dodge", -skill/8);
           me->add_temp("apply/parry", -skill/8);
           me->add_temp("apply/armor", -skill/8);
        }
        me->delete_temp("lqsg/lq");
        tell_object(me, HIW"你逐渐将体内寒气化去,面色恢复正常。\n"NOR);
}
