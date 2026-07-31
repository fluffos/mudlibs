// longxia.c 
// By dream

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIR "红烧大龙虾" NOR, ({ "da longxia", "longxia" }) );
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一只又鲜又香的大龙虾，是随意为了庆祝中国队进求而特意烹调的。\n");
                set("unit", "只");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
}







