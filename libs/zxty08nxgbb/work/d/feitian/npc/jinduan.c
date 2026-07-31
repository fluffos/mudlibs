//½õ¶Ð
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
string check_ip(object ob, object *user);
void create()
{
        set_name("½õ¶Ð", ({ "jin duan","duan" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("value", 6000);
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
