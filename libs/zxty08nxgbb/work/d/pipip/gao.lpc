inherit ITEM;
void create()
{
        set_name(BLINK HIM"生日"HIC"蛋糕"NOR, ({ "cake",}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIG"西门无剑(Pipip)终于十七岁了，这是一小块他亲手精制的生日蛋糕。\n");
                set("unit", "块");
                set("value",0); 
                set("no_get",1);
                set("no_drop",1);
                set("no_give",1);        }
    setup();
}
void init()
{
    if (environment()==this_player())
        add_action("do_eat", "eat");
}
int do_eat(string arg)
{
  object me = this_player();
  int food,water;
    food = me->query("food");
    water = me->query("water");
    
  if(!id(arg)) return 0;
  if(me->is_busy()) return notify_fail("你上一个动作还没有完成。\n");

       me->set("food", 17000);
       me->set("water", 17000);
       if(me->is_fighting()) me->start_busy(20);
       message_vision(HIM"$N一口吞下小蛋糕，只觉美味极了，差点没把舌头也一起吞下去。\n"NOR,me);
       me->start_busy(10);
       destruct(this_object());
       return 1;
}

