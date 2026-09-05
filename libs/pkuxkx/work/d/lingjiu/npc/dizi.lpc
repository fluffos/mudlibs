// NPC yupopo.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("灵鹫宫弟子", ({ "dizi" }));
	set("long",
	    "她是「灵鹫宫」九天九部的弟子.\n");
	set("title", "弟子");
	set("gender", "女性");
	set("age", 18);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 20);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("qi", 300);
	set("max_qi", 300);
	set("jing", 200);
	set("max_jing", 200);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 10);

	set("combat_exp", 10000);
	set("score", 200);
	set_skill("force", 30);
//	set_skill("unarmed", 100);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("hand",30);
	set_skill("strike", 30);
        set_skill("sword",30);

        set_skill("changhen-jian",30);
	set_skill("zhemei-shou",30);
	set_skill("liuyang-zhang",30);
	set_skill("lingbo-weibu",30);
	set_skill("bahuang-gong", 30);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "lingbo-weibu");
//	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
   	map_skill("sword", "changhen-jian");
	create_family("灵鹫宫",5,"弟子");
	setup();
        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
