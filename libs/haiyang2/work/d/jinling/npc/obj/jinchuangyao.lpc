// jinchuangyao.c

inherit ITEM;
setup()
{
}
void create()
{
	set_name("金创药", ({ "jinchuang yao","yao","jinchuang" }) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一贴黑色的膏药，发出一种刺鼻的药香，可贴(tie)在伤口上，跌打刀伤适用。\n");
		set("unit", "贴");
		set("value", 200);
	}
}
void init()
{
	add_action("do_use", "tie");
}

int do_use(string arg)
{
	
	if( !this_object()->id(arg) ) return notify_fail("你贴什么？\n");
        this_player()->add("qi", 30 );
        this_player()->add("jing", 10 );


	 message_vision("$N拿出一块" + name() + "贴在伤口上，感觉好多了。\n", this_player());
	 destruct(this_object());
	 return 1;

}

