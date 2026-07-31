// oil.c

inherit ITEM;
setup()
{
}
void create()
{
	set_name("万金油", ({ "wanjin oil","oil","wanjin" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一小瓶褐色的药油，发出一种薄荷的香气，使用(use)后有提神的作用。\n");
		set("unit", "瓶");
		set("value", 150);
		set("oil_left",5);
	}
}
void init()
{
	add_action("do_use", "use");
}

int do_use(string arg)
{
	
	if( !this_object()->id(arg) ) return notify_fail("你使用什么？\n");
        this_player()->add("qi",10);
                this_player()->add("jing",10);
        add("oil_left",-1);

	 message_vision("$N拿出一个小瓷瓶，搽了一些" + name() + "，精神好了一些。\n", this_player());
	 if(!query("oil_left")) {
		message_vision("$N把小瓷瓶里" + name() + "用完了。\n",this_player());
		destruct(this_object()); }
	 return 1;

}

