#include <ansi.h>
#include <weapon.h>
inherit COMBINED_ITEM;
inherit THROWING;

void create()
{
       set_name(HIY "神龙镖" NOR, ({"shenlong biao", "biao"}));
       if( clonep() )
               set_default_object(__FILE__);
       else {
		set("long", "一堆色泽暗红，上铸有飞龙图案的飞镖。\n");               
               set("unit", "堆");
               set("base_value", 10000);
               set("base_unit", "把");
               set("base_weight", 10);
       }
       set_amount(100);
       init_throwing(20);
}

