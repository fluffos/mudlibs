// 樵子 by leontt

inherit NPC;
#include <ansi.h>

string ask_fish();
string ask_yideng(string name);

void create()
{
	set_name("渔人", ({ "yu ren", "yu", "ren" }) );
	set("long", "见他约莫四十来岁年纪，一张黑漆漆的锅底脸，虬髯满腮，根根如铁。\n");
	set("gender", "男性" );
	set("age", 45);
	set("str", 30);
	set("con", 30);
	set("dex", 25);
	set("int", 25);
	set("per", 20);
	set("unique", 1);
	set("attitude", "friendly");

	set("max_qi", 5000);
	set("max_jing", 2800);
	set("eff_jingli", 3600);
	set("neili", 8000);
	set("qi", 5000);
	set("jingli", 3600);
	set("max_neili", 8000);
	set("jiali", 50);

	set("combat_exp", 2300000);
	set("score", 5000);

	set_skill("parry", 280);
	set_skill("dodge", 280);
	set_skill("force", 280);
	set_skill("literate", 200);
	set_skill("qiantian-yiyang", 280);
	set_skill("tianlong-xiang", 280);
	set_skill("finger", 280);
	set_skill("yiyang-zhi", 280);
	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "yiyang-zhi");
	map_skill("force", "qiantian-yiyang");
	map_skill("finger", "yiyang-zhi");
	prepare_skill("finger","yiyang-zhi");

	set("inquiry", ([
		"金娃娃" : "金娃娃就是金色的娃娃鱼。",
		"一灯大师" :(: ask_yideng, "一灯大师" :),
		"段皇爷" : (: ask_yideng, "段皇爷" :),
	]));
	setup();

	carry_object(ARMOR_D("b_cloth"))->wear();
	carry_object(ARMOR_D("caoxie"))->wear();
}

string ask_yideng(string name)
{
	object me= this_player();

	if ( name == "段皇爷" )
		return "段皇爷早已不在尘世了！";

	if ( me->query_temp("yideng/boat"))
		return "我不是已经告诉你上山的方法了么？";

	if ( me->query_temp("yideng/yuren"))
		return "我让你去找的金娃娃呢？";

	if ( name == "一灯大师" ){
		me->set_temp("yideng/yuren", 1);
		return "要见我师傅到也不难，可是我刚丢失了两条金娃娃，不知这位"+RANK_D->query_respect(me)+"能否帮我抓回。";
	}
}

int accept_object(object me, object ob)
{
	if ( ob->query("id") != "jin wawa" ){
		command("say 你把这个给我干吗？");
		return 0;
	}
	if ( ob->query_temp("owner") != me->query("id")){
		command("say 你从那里得到这对金娃娃啊？");
		return 1;
	}
	message_vision(CYN"$N看着两尾金娃娃在掌中翻腾挣扎，哇哇而叫，宛如儿啼，不由笑道：「怪不\n"+
			"得叫作娃娃鱼，果然像小孩儿哭叫一般。」\n"+
			HIW"\n$N伸手交给$n，那$n喜上眉梢，放下铁桨，伸手接了过去。\n\n"NOR, me, this_object());
	me->delete_temp("yideng");
	me->set_temp("yideng/boat", 1);
	me->add_busy(1);
	call_out("give_bonus", 1, me, this_object());
	call_out("dest", 1, ob);
	return 1;
}

void dest(object ob)
{
	if ( !ob) return;
	destruct(ob);
}

int give_bonus(object me, object ob)
{
	object boat, jiang;

	message_vision("\n", me);
	command("say 这上山说难是难，说易却也容易得紧。从右首转过山角，已非瀑\n"+
		"布乃是一道急流，坐在这铁舟之中，扳动铁桨，在急湍中逆流而上就可以了。");
	boat = unew(__DIR__"../obj/boat");
	jiang= unew(__DIR__"../obj/jiang");
	boat->move(me);
	jiang->move(me);
	message_vision("$N给了$n一艘"HIB"铁舟"NOR"。\n",this_object(), me);
	message_vision("$N给了$n一柄"BLU"铁桨"NOR"。\n",this_object(), me);
	return 1;
}
