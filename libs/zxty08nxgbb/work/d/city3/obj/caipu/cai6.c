// cai by -wyz
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(  "什锦肉丁" , ({"chook"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", RED "这是一碟香喷喷的安徽名菜。\n" NOR);
                set("unit", "碟");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
                set("eat_msg", "$N用勺子勺起一些$n，轻咬一口，赞不绝口的叫好。\n");
        }
}

