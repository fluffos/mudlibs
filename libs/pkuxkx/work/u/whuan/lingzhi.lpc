//灵芝
#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIM"千年灵芝"NOR, ({"ling zhi", "zhi", "lingzhi"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "产自泰山的千年灵芝，能使人恢复精力。\n");
                set("value", 200000);
        }
        setup();

}

int do_eat(string arg)
{
        if (arg!="ling zhi" && arg!="zhi"&& arg!="lingzhi")
           return notify_fail("你要吃什么药？\n");
                this_player()->set("jingli", this_player()->query("max_jingli")+random(100));
                message_vision("$N吃下一只人参，顿时你觉得精力充沛。\n", this_player());
                destruct(this_object());
                return 1;
}
