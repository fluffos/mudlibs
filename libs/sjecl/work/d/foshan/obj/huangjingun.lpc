// huangjingun.c 黄金棍

#include <weapon.h>
#include <ansi.h>
inherit CLUB;

void create()
{
        set_name(HIY "黄金棍" NOR, ({ "huangjin gun","gun" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
		set("unique", 1);
                set("long", "这金棍长达七尺，径一寸有半，通体黄金铸成。\n");
                set("value", 50000);
                set("material", "steel");
                set("wield_msg", "$N将$n一抖，握在手中，顺手抖起两朵金花，只见金光耀眼。\n");
                set("unwield_msg", "$N收起手中的$n，金光忽然消失不见。\n");
        }
                init_club(120);
        setup();
}
