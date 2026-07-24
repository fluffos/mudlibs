// guojing.c 郭靖

#include <ansi.h>

inherit NPC;
int ask_rong();
void create()
{
	set_name("郭靖", ({"guo jing", "guo", "jing"}));
	set("nickname", HIY"北俠"NOR);
	set("gender", "男性");
	set("age", 25);
	set("long", 
		"他就是人稱北俠的郭靖，既是蒙古成吉思汗的金刀駙馬，又是\n"
		"江南七怪、全真派馬鈺道長、「北丐」洪七公和「老頑童」周\n"
		"伯通等人的徒弟，身兼數門武功\。\n"
		"他身著一件灰色長袍，體態魁梧，敦厚的面目中透出一股威嚴\n"
		"令人不由得產生一股欽佩之情。\n");
 	set("attitude", "peaceful");
	
	set("str", 40);
	set("int", 20);
	set("con", 30);
	set("dex", 25);

//	set("chat_chance", 1);
	set("chat_chance", 50);
	set("chat_msg", ({
//		"郭靖嘆了口氣道：“蒙古兵久攻襄陽不下，一定會再出詭計，蓉兒又不在身邊，這....\n",
//		"郭靖說道：“華箏公主近來不知可好，抽空一定要回大漠去看看她。\n",
//		(: random_move :),
		(: savefile :)
	}));

	set("inquiry", ([
		"黃蓉" : "蓉兒是我的愛妻，你問她做甚？\n",
		"蓉兒" : (:ask_rong:),
		"丐幫" : "東北西北東西北。\n",
		"拜師" : "現在蒙古人圍攻襄陽，我哪有心情收徒啊！\n",
	]));

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	
	set("combat_exp", 800000);
	set("score", 200000);
	 
	set_skill("force", 150);		// 基本內功
	set_skill("huntian-qigong", 130);	// 混天氣功
	set_skill("unarmed", 220);		// 基本拳腳
	set_skill("xianglong-zhang", 200);	// 降龍十八掌
	set_skill("dodge", 100);		// 基本躲閃
	set_skill("xiaoyaoyou", 80);		// 逍遙游
	set_skill("parry", 120);		// 基本招架
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.xi1" :),
                (: perform_action, "unarmed.xi2" :),
                (: perform_action, "unarmed.xi3" :),
                (: exert_function, "re1" :),
                (: exert_function, "p" :),
                (: exert_function, "s1" :),
        }) );
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}
int ask_rong()
{
    object ob;
    ob = this_player();
    if (ob->query_int()>=30)
    {
        ob->set_temp("marks/蓉兒",1);
        command("say " + ob->query("name") + "，你幫我帶個口信去桃花島吧！\n");
    }
    else
    {
        command("say " + ob->query("name") + "，你打聽這干嘛？\n");
    }
    return 1;
}
varargs void savefile()
{
	object *ob;
	int i, skill;

	ob = users();
	for(i=0; i<sizeof(ob); i++) {
		ob[i]->save();
		tell_object(ob[i],"系統存盤中...... ok!\n");
	}
}

