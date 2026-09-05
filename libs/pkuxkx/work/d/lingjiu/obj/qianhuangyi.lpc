//qingyi.c
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("浅黄衫", ({"qing yi", "cloth","yi"}) );
    set_weight(2000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
	set("unit", "件");
		set("long", "这是件质量上佳的浅黄衫，是由[针神]亲手缝制的。\n");
	set("material", "cloth");
	set("armor_prop/armor", 10);
        set("value",100);
    }
    setup();
}
