// shenliwan.c 神力丸

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "神力丸" NOR, ({ "shenli wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一颗圆圆的神力丸，据说"ZJURL("cmds:eat shenli wan")ZJSIZE(20)"吃"NOR"了可以增强膂力。\n");
		set("value", 500000);
		set("yuanbao", 100);
            set("no_sell",1);
            set("no_give",1);
            set("no_drop",1);
            set("no_get",1);
            //set("no_put",1);
            set("no_shop",1);
		set("unit", "颗");
		set("only_do_effect", 1);
		set("suit_point", 300);
	}
}

int do_effect(object me)
{
	message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
		       "。\n", me);
	if (me->query("gift/shenliwan") >= 5)
	{
		message_vision("$N眨眨眼。\n", me);
		tell_object(me, "你觉得这药没啥味道，还不如花生好吃。\n");
	} else
	if (random(10) >3 && !me->query("special_skill/lucky"))
	{
		tell_object(me, "不过你觉得好像没什么作用。\n");
	        //me->add("gift/shenliwan_fail", 1);
	} else
	{
		tell_object(me, HIR "你觉得双臂几乎爆裂，充满了力量。"NOR"\n");
		me->add("str", 1);
	      me->add("gift/shenliwan", 1);
		write("\n "+HIR+"恭喜你："+NOR+HIG+"服用神力丸成功，《先天臂力》增加了！！！"NOR"\n");
	}

	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }