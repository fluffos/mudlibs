// NPC yupopo.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("余婆婆", ({ "yu popo", "yu", "popo" }));
	set("long",
	    "她是「灵鹫宫」九天九部中昊天部的首领.\n"+
	    "她跟随童姥多年, 出生入死,饱经风霜.\n");
	set("title", "昊天部首领");
	set("gender", "女性");
	set("age", 60);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 20);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 1200);
	set("max_jing", 1200);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 40);

	set("combat_exp", 250000);
	set("score", 10000);
	set_skill("force", 140);
	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("hand",120);
	set_skill("strike", 120);
	set_skill("sword",120);

	set_skill("tianyu-qijian",120);
	set_skill("zhemei-shou",120);
	set_skill("liuyang-zhang",120);
	set_skill("yueying-wubu",120);
	set_skill("lingjiu-xinfa", 140);

	map_skill("force", "lingjiu-xinfa");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
   	map_skill("sword", "tianyu-qijian");

	create_family("灵鹫宫",2,"弟子");
	setup();

	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",40);
}
