#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name(HIG "剑灵之痕" NOR, ({ "jianling zhihen", "zhihen" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("long", HIG "这是由剑灵的真气结晶而成的宝靴，看上去异常奇特。\n");
                set("xy_money", 300);
                
                set("armor_prop/dex", 10);
                set("armor_prop/T_jianling", 1);
                set("material", "boots");
        }
        setup();
}

int query_autoload()
{
        return 1;
}
