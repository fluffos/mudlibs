// roar.c 碧海生潮曲
#include <ansi.h>
inherit F_CLEAN_UP;
int exert(object me, object target)
{
    object *ob;
    int i, skill, damage;
//    if (!me->is_fighting())
//        return notify_fail("碧海生潮曲只能在战斗中使用。\n");
    if( (int)me->query("neili") < 100 )
        return notify_fail("你的内力不够。\n");
    skill = me->query_skill("bibo-shengong",1)+me->query_skill("force",1)/4;
    if (skill<60) return notify_fail("你的碧波神功还不够娴熟。\n");
    me->add("neili", -100);
    me->receive_damage("qi", 10);
    me->start_busy(2);
    message_vision(
        HIY "$N气凝丹田，运集全身内力吟出一曲「碧海生潮」！\n" NOR, me);
    ob = all_inventory(environment(me));
    for(i=0; i<sizeof(ob); i++) {
        if( !living(ob[i]) || ob[i]==me || wizardp(ob[i]) || ob[i]->query("age")<17 )
            continue;
        if( skill/2 + random(skill/2) < (int)ob[i]->query_skill("force"))
            continue;
        
        damage = skill - ((int)ob[i]->query("max_neili") / 10);
        if( damage > 0 ) {
            ob[i]->receive_damage("jing", damage * 2,me );
            if( (int)ob[i]->query("neili") < skill * 2 )
                ob[i]->receive_wound("jing", damage,me);
        tell_object(ob[i], "你只觉得眼前一片模糊，朦胧中似乎无数排山巨浪向你打来......\n");
		ob[i]->start_busy(2);
        if( !ob[i]->is_killing(me) )	ob[i]->kill_ob(me);
        if( !me->is_killing(ob[i]) )	me->fight_ob(ob[i]);
        }
    }
    return 1;
}
