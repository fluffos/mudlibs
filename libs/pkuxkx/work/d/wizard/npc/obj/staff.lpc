// 新手用staff
// By Kiden@pkuxkx

#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("熟铜棍", ({ "shutong gun", "gun", "staff" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 0);
                set("material", "steel");
                set("long", "这是一根很沉的熟铜棍，看起来很耐用。\n");
        }
        init_staff(60);
        setup();
}

