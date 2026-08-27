#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("警衛盔甲",({"patrol armor","armor"}) );
	set("long",@LONG
這是一件警衛用的盔甲。
LONG
);
	set_weight(8600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("unit", "件");
        }
        set("auto_set",2);
        setup();
}

//int query_autoload() { return 1; }
