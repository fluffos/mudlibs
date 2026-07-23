
// suck.c
// by star 亮晶晶 98.12.4
#include <ansi.h>

inherit F_SSERVER;
int perform(object me,object target)
{
        int temp;
        int my_skill,my_force,tg_age,skill_count,duli;
int sk1,sk2;
	object where = environment(me);
//  if ( !target || target == me ) target = offensive_target(me);
//  target = present(arg,environment(me));

    if( (int)me->query_skill("wudu-shengong",1) < 50 )
                return notify_fail("你的五毒神功修为还不够！\n");
    if( (int)me->query_skill("duji",1) < 50 )
                return notify_fail("你的毒技(duji)修为还不够！\n");
    if( (int)me->query_skill("qianzhu-wandushou",1) < 50 )
                return notify_fail("你的千蛛万毒手修为还不够！\n");

    if( !objectp(target)
    ||  target->query("host_id") != me->query("id") )   
        return notify_fail("你要吸取什么毒虫的毒素？\n");

    if( target->query("age") < 99 )
        return notify_fail("你看清楚点，那东西像是毒虫吗？\n");
    my_skill = (int)me->query_skill("qianzhu-wandushou", 1);
    my_force = (int)me->query_skill("wudu-shengong", 1);
sk1=(int)me->query_skill("duji", 1)/30+1;
sk2=my_skill/30+1;
    tg_age = (int)target->query("age");

    if( my_skill < 50 )
        return notify_fail("你的千蛛万毒手火候太浅，不能用来吸取毒素！\n");
    if( objectp(me->query_temp("weapon")) )
        return notify_fail("你必须空手才能修炼千蛛万毒手！\n");
    if( me->is_fighting() )
        return notify_fail("战斗中无法修炼千蛛万毒手！\n");
if (environment(me)->query("sleep_room"))
                return notify_fail("卧室不能吸取毒素，会影响别人休息。\n");

if( environment(me)->query("no_beg") &&
      environment(me)->query("no_fight") &&
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n不要影响别人，还是找一个别的地方吧。\n"NOR);

    if( me->is_busy() )
        return notify_fail("你正忙着呢！\n");
    if( target->is_fighting() || target->is_busy() )
        return notify_fail("毒虫正忙着呢，不能和你配合！\n");
    if( me->query_temp("wudu_suck") )
        return notify_fail("你正在修炼中！\n");

    if( my_skill > 100 && my_skill < 160 && tg_age < 999 )
        return notify_fail(target->query("name")+"的毒力对你来说已经太轻微了！\n");
    if( my_skill > 159 && tg_age < 9999 )
        return notify_fail(target->query("name")+"的毒力对你来说已经太轻微了！\n");

    if( (int)me->query("neili") < 200 )
        return notify_fail("你的内力不够，不足以对抗毒气，别把小命送掉。\n");
    if( (int)target->query("qi") < 50 )
        return notify_fail( target->query("name") + "已经这样了，你无法从他体内吸取任何毒素！\n");

    if( (int)me->query("qi") < 50 )
        return notify_fail( "你快不行了，再练会送命的！\n");

    if( (int)me->query("jing") < 50 )
        return notify_fail( "你快不行了，再练会送命的！\n");

    message_vision(BLU"$N小心翼翼的将手伸到$n的面前，$n张嘴就咬住了$N的中指。\n" NOR, me, target);
    message_vision(BLU"只见$N深吸一口气，面上顿时罩着一股黑气，豆大的汗珠从额头滚了下来。\n" NOR, me, target);
    tell_object(me, HIG "你只觉得" + target->query("name") + "的毒素自伤处源源不绝地流了进来，随真气遍布全身。\n" NOR );

    target->receive_wound("qi", 10);
    me->add("jing",-30);
    me->add("qi",-40);
    me->start_busy(5);
    if( tg_age < 999 ){
        me->add("combat_exp",1+random(4));
        me->add("potential",1 );
        duli=3;
    }
    if( tg_age > 999 && tg_age < 9999){
        me->add("combat_exp", 1+random(5));
        me->add("potential", 1+random(2));
        duli = 5;
    }
    if( tg_age > 9999 ){
        me->add("combat_exp", 2+random(5));
        me->add("potential", 1+random(2));
        duli=7;
    }
    
/*
    if( (int)me->query("potential") > (int)me->query_max_pot() )
        me->set("potential", me->query_max_pot());
*/
    
    skill_count = duli*(10+random((int)me->query_int()))/2;
    me->improve_skill("qianzhu-wandushou", skill_count);
    me->set_temp("wudu_suck", 1);
    call_out("del_wudusuck", 5, me, target);

    switch( random(duli) ){
    case 0:
        temp = (int)me->query("combat_exp");
        target->add("combat_exp", temp/1000 + sk1+sk2);
        if( (int)target->query("combat_exp") > (temp*12/10) )
            target->set("combat_exp", temp*12/10);
        else
            tell_object(me, HIG+ target->query("name") + "的经验提高到" +
                chinese_number((int)target->query("combat_exp")) +"点。\n"NOR );
        break;
    case 1:
        target->add_temp("apply/attack",1+sk2/2);

        if( (int)target->query_temp("apply/attack")>200 )
            target->set_temp("apply/attack",200);
        else
            tell_object(me, HIG+ target->query("name") + "的攻击力提高到" +
                chinese_number((int)target->query_temp("apply/attack")) + "点。\n"NOR );
        break;
    case 2:
        target->add_temp("apply/defense",1+sk2/2);
        if((int)target->query_temp("apply/defense")>200)
            target->set_temp("apply/defense",200);
        else
            tell_object(me, HIG+ target->query("name") + "的防御力提高到" +
                chinese_number((int)target->query_temp("apply/defense")) +"点。\n"NOR );
        break;
    case 3:
        target->add_temp("apply/armor",1+sk2/2);
        if( (int)target->query_temp("apply/armor") > 1000 )
            target->set_temp("apply/armor", 1000);
        else
            tell_object(me, HIG+ target->query("name") + "的抗打击能力提高到" +
                chinese_number((int)target->query_temp("apply/armor")) +"点。\n"NOR );
        break;
    case 4:
        target->add("max_qi",10+sk1);
        if( target->query("max_qi") > 10000 )
            target->set("max_qi", 10000);
        else
            tell_object(me, HIG+ target->query("name") + "的生命力提高到" +
                chinese_number((int)target->query("max_qi")) +"点。\n"NOR );
        break;
    case 5:
        target->add("max_jing",10+sk1);
        if( target->query("max_jing") > 10000)
            target->set("max_jing", 10000);
        else
            tell_object(me, HIG+ target->query("name") + "的精提高到" +
                chinese_number((int)target->query("max_jing")) +"点。\n"NOR );
        break;
    case 6:
        temp = (int)target->query_skill("dodge",1);
        target->set_skill("dodge",temp+1+sk2/2);
        if((int)target->query_skill("dodge",1)>300)
            target->set_skill("dodge",300);
        else
            tell_object(me, HIG""+ target->query("name") + "的躲闪技能提高到" +
                chinese_number((int)target->query_skill("dodge",1)) +"级。\n"NOR );
    }
    return 1;
}

void del_wudusuck(object me,object target)
{
   if (!me) return;
   if (!target) return;
   if( me->query_temp("wudu_suck") ){
        me->delete_temp("wudu_suck");
        message_vision(HIG
            "只见$N的肚子越涨越大，“吧嗒”一声，松开口掉在地上。\n" NOR, target );
        message("vision", target->query("name") +
            "吸饱了鲜血，身上透出一层宝光，身子顿时涨大了许多！\n",
            environment(me), ({ me }) );
        me->receive_damage("qi", 20);
   }

   target->set("eff_jing", target->query("max_jing"));
   target->set("jing",   target->query("max_jing"));
   target->set("eff_qi", target->query("max_qi"));
   target->set("qi", target->query("max_qi"));
   target->set("neili", target->query("max_neili"));
   target->set("food", target->max_food_capacity());
   target->set("water", target->max_water_capacity());

   target->set_temp("nopoison", 0);
}
