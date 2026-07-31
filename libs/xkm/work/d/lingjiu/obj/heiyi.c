//qingyi.c
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("黑衣", ({"hei yi", "cloth","yi"}) );
    set_weight(2000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
	set("unit", "件");
		set("long", "这是一件特制的黑衣，上面绣着一只灵鹫。\n");
	set("material", "cloth");
	set("armor_prop/armor", 10);
        set("value",100);
    }
    setup();
}
