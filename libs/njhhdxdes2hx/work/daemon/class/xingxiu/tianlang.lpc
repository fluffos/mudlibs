#include <ansi.h>
// tianlang.c 天狼子

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("天狼子", ({ "tianlang zi", "tianlang" }));
	set("title",MAG "星宿派" NOR + YEL "邪士" NOR);
        set("nickname", RED "星宿派三师兄" NOR);
	set("long", 
		"他就是丁春秋的三弟子天狼子。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 27);
	set("int", 16);
	set("con", 25);
	set("dex", 27);
	
	set("max_kee", 400);
	set("max_gin", 400);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 15);
	set("combat_exp", 150000);
	set("score", 30000);

	set_skill("force", 70);
//	set_skill("huagong-dafa", 4);
	set_skill("dodge", 50);
	set_skill("zhaixinggong", 40);
	set_skill("strike", 50);
	set_skill("xingxiu-duzhang", 30);
	set_skill("parry", 40);
	set_skill("staff", 70);
  	set_skill("tianshan-zhang", 70);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingxiu-duzhang");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "xingxiu-duzhang");

	create_family("星宿派", 2, "弟子");

	setup();
  	carry_object("/obj/weapon/gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") > -100) {
                command("say 我派讲究要心狠手辣，奸恶歹毒，你可做得不够呀！");
                return;
        }

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	if((string)this_player()->query("gender")!="女性")
        	this_player()->set("title",HIR "星宿派" NOR + GRN +"邪士" NOR);
        else
		this_player()->set("title",HIR "星宿派" NOR + GRN +"妖女" NOR);
}
