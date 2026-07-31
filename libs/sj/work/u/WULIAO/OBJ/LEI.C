// lei.c 伤心的眼泪

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("伤心的眼泪", ({"yan lei", "lei"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一滴晶莹的泪水。\n");
                set("unit", "滴");
                set("value", 50);
                set("food_remaining", 3);
                set("food_supply", 20);
                  set ("combat_exp", 50000);
                   set ("potential", 50000);
        }
}

