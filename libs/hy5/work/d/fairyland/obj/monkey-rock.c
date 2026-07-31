// monkey-rock.c
// By jpei

inherit ITEM;

void create()
{
	set_name("岩石", ({ "rock", "yanshi", "yan shi", "shi" }));
	set_weight(8000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块很不稳固的岩石。\n");
		set("value", 0);
		set("no_get", "这块岩石又重又没用，你拿它做甚？");
		set("material", "rock");
	}
	setup();
}

void init()
{
	add_action("do_move", ({"move", "ban", "peng", "yi"}));
}

int do_move(string arg)
{
	object me = this_player();
	object monkey;

	if (!id(arg))
		return notify_fail("你想搬什么？\n");

	if ((monkey = present("xiao hou", environment())) && monkey->query("get_wound")) {
		message_vision("$N将压在小猴身上的岩石搬开，把小猴拉起。\n", me);
		monkey->set("rock_moved", 1);
		return 1;
	}
	return 0;
}
