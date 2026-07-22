#include <ansi.h>;
inherit ITEM;

void create()
{
     set_name(HIW"银钥匙"NOR, ({"yin yaoshi","silver key","key"}));
     set_weight(10);
     if (clonep())
           set_default_object(__FILE__);
     else {
           set("unit", "把");
           set("long", "这是一把白银打制的钥匙，上书古墓字样，似乎和古墓的某些秘密有关。\n");
           set("unique", 1);
           set("value", 400);
     }
     setup();
}
