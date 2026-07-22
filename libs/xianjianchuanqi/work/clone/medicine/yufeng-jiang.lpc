#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_drink", "drink");
}

void create()
{
        set_name(HIY"玉蜂浆"NOR, ({"yufeng jiang", "jiang"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "瓶");
                set("long", "这是一个小瓶子,散发着一股浓郁的甜香之气，你不由的咽了一口口水。\n");
                set("value", 1000000);
                set("no_drop", 1);
                set("no_get", 1);
                 }
        setup();
}

int do_drink(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("你要喝什么？\n");

        if ( me->query_skill_mapped("force") != "yunu-xinjing" )
      {
       
                write("所练内功不符，这玉蜂浆恐怕对你没有什么作用！\n");

                return 1;
            }  

         if ( me->query("max_neili") < 400 )
        {
    message_vision(HIR "$N喝下玉蜂浆，只觉蛮口甘甜，可惜内力修为尚缺，没有什么收益！\n" NOR, me);
        }
        else if ( (int)me->query_condition("medicine" ) > 0 )
     
        {
         me->add("max_neili",-5);                         
           message_vision(HIR "$N喝下玉蜂浆，可惜服食太急太多，药效无法吸收，反而有损真气！\n" NOR, me);
        }
         else if ((me->query_skill("force")*8 +  me->query("combat_exp",1)/1000 ) <= me->query("max_neili") )
        { 
                message_vision(HIR "$N喝下玉蜂浆，只觉得药性平平，难以再提高你的修为了！\n" NOR, me);
        }
        else
        {
                me->add("max_neili", 1);
       message_vision(HIG "$N喝下玉峰浆，只觉得浑身上下舒坦，似乎功力有所提高！\n" NOR, me);
              me->apply_condition("medicine", 60);
        }
        destruct(this_object());
        return 1;
}

