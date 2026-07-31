// fang.c 方碧琳

#include "emei.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("方碧琳", ({ "fang bilin","fang","bilin"}));
	set("long", "她是峨嵋派的第四代俗家弟子。\n");
	set("gender", "女性");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "fighter");

	set("str", 16);
	set("int", 22);
	set("con", 21);
	set("dex", 19);

	set("max_qi", 1200);
	set("max_jing", 600);
	set("neili", 1500);
	set("max_neili", 1500);

	set("combat_exp", 70000);
	set_skill("persuading", 40);
	set_skill("throwing", 30);
	set_skill("force", 70);
	set_skill("dodge", 80);
	set_skill("finger", 50);
	set_skill("parry", 70);
	set_skill("strike", 80);
	set_skill("blade", 60);
	set_skill("jinding-zhang", 80);
	set_skill("tiangang-zhi", 50);
	set_skill("yanxing-dao", 60);
	set_skill("zhutian-bu", 80);
	set_skill("emei-xinfa", 70);

	map_skill("force","emei-xinfa");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("blade","yanxing-dao");
	map_skill("parry","yanxing-dao");

	create_family("峨嵋派", 4, "弟子");

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
