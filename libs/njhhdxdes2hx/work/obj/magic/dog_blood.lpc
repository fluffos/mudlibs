// dog_blood.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("黑狗血", ({ "dog blood", "blood" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "瓶");
		set("long",
			"这是用来驱鬼用的黑狗血(装在竹筒中)，把黑狗血泼(splash)在鬼怪身上\n"
			"可以造成相当大的伤害。\n");
		set("value", 300);
		set("material", "bamboo");
	}
	setup();
}

void init()
{
	add_action("do_splash", "splash");
}

int do_splash(string arg)
{
	object ob;
	string msg;
	int ghost_hit;

	if( !arg || arg=="" )
		return notify_fail("你要将黑狗血泼在谁身上？\n");
	ob = present(arg, environment(this_player()));
	if( !ob || !ob->is_character() )
		return notify_fail("这里没有这个人。\n");
	msg = HIR "\n$N拔开装著黑狗血的竹筒塞，对准$n泼了过去！\n\n" NOR;
	if( random(ob->query("combat_exp")) > (int)this_player()->query("combat_exp") )
		msg += "但是$n很快地闪了开去，一滴也没有被溅到。\n";
	else {
		msg += "只听见「哗啦」一声，$n被黑狗血淋了满身！\n";
		if( ob->is_ghost() || ob->is_undead() ) {
			msg += "在$n凄厉的哀嚎声中，$p身上被黑狗血淋到的部位发出阵阵白烟！\n";
			ob->receive_wound("kee", 120);
			ghost_hit = 1; // 有打到鬼
		}
	}
	message_vision(msg, this_player(), ob);
	// 要对方是鬼才会开打
	if( !ob->is_killing(this_player()->query("id")) && ghost_hit )
		ob->kill_ob(this_player());
	destruct(this_object());
	return 1;
}

