#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("Ìú»¤¼×", ({ "tie hujia","jia","hujia" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
              set("value", 3000);
                set("material", "steel");
             set("armor_prop/armor", 30);
        }
        setup();
}
