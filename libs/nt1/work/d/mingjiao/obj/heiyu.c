// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// heiyu.c

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "fu");
}

void create()
{
        set_name(HIW "黑玉断续膏" NOR, ({"heiyu duanxugao", "gao", "heiyu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "盒");
                set("heiyu", 3);
                set("long", "一盒疗伤圣药黑玉断续膏，名虽黑玉，实则雪白。\n");
                set("value", 100000);
        }
        setup();
}

int do_eat(string arg)
{
        object me, ob;
      
        me = this_player();
        ob = this_object();

        if (! id(arg))
                return notify_fail("你要服什么？\n");
                
        if (this_player()->is_busy() || this_player()->is_fighting())
                return notify_fail("你正忙着呢。\n");
                
        if ((int)this_player()->query("eff_qi") == 
            (int)this_player()->query("max_qi"))
                return notify_fail("你现在不需要用黑玉断续膏。\n");

        if (ob->query("heiyu") > 0)
        {      
                me->receive_curing("qi", me->query("max_qi"));
                me->receive_curing("jing", me->query("max_jing")/2);
                me->add("neili",me->query("max_neili")/10);
                me->set("food", me->max_food_capacity());
                me->set("water", me->max_water_capacity());
                message_vision(HIW"$N把黑玉断续膏涂在伤口上，只觉伤势大为好转。\n"NOR, me);
                ob->add("heiyu", -1);   
                this_player()->start_busy(3);      
                return 1;
        }
        
        if (ob->query("heiyu") < 1)
        {
                write("盒中的黑玉断续膏已经所剩无几了。\n");
                ob->set("long", "一个用来盛疗伤圣药黑玉断续膏的木盒。\n");
                ob->set("value", 5000);
                return 1;
        }
}

