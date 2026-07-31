#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name(YEL"东方金铁之英"NOR, ({ "golden iron" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一块平滑如镜的玄铁。\n");
                set("value", 3);
                set("for_create_weapon",1);
                set("material", "iron");
        }
        ::init_hammer(50);
}      
