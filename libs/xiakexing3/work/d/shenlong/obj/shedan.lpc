inherit ITEM;


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name("腹蛇胆", ({"dan"}));
        set("unit", "枚");
	set("long", "这是一枚火红的腹蛇胆。\n");
	set("value", 500);
        setup();
}

int do_eat(string arg)
{
if (!id(arg))  return notify_fail("你要吃什么？\n");
if(arg=="dan") this_player()->unconcious();
}
