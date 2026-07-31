#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("女店主", ({ "nv dianzhu", "dianzhu", "master" }));
	set("shen_type", 1);

	set("str", 20);
	set("gender", "女性");
	set("age", 35);
	set("long", "女店主久居大理城，知道他名字的人并不多，据说她年轻时很有几分风韵。\n");
	set("combat_exp", 800);
	set("attitude", "friendly");
	set("inquiry", ([
		"name" : "小娘子夫家姓李。\n",
	]));
	setup();
	carry_object(ARMOR_D("cloth"))->wear();

}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting() && visible(ob)) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say(CYN"女店主笑眯眯地说道：客人来坐，请问我今天漂亮么？\n"NOR);
		break;
	case 1 :
		say(CYN"女店主说道：可嘴的，你要买什么？\n"NOR);
		break;
	}
}
