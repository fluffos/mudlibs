
// girldizi.c 女弟子

inherit NPC;
#include <ansi.h>
void create()
{
	set_name("女弟子", ({ "dizi","nu dizi"}));
	set("long","峨嵋派下三千弟子之一。\n");
	set("gender", "女性");
	set("age", 15);
	set("class","xian");
	set("title", HIM"峨嵋派下三千弟子"NOR);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);

	set("max_lee", 450);
	set("max_sen", 400);
	set("force", 500);
	set("max_force", 500);

	set("combat_exp", 20000);
	set("score", 1000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);

	create_family("峨嵋派", 5, "弟子");

	setup();
        carry_object("/d/city/obj/cloth.c")->wear();
        carry_object("/d/emei/obj/mejian")->wield();
}
