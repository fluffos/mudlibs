// Object: /clone/herb/haitang.c 七心海棠
// Date: Feb . 3 2002 by Pound
// 每棵七心海棠可以使用四次，分别是花、叶、茎、根。用来救人，可使白骨生肉，可解天下百毒。
// 如果用来害人，那么再精明细心的人也防备不了，不知不觉之间，已是中毒而死。
// 七心海棠可以直接用来救人，经过制炼以后可以用做毒药。炼制毒药需要程灵素帮忙。
// 程灵素噗哧一笑，道：“这花的根茎花叶，均是奇毒无比，但不加制炼，不会伤人。你只要不去吃它，便死不了。”
// 胡斐笑道：“你当我是牛羊么，吃生草生花？”

#include "/clone/herb/herb.h"
int do_eat(string arg);

void create()
{
	set_name(RED HBGRN "七心海棠" NOR, ({"qixin haitang", "haitang"}));
	if (clonep())
	    set_default_object(__FILE__);
	else 
	{
	    set("base_unit", "棵");
	    set("long", HIY "花瓣紧贴枝干而生，花枝如铁，花瓣上有七个小小的黄点。"NOR"\n");
	    set("no_sell", 1);	
	    set("base_value", 200000);
	    set("no_give", 1);
	    set("no_drop", 1);
	    set("no_steal", 1);
	    set("no_beg", 1);
//	  set("poison_type", "haitang_posion");
//	  set("can_drug", 1);
	    set("base_weight", 90);
	}		   
	setup();
}

void init()
{   
	add_action("do_eat", "eat");   
	add_action("do_use", "use"); 
}

int do_eat(string arg)
{
	object me;
	me = this_player();

	if (! arg || ! id(arg))
	    return notify_fail("你要吃什么？\n");
	message_vision(name() + "花香诱人，$N忍不住拿起来尝了几口。\n\n", me);
	message_vision(HIB "$N" HIB "感觉周围事物逐渐离自己而去，双膝渐渐弯曲，身子软了下来。"NOR"\n", me);
	me->set_temp("die_reason", "死的时候脸上始终带着微笑，似乎十分平安喜乐");
// 目前的系统死前描述都是“你扑在地上挣扎了几下，腿一伸，口中喷出几口鲜血，死了！”，必须要吐血？

	me->die();
	destruct(this_object());
	return 1;
}

