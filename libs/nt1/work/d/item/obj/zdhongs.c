// zdhong-stone.c 照殿红

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIR "照殿红" NOR, ({ "zdhong stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIR "此石是红宝石的最珍惜的一种。色彩艳丽无方，在光线的照射下会反射出\n"
                                "迷人的六射星光。人们把它看成爱情、热情和品德高尚的代表，光辉的象\n"
                                "征。传说佩戴照殿红的人将会健康长寿、爱情美满、家庭和谐。相传昔日\n"
                                "的武士在身上割开一个小口，将一粒红宝石嵌入口内，认为这样可以达到\n"
                                "刀枪不入的目的。\n" NOR);
                set("value", 500000);
                set("unit", "块");
                set("can_be_enchased", 1);
                set("enchased_armor", 1);
                set("magic/type", "gold");
                set("magic/power", 100);
                set("armor_prop/per", 7);
                set("wear_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "戴在头上。\n" NOR);
                set("remove_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "从头上摘了下来。\n" NOR);
        }
        setup();
}

int query_autoload() { return 1; }

