// write by Zjb@TY 2003-07-10

#include <armor.h>
inherit BOOTS;
void create()
{
        set_name( HIB "�⻨"HIC"СЬ" NOR, ({ "xiuhua xie","boots","xie" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("material", "cloth");
                set("female_only", 1); 
                set("skill/pixie-jian", "xie");
                set("no_give",1);
                set("no_drop",1);
                set("no_get",1);
                set("ty_paimai",1);
                set("armor_prop/dexerity", 50);
        }
        setup(); 
}

