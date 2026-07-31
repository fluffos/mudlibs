// meng.c 安健刚

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("安健刚", ({ "an jiangang", "an","jiangang" }));
	set("nickname", HIY "独角虎" NOR);
	set("long", 
"他是铁胆周仲英的二弟子，对师父始终忠心不二。\n");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 11000);
	set("max_jing", 11500);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 50);
	set("combat_exp", 50000);

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("throwing", 50);
	set_skill("mantian-xing", 150);
	set_skill("hunyuan-yiqi", 150);
	set_skill("shaolin-shenfa", 150);
	set_skill("jingang-quan", 150);

	map_skill("dodge", "shaolin-shenfa");
	map_skill("force", "hunyuan-yiqi");
	map_skill("throwing", "mantian-xing");
	map_skill("unarmed", "jingang-quan");
	map_skill("parry", "jingang-quan");

	set("env/wimpy", 20);
	create_family("少林派", 52, "俗家弟子");
 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/tiedan")->wield();
}

