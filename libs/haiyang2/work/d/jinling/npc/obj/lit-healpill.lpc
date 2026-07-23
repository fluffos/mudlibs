// lit-healpill.c

inherit ITEM;

void create()
{
	set_name("小还丹", ({ "lit-heal pill","pill" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一粒黑黑的小药丸，可以治内伤。\n");
		set("unit", "粒");
		set("value", 350);
	}
}
void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	
	if( !this_object()->id(arg) ) return notify_fail("你要吃什麽？\n");
	if( this_player()->query_temp("block_msg/all"));
		return notify_fail("什么？\n");

        this_player()->add("qi", 50 );
        this_player()->add("jing", 50 );

	 
	 message_vision("$N吞下一粒" + name() + "，精神好了很多。\n", this_player());
	 destruct(this_object());
	return 1;

}

