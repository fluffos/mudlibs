// dumpling.c
inherit ITEM;

void create()
{
        set_name("饭盒", ({"fan he", "fan"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个小巧的饭盒，摸着还热腾腾的．\n");
                set("unit", "个");
                set("food_remaining", 1);
                set("food_supply", 200);
        }
}

int do_eat(string arg)
{

        object me = this_player();
        if (!arg || !id(arg))
                return notify_fail("你要吃什么？\n");

	message_vision("$N悄悄打开饭盒扒了几口饭，差点没噎死！\n", me);
	me->set("food",me->max_food_capacity());
	destruct(this_object());
        return 1;
}


