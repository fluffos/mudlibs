// shaohuo.c 烧饭道士

inherit NPC;

void create()
{
	set_name("道士", ({ "shaohuo daoshi", "daoshi" }));
	set("long", 
		"他是香积厨的烧饭道士，他面容稍胖，一双手却十分有力，不时熟练的用铲子在锅中搅两下。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_qi", 300);
	set("max_jing", 200);
	set("neili", 300);
	set("max_neili", 300);
	set("times",3);

	set("combat_exp", 5000);
	set("score", 1000);

//	set_skill("force", 60);
	set_skill("dodge", 40);
//	set_skill("club",40);
	set_skill("unarmed", 40);
	set_skill("parry", 50);
//	set_skill("sword", 40);
//	set_skill("taiji-quan", 20);
	set_skill("taoism", 20);

	create_family("武当派", 4, "烧饭弟子");

	setup();
        carry_object("/d/wudang/obj/yellowrobe")->wear();
}
#include "/kungfu/class/wudang/wudang.h"
