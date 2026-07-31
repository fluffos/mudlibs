// huxin-dan.c

#include <ansi.h>

inherit ITEM;

void init()
{
             add_action("do_eat", "eat");
             add_action("do_eat", "fu");
}

void create()
{
        set_name("天王护心丹", ({"huxin dan","dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
                "武当派丹药，疗重伤。\n");
                set("value", 10);
                set_weight(25);
                set("unit", "颗");
                set("no_get", 1);
                set("no_drop", 1);
                set("no_give", 1);
        }
}

int do_eat(string arg)
{
        object me;
        mapping fam;
        me = this_player();
        if (!id(arg)) return 0;
        if( (int)me->query_condition("medicine") > 0 )
                return notify_fail("你上次的药劲儿还没过呢，等会再吃吧。\n");
        if( (int)me->query("eff_qi") > (int)me->query("max_qi")/2 )
                return notify_fail("你没受重伤，吃了这颗灵丹妙药岂不可惜？\n");
        if( (int)me->query("eff_qi") < (int)me->query("max_qi")/10 )
                return notify_fail("你的伤势过重，还是想其他办法吧。\n");
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="武当派")
               {
                tell_object(me, "ｏｏｐｓ！你突然发现身上少了一颗天王护心丹。。。\n");
                destruct(this_object());
                return 1;
               }

        if((int)me->query("combat_exp") < 100000 )
                return notify_fail("你的实战经验太低。\n");
        if((int)me->query_skill("yinyun-ziqi", 1) < 80 )
                return notify_fail("你的氤氲紫气功力不够深厚。\n");
        if((int)me->query_skill("medicine", 1) < 60 )
                return notify_fail("你的药理知识还不足。\n");

        message_vision(GRN"\n$N服下一颗天王护心丹，感觉伤势大转！\n\n"NOR , me);
        me->apply_condition("medicine", 60);
        me->set("eff_qi",(int)me->query("max_qi"));
        me->set("qi",(int)me->query("max_qi"));
        destruct(this_object()); 
        return 1;
}