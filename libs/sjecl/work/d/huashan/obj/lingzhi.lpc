// ITEM: /d/huashan/obj/lingzhi.c
// Date: Look 99/03/25

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("灵芝草", ({"lingzhi cao", "lingzhi", "cao"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
                set("long", HIY"这是一棵生长在山崖上的灵芝草，灵效无比。\n");
                set("value", 10000);
              set("no_drop", 1);
              set("no_give", 1);
              set("no_get", 1);
        }

        set("huashan",1);
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("你要吃什么？\n");


        if ( me->query_skill_mapped("force") != "zixia-gong" )
        {
                me->add("max_neili", -10);
                message_vision(HIR "$N吃下一棵灵芝草，只觉得肝肠寸断，原来所此草久生于华山之上，反而大损你的真气！\n" NOR, me);
                me->unconcious();
                destruct(this_object());
                return 1;
        }

        if ( me->query("max_neili") < 400 )
        {
                me->add("max_neili", -1);
                message_vision(HIR "$N吃下一棵灵芝草，只觉得头重脚轻，摇摇欲倒，原来功力不够，服食仙草，药效适得其反！\n" NOR, me);
        }
            else if ( (int)me->query_condition("medicine") > 0 )
        {
                me->add("max_neili", -5);
                message_vision(HIR "$N吃下一棵灵芝草，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
        }
         else if ((me->query_skill("force")*8 +  me->query("combat_exp",1)/1000 ) <= me->query("max_neili") )
        { 
                message_vision(HIR "$N吃下一棵灵芝草，只觉得纵然仙草灵验，也难以再提高你的修为了！\n" NOR, me);
        }
        else
        {
                me->add("max_neili", 1);
                message_vision(HIG "$N吃下一棵灵芝草，只觉得体内真力源源滋生，功力顿然提高 !\n" NOR, me);
        }
            me->apply_condition("medicine", 60);
        
        destruct(this_object());
        return 1;
}
