// zhangjian.c  掌甲童子
// Written by Doing Lu  1998/11/2

// 接受原料配料，铸造粗坯
// 设置粗坯各项参数，包括：
// material1  原料名称
// mat_attr1  原料有效点数
// material2  培料名称
// mat_attr2  配料的比例因子 * 2
// weight     甲坯重量 = 原料重量 * 6 ( 配料重量不计 )

inherit NPC;

#include <ansi.h>

int	ask_me(object me);
int	do_start();
int	item_temp_make(object me);

void create()
{
	set_name("掌甲童子", ({ "zhangjia tongzi", "tongzi", "zhangjia" }));
	set("long", "他是干将的二弟子，专门铸造甲坯。\n" );

	set("gender", "男性");
	set("attitude", "friendly");

	set("age", 33);
	set("shen_type", 0);
	set("str", 500);	// 防止东西过多，不堪负荷
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("combat_exp", 5000);

	set("inquiry", ([
		"铸甲" : (: ask_me, this_player() :),
		"打造" : (: ask_me, this_player() :),
		"铸造" : (: ask_me, this_player() :),
	]));

        setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_start", "开始");
	add_action("do_start", "start");

	remove_call_out("greeting");
	call_out("greeting", 1, this_player());
}

void greeting(object me)
{
        message_vision("掌甲童子看了看$N说：是不是要打造甲坯？\n",me);
}

// 如果不忙，询问信息，提示交付信件
int ask_me(object me)
{
	if (this_object()->query_temp("item/铸造中"))
	{
		message_vision("掌甲童子对$N说：对不起，让我先忙完，好不好？\n", me);
		return 1;
	}
	message_vision("掌甲童子问$N：如果你带来了我师傅的信件，我就替您打造。\n", me);
	return 1;
}

// 接受物品：
// 如果正在铸造，不接受物品
// 如果是信件，则设置标志item/step 为 接受原料，并提示交付原料和配料
// 如果已经设置了item/step 为 接受原料，并且接受的是原料/配料，记录并且提示是否交付完
int accept_object(object me, object ob)
{
	if (this_object()->query_temp("item/铸造中"))
	{
		message_vision("掌甲童子对$N说：我正在忙，什么是过会再谈吧。\n", me);
		return 0;
	}

	switch (ob->query("id"))
	{
		// 接受信件
		case "item permit":
		if (me->query_temp("item/step") == "接受原料")
		{
			message_vision("掌甲童子奇怪的对$N说：你怎么有这么多师傅的信啊。\n", me);
		} else
		{
			me->set_temp("item/step", "接受原料");
			message_vision("掌甲童子对$N说：你把原料和配料给我，如果准备好了，咱们就开始(start)吧。\n", me);
		}
		return 1;

		default:
		if (me->query_temp("item/step") != "接受原料")
		{
			message_vision("掌甲童子对$N说道：对不起，师傅教我们不要随便要别人的东西。\n", me);
			return 0;
		}
		// 接受铸甲原料
		if (ob->query("material_attrib") == "y")
		{
			if (me->query_temp("item/material1"))
			{
				message_vision("掌甲童子摇摇头说道：这个没法和" + 
					me->query_temp("item/material1") + "混在一起炼的。\n", me);
				return 0;
			}
			if (me->query_temp("item/material2"))
			{
				message_vision("掌甲童子说道：很好，原料配料都齐了，咱们是不是就开始啊。\n", me);
			} else
			{
				message_vision("掌甲童子看了看说道：很好，你有没有配料啊，要是没有。咱们就开始吧。\n", me);
			}
			me->set_temp("item/material1", ob->query("name"));
			me->set_temp("item/mat_attr1", ob->query("power_point"));
			me->set_temp("item/mat_id1", ob->query("id"));
			me->set_temp("item/item_weight", ob->query_weight() * 6);
			return 1;
		}
		// 接受铸甲配料
		if (ob->query("material_attrib") == "z")
		{
			if (me->query_temp("item/material2"))
			{
				message_vision("掌甲童子摇摇头说道：这只能做配料，你得给我原料啊。\n", me);
				return 0;
			}
			if (me->query_temp("item/material1"))
			{
				message_vision("掌甲童子说道：很好，原料配料都齐了，咱们是不是开始啊。\n", me);
			} else
			{
				message_vision("掌甲童子看了看说道：很好，你快点把原料给我吧。\n", me);
			}
			me->set_temp("item/material2", ob->query("name"));
			me->set_temp("item/mat_attr2", ob->query("scale"));
			me->set_temp("item/mat_id2", ob->query("id"));
			return 1;
		}
		// 不能使用的原料
		command("shake " + me->query("id"));
		message_vision("掌甲童子说：对不起，这东西不能用来练甲！\n", me);
		return 0;
	}
}

