
#include <armor.h>
inherit PANTS;

void create()
{
	set_name("褲子",({ "pants" }) );
	set("long",@LONG
這是一件有著花色格子圖樣的褲子。
LONG
);
	set_weight(1300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        set("auto_set",2);
        setup();
}

//int query_autoload() { return 1; }
