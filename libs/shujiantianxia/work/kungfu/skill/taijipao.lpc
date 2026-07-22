// /clone/armor/taijipao.c 太极道袍

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"太极道袍"NOR, ({ "taiji daopao", "dao pao", "daopao" }));
        set_weight(2500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW"这是一领武当山张真人亲制的风雪色白绒道袍，乍一看是棉布粗麻所制。\n细细观察却见袍身是用罕见的软甲缠丝编织而成。\n暗色成"HIC"阴"HIW"，亮色为"HIR"阳"HIW"，勾轮圆转成一个【太极】图形。\n"NOR);
                set("material", "silk");
                set("unit", "领");
                set("unique", 1);
                set("value", 1000000);
                set("wear_msg", HIW "只见$N翻身披上一领雪绒道袍，仿佛一轮"HIC"太极"HIW"随身和形而起。\n" NOR);
                set("remove_msg", HIW "$N和身解下一领雪绒色太极道袍。"HIC"太极圆转"HIW"之形顿时消于无形。\n" NOR);
                set("treasure",1);
                set("armor_prop/armor", 75);
                set("armor_prop/parry", 10);
        }
        setup();
}
