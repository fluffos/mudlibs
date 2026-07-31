// greenrobe.c 青色道袍
// By Marz
// Modify By River 98/12
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(HIC"青色道袍"NOR, ({"qingse daopao", "pao", "cloth", "daopao"}) );
        set_weight(1500);
        if( clonep())
             set_default_object(__FILE__);
        else { 
            set("unit", "件");
	    set("long", "这是件质地轻软的青色道袍，边上还镂着花呢。\n");
            set("material", "cloth");
            set("armor_prop/armor", 10);
            }
        setup();
}
