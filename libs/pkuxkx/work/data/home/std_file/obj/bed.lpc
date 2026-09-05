//Created By Pal
//cometh@tom.com
//2003.10.5
//物品类物品模板
#pragma save_binary

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("标准物品", ({ "biaozhun wupin" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "单位");
                set("material", "wood");
        }
		set("no_get",1);
		set("selfcreate",1);
		set("value",VALUE);
        setup();
}
