// yangjing_wan 养精丸

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("养精丸", ({"yangjing wan", "jing", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "一颗乌黑发亮的小药丸。\n");
              set("medicine", "drug");
                set("value", 5000);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("你要吃什么药？\n");
        if ((int)this_player()->query("eff_jing") == 
            (int)this_player()->query("max_jing"))
                return notify_fail("你现在不需要用养精丸。\n");
        else {
                this_player()->receive_curing("jing", 20);
                message_vision("$N吃下一颗养精丸，顿时脸上泛出了红润。\n", this_player());
                destruct(this_object());
                return 1;
        }
}

