// jingwei-stone.c 精卫石

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIY "精卫石" NOR, ({ "jingwei stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIY "相传精卫是炎帝的小女儿，名叫女娃。去东海游玩时，不慎落水淹死，变\n"
                                "成了精卫鸟。为报淹死之仇，她经常叼着西山的木石，想把东海填平。\n" NOR);
                set("value", 50000);
                set("unit", "块");
                set("can_be_enchased", 1);
                set("enchased_armor", 1);
                set("magic/type", "fire");
                set("magic/power", 100);
                set("armor_prop/per", 5);
                set("wear_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "戴在头上。\n" NOR);
                set("remove_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "从头上摘了下来。\n" NOR);
        }
        setup();
}

int query_autoload() { return 1; }

