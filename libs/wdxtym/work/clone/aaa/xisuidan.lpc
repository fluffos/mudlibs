// xisuidan.c 洗髓丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL "洗髓丹" NOR, ({ "xisui dan", "dan", "xisuidan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一颗黑不溜秋的丹药，据说"ZJURL("cmds:eat xisui dan")ZJSIZE(20)"吃"NOR"了可以增强体质。\n");
		set("spectxt", "80%的几率增加1点先天根骨。\n");
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
		set("suit_point",300);
	}
}

int do_effect(object me)
{
	message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
		       "。\n", me);
	if (me->query("gift/xisuidan") >= 5)
	{
		message_vision("$N突然放了一个奇臭无比的响屁。\n", me);
		tell_object(me, "你觉得大概是吃坏了肚子。\n");
	} else
	if (random(10) >3 && !me->query("special_skill/lucky"))
	{
		tell_object(me, "不过你觉得好像没什么作用。\n");
	      //me->add("gift/xisuidan_fail", 1);
	} else
	{
		message("vision", "你似乎听见" + me->name() + "的骨头哗啦啦的响。\n",
				  environment(me), ({ me }));
		tell_object(me, HIY "你浑身的骨骼登时哗啦啦的响个不停，可把你吓坏了，"
				"好在一会儿就停了下来，似乎筋骨更灵活了。"NOR"\n");
		me->add("con", 1);
	      me->add("gift/xisuidan", 1);
		write("\n "+HIR+"恭喜你："+NOR+HIG+"服用洗髓丹成功，《先天体质》增加了！！！"NOR"\n");
	}

	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }