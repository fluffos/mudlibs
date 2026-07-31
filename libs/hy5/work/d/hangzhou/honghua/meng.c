// meng.c 孟健雄

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("孟健雄", ({ "meng jianxiong", "meng","jianxiong" }));
	set("nickname", HIC "神弹子" NOR);
	set("long", 
"他是铁胆周仲英的大弟子，对师父忠心耿耿。\n");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 31);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 18);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 21000);
	set("max_jing", 22500);
	set("neili", 25020);
	set("max_neili", 22500);
	set("jiali", 50);
	set("combat_exp", 60000);

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("unarmed", 150);
	set_skill("parry", 150);
	set_skill("throwing", 150);
	set_skill("mantian-xing",150);
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

