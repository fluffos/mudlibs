// ping.c 蜂浆瓶
// 可以用来使用驱蜂之术，驱使玉蜂


#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("蜂浆瓶", ({ "fengjiang ping", "bottle", "ping" }));
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "jade");
                set("unit", "个");
                set("long", "这是一个用上古美玉雕成的小瓶，还未拔开瓶塞，就可以闻到一股浓郁的香味，可以用来驱蜂。\n") ;
                set("value", 0);
                set("jian", 10);
        }
}

void init()
{
        add_action("do_qufeng", "qufeng");
}

int do_qufeng(string arg)
{
        object me=this_player(), obj;
        int myexp, objexp, mylev, objlev, myforce, obforce;
        int steps;
        if(me->query("family/family_name")!="古墓派")
                return notify_fail("你的师傅并不会驱蜂术呀。\n");
        if( !environment(me) || environment(me)->query("no_fight") )
                return notify_fail("这里禁止战斗。\n");
        if( me->is_busy() )
                return notify_fail("你正忙着。\n");
        if( !arg )
                return notify_fail("你想驱蜂攻击谁？\n");
        if( query("jian") <= 0 )
                return notify_fail("小瓶里的玉蜂蜜已经给用光了。\n");
        if( !objectp(obj = present(arg, environment(me))) )
                return notify_fail("这里没有这个人。\n");
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");
        if( obj == me )
                return notify_fail("玉蜂不能攻击你。\n");

        myexp = me->query("combat_exp")/100;
        objexp = obj->query("combat_exp")/100;
        mylev = me->query_skill("qufengshu");
        objlev = obj->query_skill("qufengshu");
        myforce = me->query_skill("force");
        obforce = obj->query_skill("force");

        if( mylev <= 0 )
                return notify_fail("你不会驱蜂之术，不能驱使玉蜂为你攻击敌人！\n");
                
        if( me->query_skill("yunu-xinfa", 1) < 30 )
                return notify_fail("你的玉女心法等级不够，无法驱使玉蜂为你攻击敌人！\n");

        myexp = 30 * objexp / myexp;
        if( myexp < 30 ) myexp = 30;

        if( (int)me->query("jing") < myexp )
                return notify_fail("你的精不足以驱动玉蜂伤敌！\n");
        if( (myforce + 15) <= obforce )
                return notify_fail("对手的内功太深厚了，驱蜂术对他不起作用！\n");

        add("jian", -1);
        steps = (mylev - objlev) / 10;
        if( steps < 2 ) steps = 2;
        if( steps > 6 ) steps = 6;

        message_vision(HIY "\n$N拔开玉瓶塞，手捂玉瓶潜运内力，使得瓶中的香气远远飘了开去，\n"
                "突然嗡嗡之声大作，不知道从哪里飞来一大群玉蜂，向$n围了过去。\n" NOR, me, obj);

        if( userp(obj) )
                obj->fight_ob(me);
        else
                obj->kill_ob(me);
        me->fight_ob(obj);

        if( random(mylev) < objlev*2/3 ) {
                message_vision(YEL "\n但$n撮唇一啸，玉蜂似乎听懂了号令，远远避了开去。\n" NOR, me, obj);
                me->start_busy(3);
        } else {
                tell_object(obj, HIR "\n你周围刹那间尽是玉蜂围绕，一只只玉蜂悍不畏死地向你蜇了过来，\n"
                        "你只觉得背心微微一痛，已被玉蜂蜇中！\n" NOR);
                obj->receive_wound("jing", steps*5, "被古墓玉蜂蜇");
                obj->receive_wound("qi", steps*6, "被古墓玉蜂蜇");
                if (!obj->is_busy())
                obj->start_busy(3+random(5));
                me->start_busy(1);
                remove_call_out("disperse");
                call_out("disperse", 6, obj);
        }
        me->receive_damage("jing", myexp);
        return 1;
}

void disperse(object ob)
{
        if( !ob ) return;
        message_vision("蜂群终于从$N周围散开了！\n"  , ob );
}
