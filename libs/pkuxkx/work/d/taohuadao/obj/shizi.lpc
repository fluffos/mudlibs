// shizi.c 玉石子

#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
    set_name(HIW"玉石子"NOR, ({ "shi zi", "stone" }));
    set_weight(150);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "把");
        set("base_unit", "枚");
        set("long", HIW"这是一枚白里透亮的石子，不过在暗器高手的手里可是杀人的利器。\n"NOR);
        set("value", 10);
        set("base_weight", 15);
        //set("material", "stone");
        set("wield_msg", "$N不知道从哪里拿出起一枚$n，捏在手中。\n");
        set("unwield_msg", "$N手中的$n又不知道跑哪里去了。\n");
    }
    set_amount(10);
    init_throwing(30);
    setup();
}

