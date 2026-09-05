
#include <ansi.h>


inherit NPC;
inherit F_SKILL;
int ask_liujin();

void create()
{
        set_name("杨伟涛", ({ "yang weitao", "yang", "tao" }));
        set("gender", "男性");
        set("age", 23);
        set("long", "他就是「电学实验室」的总管－－杨伟涛。\n");
	set("title", GRN "MUD 专家" NOR);
	set("nickname", RED "泥虫" NOR);

        set("combat_exp", 3000000);
		set("shen_type", -1);

        set("max_neili",5000);
        set("neili", 5000);
        set("jiali", 100);

        set_skill("force", 200);
        set_skill("sword", 200);
        set_skill("unarmed", 50);
        set_skill("dodge", 250);
        set_skill("parry", 250);

        set("inquiry", ([
                "刘进" : (: ask_liujin :),
        ]) );

        set_temp("apply/damage", 15);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

int ask_liujin()
{
	command("say 刘进是卖狗皮膏药的。");
	command("say 招摇撞骗.");
	return 1;
}
