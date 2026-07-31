// cai by -wyz
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(  "回鍋肉" , ({"meat"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "这是一碟香喷喷的四川名菜。\n" NOR);
                set("unit", "碟");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
                set("eat_msg", "$N夹起一块$n，轻轻一口，只觉香馥无比。\n");
        }
}

