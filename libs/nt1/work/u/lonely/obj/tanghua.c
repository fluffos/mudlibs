// tanghua.c

#include <weapon.h>
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"唐花" NOR, ({"tang hua","hua"}));
        set_weight(50);

        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "枚");
                set("long", HIR"这是一朵铁花，但美若昙花，精致玲珑，让人一看之下，就动人心魄。\n"NOR);
                set("value", 0);
        }
        setup();
}

void init()
{
        add_action("do_perform", "use");
}

int do_perform(string arg)
{
        object me, target;
        string msg;

        me = this_player();
        
        me->clean_up_enemy();
        target = me->select_opponent();
        if ( ! objectp(target) ) return 0;

        if ( !arg || arg != "hua" )
                return 0;
        /*        
        if ( !(me->is_fighting()) )
                return notify_fail("唐花只能在战斗中使用。\n");
 
        if( (int)me->query_skill("tangmen-jueqi", 1) < 150 )
                return notify_fail("你的唐门绝器不够娴熟，无法使用唐花。\n");

        if( (int)me->query("max_neili") < 2000  ) 
                return notify_fail("你的内力修为不够，无法使用唐花。\n");

        if( (int)me->query_temp("tanghua") ) 
                return notify_fail("你忙于战斗，无法分神使用唐花了。\n");

        if( (int)me->query("neili") < 1200  ) 
                return notify_fail("你的内力不够。\n");
        
        if( (int)me->query("tangmen/yanli") < 80 )
                return notify_fail("你的眼力太差了，目标不精确！\n");      
        */   

        msg = HIR "\n$N手中突然多了一支花，美得妖艳，$n觉得有点痴了，$N向$n一笑,一扬手向$n抛去。\n" +
              HIG "只见那花开了，五瓣齐舒，中央花心吐蕊，煞是好看。\n" NOR;
        message_vision(msg, me, target);
        me->add("neili", -1000);
        me->set_temp("tanghua", 1);

        tell_object(target, HIC "\n你急忙伸出手去接，但突地，你发现有异，那是一朵铁花，纵身一跃。\n" NOR);
        target->start_busy(5);

        remove_call_out("effect_hua");
        call_out("effect_hua", 0, me, target);

        return 1;
}

int effect_hua(object me, object target)
{
        int myskill, trskill;
        string msg;

        myskill = (int) ( me->query("dodge")+ me->query("biyun-xinfa")+ me->query("neili")+ me->query("tangmen/yanli") );
        trskill = (int) ( 2 * (me->query("dodge"))+ me->query("neili") );
        
        if ( ( myskill >= trskill ) && ( random(100) >= 10 ) && ! me->query("tangmen/potanghua"))
        {
                msg = HIR"那花越开越艳，$n不知不觉中已痴迷了，身形一慢,微笑着倒下了，那花也谢了。\n" NOR;
                message_vision(msg, me, target);
                tell_object(target, HIR "\n你看到那花，果真是一朵铁花。\n你慢慢的伸出手想摘下它，但"
                                        "那花好象变的越来越多了，依稀中你记得那上面有一个小小的“唐”字。\n" NOR);
                me->delete_temp("tanghua");
                me->start_busy(3);
                this_object()->move(target);
                target->receive_wound("qi", 100, me);
                target->unconcious();
        }
        else
        {
                tell_object(target, HIR "果真是唐花，唐门中的唐花。你运足全身的内力，身形掠的更急。\n" NOR);
                msg = HIR "$n身形飘忽，那花划空而过。只听当的一声轻响，那花谢了，轻轻地砸在地面上。\n" NOR;
                message_vision(msg, me, target);
                if ( target->query("neili") < 1000 )
                        target->set("neili", 0);
                else
                        target->add("neili", -1000);
                me->delete_temp("tanghua");
                me->start_busy(2);
                destruct(this_object());
        }
        return 1;
}

