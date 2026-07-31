//standard blade.c(第二档) edit by lin on March 3,  97
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name("单刀", ({ "blade"}) );
        set_weight(2500);
        set("long","一把精钢打就的刀，长约二尺半，柄系黄丝，刀面光可鉴人。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",1500);
                set("material", "steel");
        }
        init_blade(60);
        set("wield_msg", "$N「唰」的一声抽出一把明晃晃的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插入腰间。\n");
        setup();
}