int do_use(string arg)
{
	object me, ob;
	string what, target;
	mapping my;

	me = this_player();
	if (! arg || sscanf(arg, "%s to %s", what, target) != 2)
	    return notify_fail("七心海棠救人的使用方法为“use 海棠部位名称 to 目标英文ID”。\n");

	if (sscanf(arg, "%s to %s", what, target) == 2)
	{
	    if (what != "jing" && what != "茎" && what != "gen" && what != "根" &&
		what != "ye" && what != "叶" && what != "hua" && what != "花") 
		return notify_fail("你总得先想好用七心海棠的哪部分吧，花、叶、茎、根？\n");
	    ob = present(target, environment(me));
	    if (! objectp(ob = present(target, environment(me)))) 
		return notify_fail("你想要用七心海棠救谁？\n");
	    if (me->is_busy())
		return notify_fail("还是先等你忙完再救人吧！\n");

	    if (what == "ye" || what == "叶") 
	    {
		if (me->query("yaowang/qxht/ye"))
		    return notify_fail("七心海棠的叶子已经被你用掉了。\n");
		message_vision("$N把七心海棠的叶子摘了下来捣得烂了，敷在" + ob->query("name") + "身上。\n", me);
		me->set("yaowang/qxht/ye", 1);
		ob->set_temp("nopoison", 3);
		me->add("yaowang/qxht/using", 1);
//	      ob->clear_condition(); // 叶子解天下奇毒，此处使用了Doing设计的标记nopoison解毒。
		ob->receive_damage("qi", (200 + random(100))); // 剧痛
		message_vision(HIR "一阵剧痛过后，" + ob->query("name") + "发现体内的束缚已经全部散去了。"NOR"\n", me);
		me->start_busy(2 + random(3));
		me->receive_damage("jing", (66 + random(33)));
		return 1;
	    }

	    if (what == "hua" || what == "花") 
	    {
		if (me->query("yaowang/qxht/hua"))
		    return notify_fail("七心海棠的花已经被你用掉了。\n");
		message_vision("$N把七心海棠的花摘了下来捣得烂了，涂在" + ob->query("name") + "周身穴位上。\n\n", me);
		message_vision(CYN + ob->query("name") + "只觉得周身穴位一阵热麻，全身气血充盈，内力精力充沛之极。"NOR"\n", me);
		me->set("yaowang/qxht/hua", 1);
		me->add("yaowang/qxht/using", 1);
		my = ob->query_entire_dbase(); // 花使气血全满，临时内力精力加倍。
		my["eff_jing"] = my["max_jing"];
		my["jing"] = my["max_jing"];
		my["eff_qi"] = my["max_qi"];
		my["qi"] = my["max_qi"];
		my["jingli"] = my["max_jingli"] * 2;
		my["neili"] = my["max_neili"] * 2;
		me->start_busy(2 + random(3));
		me->receive_damage("jing", (66 + random(33)));
		return 1;
	    }
// 还有 根 和 茎，用来配合其他药物，或者配合其他武功？ 例如配合打通任督二脉？
// 每次使用将标记写在使用者身上，当花、叶、茎、根全部使用完毕后，destruct haitang，并删除使用者身上的标记。
//		me->delete("yaowang/qxht);
//		destruct(this_object());
// Create里面已经设计了各种防范措施，避免七心海棠离开使用者导致的标记混乱。

	    if (what == "jing" || what == "茎") 
	    {
		if (me->query("yaowang/qxht/jing"))
		    return notify_fail("七心海棠的茎已经被你用掉了。\n");
		if (! me->query("yaowang/qxht/hua") || ! me->query("yaowang/qxht/ye"))
		    return notify_fail("七心海棠的花和叶还都没用，如果先使用茎，花和叶就要浪费了！\n");
// 取走了植物的茎，花和叶自然会枯萎，无法使用了。因此加了这个判断。
		message_vision("$N把七心海棠的茎折了下来用力捣得烂了，敷在" + ob->query("name") + "身上。\n", me);
		me->set("yaowang/qxht/jing", 1);
		ob->set_temp("nopoison", 3);
		me->add("yaowang/qxht/using", 1);
//	      ob->clear_condition(); // 解天下奇毒，此处使用了Doing设计的标记nopoison解毒。
		ob->receive_damage("qi", (200 + random(100))); // 剧痛
		message_vision(HIR "一阵剧痛过后，" + ob->query("name") + "发现体内的束缚已经全部散去了。"NOR"\n", me);
		me->start_busy(2 + random(3));
		me->receive_damage("jing", (99 + random(33)));
		return 1;
	    }

	    if (what == "gen" || what == "根") 
	    {
		if (me->query("yaowang/qxht/gen"))
		    return notify_fail("七心海棠的根已经被你用掉了。\n"); // 或许这个判断并不需要。
		if (! me->query("yaowang/qxht/hua") || ! me->query("yaowang/qxht/ye") || ! me->query("yaowang/qxht/jing"))
		    return notify_fail("如果先使用根，七心海棠的花、叶和茎就要浪费了！\n");
// 取走了植物的根，花、叶和茎自然会枯萎，无法使用了。因此加了这个判断。
		message_vision("$N把七心海棠的根折了下来擦拭干净，用力捣得烂了，敷在" + ob->query("name") + "身上。\n", me);
		me->set("yaowang/qxht/gen", 1);
		ob->set_temp("nopoison", 3);
		me->add("yaowang/qxht/using", 1);
		me->delete("yaowang/qxht");
//	      ob->clear_condition(); // 解天下奇毒，此处使用了Doing设计的标记nopoison解毒。
		ob->receive_damage("qi", (20 + random(10))); // 轻痛，此处设计根的作用稍微温和些。
		message_vision(HIR "一阵轻微的疼痛过后，" + ob->query("name") + "发现体内的束缚已经全部散去了。"NOR"\n", me);
		me->start_busy(2 + random(3));
		destruct(this_object());
		me->receive_damage("jing", (166 + random(33)));
		return 1;
	    }

	}
	return 1;
}
