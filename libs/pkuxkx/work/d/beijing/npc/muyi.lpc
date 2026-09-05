// 木易

inherit NPC;

void create()
{
        set_name("木易", ({ "mu yi", "mu", "yi" }));
        set("gender", "男性");
        set("age", random(10) + 40);
        set("str", 25);
        set("dex", 16);
        set("long", "他神色凝重，似乎在想着什么心事。\n");
        set("combat_exp", 75000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("sword", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 30);

        set("neili", 400); 
        set("max_neili", 400);
        set("jiali", 10);

        setup();
        
		carry_object(__DIR__"items/cloth1")->wear();
}

int intro()
{
	command("say 在下姓穆名易，山东人氏。路经贵地，一不求名，二不为利，只为小女年已及笄，尚未许锝婆家。\n");
	command("say 她曾许下一愿，不望夫婿富贵，但愿是个武艺超群的好汉，因此上斗胆比武招亲。\n");
	command("say 凡年在三十岁以下，尚未娶亲，能胜得小女一拳一脚的，在下即将小女许配于彵。\n");
	command("say 在下父女两人，自南至北，经历七路，只因成名的豪杰都已婚配，而少年英雄又少肯于下顾，是以始终未得良缘。”\n");
}
