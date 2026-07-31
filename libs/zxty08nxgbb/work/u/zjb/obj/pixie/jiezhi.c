// write by Zjb@TY 2003-07-10

#include <armor.h>
inherit FINGER;
void create()
{
        set_name(HIY"½ð"HIW"½ä"HIG"Ö¸"NOR, ({ "jin jiezhi","jiezhi" , "ring" }));
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
                set("material", "gold");
                set("no_give",1);
                set("no_drop",1);
                set("no_get",1);
                set("ty_paimai",1);
                set("skill/pixie-jian","jiezhi");
                set("armor_prop/strength", 100);
                set("armor_prop/armor", 1);
        }
        setup();
}       

