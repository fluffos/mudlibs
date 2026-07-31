// jiedu-dan.c

#include <ansi.h>

inherit ITEM;

void init()
{
             add_action("do_eat", "eat");
             add_action("do_eat", "fu");
}

void create()
{
        set_name("天心解毒丹", ({"jiedu dan","dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
                "武当派丹药，解毒用。\n");
                set_weight(25);
                set("value", 10);
                set("unit", "颗");
                set("no_get", 1);
                set("no_drop", 1);
                set("no_give", 1);
        }
}

int do_eat(string arg)
{
        object me;
        int i,plvl,cure;
        mixed a;
        mapping fam;
        string poison;
        a = ({"snake_poison","xx_poison","dsy_poison","fs_poison","huagu_poison","man_poison","qinghua_poison","qishang_poison","qzhu_poison","sl_poison","sy_poison","warm_poison","hot_poison","cold_poison","bing_poison","hb_poison","bt_poison"}); 
        me = this_player();
        cure = 10 + random(20);
        for( i=0; i < sizeof(a); i++ )
                        if( me->query_condition(a[i]) > 0 )
                        {
                                poison = a[i];
                                break;
                        }
        if (!id(arg)) return 0;
        if( (int)me->query_condition("medicine") > 0 )
                return notify_fail("你上次的药劲儿还没过呢，等会再吃吧。\n");

        plvl= me->query_condition(poison , 1);

        if (!(fam = this_player()->query("family")) || fam["family_name"] !="武当派")
               {
                tell_object(me, "ｏｏｐｓ！你突然发现身上少了一颗天心解毒丹。。。\n");
                destruct(this_object());
                return 1;
               }

        if( plvl == 0 )
                return notify_fail("你并没中毒，小心吃错了药！\n");
        if((int)me->query("combat_exp") < 100000 )
                return notify_fail("你的实战经验太低。\n");
        if((int)me->query_skill("yinyun-ziqi", 1) < 80 )
                return notify_fail("你的氤氲紫气功力不够深厚。\n");
        if((int)me->query_skill("medicine", 1) < 60 )
                return notify_fail("你的药理知识还不足。\n");

        message_vision(MAG"\n$N服下一颗天心解毒丹，感到体内所中的毒有所减轻！\n\n"NOR , me);
        me->apply_condition("medicine", 3);
        if (plvl < cure) 
            me->apply_condition(poison, 0);
        else me->apply_condition(poison, plvl-cure);
        destruct(this_object()); 
        return 1;
}