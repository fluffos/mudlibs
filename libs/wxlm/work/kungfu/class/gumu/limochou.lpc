// Jay 3/21/96



inherit NPC;

int do_look(string var);
int ask_me();

void create()
{
	set_name("李墨愁", ({ "li mochou", "li", "mochou" }));
	set("long", "她生得极为美貌，但冰冷的目光让人不寒而立。\n");
	set("nickname", HIR "赤练仙子" NOR);
	set("gender", "女性");
	set("rank_info/respect", "道姑");
	set("age", 27);
	set("attitude","heroism");
	set("str", 30);
	set("dex", 35);
	set("con", 17);
	set("int", 25);
	set("shen_type", -1);

	set_skill("unarmed", 160);
	set_skill("force", 160);
	set_skill("dodge", 160);
	set_skill("whip",160);
	set_skill("yunv-xinfa",160);
	set_skill("qiufeng-chenfa", 160);
	map_skill("force", "yunv-xinfa");
	set_skill("throwing", 160);
	set_skill("yufeng-zhen", 160);
	set("jiali", 50);

	set("combat_exp", 400000);

	set("max_qi", 2900);
	set("max_jing", 1400);
	set("neili", 3100);
	set("max_neili", 3100);

	set("inquiry", ([
	    "name" : "站远点！",
	    "here" : "我不是本地人，不知道。",
	    "情" : "你如何能理解其中相思之苦、惆怅之意？",
	    "陆展元" : "你问那个薄情的小畜生做什么？",
	    "何沅君" : (: ask_me :),
	    "龙姑娘" : "那是我的师妹。你问她想干什么？",
	    "林潮瑛" : "那是我的师祖，不该你问的你别问，小心我宰了你。",
       ]) );

	set("chat_chance", 1);
	set("chat_msg", ({
	    "李墨愁纵声而歌，音调凄婉，歌道：「问世间，情是何物，直教生死相许？」\n",
	    "李墨愁歌道：「天南地北双飞客，老翅几回寒暑？」\n",
	    "李墨愁唱道：「欢乐趣，离别苦，就中更有痴儿女。」\n",
	    "李墨愁唱道：「君应有语，渺万里层云，千山暮雪，只影向谁去？」\n",
	    "李墨愁词意悲切，声调更是哀怨，唱道：「横汾路，寂寞当年箫鼓。荒烟依旧平楚。」\n",
	    "李墨愁歌道：「招魂些何嗟及，山鬼自啼风雨。」\n",
	    "李墨愁唱道：「天也妒，未信兴，莺儿燕子俱黄土。」\n",
	    "李墨愁唱道：「千秋万古，为留待骚人，狂歌痛饮，来访雁丘处。」\n",
	}) );

	setup();
	carry_object("/d/quanzhou/obj/fuchen")->wield();
	carry_object("/d/wudang/obj/greenrobe")->wear();

}

void init()
{
	::init();
	add_action("do_look","look");
	add_action("do_look","hug");
	add_action("do_look","mo");
	add_action("do_look","18mo");
	add_action("do_look","kiss");

}

int ask_me()
{
	object me;
 
	me = this_player();
	message("vision",
		HIY "李墨愁冷笑一声：『我这就送你去见她』\n"
		    "李墨愁决心杀死" + me->name() +"\n"
		NOR, environment(), this_object() );
	kill_ob(this_player());
	return 1;
}
  

int do_look(string target)
{
	object me;
 
	me = this_player();
	if (! id(target))
		return notify_fail("你要看什么？");
	if ((string)me->query("gender") != "女性") {
		message("vision",
			HIY "李墨愁大怒，喝道：我最恨你们这些薄情的臭男人！去死吧！\n"
			"李墨愁决心杀死" + me->name() +"\n"
			NOR, environment(), this_object() );
		kill_ob(this_player());
	}
	return 1;
}

void attempt_apprentice(object ob)
{
	command("say 滚开！我不收徒。\n");
}
