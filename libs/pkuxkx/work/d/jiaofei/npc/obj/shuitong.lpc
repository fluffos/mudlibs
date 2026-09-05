// shuitong.c  水桶

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("水桶", ({"shuitong", "tong" }));
        set_weight(60000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "朝廷潜火军专用的水桶，可以装大量的水。\n");
                set("unit", "个");
                set("value", 1000);
                set("max_liquid", 2000);
        }

        set("liquid", ([
                "type": "water",
                "name": "清水",
                "remaining": 0,
                "drink_func": 0,
        ]));
}

void init()
{
    ::init();
    add_action("do_pour","pour");
}

//倒水
int do_pour(string arg)
{
    int number;
    string username;
    object target;
    object me = this_player();
    int fire_cond = 0;
    int exp,pot,money;
        
    if(environment() != me) return 0;
        
    if(!arg || ((sscanf(arg, "%d on %s", number, username) !=2 )))
    {        
        return notify_fail("pour 水的数量 on 玩家\n");
    }
    if(number < 100 )
    {
        return notify_fail("这么点水，刷牙都不够！这是救火啊！！！\n");
    }
    if(number > query("liquid/remaining"))
    {        
        return notify_fail("你的桶里水不够了！\n");
    }
    target = present(username,environment(me));
    if(undefinedp(target) || !objectp(target) || !userp(target))
    {
        return notify_fail("这里没有这个人呢。\n");
    }
    if(query("liquid/type") != "jiaofei_water")
    {
            return notify_fail("普通的清水无济于事，赶快去找道鸟禅师取水！\n");
    }
    
    fire_cond = target->query_condition("jiaofei-fire");
    if(fire_cond <= 0)
    {
        message("vision",me->query("name")+"抄起一个大木桶，把"+target->query("name")+"淋成个落汤鸡\n",environment(me));        
    }
    else
    {
        message("vision",me->query("name")+"抄起一个大木桶，向身上着火的"+target->query("name")+"用力倒去。\n",environment(me));
        fire_cond = fire_cond - number/20;
        if(fire_cond <= 0)
        {
            message("vision",me->query("name")+"终于扑灭"+target->query("name")+"身上的火。\n",environment(me));
            target->apply_condition("jiaofei-fire",0);
            
            //给一点奖励
            //每救一个人，奖励如下
            //exp = 1000 + random(1000)
            //pot = 300 + random(300)
            //money = 10000
            
            exp = 1000 + random(1000);
            pot = 300 + random(300);
            money = 10000;
            
            write(sprintf("你被奖励了经验%d点，潜能%d点，白银%d两！\n",exp,pot,money/100));
            me->add("combat_exp",exp);
            me->add("potential",pot);
            me->add("exp/jiaofei",exp);
    		me->add("pot/jiaofei",pot);
    		me->add("balance",money);                    
        }
        else
        {
            target->apply_condition("jiaofei-fire",fire_cond);
        }
    }
    add("liquid/remaining",-number);
    return 1;
    
}
