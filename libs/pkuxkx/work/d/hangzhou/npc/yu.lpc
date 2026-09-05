// yu.c 余鱼同

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("余鱼同", ({ "yu yutong", "yu","yutong" }));
	set("title", HIR "红花会"HIG"十四当家" NOR);
	set("nickname", YEL "金笛秀才" NOR);
	set("long", 
"一个长身玉立，眉清目秀，风流英俊的书生。余鱼同乃江南望族
子弟，中过秀才。他父亲因和一家豪门争一块坟地，官司打得倾家
荡产，又被豪门借故陷害，瘐死狱中。余鱼同一气出走，得遇机缘，
拜马真为师，弃文习武，回来把士豪刺死，从此亡命江湖，后来入
了红花会。他为人机警灵巧，多识各地乡谈，在会中任联络四方、
刺探讯息之职。\n");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 20);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 27);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 3000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("literate", 200);
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("sword", 180);

	set_skill("bingchuan-xinfa", 180);
	set_skill("zhuangzi-mengwu", 180);
	set_skill("luohua-jian",     180);

	map_skill("dodge", "zhuangzi-mengwu");
	map_skill("force", "bingchuan-xinfa");
	map_skill("sword", "luohua-jian");
	map_skill("parry", "luohua-jian");

	set("env/wimpy", 20);
	create_family("红花会", 3, "弟子");
 	setup();
 	carry_object("/clone/misc/cloth")->wear();
	carry_object("/d/hangzhou/npc/obj/jindi")->wield();
}
void attempt_apprentice(object ob)
{
	command("say 我不收徒！");
	return;
}

