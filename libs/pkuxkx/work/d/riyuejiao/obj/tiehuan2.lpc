// tiehuan2 铁环
// by bing

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("铁环", ({ "tie huan","huan" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
		set("long", "这是一只精钢打造的铁环，上面有一道细细的裂口，好象被锯子锯过。\n" NOR);
                set("material", "steel");
                set("armor_prop/armor", -1);
		set("mingjiao",1);
        }
        setup();
}

