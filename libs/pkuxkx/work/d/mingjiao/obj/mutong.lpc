// mutong.c 木桶

inherit ITEM;  
void setup()
{}

void init()
{
	add_action("do_pi", "pi");
}


void create()
{
	set_name("木桶", ({ "mutong", "tong", "mu tong" }));
	set_weight(500);
	set_max_encumbrance(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", "一只木桶，里面好象装着些黑色的粉末。\n");
		set("value", 100);
	}
}

int do_pi(string arg)
{
	if (!id(arg))
		return notify_fail("你要劈什么？\n");
	else {
		message_vision("$N劈开木桶，只觉桶中散出许多粉末。\n", this_player());
                remove_call_out("finished");
                call_out("finished",1, this_object());
		
		return 1;
	}
}  
void finished(object room)
{       
	object ob; 
	destruct(this_object());
        ob = new("/d/mingjiao/obj/mutong");
       // ob->move(this_player());
       
}
