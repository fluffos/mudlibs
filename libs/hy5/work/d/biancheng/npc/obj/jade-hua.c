#include <armor.h>
inherit HEAD;
#include <ansi.h>
 
void create()
{
        set_name(HIG"珠花"NOR, ({ "jade flower"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一朵本应在美人床头的珠花\n");
                set("unit", "个");
                set("value", 3000);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 10);
                set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
                set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n"); 
                set("female_only", 1); 
        }

}       
