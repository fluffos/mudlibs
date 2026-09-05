// book0.c

inherit ITEM;
int do_study(string arg);

void create()
{
	set_name("天竺梵语",({"shu", "book"}));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这是一本薄薄的小册子，翻开一看，都是一些奇形怪状的文字。\n");
		set("value", 200000);
		set("material","paper");
	}
	setup();
}

void init()
{
	add_action("do_study","study");
        add_action("do_study","du");
        add_action("do_study","read");
}

int do_study(string arg)
{
	object me = this_player();
	string book;
	int times;

        if(!arg || (sscanf(arg, "%s %d", book, times) < 1))
        {
                write("指令格式：study shu [次数]\n");
                return 1;
        }
	if (!id(book))
		return 0;
	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");
	if( (int)me->query_skill("fanwen",1)<1)
	{
		write("你不懂梵文，无法领悟上面的东西。\n");
		return 1;
	}
	if( times < 1 || times > 50)
		return notify_fail("你要读多少次？(1 - 50)\n");
	if( me->is_fighting() )
		return notify_fail("你无法在战斗中专心下来研读新知！\n");
	if(me->query("jing") < 20 * times)
		return notify_fail("你的精神太差，读不下去了。\n");

	me->receive_damage("jing", 20 * times);
	if( (int)me->query_skill("fanwen",1) < 100)
	{
		message_vision("$N正专心研读梵文。\n", me);
		me->improve_skill("fanwen", (int)me->query_skill("fanwen",1)/5 * times + 1);
		write("你对天竺梵文琢磨了一会，似乎有些心得。\n");
	}
	else
	{
		write("你对天竺梵文研读了一会，发现上面的太过浅薄，对你来说已毫无意义了。\n");
	}
	return 1;
}
