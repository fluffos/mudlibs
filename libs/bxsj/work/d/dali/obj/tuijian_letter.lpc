// Modify By River 98/12
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"推荐信"NOR, ({ "tuijian xin", "xin", "letter" }));
        set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit","封");
		set("long","这是一封镇南王亲笔手书的推荐信，信是写给天龙寺了惑禅师的。\n");
                set("no_get", 1);              
                set("material", "paper");
         }
}
