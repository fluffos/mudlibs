
#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(YEL "洗髓丹" NOR, ({ "xisui dan", "dan", "xisuidan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一颗黑不溜秋的丹药，据说吃了可以增强体质。\n");
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
		set("base_value", 10000);
		set("yuanbao", 100);
            set("no_sell", 1);
		set("suit_point", 300);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	message_vision("$N一仰脖，吞下了一" + query("unit") + name() + "。\n", me);

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

	add_amount(-1);
      return 1;
}


