// zhenjing.c

#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

void setup()
{
}

void init()
{
	add_action("do_du", "yanjiu2");
	add_action("do_du", "research2");
	add_action("halt_read", "stopread");
}

void create()
{
	set_name(HIY "《" HIW "九阴真经" HIY "》" NOR, ({ "jiuyin zhenjing", "zhenjing"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("material", "paper");
		set("no_give", 1);
		set("no_sell", 1);
		set("no_put", 1);
		set("long", HIW
	"这是一本用薄纸写成的书。书面上写着《九阴真经》。书皮泛黄，看来已经保存很久了。\n"
	"真经里记载了催心掌、九阴白骨爪、易筋锻骨和蛇行狸翻，你可以试着研究研究。"NOR"\n", );
	}
	set("action_list", ([
		"研究" : "yanjiu2",
		"停止研究": "stopread",
	]));
}

int do_du(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	string skill, book;
	int lv;

	if (! arg)
	{
		/*write("研究九阴真经的指令格式：\n"
		      "research2|yanjiu2 <技能> from <九阴真经>\n");
		*/
		write(ZJOBLONG +"请选择研究的技能：\n"+ZJOBACTS2+ ZJMENUF(2,2,9,30)+
			"研究 易筋锻骨:yanjiu2 yijin-duangu from jiuyin zhenjing"+ZJSEP+
			"研究 蛇行狸翻:yanjiu2 shexing-lifan from jiuyin zhenjing"+ZJSEP+
			"研究 摧心掌:yanjiu2 cuixin-zhang from jiuyin zhenjing"+ZJSEP+
			"研究 九阴白骨爪:yanjiu2 jiuyin-baiguzhao from jiuyin zhenjing"+
		"\n");
		
		return 1;
	}
	if (arg == "yijin-duangu" || arg == "shexing-lifan" ||
	    arg == "cuixin-zhang" || arg == "jiuyin-baiguzhao" ||
	    arg == "jiuyin zhenjing" || arg == "zhenjing")
	{
		write("研究九阴真经的指令格式：\n"
		      "research2|yanjiu2 <技能> from <九阴真经>\n");
		return 1;
	}

	if (sscanf(arg, "%s from %s", skill, book) != 2)
		return 0;

	if (me->is_busy())
	{
		write("你现在正忙着呢。\n");
		return 1;
	}

	if (me->is_fighting())
	{
		write("你无法在战斗中专心下来研读新知！\n");
		return 1;
	}
	if (! id(book))
	{
		write("这里没有这本书。\n");
		return 1;
	}

	if (skill != "yijin-duangu" && skill != "shexing-lifan" &&
	    skill != "cuixin-zhang" && skill != "jiuyin-baiguzhao")
	{
		write(HIW "你可以从九阴真经里研究到易筋锻骨（yijin-duangu），蛇行狸翻（shexing-lifan），\n"
			  "催心掌（cuixin-zhang）以及九阴白骨爪（jiuyin-baiguzhao）。"NOR"\n",);
		return 1;
	}
	if ((int)me->query("combat_exp") < 500000)
	{
		write("你的实战修为不足，再怎么读也没用。\n");
		return 1;
	}

	if ((int)me->query("jing") < 100 || (int)me->query("qi") < 100)
	{
		write("你现在过于疲倦，无法专心下来研读新知。\n");
	me->start_busy(2);
	call_out("auto_read2",2,me,arg);
		return 1;
	}

	if ((me->query("potential") - me->query("learned_points")) < 10)
		return notify_fail("你的潜能不足。\n");

	if (skill == "yijin-duangu")
	{
	      if (! me->query_skill("literate", 1))
	{
		write("你是个文盲，先学点文化(literate)吧。\n");
		return 1;
	}
		lv = me->query_skill("yijin-duangu", 1);
		if (! me->can_improve_skill("yijin-duangu", 1))
		{
			write("你的实战修为不足，再怎么读也没用。\n");
			return 1;
		}

		if (lv > 199)
		{
			write("你研读了一会儿，但是发现上面所说的对你而言"
			      "都太浅了，没有学到任何东西。\n");
			return 1;
		}

		if (me->query("gender") == "无性" && (int)me->query_skill("yijin-duangu", 1) > 49)
			return notify_fail("你无根无性，阴阳不调，难以领会高深的易筋锻骨内功。\n");

		if (me->query("character") == "狡黠多变" && (int)me->query("yijin-duangu", 1) > 199)
			return notify_fail("这九阴真经中所记载的易筋锻骨正大恢弘，气度俨然，依照"
				   "你狡黠多变的天性似乎只能学到这种程度。\n");

		if (me->query("character") == "心狠手辣" && (int)me->query("yijin-duangu", 1) > 169)
			return notify_fail("这九阴真经中所记载的易筋锻骨正大恢弘，气度俨然，依照"
				   "你心狠手辣的天性似乎只能学到这种程度。\n");

		if (me->query("character") == "阴险狡诈" && (int)me->query("yijin-duangu", 1) > 139)
			return notify_fail("这九阴真经中所记载的易筋锻骨正大恢弘，气度俨然，依照"
				   "你阴险狡诈的天性似乎只能学到这种程度。\n");
		if (me->query("int") < 26)
			return notify_fail("你觉得易筋锻骨深奥无比，一时难以领会。\n");

		if ((int)me->query_skill("force", 1) < 100)
			return notify_fail("你的基本内功火候还不够，还不能学习易筋锻骨内功。\n");

		message("vision", me->name() + "正专心地研读九阴真经。\n",
			environment(me), me);
		me->receive_damage("qi", 100);
		me->receive_damage("jing", 100);
		me->add("learned_points", 10);
		me->improve_skill("yijin-duangu", 10 + random(me->query("int")*2));
		write("你仔细研读九阴真经，对真经里所记载的易筋锻骨颇有心得。\n");
	}
	else
	if (skill == "shexing-lifan")
	{
		lv = me->query_skill("shexing-lifan", 1);
		if (! me->can_improve_skill("shexing-lifan"))
		{
			write("你的实战修为不足，再怎么读也没用。\n");
			return 1;
		}

		if (lv > 199)
		{
			write("你研读了一会儿，但是发现上面所说的对"
			      "你而言都太浅了，没有学到任何东西。\n");
			return 1;
		}

		message("vision", me->name() + "正专心地研读九阴真经。\n",
			environment(me), me);
		me->receive_damage("qi", 100);
		me->receive_damage("jing", 100);
		me->add("learned_points", 10);
		me->improve_skill("shexing-lifan", 10 + random(me->query("int")*5));
		write("你仔细研读九阴真经，对真经里所记载的蛇行狸翻轻功颇有心得。\n");
	}
	else
	if (skill == "cuixin-zhang")
	{
	      if (! me->query_skill("literate", 1))
	{
		write("你是个文盲，先学点文化(literate)吧。\n");
		return 1;
	}
		lv = me->query_skill("cuixin-zhang", 1);
		if (! me->can_improve_skill("cuixin-zhang"))
		{
			write("你的实战修为不足，再怎么读也没用。\n");
			return 1;
		}
		if (lv > 199)
		{
			write("你研读了一会儿，但是发现上面所说的对"
			      "你而言都太浅了，没有学到任何东西。\n");
			return 1;
		}
		message("vision", me->name() + "正专心地研读九阴真经。\n",
			environment(me), me);
		me->receive_damage("qi", 100);
		me->receive_damage("jing", 100);
		me->add("learned_points", 10);
		me->improve_skill("cuixin-zhang", 10 + random(me->query("int")*10));
		write("你仔细研读九阴真经，对真经里所记载的催心掌颇有心得。\n");
	}
	else
	if (skill == "jiuyin-baiguzhao")
	{
	      if (! me->query_skill("literate", 1))
	{
		write("你是个文盲，先学点文化(literate)吧。\n");
		return 1;
	}
		lv = me->query_skill("jiuyin-baiguzhao", 1);
		if (! me->can_improve_skill("jiuyin-baiguzhao"))
		{
			write("你的实战修为不足，再怎么读也没用。\n");
			return 1;
		}

		if (lv > 199)
		{
			write("你研读了一会儿，但是发现上面所说的对"
			      "你而言都太浅了，没有学到任何东西。\n");
			return 1;
		}
		message("vision", me->name() + "正专心地研读九阴真经。\n",
			environment(me), me);
		me->receive_damage("qi", 100);
		me->receive_damage("jing", 100);
		me->add("learned_points", 10);
		me->improve_skill("jiuyin-baiguzhao", 10 + random(me->query("int")*10));
		write("你仔细研读九阴真经，对真经里所记载的九阴白骨爪颇有心得。\n");
	}
	else
	{
		write("真经里面并没有记录这些技能。\n");
		return 1;
	}
	call_out("auto_read",1,me,arg);
	me->set_temp("read_zhenjing",1);
	return 1;
}

void auto_read(object me,string arg)
{
	if(!me||!me->query_temp("read_zhenjing"))
		return;
	if(me->is_busy())
	{
		call_out("auto_read",1,me,arg);
		return;
	}
	me->force_me("yanjiu2 "+arg);
}

void auto_read2(object me,string arg)
{
	if(!me||!me->query_temp("read_zhenjing"))
		return;
	if(me->is_busy())
	{
		call_out("auto_read2",1,me,arg);
		return;
	}
	me->force_me("exert recover");
	me->force_me("exert regenerate");
	me->force_me("fuyong huxin dan");
	me->force_me("yanjiu2 "+arg);
}

int halt_read()
{
	object me = this_player();
	me->delete("read_zhenjing");
	return 1;
}