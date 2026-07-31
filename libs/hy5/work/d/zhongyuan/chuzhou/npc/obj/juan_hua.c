// 绢花 /d/city/chuzhou/npc/obj/juan_hua.c

#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
    set_name( MAG"绢花"NOR, ({"juan hua", "hua", "flower"}));
    set_weight( 15 );
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", @LONG
山东曲阜不但是圣人之乡，也出产美丽的绢花。
LONG
        );
        set("unit", "朵");
        set("material", "cloth");
        set("value", 30);
        set("armor_prop/personality", 2);
    }
}
