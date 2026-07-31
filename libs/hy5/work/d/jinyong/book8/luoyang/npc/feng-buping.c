// feng-buping.c  封不平
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("封不平", ({ "feng buping", "feng" }) );
        set("nickname", YEL"狂风快剑"NOR);
        set("gender", "男性");
        set("class", "swordsman");
        set("title", "华山剑宗第十三代弟子");
        set("age", 45);
        set("long",
                "封不平是华山剑宗第一高手，满脸戾气一张黄焦焦的面皮。\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        set("neili", 30000);
        set("max_neili", 30000);
        set("jiali", 30);
        set("max_qi",30000);
        set("max_jing",30000);

        set("combat_exp", 5000000);
        set("shen", -200000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
              (: perform_action, "sword.feilong" :),
                (: perform_action, "sword.kuangfeng" :),
                (: perform_action, "sword.kuanglong" :),
                (: perform_action, "sword.sao" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),   
                (: exert_function, "powerup" :),
        }) );
     
        set_skill("zixia-shengong", 300);
        set_skill("unarmed", 300);
        set_skill("strike", 300);
        set_skill("sword", 300);
        set_skill("force", 300);
        set_skill("parry", 300);
        set_skill("dodge", 300);
        set_skill("literate", 300);
        set_skill("huashan-sword", 300);
        set_skill("kuangfeng-jian", 300);
        set_skill("huashan-neigong", 300);
        set_skill("huashan-ken", 300);
        set_skill("huashan-zhangfa", 300);
        set_skill("huashan-shenfa", 300);
        set_skill("zhengqijue",200);
        map_skill("sword", "kuangfeng-jian");
        map_skill("parry", "kuangfeng-jian");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-zhangfa");
        map_skill("dodge", "huashan-shenfa");

        create_family("华山派", 13, "弟子");
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
	int i;
        object who = this_object()->query_temp("last_damage_from");
 	if(((int)who->query("jinyong/book8")>=5))
	{
//::die();	
	}
        else if((who)&& ((int)who->query("jinyong/book8")==4)) {
		i = random(1400);
		who->set("jinyong/book8",5);
		who->add("combat_exp",i+16000);
		who->add("potential",i*14);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+16000)+"点经验"+
		           chinese_number(i*14)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		who->save();
        }
	::die();
}
