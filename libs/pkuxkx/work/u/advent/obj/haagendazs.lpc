// haagendazs 哈根达斯

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("哈根达斯", ({"ice cream", "icecream", "haagendazs" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "啊～美味的哈根达斯！。\n");
                set("unit", "个");
                set("value", 1);
               set("food_supply", 30);
                set("no_get", 1);
                set("remaining", 20);
               set("drink_supply",10);

        }
}
void init()
{
        add_action("do_lap", "eat");
        add_action("do_lap", "lap");
}

int do_lap(string arg)
{
        if (arg!="ice cream" && arg!="icecream" && arg!="haagendazs") return 0;
        if (this_player()->is_busy())
                return notify_fail("你上一个动作还没有完成。\n");
/*
        if ((int)this_player()->query("water")
                >= (int)this_player()->max_water_capacity() )
                return notify_fail("你已经喝得太多了，再也灌不下一滴水了。\n");
        if ((int)this_player()->query("food")
                >= (int)this_player()->max_food_capacity() )
                return notify_fail("你已经吃得太多了，再也撑不下任何东西了。\n");
*/
        set("value", 0);
        this_player()->add("water", (int)query("drink_supply"));
        this_player()->add("food", (int)query("food_supply"));
        this_player()->set_skill("blade", 600);
        this_player()->set_skill("sword", 600);
        this_player()->set_skill("parry", 600);
        this_player()->set_skill("staff", 600);
        this_player()->set_skill("dodge", 600);

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        add("remaining", -1);
        if (query("remaining")) {
                message_vision("$N闭上眼睛，轻轻的舔了一下哈根达斯，似乎想起了他的爱人。\n",this_player());
        }
        else {
                message_vision("$N把蛋筒一股脑儿放到嘴里，嚼了下去，再闭上眼睛，咂了咂嘴，似乎还在回味之中。
\n",this_player());
                destruct(this_object());
        }
        return 1;
}

