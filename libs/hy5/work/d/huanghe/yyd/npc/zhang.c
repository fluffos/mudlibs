// zhang.c 张妈
// zly 99.6.12

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("张妈", ({"zhang ma", "zhang", "ma"}));
	set("gender", "女性");
	set("shen_type", 1);
	set("age", 48);
	set("long", 
"这是萧府的佣妇张妈，她脸上笑嘻嘻的，不知道有什么喜事。\n"
	);
	
	set("str", 20);
	set("int", 10);
	set("con", 10);
	set("dex", 15);

	set("max_qi", 200);
	set("eff_qi", 200);
	set("qi", 200);
	set("jing", 100);
	set("eff_jing",100);
	set("max_jing", 100);
	set("neili", 250);
	set("max_neili", 250);
	set("jiali", 10);
	
	set("combat_exp", 5000);

	set_skill("force", 40);		
	set_skill("huntian-qigong", 40);	
	set_skill("dodge", 40);			
	set_skill("xiaoyaoyou", 40);		
	set_skill("parry", 40);			
		
	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");

	setup();
        carry_object("/clone/misc/cloth")->wear();        
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "张妈乐呵呵地对着" + RANK_D->query_respect(ob) + "说：“今天这日子真好，双喜临门！”。 \n");
                        break;
                case 1:
                        say( "张妈笑着道: “今天又是老爷的寿诞，又是小姐订婚的大喜日子！这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}

int accept_object(object who, object ob)
{
        
          if((string)ob->query("id") == "jin chai")
        {
         command("ah"+ (string)who->query("id"));
         command("say 这不是小姐的金钗吗？你是......，哦，欢迎欢迎，快请进！\n");
         who->set_temp("yyd_jinchai", 1);
         remove_call_out("destroying");
         call_out("destroying", 1, ob);
         return 1;
}
        return 0;
}

void destroying(object obj)
{     
        destruct(obj);
        return;
}     
