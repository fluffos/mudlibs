// yuxiao.c 玉箫

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(GRN "玉箫" NOR, ({ "yu xiao", "xiao" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", "这是一支玉箫，他是黄药师的特殊兵器。\n");
                set("value", 100);
                set("material", "玉");
                set("music", "shaw");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插到背后。\n");
        }
        init_sword(25);
        setup();
}
