//霓裳羽衣
//by junhyun@SK

#include <armor.h>
#include <ansi.h>

inherit SURCOAT;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"霓裳"HIC"羽衣"NOR, ({"nishang yuyi", "cloth", "yuyi" }) );
        set("long", "一件用七彩云霞特别织就的羽衣，触手轻似无物。\n");
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("unique", 1);
                set("armor_prop/armor", 140);
                set("armor_prop/dodge", 50);
                set("armor_prop/personality", 10);
                set("value", 500);
                set("female_only", 1);

        }
        setup();
}

