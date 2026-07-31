// lin-pingzhi.c

inherit NPC;
#include <ansi.h>;
void yueappear(object who);

void create()
{
        set_name("林平之", ({ "lin pingzhi","lin","pingzhi"}));
        set("gender", "男性");
        set("age", 18);
        set("long",
                "林平之是岳不群最小的一个弟子，也是他的东床快婿。\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("con", 30);
        set("int", 24);
        set("dex", 35);

        set("max_qi",150000);
        set("max_jing",150000);
        set("neili", 150000);
        set("max_neili", 150000);
        set("jiali", 100);

        set("combat_exp", 10000000);
        set("shen_type", -1);
        set("score", 200000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.cimu" :),
                (: perform_action, "sword.huanying" :),
                (: perform_action, "sword.sanlianci" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );
        


        set_skill("unarmed", 500);
        set_skill("sword", 500);
        set_skill("force", 500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set_skill("literate", 500);
        set_skill("pixie-jian",380);
        //set_skill("huashan-sword", 500);
        set_skill("pixie-jian", 380);
        set_skill("kuihua-xinfa", 380);
        set_skill("huashan-ken", 500);
        set_skill("feiyan-huixiang", 500);

        map_skill("sword", "pixie-jian");
        map_skill("parry", "pixie-jian");
        map_skill("force", "kuihua-xinfa");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");

        create_family("华山派", 14, "弟子");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void unconcious()
{
	die();
}
void die()
{
	object where = environment(this_object());
	object yue = present("yue lingshan",where);
	message_vision("$N说道：可惜我大仇未报，师姐，原谅我无情！\n" NOR,this_object());
	if(yue)
	{
		message_vision("$N哭道： 小林子!！\n",yue);
	}
	::die();
}

