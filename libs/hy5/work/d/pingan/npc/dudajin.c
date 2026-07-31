//music yangzhou' 书生
#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("都大锦", ({ "du dajin","du"}) );
	set("gender", "男性" );
	set("age", 36);
	set("nickname",YEL"多臂熊"NOR);
	set("combat_exp",200000);
	set("long",
		"龙门镖局的总镖头，听说是少林寺俗家弟子。\n");
	set("score",2000);
	set("attitude", "peaceful");
	set_skill("unarmed",150);
	set_skill("jingang-quan",150);
	set_skill("dodge",150);
	set_skill("shaolin-shenfa",150);
	set_skill("force",150);
	set_skill("hunyuan-yiqi",150);
	set_skill("parry",150);
	set_skill("sword",150);
	set_skill("damo-jian",150);
	map_skill("unarmed","jingang-quan");
	map_skill("dodge","shaolin-shenfa");
	map_skill("parry","jingang-quan");
	map_skill("force","hunyuan-yiqi");
	map_skill("sword","damo-jian");
	set("max_neili",1500);
	set("neili",1500);
	set("force_factor",100);
	set("max_qi",1200);
	set("vendor_goods", ({
		"/d/pingan/npc/obj/ling1",
		"/d/pingan/npc/obj/ling2",
                "/d/pingan/npc/obj/ling3",
                "/d/pingan/npc/obj/ling4",
               "/d/pingan/npc/obj/ling5",
	}));

	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/tongjia")->wear();
	carry_object(__DIR__"obj/tongxue")->wear();
	carry_object(__DIR__"obj/tongkui")->wear();
	carry_object(__DIR__"obj/tongshoutao")->wear();
	carry_object(__DIR__"obj/sword")->wield();
}
//		"qinglong":500000,
//		"baihu":400000,
//		"lvbao":200000,
//		"chilang":100000,
//		"jinshe":10000,
void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
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
		say("都大锦说道：人客来坐。\n");
		break;
	case 1 :
		say("都大锦说道：这位兄弟，你要保护么？\n");
		break;
	}
}

