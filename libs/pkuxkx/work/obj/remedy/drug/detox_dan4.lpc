#include <ansi.h>
inherit COMBINED_ITEM;
#include "detox.h"
#define POISON "蝎毒"
void create()
{
        set_name(YEL"劣质"+POISON+"解药"NOR, ({"xiedu jieyao", "yao"}));
        set_weight(300+random(60));
        set("long", "这是一枚"+POISON+"解药，可以降低"+POISON+"发作时间。\n");
        set("unit", "枚");
		set("value",25);
		set("dur",3+random(4));
		set("poison","scorpion_poison");
		set_amount(1);
		setup();
}
