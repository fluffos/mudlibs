// bow.c
//2005.6.6

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("长猎弓", ({ "hunter bow", "bow"}) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("value", 2000);
                set("material", "wood");
                set("long", "这是一张普通的木制猎弓。\n");
                set("wield_msg", "$N从背后抽出一张$n挽在手中。\n");
                set("unwield_msg", "$N将手中的$n插回背后。\n");
                set("unequip_msg", "$N将手中的$n插回背后。\n");
               }       
        setup();
}
