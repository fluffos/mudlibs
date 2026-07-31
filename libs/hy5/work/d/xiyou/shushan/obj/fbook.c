//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
#include <ansi.h>
inherit ITEM;
void init();
void create()
{
        set_name(HIR"奇怪的书"NOR, ({"fbook"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "一本奇怪的书，你忍不住想打开看一下。\n");
                set("value", 1);
                set("material", "paper");
        }
        setup();
}


