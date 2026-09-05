// chang1.c 常赫志

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("常赫志", ({ "chang hezhi", "chang","hezhi" }));
	set("title", HIR "红花会"HIG"五当家" NOR);
	set("nickname", HIB "黑无常" NOR);
	set("long", 
"他身材又高又瘦，脸色蜡黄，眼睛凹进，眼角上有一粒黑痣，眉毛
斜斜的倒垂下来，形相甚是可怖。他是青城派慧侣道人的徒弟。黑沙
掌的功夫，江湖上无人能敌。黑白无常两兄弟是川江上著名的侠盗，
一向劫富济贫，不过心狠手辣，因此得了这难听的外号。\n");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 42);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 14);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("combat_exp", 5000000);

	set_skill("literate", 300);
        set_skill("strike", 300);
        set_skill("heisha-zhang", 300);
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("blade", 300);

	set_skill("bingchuan-xinfa", 300);
	set_skill("zhuangzi-mengwu", 300);
	set_skill("luojia-dao", 300);
	
	map_skill("dodge", "zhuangzi-mengwu");
        map_skill("strike", "heisha-zhang");
	map_skill("force", "bingchuan-xinfa");
	map_skill("blade", "luojia-dao");
	map_skill("parry", "luojia-dao");

	set("env/wimpy", 20);

 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}


