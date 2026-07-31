// learn_fly.c 云游仙人
#include <ansi.h>

inherit NPC;
inherit F_DEALER;
string ask_fly();
void create()
{
	set_name("云游仙人", ({"xian ren"}));
	set("age", 32);
	set("gender", "男性");
	set("title", "御剑天下");
	set("long", "这是云游天下的仙人，现在被请来传授《 御剑术 》。\n");
	set("attitude", "friendly");
	set("str", 30);
	set("skill_fly", 1);
	set("dex", 30);
	set("combat_exp", 40000000);
	set("shen_type", 1);
	set("chat_chance",1);
	set_skill("fly", 600);  //御剑术
	set("inquiry", ([
	    "御剑术" : (: ask_fly :),
	]));
	setup();
}

void init()
{
}
string ask_fly()
{
	return "我可以教你< 御剑术 >，但要先交 二十 两银子!\n";
}
void greeting(object ob)
{
	if (! ob || environment(ob) != environment())
		return;

	say("云游仙人爽朗的说道：可否是来学习< 御剑术 >？\n");
}
int recognize_apprentice(object ob)
{
	if (ob->query_temp("mark/御剑术") < 1)
		return 0;

	ob->add_temp("mark/御剑术", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	if (! who->query_temp("mark/御剑术"))
		who->set_temp("mark/御剑术", 0);

	if (ob->query("money_id") && ob->value() >= 2000)
	{
		message_vision(HIG"云游仙人同意指点$N一些[ 御剑术 ]上的问题。"NOR"\n", who);
		who->add_temp("mark/御剑术", ob->value() / 50);
		destruct(ob);
		return 1;
	}

	command("say 看清楚学规，请教[ 御剑术 ]至少要二十两白银！");
	return 0;
}

