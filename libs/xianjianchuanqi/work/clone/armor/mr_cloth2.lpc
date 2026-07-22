#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIB "白色长杉" NOR, ({ "chang shan", "cloth","changshan","shan"}));
        set_weight(3500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件剪裁很好的白色棉布长衫，穿起来非常潇洒。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 25);
                set("value", 100);
                set("wear_msg","$N缓缓的把$n穿在身上。\n");
                set("remove_msg","$N的把$n从身上脱了下来。\n");
        }
        setup();
}
