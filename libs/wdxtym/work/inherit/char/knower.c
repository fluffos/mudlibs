// inherit object: knower.c
// 消息灵通人士继承此对象

#include <ansi.h>

inherit NPC;

int is_knower() { return 1; }

// 接收打听消息
mixed accept_ask(object ob, string topic)
{
	return QUEST_D->generate_information(this_object(), ob, topic);
}

int accept_hit(object me)
{
	command("say 哇哇，我... 我...");
	return -1;
}

int accept_fight(object me)
{
	command("say 小的可不敢和" + RANK_D->query_respect(me) + "过招。");
	return -1;
}

int accept_kill(object me)
{
	return notify_fail("你暗想：以后这人或许还有些用处，暂且不忙下手。\n");
}

int accept_ansuan(object me)
{
	return notify_fail("你觉得是时机不妥当，不敢贸然下手。\n");
}

int accept_touxi(object me)
{
	return notify_fail("你觉得对方甚是警惕，不好下手。\n");
}

varargs int receive_damage(string type, int points, object who)
{
	return 0;
}

varargs int receive_wound(string type, int points, object who)
{
	return 0;
}

void unconcious()
{
	die();
}

varargs void die()
{
	mapping my;
	message_vision("$N“哇”的大叫了一声。\n", this_object());
	my = query_entire_dbase();
	my["qi"] = my["eff_qi"] = my["max_qi"];
	my["jing"] = my["eff_jing"] = my["max_jing"];
}
