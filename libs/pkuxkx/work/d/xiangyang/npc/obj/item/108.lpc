//cat shedangao.c
inherit ITEM;
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name("蛇胆膏", ({"shedan gao", "gao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是珍贵补品『蛇胆膏』。\n");
                set("value", 1000);
        }
        setup();
}
int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
//        if((me->query("max_jingli")>=800))
//                return notify_fail("你吃『蛇胆膏』已无效用！\n");
        if(me->query("max_jingli")<600)
           {me->add("max_jingli", 12);
            me->add("jingli",12);
            me->add("max_jing",3);
            me->add("jing",3);
           }
        else if (me->query("max_jingli")<1200)
           {me->add("max_jingli",8);
            me->add("jingli",8);
            me->add("max_jing",2);
            me->add("jing",2);
            }
        else 
           {me->add("max_jingli",4);
            me->add("jingli",4);
            me->add("max_jing",1);
            me->add("jing",1);
            }
        message_vision( "$N吃下一块蛇胆膏，顿觉一股浩荡真气直涌上来，精力倍增...\n" , me);
        destruct(this_object());
        return 1;
}
