// /u/poq/sdxl/obj/gshedan.c 怪蛇蛇胆
// by poq@jyqx 97/7
// amend dubei

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
    set_name("毒蟒胆", ({"she dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
        set("unit", "枚");
            set("unique", 1);
        set("long", "这是一枚深紫色的圆囊，甚是腥臭。\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
{
    object me = this_player();

    if (!id(arg))
        return notify_fail("你要吃什么？\n");

       me->add("max_neili", random(10));
       me->add("neili",900);
me->set_temp("book1061",1);
    message_vision("$N吃下一枚怪蛇蛇胆，只觉得这汁液腥极苦极，难吃无比。!\n", me);
    destruct(this_object());
    return 1;
}
