#include <ansi.h>

inherit ITEM;

int do_eat(string);


void init()
{                                  
  add_action("do_eat", "eat");

}

void create()
{
        set_name(HIR"Ｍ"HIY"＆"HIB"Ｍ"HIW"'"HIG"ｓ"NOR, ({"mms"}));
	set_weight(20);
	if (clonep())
	    set_default_object(__FILE__);
	else {
	set("unit", "颗");
	set("long", "一捧五颜六色的"+this_object()->name()+"巧克力豆，●○●○●○●○～～ 真是一粒在手，三天吃饭不愁。\n");
	
	set("value", 300000);
	set("food_supply", 150);
	set("food_remaining",1);

        set("no_put",1);
        set("no_sell",1);
        
        set("remaining", 4);
	}


	setup();
}

int do_eat(string arg)
{       
        object me = this_player();
        if (!living(me)) return notify_fail("想当机吗？\n");
        if (!id(arg)) return 0;
        if( me->query("food") > me->max_food_capacity())
             return notify_fail("你已经吃饱了，什么也吃不下了。\n");
        set("value", 0);
        me->add("food", (int)query("food_supply"));
        add("remaining", -1);

        if ( this_object()->query("remaining")){
            message_vision("$N脸带微笑，甜蜜地咬了一口"+this_object()->query("name")+"，只觉得香滑可人。\n",me);
        }
        else{ 
            message_vision("$N咬下了最后一口"+this_object()->query("name")+"，脸上浮现出满足的微笑。\n",me);
            destruct(this_object());
        }
        return 1;
}
