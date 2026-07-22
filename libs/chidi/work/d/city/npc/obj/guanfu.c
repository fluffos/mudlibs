
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("官服", ({ "guanfu","cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
		set("no_sell",1);
		set("value",200);
		set("long","一件朝廷命官穿着的官服，上面用金丝线绣着一些花纹。\n");
                set("armor_prop/armor", 20);
        }
        setup();
}
