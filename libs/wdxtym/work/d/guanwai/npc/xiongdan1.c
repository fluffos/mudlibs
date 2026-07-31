// xiongdan1.c

inherit ITEM;

void create()
{
	set_name("熊胆干", ({"xiongdan gan", "xiongdan", "gan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "副");
		set("long", "这是一副熊胆干。\n");
		set("value", 1000);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	me->set("eff_qi", me->query("max_qi"));
	message_vision("$N吃下一副熊胆干，觉得精神好多了。\n", me);
	destruct(this_object());
	return 1;
}
