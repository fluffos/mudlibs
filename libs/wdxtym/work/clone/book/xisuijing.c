// xisuijing.c 洗髓经

inherit ITEM;

#include <ansi.h>

int do_study(string);

string* skill = ({
	"whip",
	"finger",
	"hand",
	"cuff",
	"claw",
	"strike",
});

void create()
{
	set_name(YEL "洗髓经" NOR, ({ "xisui jing" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "卷");
		set("long","这本破纸筒就是少林最高武学典籍，是达摩老祖面壁九年与易筋经一起"ZJURL("cmds:canwu1 xisui jing")+ZJSIZE(20)+"参悟"NOR"出来的绝世典籍。\n");
		set("value", 10);
		set("no_sell", 1);
		set("no_get", 1);
		set("no_put", 1);
		set("material", "paper");
	}
}

void init()
{
	add_action("do_study","canwu1");
}

int do_study(string arg)
{
	object where;
	object ob = this_object();
	object me = this_player();
	int cost, exp;
	int i;

	where = environment(me);
	if (! arg || ! id(arg))
		return notify_fail("你要参悟什么？\n");

	if ((string)where->query("short") != "达摩院二楼")
		return notify_fail("洗髓经只能在达摩院里参悟！\n");

	if (me->query_skill("literate", 1) < 100)
	{
		write("你把纸筒翻来翻去，就是什么都读不懂。\n");
		return 1;
	}

	if (me->is_busy()) {
	      call_out("do_lian3", 5, me);
		return notify_fail("你现在正忙着呢。\n");
            }

	if (me->is_fighting())
		return notify_fail("你无法在战斗中专心下来研读新知！\n");

	if (me->query_temp("auto"))
		return notify_fail("你不是已经在挂机了吗？\n");

	exp = (int)me->query("combat_exp");
	if (exp < 300000)
	{
		write("你的实战修为不足，不能参悟洗髓经。\n");
		return 1;
	}

	me->add("neili", -10 - random(10));

	cost = 50 + random(50);
	if (me->query("jing") > cost)
	{
		for (i = sizeof(skill); i > 0; i--)
		{
			if (me->query_skill(skill[i-1], 1) < 180 &&
			    me->query_skill(skill[i-1], 1) >= 100 &&
			    me->can_improve_skill(skill[i-1]))
			{
				me->improve_skill(skill[i-1], 15 + random(90));
			}
		}
		write(sprintf("你参悟洗髓经上的经文，似乎有点心得。\n"));
		me->receive_damage("jing", cost);
                tell_object(me,ZJFORCECMD("canwu1 xisui jing"));
	} else
	{
		me->set("jing", 0);
		me->set_temp("auto", 1);
		write("你现在过于疲倦，无法专心下来参悟洗髓经。\n");
	    if (me->query("neili") >500) {
	        call_out("do_lian3", 2, me);
            } else
           {
		write("你的内力不足，等待恢复中...\n");
              tell_object(me,ZJFORCECMD("use huxin dan"));
	        call_out("do_lian3", 10, me);
            }

	}

	return 1;
}


void do_lian3(object me)
{
	if (! objectp(me))
		return;
	   me->delete_temp("auto");
         tell_object(me,ZJFORCECMD("exert regenerate")+ZJFORCECMD("canwu1 xisui jing"));
}