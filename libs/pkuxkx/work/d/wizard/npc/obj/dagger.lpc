// 新手用staff
// By Kiden@pkuxkx

#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("峨嵋刺", ({ "emei ci", "ci", "dagger" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 0);
                set("material", "steel");
                set("long", "这是一根锋利的峨嵋刺，看起来很耐用。\n");
        }
        init_dagger(60);
        setup();
}

