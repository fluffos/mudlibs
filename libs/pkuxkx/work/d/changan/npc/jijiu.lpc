#include <ansi.h>
inherit NPC;

void create()
{
	set_name("孔颖达", ({ "guozijian jijiu", "jijiu" }));
	set("title",HIC"国子监祭酒"NOR);
  set("gender", "男性");
	set("age", 69);
	set("long", "他是国子监祭酒，著名儒学家，以编撰《五经正义》闻名于世。\n");
	
	set("combat_exp", 100000);
	set("shen_type", 1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("literate", 300);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}