// qingyun.c
// shilling 97.2

inherit NPC;

#include <ansi.h>

void create()
{
	set_name("黑白棋武士", ({ "qi wushi", "wushi" }));
	set("long", 
		"他是黑白棋武士，一个十分厉害的神秘人物。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("str", 35);
	set("int", 28);
	set("con", 30);
	set("dex", 28);
	
	set("max_qi", 11000);
	set("max_jing", 11000);
	set("neili", 11000);
	set("max_neili", 11000);
	set("jiali", 100);
	set("combat_exp", 1200000);
	set("score", 50000);

	set_skill("blade",200);
	set_skill("ruyi-dao",200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("lingboweibu", 200);
	set_skill("beiming-shengong",200);
	set_skill("liuyang-zhang", 200);
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.shishiruyi" :),
                (: perform_action, "blade.shishiruyi" :),
                (: perform_action, "blade.ruyi" :),
                (: perform_action, "blade.ruyi" :),
                (: perform_action, "dodge.lingbo" :),
                (: perform_action, "dodge.lingbo" :),
                (: exert_function, "strike.zhong" :),                
                (: exert_function, "strike.zhong" :),                
	}) );
	map_skill("unarmed", "liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("blade", "ruyi-dao");


	set("nickname","黑白棋武士");
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/blade")->wield();

}

void init()
{
	object ob;

	::init();

	ob = this_player();


		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 

}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");

        destruct(ob);
        return;
}