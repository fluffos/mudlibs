#pragma save_binary
 
// poison_dust.c

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIG"迷春药"NOR, ({ "michun yao", "yao", "dust" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是韦春芳的春药，你可以把它倒(pour)在酒水之中使用。\n" );
		set("unit", "包");
		set("base_value", 700);
		set("owner","韦春芳");
		set("task",1);
		set("base_unit", "份");
		set("base_weight", 30);
		set("no_put_in",1); 
	}
	set_amount(1);
}

void init()
{
	add_action("do_pour", "pour");
}

int do_pour(string arg)
{
	string me, what;
	object ob;
	function f;

	if( !arg
	||	sscanf(arg, "%s in %s", me, what)!=2
	||	!id(me) )
		return notify_fail("指令格式: pour <药粉> in <物品>\n");

	ob = present(what, this_player());
	if( !ob )
		return notify_fail("你身上没有 " + what + " 这样东西。\n");
	if( !ob->query("liquid/remaining") )
		return notify_fail(ob->name() + "里什麽也没有，先装些水酒才能溶化药粉。\n");
	f = (: call_other, __FILE__, "drink_drug" :);
	ob->set("liquid/drink_func", bind(f, ob));
	ob->add("liquid/slumber_effect", 150);
	message_vision("$N将一些" + name() + "倒进" + ob->name() 
		+ "，摇晃了几下。\n", this_player());
	add_amount(-1);
	return 1;
}

int drink_drug(object ob)
{
	object me = this_player();

	CHANNEL_D->do_channel(ob, "rumor", "听说有人喝了迷春药，情欲大动……");
	CHANNEL_D->do_channel(me, "chat", RANK_D->query_self_rude(me) + "受不了啦！");
	this_player()->apply_condition("heat",
		(int)this_player()->query_condition("heat") 
		+ (int)ob->query("liquid/slumber_effect") );
	return 0;
}