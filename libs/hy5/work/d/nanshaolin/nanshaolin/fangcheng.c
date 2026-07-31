// Npc: /kungfu/class/nanshaolin/fangcheng.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("方成", ({ "fang cheng", "fang", "cheng"}));
	set("long", "他是一位身穿黄布袈裟的青年僧人。脸上稚气未脱，身手却已相\n"
		"当矫捷，看来似乎学过一点武功。\n");
	set("nickname", "狱头");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 50);
	set_skill("zhanzhuang-gong", 60);
	set_skill("shaolin-cuff", 60);
	set_skill("shaolin-leg", 60);
	set_skill("yiwei-dujiang", 60);
	set_skill("boluomi-hand", 60);
	set_skill("jingang-strike", 60);
	set_skill("wuxiang-finger", 60);
	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("yijinjing", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cuff", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("luohan-quan", 50);
	set_skill("strike", 50);
	set_skill("sanhua-zhang", 50);
	set_skill("sanhua-zhang", 50);
	set_skill("finger", 50);
	set_skill("yizhi-chan", 50);
	set_skill("sword", 50);
	set_skill("damo-jian", 50);

	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("strike", "sanhua-zhang");
	map_skill("finger", "yizhi-chan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");
	prepare_skill("strike", "sanhua-zhang");
	prepare_skill("finger", "yizhi-chan");

	create_family("南少林派", 21, "弟子");

	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
}
void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) )
	{
		remove_call_out("speaking");
		call_out("speaking", 1, ob);
	}
}

void speaking(object ob)
{
	if ( random(5) < 1 )
	{
		switch( random(3) )
		{
			case 0:
				command( "say 百年前的一场大火，整个少林寺就除这监牢和北边\n的钟楼没遭灾。唉。。。\n");
				break;
			case 1:
				command( "say 这里四周全用钢汁浇缝的花岗岩给封了起来，你们\n就是变成苍蝇也飞不出去！\n");
				break;
			case 2:
				command( "say 好好呆着别动，等会儿自然会放你们出去，不过你\n们自己要打架我可不管！\n");
				break;
		}
	}
}
#include "fang.h";

