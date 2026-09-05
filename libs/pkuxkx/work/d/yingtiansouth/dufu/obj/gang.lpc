inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("水缸", ({"shui gang", "gang"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "口");
		set("long", "一口大水缸，盛满了水，平时应对走水的情况，你也可以喝一口。\n");
        set("material", "stone");
		set("value",30);
		set("no_get","你运劲想托起水缸，才发现这个水缸是生铁铸成，连着地面的。\n");
		 set("resource/water", 1);

    }
    setup();
}

void init()
{
	add_action("do_drink","drink");
}


int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;
        me = this_player();
        if(arg)
                return 0;
        current_water = me->query("water");
        max_water = (int)me->max_water_capacity();
        if (current_water<max_water) {
                me->add("water", 50);
                message("vision", me->name()+"舀出一瓢水，喝了起来\n",
                        environment(me), ({me}) );
                write("你喝了一口水。\n");
        }
        else write("你一点也不渴。\n");

        return 1;
}