int	do_start()
{
	object me;
	me = this_player();
	switch (me->query_temp("item/step"))
	{
		case "接受原料":
		if (me->query_temp("item/material1"))
		{
			message_vision("掌甲童子说道：好，我开始铸甲了！\n", me);
			item_temp_make(me);
			break;
		}
		message_vision("掌甲童子摇摇头，说道：你给我原料，我才能练甲啊。\n", me);
		break;

		default:
		message_vision("掌甲童子问$N：你想干什么？\n", me);
		break;
	}
	return 1;
}

int item_temp_make(object me)
{
	me->set_temp("item/step", "铸造粗坯");
	this_object()->set_temp("item/铸造中", 1);
	this_object()->set_temp("item/material1", me->query_temp("item/material1"));
	this_object()->set_temp("item/mat_id1", me->query_temp("item/mat_id1"));
	if (me->query_temp("item/material2"))
	{
		this_object()->set_temp("item/material2", me->query_temp("item/material2"));
		this_object()->set_temp("item/mat_id2", me->query_temp("item/mat_id2"));
	}
	remove_call_out("work_step_1");
	call_out("work_step_1", 3, me);
	return 1;
}

int work_step_1(object me)
{
	object ob;
	if (objectp(ob = present(this_object()->query_temp("item/mat_id1"), this_object())))
	{
		destruct(ob);
	}
	message_vision(HIY "\n掌甲童子把" + this_object()->query_temp("item/material1") + HIY "放进了火炉，" +
			"然后轻轻拨拉拨拉一下炉膛，火渐渐的旺了起来。\n\n" NOR, this_object());
	remove_call_out("work_step_2");
	call_out("work_step_2", 4, me);
	return 1;
}

int work_step_2(object me)
{
	message_vision(HIR "掌甲童子用力鼓动着风机，又添了一些精炭，火光越来越亮。\n\n" NOR, this_object());
	remove_call_out("work_step_3");
	call_out("work_step_3", 3, me);
	return 1;
}

int work_step_3(object me)
{
	object ob;
	message_vision(HIW "一股发亮的铁水从炉中流了出来，流到了一旁的模具中。\n\n" NOR, this_object());
	if (this_object()->query_temp("item/mat_id2"))
	{
		message_vision(HIW "掌甲童子忙把" + this_object()->query_temp("item/material2") + HIW "添到铁水中，"
				+ "只见忽然一亮，巨热的溶液闪耀着奇异的光芒。\n\n" NOR, this_object());
		// 用掉配料
		if (objectp(ob = present(this_object()->query_temp("item/mat_id2"), this_object())))
		{
			destruct(ob);
		}
	} else
	{
		message_vision(HIW "掌甲童子叹息道：可惜没有配料，不然能造出更好的甲。\n\n" NOR, this_object());
	}
	message_vision(HIW "掌甲童子合好模具，小心的盯着。\n\n" NOR, this_object());
	remove_call_out("work_step_4");
	call_out("work_step_4", 5, me);
	return 1;
}

int work_step_4(object me)
{
	object ob;
	if (! objectp(me) || ! objectp(present(me, environment())))
	{
		message_vision(HIW "掌甲童子小心翼翼的打开了模具，看了看，高兴地说：好了好了！\n\n" NOR, this_object());
		command("say 咦，人呢？怎么这就走了，东西都不要了，真是可惜。\n");
		this_object()->delete_temp("item");
		if (objectp(me)) me->delete_temp("item");
		return 1;
	}
	message_vision(HIW "掌甲童子小心翼翼的打开了模具，看了看，高兴地说：好了好了，甲坯铸好了！\n\n" NOR, me);
	// 生成粗坯
	ob = new("/d/item/obj/armor_origin");
	ob->set("material1", me->query_temp("item/material1"));
	ob->set("mat_attr1", me->query_temp("item/mat_attr1"));
	ob->move(me);
	if (me->query_temp("item/material2"))
	{
		ob->set("material2", me->query_temp("item/material2"));
		ob->set("mat_attr2", me->query_temp("item/mat_attr2"));
	} else
	{
		ob->delete("material2");
		ob->set("mat_attr2", 5);
	}
	ob->set_weight(me->query_temp("item/item_weight"));
	me->delete_temp("item");
	this_object()->delete_temp("item");
	message_vision("掌甲童子把甲坯交给了$N。\n", me);
	return 1;
}

