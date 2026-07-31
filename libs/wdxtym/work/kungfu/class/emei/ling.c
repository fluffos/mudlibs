// ling.c 赵灵珠

inherit NPC;
inherit F_MASTER;

#include "emei.h"

void create()
{
	set_name("赵灵珠", ({ "zhao lingzhu","zhao","lingzhu"}));
	set("long", "她是峨嵋派的第四代俗家弟子。\n");
	set("gender", "女性");
	set("age", 22);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "fighter");

	set("str", 20);
	set("int", 22);
	set("con", 20);
	set("dex", 21);

	set("max_qi", 1500);
	set("max_jing", 750);
	set("neili", 1800);
	set("max_neili", 1800);

	set("combat_exp", 90000);
	set_skill("throwing", 30);
	set_skill("persuading", 50);
	set_skill("force", 70);
	set_skill("dodge", 80);
	set_skill("finger", 60);
	set_skill("parry", 80);
	set_skill("strike", 60);
	set_skill("blade", 90);
	set_skill("jinding-zhang", 60);
	set_skill("tiangang-zhi", 60);
	set_skill("yanxing-dao", 90);
	set_skill("zhutian-bu", 80);
	set_skill("emei-xinfa", 70);

	map_skill("force","emei-xinfa");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("blade","yanxing-dao");
	map_skill("parry","yanxing-dao");
	create_family("峨嵋派", 4, "弟子");

	set("no_teach", ([
		"linji-zhuang" : "想学临济十二庄？找灭绝师太去。",
	]));

	setup();
	carry_object("/d/city/obj/gangdao")->wield();
	carry_object("/d/city/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
}
