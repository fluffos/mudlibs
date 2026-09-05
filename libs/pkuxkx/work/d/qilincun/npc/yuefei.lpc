// yang.cg.c
// Rewrote by iszt@pkuxkx, 2007-02-11

#include <ansi.h>

inherit NPC;

void heal();
string ask_me();

void create()
{
	set_name("岳飞",({"yue fei","yue"}));
        set("long", "这是一个眉红齿白，英气逼人的少年。\n");
	set("gender", "男性");
	set("age", 16);
        set("no_get", 1);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 50);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	set("inquiry",([ 
		"周侗"  : (: ask_me :),
		"老师"  : (: ask_me :),
		"同去"  : (: ask_me :),
	]));
	set("chat_chance", 100);
	set("chat_msg", ({
		(: heal :),
	}));
	set("max_qi", 4000);
	set("max_jing", 2000);
	set("neili", 40000);
	set("max_neili", 40000);
	set("jiali", 300);
	set("combat_exp", 3000000);
	set("score", 4000);

	set_skill("force",500);
	set_skill("jiuyang-shengong",500);
	set_skill("dodge",500);
	set_skill("datengnuo-bufa", 500);
	set_skill("hanbing-zhang",500);
	set_skill("parry",500);
	set_skill("sword",500);
	set_skill("shenghuo-lingfa",500);
	set_skill("qiankun-danuoyi", 530);
	set_skill("strike",500);
	set_skill("spear",500);
	set_skill("yuejia-qiangfa",500);

	map_skill("spear", "yuejia-qiangfa");
	map_skill("strike", "hanbing-zhang");
	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "datengnuo-bufa");
	map_skill("parry", "shenghuo-lingfa");
	map_skill("sword", "shenghuo-lingfa");

	prepare_skill("strike", "hanbing-zhang");

	setup();
	carry_object(__DIR__"obj/changqiang")->wield();
	carry_object("/d/mingjiao/obj/changpao")->wear();
}

void heal()
{
	object ob=this_object();
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		command("enforce 50");
		return;
	}
	if (ob->query("qi") < ob->query("eff_qi"))
	{
		command("exert recover");
		return;
	}
	if (ob->query("jing") < ob->query("eff_jing"))
		command("exert regenerate");
	return;
}

string ask_me()
{
	object me;
	me = this_player();
	me->set_temp("liquan/find_yue", 1);
	return RANK_D->query_respect(me)+"真乃义人也，麻烦告知老师，我护送王大嫂回家，莫等我了。";
}
