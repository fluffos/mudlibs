
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM"皇宫通行令"NOR, ({ "huanggong ling" }) );
        set_weight(100);
        set("unit", "面");
        set("long", "这是一面皇宫通行令，有它以后整个太极宫可以通行无碍。\n");
        set("value", 10000);
        set("no_put",1);
        set("no_drop",1);
        set("no_sell",1);
        set("no_give",1);
        set("material", "gold");
        setup();
        call_out("do_dest",900);
}

void do_dest()
{
        if ( objectp(environment(this_object())) )
	        tell_object(environment(this_object()), "只见走过来一个金吾卫，说道：你的皇宫通行令到期了。\n");
	      destruct(this_object());
}