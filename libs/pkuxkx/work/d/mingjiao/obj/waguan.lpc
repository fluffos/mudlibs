// 瓦罐 mj新手任务用品

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("瓦罐", ({"wa guan", "guan", "pot"}));
	set_weight(700);
	
		set("long", "一个大瓦罐，可以用来盛水。\n");
		set("unit", "个");
		set("value", 0);
		set("max_liquid", 5+random(10));
	
	set("liquid", ([
		"type": "water",
		"name": "水",
		"remaining": 0,
		"drunk_apply": 1,
	]));
}

void init()
{
    add_action("do_drink", "he");
        add_action("do_drink", "drink");
        add_action("do_fill", "fill");
        add_action("do_fill", "zhuang");
    add_action("do_dao","dao");
}

int do_drink(string arg)
{
        object me = this_player();
        object obj = this_object();

        if( !obj->id(arg) ) return 0;
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");
        if( !query("liquid/remaining") )
                return notify_fail( name() + (query("liquid/name") ? "已经被喝得一滴也不剩了。\n":"是空的。\n"));
        if( (int)me->query("water") >= (int)me->max_water_capacity() )
                return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");

        if( environment() != me && !me->query("env/food"))
                return notify_fail("你身上没有这样东西。\n");


        add("liquid/remaining", -1);
        if((string)obj->query("drink_msg"))
                message_vision(obj->query("drink_msg"), me, obj);
        else
                message_vision("$N拿起$n咕噜噜地喝了几口" + obj->query("liquid/name")+ "。\n", me, obj);
        me->add("water", 30);
        if( me->is_fighting() ) me->start_busy(2);
        if( !query("liquid/remaining") )
        {
                if((string)obj->query("finish_msg"))
                        write(obj->query("finish_msg"));
                else
                        write("你已经将" + obj->name() + "里的" + obj->query("liquid/name")+ "喝得一滴也不剩了。\n");
        }

        // This allows customization of drinking effect.
        if( query("liquid/drink_func") ) return 1;

        switch(query("liquid/type")) {
                case "alcohol":
                        me->apply_condition("drunk",
                                (int)me->query_condition("drunk") 
                                + (int)query("liquid/drunk_apply"));
                        break;
        }
        
        return 1;
}

int do_fill(string arg)
{
        object me = this_player();
        object obj = this_object();

        if( !obj->id(arg) ) return 0;
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");
        if( !environment(me)->query("resource/water") )
                return notify_fail("这里没有地方可以装水。\n");

        if( query("liquid/remaining") )
                message_vision("$N将" + name() + "里剩下的" + query("liquid/name") + "倒掉。\n", me);
        message_vision("$N将" + name() + "装满清水。\n", me);

        me->add_busy(2+random(3));
        
        set("liquid/type", "water");
        set("liquid/name", "清水");
        set("liquid/remaining", query("max_liquid"));
        set("liquid/drink_func", 0);

        return 1;
}


int do_dao()
{
    object ob=this_object();
    object me=this_player();
    if (ob->query("liquid/remaining")<=0)
    {
        tell_object(me,ob->query("name")+"已经一滴水不剩，你什么也没倒出来。\n");
        return 1;
    }
    me->add_busy(3+random(2));
    if (me->query_temp("mingjiao/tasks/taskno")!=4)
    {
        ob->set("liquid/remaining",0);
        message_vision("$N胡乱把瓦罐中的水倒出来，洒了一地。\n",me);
        return 1;
    }
    if (base_name(environment(me))!="/d/mingjiao/houhuayuan1")
    {
        ob->set("liquid/remaining",0);
        message_vision("$N胡乱把瓦罐中的水倒出来，洒了一地。\n",me);
        return 1;
    }
    message_vision("$N小心翼翼地将瓦罐中的水倒进大水缸，一滴都没有洒出来。\n",me);
    me->add_temp("mingjiao/tasks/task4water",ob->query("liquid/remaining"));
    ob->set("liquid/remaining",0);
    if (me->query_temp("mingjiao/tasks/task4water")>100)
    {
        me->set_temp("mingjiao/tasks/task4suc",1);
        message_vision(HIG"不多时，水缸已经被盛满。\n"NOR,me);
        tell_object(me,"你可以回去和龙王复命了。\n");
        return 1;
    }
    else
    {
        message_vision("水缸还有很多空余。\n",me);
        return 1;
    }
}