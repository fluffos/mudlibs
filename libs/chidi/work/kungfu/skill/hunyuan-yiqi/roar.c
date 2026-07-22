// roar.c 佛门狮子吼
#include <ansi.h>
inherit F_CLEAN_UP;
int exert(object me, object target)
{
    object *ob;
    int i, skill, damage;
//    if (!me->is_fighting())
//        return notify_fail("佛门狮子吼只能在战斗中使用。\n");
    if( ((int)me->query("neili") < 600 ) || ( (int)me->query_skill("hunyuan-yiqi",1) < 50) )
        return notify_fail("你鼓足真气「喵」的叫了一声, 结果吓走了几只老鼠。\n");
    skill = me->query_skill("hunyuan-yiqi",1);
    if (skill<60) return notify_fail("你的混元一气功还不够娴熟。\n");
    me->add("neili", -150);
    me->receive_damage("qi", 10);
    me->start_busy(2);
    message_vision(
        HIY "$N深深地吸一囗气，真力迸发，发出一声惊天动地的巨吼。\n" NOR, me);
    ob = all_inventory(environment(me));
    for(i=0; i<sizeof(ob); i++) {
        if( !living(ob[i]) || ob[i]==me || wizardp(ob[i]) || ob[i]->query("age")<17 )
                continue;
        if( skill/2 + random(skill/2) < (int)ob[i]->query_skill("force"))
                continue;
        
        damage = skill - ((int)ob[i]->query("max_neili") / 10);
        if( damage > 0 ) {
            ob[i]->receive_damage("jing", damage * 2 ,me);
            if( (int)ob[i]->query("neili") < skill * 2 )
                ob[i]->receive_wound("jing", damage,me);
            tell_object(ob[i], "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样。\n");
        ob[i]->start_busy(2);
        if( !ob[i]->is_killing(me) )    ob[i]->kill_ob(me);
        if( !me->is_killing(ob[i]) )    me->fight_ob(ob[i]);
        }
    }
    return 1;
}
