// jinsha.c



inherit ITEM;

void create()
{
	set_name(HIY "忘尘丹" NOR, ({ "wangchen dan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "清除角色除元宝和会员相关的所有数据。\n");
		set("unit", "颗");
		set("value", 500000);
		set("yuanbao", 1200);
		set("only_do_effect", 1);
		set("weight", 1);
	}
	setup();
}

int do_effect(object me)
{
	message_vision(CYN "$N" CYN "小心的服下了" + name() + CYN "，所有数据清空。"NOR"\n", me);
	UPDATE_D->init_player(me);
	destruct(this_object());
	return 1;
}
