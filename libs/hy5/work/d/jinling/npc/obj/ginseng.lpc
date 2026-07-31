// ginseng.c

inherit ITEM;
setup()
{
}
void create()
{
	set_name("人参", ({ "ginseng","renshen" }) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一根普通的人参，有补气提神，恢复体力的功效。\n");
		set("unit", "根");
		set("value", 250);
	}
}
void init()
{
	add_action("do_use", "eat");
}

int do_use(string arg)
{
	
	if( !this_object()->id(arg) ) return notify_fail("你要吃什么？\n");
        this_player()->add("qi", 90);
        this_player()->add("jing", 10);


	 message_vision("$N吃下一根" + name() + "，气力恢复了一些。\n", this_player());
	 destruct(this_object());
	 return 1;

}

