// dingtong.c
#include <ansi.h>
inherit NPC;
void create()
{
       set_name("丁同", ({ "ding tong", "ding", "tong" }) );
       set("title", "镖师");
       set("nickname", "两头蛇");
       set("gender", "男性" );
       set("shen", -2000);
       set("age", 45);
       set("str", 20);
       set("con", 20);
       set("int", 20);
       set("dex", 20);
       set("env/wimpy", 60);
       set("long","他是霍元龙手下的镖师之一，一直在这一带寻找着一个人。\n" );
       set("combat_exp", 200000);
       set("attitude", "heroism");
       set("chat_chance", 10);
       set("chat_msg", ({(: random_move :) }) );          
  set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
       set("per", 30);
	
	set("max_qi", 13500);
	set("max_jing", 13000);
	set("neili", 33500);
	set("max_neili", 33500);
	set("jiali", 50);
	set("combat_exp", 8000000);

        set_skill("strike",270);
        set_skill("finger",270);
        set_skill("dodge",220);
        set_skill("force", 270);
	set_skill("canhe-zhi", 300);
	set_skill("murong-jianfa",250);       
        set_skill("shenyuan-gong", 250);
	set_skill("yanling-shenfa", 250);   
	set_skill("xingyi-zhang",220);
        set_skill("douzhuan-xingyi", 220);
	set_skill("parry", 220);
	set_skill("sword", 260);
	set_skill("literate", 220);
        set_skill("murong-daofa", 220);
        set_skill("blade",260);
        
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("strike", "xingyi-zhang");
        map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-jianfa");
         map_skill("strike", "xingyi-zhang");
	prepare_skill("finger","canhe-zhi");
	prepare_skill("strike","xingyi-zhang");
        

        set_temp("apply/defense", 80);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 80);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "parry.xingyi" :),
                 (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "finger.ci" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "sword.kuangjian" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.qixing" :),
 		(: command("unwield sword") :),
		(: command("wield sword") :),           
                (: perform_action, "dodge.yanling" :),                
                   (: perform_action, "strike.riyue" :),
                	(: perform_action, "strike.xingdian" :),
        }));
       setup();
       carry_object(__DIR__"obj/yinjian")->wield();
       carry_object("/clone/misc/cloth")->wear();
       add_money("silver", 1);
}
#include "bs.h";

void unconcious()
{
    die();
}
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;
      


        me->set_temp("killltl2",1);



              ::die();
        return;
}