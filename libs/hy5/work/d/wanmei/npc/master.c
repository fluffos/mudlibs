 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void smart_fight(); 
int your_score = 0;
void create()
{
        set_name("西门吹雪", ({ "master ximen", "ximen", "master" }) );
        set("title", "万梅庄主");
        set("gender", "男性");
        set("nickname", RED "剑神" NOR );
        set("age", 34);
        set("reward_npc", 1);
        set("difficulty", 30);
    
        set("long",
                "西门吹雪乃是当代绝顶高手之一．剑法已经到达了＂无剑＂的境界．．\n"
                ); 
    
        set("resistance/kee",50);
        set("attitude", "peaceful");
        set("combat_exp", 20000000);
        set("agi",25);
        set("int",40);
        set("str", 100);
        set("int", 30);
        set("cor", 300);
        set("cps", 30);
        set("con", 30); 
        set("force", 2500);
        set("max_neili", 2500);
        set("force_factor", 30); 
        

        
        set("chat_chance", 1);
        set("chat_msg", ({
           "西门吹雪怒骂道：陆小凤，你就是逃到幽灵山庄，我也要杀了你！！\n",
            }) ); 
        set("inquiry", ([
                "拜师": "我向来有个规矩，凡是想拜我为师的，得接我三招不死，
你想试试(accept test)？\n",
                "apprentice": "我向来有个规矩，凡是想拜我为师的，得接我三招不死，
你想试试(accept test)？\n" 
        ]) ); 
        create_family("万梅山庄", 1, "庄主");
        set("ranks",({ "弟子","领班","小管家","管家","大管家", "总管","大总管","副庄主" }));
        set("rank_nogen",1); 
     set("pubmaster",1);
        set("max_neili", 95000);
        set("neili", 95000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);

                set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.hunranyijian" :),
                (: perform_action, "dodge.feitiantui" :),

		"西门吹雪冷笑道：如此废物，还来杀我？\n"
        }) );


        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 350);
        set_skill("parry", 100);
        set_skill("dodge", 80);
        set_skill("throwing", 50);
	
        set_skill("doomforce", 500);
        set_skill("doomstrike", 500);
        set_skill("doomsteps", 590);
	set_skill("doomsword",520);

        map_skill("force", "doomforce");
        map_skill("unarmed", "doomstrike");
        map_skill("sword", "doomsword");
        map_skill("dodge", "doomsteps");


       


        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2200);
        set_temp("apply/attack", 200);
        setup(); 
        carry_object(__DIR__"obj/xuejian")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
} 
void init()
{
        ::init();
        add_action("do_accept", "accept");
        if (this_player()->query_skill("lingxi-zhi",1)){
                message_vision(HIY"\n$N喝道:好!陆小风的门人,见一个杀一个!!\n"NOR,this_object());
                this_object()->kill_ob(this_player());
        }
} 
int do_accept(string arg)
{
        mapping guild;
        int extra;      
        int mgin,mkee,msen;
    
        if( arg== "test" )    {
                if(this_player()->query("family/master_id") == this_object()->query("id")){
                        say("\n西门吹雪拍拍你的头道：你已经证明你是一个可造之才了！\n");
                        return 1;
                }
                if (this_object()->is_fighting()||this_object()->query_busy()) {
                        command("say 先让我收拾了这个碍手碍脚的家伙。");
                        return 1;
                }
                mgin=(int)query("max_jing");
                mkee=(int)query("max_qi");
                msen=(int)query("max_jing");
                set("eff_qi",mkee);
                set("eff_jing",mgin);
                set("eff_jing",msen);
                set("jing",mgin);
                set("qi",mkee);
                set("jing",msen);
                extra=100;
                
                say("\n西门吹雪点了点头，说道：很好，这是第一招....\n\n");
                this_object()->add_temp("apply/attack", extra*5);       
                this_object()->add_temp("apply/damage",extra*2);
                COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
                this_object()->add_temp("apply/attack", -extra*5);      
                this_object()->add_temp("apply/damage",-extra*2);                    
                if( (int)this_player()->query("qi") < 0 || !present(this_player(), environment())) {
                        say("西门吹雪叹了口气，说道：连第一招都撑不过，真是自不量力....\n");
                        return 1;
                }
                
                say("\n西门吹雪说道：这是第二招....\n\n");
                this_object()->add_temp("apply/attack", extra*5);       
                this_object()->add_temp("apply/damage",extra*4);
           COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
                this_object()->add_temp("apply/attack", -extra*5);      
                this_object()->add_temp("apply/damage",-extra*4);                      
                if( (int)this_player()->query("qi") < 0  || !present(this_player(), environment())) {
                        say("西门吹雪「哼」地一声，说道：便是有这许多不怕死的家伙....\n");
                        return 1;
                }
                
                say("\n西门吹雪说道：第三招来了....\n\n");
                this_object()->add_temp("apply/attack", extra*5);       
                this_object()->add_temp("apply/damage",extra*4);
                COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
                this_object()->add_temp("apply/attack", -extra*5);      
                this_object()->add_temp("apply/damage",-extra*4);                      
                if( (int)this_player()->query("qi") < 0 || !present(this_player(), environment())) {
                        say("西门吹雪叹道：可惜，难道我一身武功竟无传人....\n");
                        return 1;
                }
        
                if (this_player()->query_skill("lingxi-zhi",1)){
                        say("\n西门吹雪哈哈大笑，说道：陆小凤的徒弟，果然是有些手段，不过我可不敢收你为徒！\n\n");
                        command("grin");
                        return 1;
                }
                                
                say("\n西门吹雪哈哈大笑，说道：今日终於觅得一个可造之才！\n\n");
                your_score = this_player()->query("score");
                command("recruit " + this_player()->query("id") );
                return 1;
    }
    return 0;
} 

void killed_enemy(object who)
{
        command("say 狂妄之徒，死不足惜！\n");
} 
void die()
{
        object killer;
        if(objectp(killer = query_temp("last_damage_from"))){
                if (killer->query("marks/won_lu")) killer->set("marks/kill_ximen", 1);
        }
        ::die();
} 
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>2 && enemy[1]->is_zombie()&& random(3)>0) {
                who->perform_action("sword.zombie-wp1");
                return;
        }
        who->perform_action("sword.hunranyijian"); 
        return;
}         
int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("unarmed",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("unarmed",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("unarmed",1)<100)
				i=ob->value() / 100;
			else
				i=ob->value() / 100;
		}
	}
	who->add_temp("learn_timeb",i);
command("say 既然你诚心想学我的武功，我就成全成全你吧。");
	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
