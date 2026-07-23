#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("落雁老人", ({ "luoyan master", "master", "luoyan" }) );

        set("gender", "男性");
        set("age", 74);
        set("class", "xiake");
        set("title","庄主");
	set("max_qi", 6000);
	set("max_jing", 6000);
	set("max_jingli", 6000);
	set("neili", 13000);
	set("max_neili", 13000);
	set("food",250);
	set("water",250);
	set("mingwang",200000);

        set("str", 150);
        set("int", 100);
        set("con", 30);
        set("per", 30);
        set("cps", 30);
        set("dex", 130);
        set("spi", 30);
        set("car", 50);

        set("force", 4000);
        set("max_force", 4000);
        set("force_factor", 50);
        set("combat_exp", 5500000);
        set("score", 10000);
        set_skill("sword", 300);

        set_skill("unarmed", 300);
        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("literate", 300);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("houquan", 300);
        set_skill("parry", 200);
	set_skill("houquan", 300);
	set_skill("yunlong-xinfa", 300);
	set_skill("yunlong-shengong", 300);
	set_skill("wuhu-duanmendao", 300);
	set_skill("yunlong-jian", 300);
	set_skill("yunlong-shenfa", 300);
	set_skill("yunlong-bian", 300);
	set_skill("yunlong-shou", 300);
	set_skill("yunlong-zhua", 300);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	set("chat_chance_combat", 70);  
	set("chat_msg_combat", ({
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.duoming" :),
                (: perform_action, "sword.guang" :),
                (: perform_action, "sword.jueming" :),
                (: perform_action, "sword.shen" :),                	                	
                (: perform_action, "sword.xunlei" :),                	                	
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "unarmed.pofuchenzhou" :),
                (: perform_action, "unarmed.pofuchenzhou" :),
                (: perform_action, "unarmed.pofuchenzhou" :),
             
	
	}) );
        create_family("雁荡派", 1, "掌门");
        setup();
        carry_object(__DIR__"obj/zizhuzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
        //carry_object("/obj/zijin");
}

void init()
{      object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");

                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
  if (ob&&environment(ob)!=environment()) return;
if (ob->query("mingwang")>0)
message_vision("落雁老人赞赏的看了$N一眼,摸着胡子点了点头!\n",ob);
  else 
 message_vision("落雁老人失望的看着$N,深深叹了口气,嘴边的胡子都飞了起来!\n",ob);
}
