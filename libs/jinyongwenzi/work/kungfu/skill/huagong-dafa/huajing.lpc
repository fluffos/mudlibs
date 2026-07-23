// huagong.c 化功
// by snowman@SJ
// modify by snowman@SJ 25/02/2000
// Modified by darken@SJ

#include <ansi.h>

inherit F_SSERVER;

string exert_name(){ return HBRED"化功"NOR; }
void huagong(object me, object target);

int exert(object me, object target)
{        
        object room,ob;
        
        if( !target) target = offensive_target(me);
        if( !target || !objectp(target) || !me->is_fighting(target) || !living(target))
                return notify_fail("化精只能在战斗中对对手使用。\n");
                   
        if( !objectp(target) || target->query("id") == "mu ren" )
                return notify_fail("用火把来烧比较快。\n");
        
        if( !userp(target))
                return notify_fail("你不能对他使用化精！\n");

        if(!( room = find_object("/d/taishan/fengchan")) )
                room = load_object("/d/taishan/fengchan");
        if( objectp(ob = present("zhong shentong", room)) ) {
                if(target->query("id") == ob->query("winner"))
                        return notify_fail("大胆！竟敢对中神通运用化功大法！\n");
        }

        if( !living(target) || ! target->query("can_speak"))
                return notify_fail("它不是活物。\n");

        if( me->query_temp("weapon"))
                return notify_fail("你必须使用三阴蜈蚣抓，方能抓住对手。\n");

        if( me->query_skill_prepared("claw") != "sanyin-zhua")
                return notify_fail("你必须使用三阴蜈蚣抓，方能抓住对手。\n");

        if( (int)me->query_skill("huagong-dafa",1) < 250 )
                return notify_fail("你的功力不够，不能施展化精！\n");

        if( (int)me->query_skill("poison",1) < 200 )
                return notify_fail("你体内的毒素不够，不能施展化精！\n");

        if((int)target->query("max_jingli") <= 0 || target->query("combat_exp") < me->query("combat_exp")/2)
                return notify_fail( target->name() +"没有任何精力可化！\n");

        message_vision(BLU"突然$N仰天阴阴一声长笑，接着左手手掌虚扬，右手猛地向$n拍去！\n\n" NOR, me, target );

        if( random(me->query_int()) > target->query_int()/2) {
            message_vision(HBRED"$n也是一掌拍来挡格，双掌一接，$n似乎想起了什么，暗叫一声不好！\n\n" NOR, me, target );
            me->start_busy(2);
            target->start_busy(2);
            call_out("huagong", 2, me, target, 1);
        }

        if( !target->is_killing(me->query("id")) ){ 
                me->kill_ob(target);
                target->kill_ob(me);              
        }

        me->start_exert(3);

        return 1;
}

void huagong(object me, object target)
{
        object victim, *people;
        int i;

        if (!me || !target) return;
        me->start_busy(2);
        target->start_busy(2);
        if (target->query("max_jingli") < 1 || target->query_temp("huagong/count") > 10) {
            message_vision(RED"$n被$N化尽了丹元，软软的摊在地上。\n"NOR, me, target);
            message_vision(RED"$N哈哈一笑，松开了手。\n"NOR, me, target);
            i = 50 + random(31);
            target->add("max_jingli", -i);
            target->add("eff_jingli", -i);
            target->add("jingli", -i);
            if (target->query("max_jingli") < 0) target->set("max_jingli",0);
            target->unconcious();
            target->delete_temp("huagong/count");
            me->remove_all_enemy();
            target->remove_all_enemy();
            return;
        }
        if (target->query_skill("douzhuan-xingyi") > 100 || 
            target->qyery_skill("qiankun-danuoyi") > 100){
             people = all_inventory(environment(me));
             i = random(sizeof(people));
             victim = people[i];
             if (victim != me && victim != target && victim->is_character() && living(victim) && !wizardp(victim)) {
                message_vision(HBRED"$N灵机一动，一牵一引，把$n转到身前，接过了对手的魔掌！\n"NOR, target, victim);
                target->remove_all_enemy();
                me->remove_all_enemy();
                huagong(me, victim);
                return;
             }
        }
        if (random(target->query("neili")) > me->query("neili")/2) {
            message_vision(RED"$n拼著大耗真元，将全身内力用力向$N一送，挣开了$N的掌握。\n"NOR, me, target);
            target->add("max_neili",-5-random(5));
            return;
        }
        message_vision(RED"$n使劲挣扎，就是无法脱出$N掌握，只觉得精力不断流失。\n"NOR, me, target);
        me->add("potential", (me->query_skill("force") + random(me->query_skill("poison")))/20);
        i = 20 + random(11);
        target->add("max_jingli", -i);
        target->add("eff_jingli", -i);
        target->add("jingli", -i);
        target->add_temp("huagong/count", 1);
        call_out("huagong", 2, me, target);
}

