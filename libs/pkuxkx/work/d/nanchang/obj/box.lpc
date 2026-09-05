//create by zine Aug 28 2010
#include <ansi.h>


inherit ITEM;

void create()
{	
	set_name(HIY"藏宝箱"NOR, ({ "cangbao xiang","xiang"}));
	set_weight(5000);
	set("long", "这是从鄱阳湖底取出的藏宝箱，你却不知道怎么开启。\n");
	set("material", "wood");
	set("unit", "个");
	set("value", 10);
    set("pyh",1);
	set("pyh_gem_box",1);
	setup();
        call_out("dest",1800);	
}

int dest()
{
    if (this_object())
    {
        message_vision("藏宝箱突然不见了。\n",this_object());
        destruct(this_object());
    }
    return 1;
}
