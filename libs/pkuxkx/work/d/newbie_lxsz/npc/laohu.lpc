// D:\xkx\d\liuxiu-shanzhuang\npc\laohu.c 老胡
// labaz 2012/10/22

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("老胡", ({ "lao hu", "hu" }) );
	set("title", "铁匠");
	set("gender", "男性" );
	set("age", 40);
	set("long",
		"他打着赤膊，结实的肌肉高高愤起，两鬓微白，显然经历风霜，饱尝冷暖。\n");
	set("combat_exp", 3000);
	set("str", 25);
	set("dex", 20);
	set("con", 20);
	set("int", 22);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/hammer",
		__DIR__"obj/jian"
	}));

	set("chat_chance", 1);
	set("chat_msg", ({
	"老胡嚷道：忙死我了,还让不让人活了。\n",
	"老胡叹道；很久没能锻造出好兵器了......难道是我老了么\n",
	"老胡叫道：这么多东西，只给我两周时间打造出来，看来要找帮手才行了。\n",
	}) );

	set_skill("dodge", 25);
	set_skill("parry", 25);
	set_skill("unarmed", 30);
	
	setup();
    carry_object(__DIR__"obj/cloth")->wear();
	add_money("coin", 100);
}

void init()
{
	object ob;
    ::init();
	
	if ( interactive(ob=this_player()) ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

    add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

	command("say 欢迎这位"+RANK_D->query_respect(ob)+"光临，请随便参观。");
}

