// By pingpang

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("青衫", ({"shan", "cloth", "qing shan"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
	    set("male_only", 1);
        set("unit", "件");
		set("long", "这是件质地轻软的青衫,上面镌刻着一些山水风光。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
