// cloth.c
//
// This is the basic equip for players just login.
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(HIW "婚纱" NOR, ({ "marry dress"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这件雪白的婚纱出自设计宫廷名师之手，穿上它真是艳丽动人，煞是性感。\n");
                set("unit", "件");
                set("value", 1000);
                set("armor_type", "cloth");
                set("armor_prop/personality", 1);
                set("wear_msg","$N穿上一件$n。\n");
                set("remove_msg","$将$n脱了下来。\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
