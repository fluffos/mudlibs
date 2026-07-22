// By River@sj 2002.6.5

 inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIB"铁舟"NOR, ({ "tie zhou", "zhou", "boat"}));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一艘黑黝黝的小船。\n");
		set("unit", "艘");
		set("value", 2000);
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_give", 1);
		set("no_get", 1);
	}
	setup();
}

void init()
{
	if (environment() == this_player())
		add_action("do_pao", ({"pao", "zhi" }));
}

int do_pao(string arg)
{
	object room, me = this_player();

	if (!id(arg)) return 0;

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if (! objectp(present("tie jiang", me)))
		return notify_fail("你的铁桨呢？\n");

	if ( !environment(me)->query("yideng_boat"))
		return notify_fail("你在那里掷铁舟啊？\n");

	if(!( room = find_object("/d/dali/yideng/boat")))
		room = load_object("/d/dali/yideng/boat");

	if ( room->query("ppl"))
		return notify_fail("瀑布的水流过于湍急，现在已经有艘铁舟在河中了，你还是先等会吧。\n");

	message_vision(HIW"\n$N转过山角，喝一声：“起！”用力掷入瀑布的上游，铁舟一经掷出，将铁桨\n"+
		"挟在左腋之下，只见铁舟已顺着水流冲到跟前，涌身前跃，落入舟中。\n\n"NOR, me);
	me->delete_temp("yideng");
	me->move(room);
	room->set("ppl", me->name(1));
	call_out("dest", 1, this_object());
	return 1;
}

void dest(object ob)
{
	if ( ! ob) return;
	destruct(ob);
}
