#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIB "蓝色缎袍" NOR, ({ "duan pao", "cloth","duanpao","pao"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件做工精细的蓝色长袍，似乎是用名贵的江南绸缎剪裁而成。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 35);
                set("value", 100);
                set("wear_msg","$N把$n随意一挥，缓缓的披在身上。\n");
                set("remove_msg","$N轻轻的把$n从身上脱了下来。\n");
        }
        setup();
}
