// xidu.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() ||target->is_fighting()  )
                return notify_fail("战斗中运功吸毒？找死吗？\n");

   if (me->query_condition("snake_poison") > 0 ||
       me->query_condition("xx_poison") > 0 ||
       me->query_condition("chilian_poison") > 0 ||
        me->query_condition("bt_poison") > 0)
        return notify_fail("你自己已身中剧毒，无法为他人吸毒。\n");

	if ((int)target->query_condition("chilian_poison") > 0) {
        if ((int)me->query_skill("wudu-xinfa", 1) < 70)
                return notify_fail("你的五毒心法修为还不够吸他人赤练神掌毒所需。\n");

        if( (int)me->query("neili") < 150 )
                return notify_fail("你的真气不够吸他人赤练神掌毒所需。\n");

        message_vision(HIY "$N坐了下来，伸嘴到$n创口处吸出毒质，吐出几口毒水。\n" NOR,me, target );
        write( HIW "你口中只觉苦味渐转咸味，头脑却越来越觉晕眩。\n" NOR);

        me->apply_condition("chilian_poison", target->query_condition("chilian_poison"));
        target->apply_condition("chilian_poison", 0);

        me->add("neili", -150);
   }
   else write(target->name()+"并未中毒。\n");

        return 1;
}
