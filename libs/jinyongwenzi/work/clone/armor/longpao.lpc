// /clone/armor/longpao.c 龙袍

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"龙袍"NOR, ({ "longpao", "long pao", "pao" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY"这是一件手工精细无比的的龙袍，上面镶满了玉石玛瑙等绝世珍宝，用西
域独有的啸天狒的体毛织成，闪烁着异样的光彩，刀剑不入。这是慕容世
家祖传镇国之宝，据说慕容祖上为此而穷十年之心力搜集而制成。\n"NOR);
                set("material", "silk");
                set("unit", "件");
                set("unique", 1);
                set("value", 1000000);
                set("wear_msg", HIY "只见$N披上一件龙袍，尊贵庄严，使人不敢仰视。\n" NOR);
                set("remove_msg", HIR "$N脱下一件「"HIY"龙 袍"HIR"」，看左右无人，小心翼翼的放了起来。\n" NOR);
                set("treasure",1);
                set("armor_prop/armor", 80);
        }
        setup();
}
