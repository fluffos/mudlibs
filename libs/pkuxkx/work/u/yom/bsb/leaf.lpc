// cloth.c
//
// This is the basic equip for players just login.

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIG"木头叶子"NOR,({"leaf"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("auto_load", 1);
                set("material", "cloth");
                set("armor_prop/armor", 999);
        }
        setup();
}
void init()
{
        return query("name");
}
void autoload()
{}

