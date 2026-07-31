// /NPC fumy.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("符敏仪", ({ "fu mingyi", "fu"}));
	set("long",
	    "她是「灵鹫宫」九天九部中阳天部的首领.\n"+
	    "她号称「针神」.\n");
	set("title", "阳天部首领");
	set("gender", "女性");
	set("nickname", HIR "针神" NOR);
	set("age", 20);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 22);
	set("int", 25);
	set("con", 26);
	set("dex", 22);

	set("qi", 2100);
	set("max_qi", 2100);
	set("jing", 1100);
	set("max_jing", 1100);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 30);

	set("combat_exp", 420000);
	set("score", 3500);
	set_skill("force", 160);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("hand",150);
	set_skill("strike", 150);

	set_skill("zhemei-shou", 150);
	set_skill("liuyang-zhang", 150);
	set_skill("yueying-wubu", 150);
	set_skill("lingjiu-xinfa", 160);

	map_skill("force", "lingjiu-xinfa");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");

	prepare_skill("hand", "zhemei-shou");
	prepare_skill("strike","liuyang-zhang");

	create_family("灵鹫宫",3,"弟子");
	setup();

	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/lingjiu/obj/doupeng")->wear();
	add_money("silver",20);
}

