//Cracked by Roath
//fear 2002 1 31
// /d/lingshedao/obj/yangpi.c
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW"√‡—Ú∆§"NOR, ({ "sheep skin", "pi", "mianyang pi" }) );
        set_weight(3500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "øÈ");
                set("material", "fur");
                set("value", 5000);
                set("armor_prop/armor", 4);
        }
        setup();
}

