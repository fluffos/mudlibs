// xiandan.c 醍醐仙丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "醍醐仙丹" NOR, ({ "xian dan", "dan", "xiandan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一颗圆圆的仙丹，据说"ZJURL("cmds:eat xian dan")ZJSIZE(20)"吃"NOR"了可以增强智力。\n");
		set("spectxt", "80%的几率增加1点先天悟性。\n");
		set("value", 500000);
		set("yuanbao", 100);
            set("no_shop",1);
            set("no_sell",1);
            set("no_give",1);
            set("no_drop",1);
            set("no_get",1);
            //set("no_put",1);
		set("unit", "颗");
		set("only_do_effect", 1);
	       set("suit_point", 350);
	}
}

int do_effect(object me)
{
	message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
		       "。\n", me);
	if (me->query("gift/xiandan") >= 5)
	{
		message_vision("$N忽然“哇哇”，吐了一地。\n", me);
		tell_object(me, "你觉得嘴里非常的苦。\n");
	} else
	if (random(10) >3 && !me->query("special_skill/lucky"))
	{
		tell_object(me, "不过你觉得好像没什么作用。\n");
	      //me->add("gift/xiandan_fail", 1);
	} else
	{
		tell_object(me, HIG "一股火热蓦然从脑中升起，"
			    "你头痛欲裂，恰在此时一股清凉之意"
			    "油然而起，顿感舒泰无比。\n");
		me->add("int", 1);
	      me->add("gift/xiandan", 1);
	     write("\n "+HIR+"恭喜你："+NOR+HIG+"服用仙丹成功，《先天悟性》增加了！！！"NOR"\n");
	}

	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }