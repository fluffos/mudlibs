#include <weapon.h>
inherit SWORD;
#include <ansi.h>

void create()
{
        set_name(YEL"开天魔剑"NOR, ({ "kaitian mojian", "mojian", "jian" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", HIY"这是上古时候诸神使用的魔剑,据说蕴藏了巨大的魔力。\n"NOR);
               set("value", 0);
                set("material", "steel");
                set("wield_msg", HIW""BLK "$N抽出一把散发着阵阵黑气的宝剑，刹那间，连空气也停止了流动。\n"NOR);
                set("unwield_msg", HIW""BLK "$N将宝剑收入鞘中，空气终于开始流动了。\n"NOR);
        }
        init_sword(1600);
    set("no_get",1);
    set("no_give",1);
        setup();
}

