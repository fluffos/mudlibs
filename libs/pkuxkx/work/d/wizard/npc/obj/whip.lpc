// 新手用whip
// By Kiden@pkuxkx

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("芭蕉鞭", ({ "bajiao bian", "bian", "whip" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 0);
                set("material", "steel");
                set("long", "这是一根芭蕉鞭，看起来很结实。\n");
        }
        init_whip(60);
        setup();
}

