//  shedan1.c



inherit ITEM;


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("巨蟒胆", ({"jumang dan","mangshedan", "dan"}));
        set("unit", "只");
        set("long", "这是一只亮莹莹的毒蛇胆，是制备毒药的原料。\n");
        set("value", 8000);
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
        this_player()->add("neili",300);message_vision("$N吃下了一个巨莽胆，畅快极了.\n",this_player());
destruct(this_object());
	return 1;
}

