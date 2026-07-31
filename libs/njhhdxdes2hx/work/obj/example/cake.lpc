// cake.c

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ES2 周岁生日蛋糕", ({ "cake" }) );
	set_weight(160);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "庆祝 ES2 周岁生日所订制的特大号蛋糕。\n");
		set("unit", "块");
		set("food_remaining", 99);
		set("food_supply", 100);
	}
}

void init()
{
	add_action("do_throw", "throw");
	::init();
}

int do_throw(string arg)
{
	string what, who, msg;
	object target;

	if( !arg || arg=="" || sscanf(arg, "%s at %s", what, who)!=2)
		return notify_fail("指令格式：throw <what> at <who>\n");
	if( !id(what) ) return notify_fail("丢什麽？\n");
	target = present(who, environment(this_player()));
	if( !target || !target->is_character() )
		return notify_fail("你要向谁丢蛋糕？\n");
	msg = HIY "$N举起" + name() + "，在空中画出一个漂亮的弧线——丢向$n的鼻子！\n\n";
	if( wiz_level(this_player()) < random(wiz_level(target)) )
		msg += "但是没中 .... 看起来好像是蛋糕自己躲开了。\n\n" NOR;
	else
		msg += "「啪」地一声，正中红心，好爽 ....\n\n" NOR;
	message_vision(msg, this_player(), target);
	destruct(this_object());
	return 1;
}

