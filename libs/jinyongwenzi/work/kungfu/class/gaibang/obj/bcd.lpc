//  gaibang-bcd by hunthu

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_fu", "fu");
}

void create()
{
        set_name("百草丹", ({"bai caodan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗百草丹，据说是丐帮弟子在与蛇虫相斗中配制的解毒药品。\n");
                set("value", 100);
                set("no_drop", 1);
                set("no_give",1);
                set("no_put",1);
        }
        setup();
}

int do_fu(string arg)
{
        object me;
        me = this_player();
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
        if( me->is_fighting() )
                return notify_fail("战斗中不能吃药疗伤！\n");
        if ((int)this_player()->query("eff_jing") ==
            (int)this_player()->query("max_jing"))
                return notify_fail("你现在没伤，瞎吃什麽药？\n");
        
        else {
if ((int)me->query_condition("snake_poison") > 0||(int)me->query_condition("scorpion_poison ")>0) 
       {
           me->apply_condition("snake_poison",0);
           me->apply_condition("scorpion_poison", 0);
         }
        me->receive_curing("jing", 500);
       message_vision("$N服下一颗百草丹。\n", this_player());
        me->start_busy(2);
                destruct(this_object());
                return 1;
        }
}
