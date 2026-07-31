//锦缎
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
string check_ip(object ob, object *user);
void create()
{
        set_name("锦缎", ({ "jin duan","duan" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 6000);
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
