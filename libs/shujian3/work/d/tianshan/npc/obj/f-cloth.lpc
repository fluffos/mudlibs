// Obj: /d/tianshan/npc/obj/f-cloth.c
// By Linux
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
string *color_name = ({
HIR"红色",HIG"绿色",YEL"土黄色",HIY"黄色",BLU"深蓝色",
HIB"蓝色",MAG"紫色",HIM"粉红色",HIC"天青色",HIW"白色",});

void create()
{
        set_name(color_name[random(sizeof(color_name))]+"小夹衫"NOR, ({ "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是件小夹衫。\n");
                set("unit", "件");
                set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 10+random(15));
                set("armor_prop/personality", 1);
                set("female_only", 1);
        }
        setup();
}
