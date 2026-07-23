#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(WHT "灰色长衫" NOR, ({ "chang shan", "cloth","changshan","shan"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件灰色的长衫，是用棉布剪裁而成，做工非常好。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 15);
                set("value", 100);
                set("wear_msg","$N把$n缓缓的披在身上。\n");
                set("remove_msg","$N把$n从身上脱了下来。\n");
        }
        setup();
}
