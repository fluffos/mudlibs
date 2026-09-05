// yellowrobe.c 黄色道袍
// By Marz

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("黄色道袍", ({"pao", "cloth", "dao pao"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
	    set("female_only", 1);
        set("unit", "件");
		set("long", "这是件质地轻软的黄色道袍，已经很旧了，但却仍然完好，没有一个补丁\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
