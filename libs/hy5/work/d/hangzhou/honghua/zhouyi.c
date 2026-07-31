// zhouyi.c 周绮
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("周绮", ({ "zhou yi", "zhou","yi" }));
	set("title", HIC "铁胆庄"HIM"大小姐" NOR);
	set("nickname", HIB "俏李逵" NOR);
	set("long", 
"这是铁胆庄的大小姐，周仲英的宝贝女儿。她性格豪迈，颇
有乃父之风，爱管闲事，好打不平，西北武林中人送了她个
外号，叫做“俏李逵”。\n");
	set("gender", "女性");
	set("class", "fighter");
	set("age", 17);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 25);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 5800);
	set("max_jing", 5400);
	set("neili", 5600);
	set("max_neili", 5600);
	set("jiali", 60);
	set("combat_exp", 370000);

	set_skill("force", 190);
	set_skill("dodge", 190);
	set_skill("unarmed", 190);
	set_skill("parry", 950);
	set_skill("blade", 190);
	set_skill("cibei-dao", 190);
	set_skill("hunyuan-yiqi", 190);
	set_skill("shaolin-shenfa", 190);
	set_skill("jingang-quan", 190);

	map_skill("dodge", "shaolin-shenfa");
	map_skill("force", "hunyuan-yiqi");
	map_skill("blade", "cibei-dao");
	map_skill("unarmed", "jingang-quan");
	map_skill("parry", "cibei-dao");

	set("env/wimpy", 20);
	create_family("少林派", 51, "俗家弟子");
 	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

