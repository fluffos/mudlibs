//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
#include <ansi.h>
inherit ITEM;
void init();
void create()
{
        set_name(HIM"奇怪的瓶子"NOR, ({"jar"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个奇怪的书，好象里面困住了什么，你可以试试打破(dapo)它。\n");
                set("value", 1);
                set("material", "paper");
        }
        setup();
}

