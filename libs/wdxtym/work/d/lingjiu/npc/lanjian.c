// /NPC lanjian.c

#include <ansi.h>

inherit NPC;
inherit F_GUARDER;

void create()
{
	set_name("兰剑", ({ "lan jian", "lan"}));
	set("long",
	    "这是个容貌姣好的女子，瓜子脸蛋，眼如点漆，清秀绝俗。\n");
	set("gender", "女性");
	set("age", 18);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 22);
	set("int", 26);
	set("con", 25);
	set("dex", 23);

	set("qi", 2700);
	set("max_qi", 2700);
	set("jing", 1400);
	set("max_jing", 1400);
	set("neili", 3200);
	set("max_neili", 3200);
	set("jiali", 30);

	set("combat_exp", 420000);
	set("score", 3000);
	set_skill("force", 150);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("hand", 140);
	set_skill("strike", 140);
	set_skill("sword", 140);

	set_skill("zhemei-shou", 140);
	set_skill("liuyang-zhang", 140);
 	set_skill("tianyu-qijian", 140);
	set_skill("yueying-wubu", 140);
	set_skill("lingjiu-xinfa", 150);

	map_skill("force", "lingjiu-xinfa");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("hand", "zhemei-shou");
	prepare_skill("strike","liuyang-zhang");

	set("coagents", ({
		([ "startroom" : "/d/lingjiu/dating",
		   "id"	: "xu zhu" ]),
	}));

	create_family("灵鹫宫",3,"弟子");
	setup();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",15);
}
