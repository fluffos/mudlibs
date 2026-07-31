// shuisheng 水笙
#include <ansi.h>
inherit NPC;

void greeting(object me);

void create()
{
	set_name("水笙", ({ "shui sheng","shuisheng"}));
	set("long", "她轻妆淡抹，眉目之中深深的透露哀思。\n");
	set("gender", "女性");
	set("age", 22);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 25);

	setup();
	carry_object("/clone/cloth/cloth.c")->wear();
}

void init()
{
	object me;

	::init();
	me = this_player();
	if (! objectp(me) || ! userp(me))
		return;

	remove_call_out("greeting");
	call_out("greeting", 0, me);
}

void greeting(object me)
{
	object cloth;

	if (! objectp(me) || environment(me) != environment(this_object()))
		return;

	if (! stringp(me->query("character")))
	{
		command("tell " + me->query("id") + " 欢迎进入武林群侠世界，我是游戏的新人接待，我这里有件衣服你先穿身上吧，光着身子出去可不太好看！");
		cloth = new("/clone/cloth/cloth");
		cloth->move(me);
		tell_object(me,"你得到了一件布衣。\n");
		command("tell " + me->query("id") + " 你还没有选择品质，快去附近四处看看选选吧。离开前记得先把布衣穿上哦！");
		tell_object(me,"新手任务：点击"HIG"【常用指令】"NOR"--选择【查看背包】--点击【布衣】进行穿戴。\n");
		return;
	}

	if (! wizardp(me))
	{
		command("tell " + me->query("id") + " 咦，你怎么跑到这里来了？");
		if (! stringp(me->query("born")))
		{
			message_vision("$N被昏昏沉沉的扔了出去。\n", me);
			me->delete("born");
			me->move("/d/register/yanluodian");
			message_vision("啪的一声，$N被扔到了地上。\n", me);
			return;
		}

		message_vision("$N被昏昏沉沉的扔了出去。\b", me);
		me->move(VOID_OB);
		message_vision("啪的一声，$N被扔到了地上。\n", me);
		return;
	}

	command("look " + me->query("id"));
}
