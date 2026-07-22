#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(BLK "黑色长衫" NOR, ({ "chang shan", "cloth","changshan","shan"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件黑色的长衫，是用上好的丝绸剪裁而成，似乎混合了些别的什么料子，看起来非常华贵。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 35);
                set("value", 100);
                set("wear_msg","$N把$n缓缓的披在身上。\n");
                set("remove_msg","$N把$n从身上脱了下来。\n");
        }
        setup();
}
