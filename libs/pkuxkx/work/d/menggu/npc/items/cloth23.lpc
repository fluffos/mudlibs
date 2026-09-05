// cloth2.c
//
// create by zine 30 Aug 2010
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(CYN"灰布道袍"NOR, ({ "huibu daopao", "pao","cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 600);
        }
        setup();
}

