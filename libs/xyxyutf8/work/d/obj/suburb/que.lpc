#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(HIR"御"HIR"赐  "HIW"平"HIY"乱"HIC"炔"NOR, ({ "que","necklace" }) );
        set("level",7);
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("no_zm",1);
                set("no_give",1);
                set("no_get",1);
                set("material", "pearl");
		set("value", 0);
                set("no_put",1);
                set("armor_prop/armor", 80);
        }
        setup();
}

