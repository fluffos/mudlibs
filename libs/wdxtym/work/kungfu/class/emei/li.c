// li.c 李明霞

inherit NPC;
inherit F_MASTER;

#include "emei.h"

mixed ask_back();

void create()
{
	set_name("李明霞", ({ "li mingxia", "li", "mingxia"}));
	set("long", "她是峨嵋派的第四代俗家弟子，平时经常掌管一些"
		    "入门弟子的杂事。\n");
	set("gender", "女性");
	set("age", 23);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "fighter");

	set("str", 24);
	set("int", 20);
	set("con", 21);
	set("dex", 18);

	set("max_qi", 1400);
	set("max_jing", 700);
	set("neili", 1600);
	set("max_neili", 1600);

	set("combat_exp", 70000);
	set_skill("persuading", 50);
	set_skill("throwing", 30);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("finger", 85);
	set_skill("parry", 70);
	set_skill("strike", 60);
	set_skill("sword", 60);
	set_skill("jinding-zhang", 60);
	set_skill("tiangang-zhi", 85);
	set_skill("huifeng-jian", 60);
	set_skill("zhutian-bu", 80);
	set_skill("emei-xinfa", 80);
	map_skill("force","emei-xinfa");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","huifeng-jian");
	map_skill("parry","huifeng-jian");

	set("inquiry", ([
		"上山" : (: ask_back :),
		"back" : (: ask_back :),
	]));

	create_family("峨嵋派", 4, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
}

mixed ask_back()
{
	object me;

	me = this_player();

	if (find_object(query("startroom")) != environment())
		return "什么都别问我！我什么都不知道！";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你不是长脚了吗？难道上山还要我来抬你？";

	if (me->query("age") >= 18)
		return "我说你呀，年纪这么大了还要我带你上山么？";

	command("say 好吧，看在同门的分上，我就带你上山吧。");
	message_vision("$N拉着$n的手向山顶上走去。\n",
		       this_object(), me);
	tell_object(me, name() + "拉着你，你觉得省力多了，毫不费劲的就上了金顶。\n");
	me->move("/d/emei/jinding");
	message("vision", name() + "一手拉着" + me->name() +
		"快步的向山上走去，一会儿就不见影子了。\n", environment());
	move("/d/emei/jinding");
	me->start_busy();
	call_out("back_to_startroom", 5);
	return 1;
}

void back_to_startroom()
{
	string startroom;

	if (! living(this_object()))
		return;

	if (! stringp(startroom = query("startroom")))
		return;

	if (find_object(startroom) == environment())
		return;

	message_vision("$N头也不回的急急忙忙走了。\n", this_object());
	move(startroom);
	message_vision("$N大步流星的赶了过来。\n", this_object());
}
