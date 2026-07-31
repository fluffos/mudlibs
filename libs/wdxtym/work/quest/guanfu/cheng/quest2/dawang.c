#include <ansi.h>

inherit NPC;



void create()

{

	set_name("山寨大王", ({ "shanzhai dawang","dawang" }));

	set("nickname",HIW "逃犯"NOR);

	set("long", 

		"他是前段时间从扬州监狱里越狱出来的一个逃犯。\n"

		"他看起来满脸的惊慌失措。\n");

	set("gender", "男性");

	set("age", 41);

	set("attitude", "peaceful");

	set("shen_type", 0);

	set("str", 20);

	set("int", 20);

	set("con", 20);

	set("dex", 20);

	

	set("max_qi", 2500);

	set("max_jing", 2500);

	set("neili", 2000);

	set("max_neili", 2000);

	set("jiali", 100);

	set("combat_exp", 550000);

	set("score", 10);



	set_skill("force", 160);

	set_skill("taiji-shengong", 160);

	set_skill("dodge", 160);

	set_skill("tiyunzong", 160);

	set_skill("unarmed", 160);

	set_skill("taiji-quan", 160);

	set_skill("parry", 160);

	set_skill("sword", 160);

        set_skill("taiji-jian",160);



	map_skill("force", "taiji-shengong");

	map_skill("dodge", "tiyunzong");

	map_skill("unarmed", "taiji-quan");

        map_skill("parry", "taiji-quan");

    	map_skill("sword", "taiji-jian");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);
	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :)
	}) );

    	



	

	set("chat_chance_combat", 70);

	set("chat_msg_combat", ({

		(: perform_action, "sword.sui" :),

		(: exert_function, "recover" :),

		(: random_move :)

	}) );



	setup();

	carry_object("/d/city/obj/changjian")->wield();

   	carry_object("/d/wudang/obj/greyrobe")->wear();



}



void init()
{
        remove_call_out("leave");
        call_out("leave",60);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "山寨大王钻进路边的杂草，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
