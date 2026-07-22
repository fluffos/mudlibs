// /clone/armor/yellow-cloth.c
// by dubei

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(YEL "黄色僧袍" NOR, ({ "seng pao", "cloth" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件黄色僧袍,里面衣襟绣着一把带血的短刀。\n"
                            "刀尖有三滴鲜血滴下,也是红线绣成,形态生动,十分可怖.\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 40);
                set("wear_msg","$N随手一展,将$n披在身上。\n");
                set("remove_msg","$N把$n从身上脱了下来。\n");
        }
        setup();
}

