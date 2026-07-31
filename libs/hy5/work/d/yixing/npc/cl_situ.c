// /d/yixing/npc/cl_situ.c 司徒横
// Last Modified by winder on Jul. 12 2002
#include <ansi.h>;

inherit NPC;


string *positions = ({
	"龙灵堂",
	"狮敏堂",
	"熊威堂",
});

void create()
{
	set_name("司徒横", ({ "situ heng", "situ" }));
	set("nickname", HIY"八爪金龙"NOR);
	set("party/party_name", HIC"长乐帮"NOR);
	set("party/rank", "帮主");
	set("long","他是一个身材高大，但有些干瘦的中年人，双臂很长，飞抓功夫在武林中也堪称一绝。\n");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 50);
	set("int", 28);
	set("con", 24);
	set("dex", 25);

	set("max_qi", 1000);
	set("max_jing", 800);
	set("max_neili", 1000);
	set("neili", 1000);
	set("jiali", 60);
	set("combat_exp", 300000);
	set("score", 10000);

	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("claw",  120);
	set_skill("strike", 80);
	set_skill("staff", 80);

	set_skill("poison", 80);
/*
	set_skill("huagong-dafa", 120);
	set_skill("zhaixinggong", 120);
	set_skill("sanyin-zhua",  120);
	set_skill("chousui-zhang", 80);
	set_skill("tianshan-zhang", 80);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("parry", "sanyin-zhua");
	map_skill("claw",  "sanyin-zhua");
	map_skill("strike", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");

	prepare_skill("claw",  "sanyin-zhua");
*/
	set("inquiry", ([
		"长乐帮" : "长乐帮威震江湖，指日可待！哈！哈！哈！",
		"贝先生" : "贝先生劳苦功高，所以我任命他为总管。",
		"贝大夫" : "贝先生劳苦功高，所以我任命他为总管。",
		"贝海石" : "贝先生劳苦功高，所以我任命他为总管。",
	]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
//	carry_object("/clone/weapon/feizhua")->wield();
}
