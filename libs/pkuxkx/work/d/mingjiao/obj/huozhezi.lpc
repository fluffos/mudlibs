// 火折子huozhezi.c
//by leonhart

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_hua", "hua");
}

void create()
{
	set_name("火折子", ({"huozhezi", "zhezi", "huo zhezi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", "这是一只普普通通的火折子。\n");
		set("value", 2000);
	}
	setup();
}

int do_hua(string arg)
{
	if (!id(arg))
		return notify_fail("你要划什么？\n");
	else {
		message_vision("$N划亮了一只火折子。\n", this_player());
                remove_call_out("finished");
                call_out("finished", 5, this_object());
		
		return 1;
	}
}  
void finished(object room)
{
        message_vision("火折子已经燃到了尽头。\n", room);
        destruct(this_object());
}






