inherit FIGHTER;
#include <ansi.h>
#include "/d/city/npc/skills_pfm.h";
void create()
{
	set_name("无名老僧", ({
                "wuming laoseng",
                "wuming",
                "laoseng",
        }));
        set("long",
                "他是一位身穿青袍的枯瘦僧人，身材不高。\n"
                "年纪已在七旬开外，稀稀疏疏的几根长须已然全白。\n"
        );
        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");
        set("no_bark",1);
        set("age", 70);
        set("shen", 32000);
        set("str", 40);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 15000);
        set("max_jing", 7000);
        set("eff_jingli", 4000);
        set("neili", 17000);
        set("max_neili", 17000);
        set("jiali", 100);
        set("combat_exp", 5200000);

        set_skill("force", 300);
    	set_skill("yijin-jing", 300);
        set_skill("dodge", 300);
    	set_skill("shaolin-shenfa", 300);
	set_skill("fumoquan-zhen",200);
    	set_skill("claw", 300);
        set_skill("parry", 300);
        set_skill("cuff", 300);
        set_skill("club", 300);
        set_skill("blade", 300);
        set_skill("ranmu-daofa", 300);
        set_skill("finger", 300);
        set_skill("strike", 300);
	set_skill("buddhism", 200);
	set_skill("riyue-bian",300);
	set_skill("whip",300);
        set_skill("yizhi-chan",300);
        set_skill("literate", 100);
set_skill("jingang-quan",300);
set_skill("hand",300);
set_skill("leg",300);
set_skill("ruying-suixingtui",300);
set_skill("banruo-zhang",300);
set_skill("qianye-shou",300);
set_skill("longzhua-gong",300);
set_skill("weituo-chu",300);
set_skill("zui-gun",300);
set_skill("club",300);
map_skill("blade","ranmu-daofa");
map_skill("club","weituo-chu");

        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("finger", "yizhi-chan");
map_skill("cuff","jingang-quan");
map_skill("leg","ruying-suixingtui");
map_skill("hand","qianye-shou");
map_skill("claw","longzhua-gong");
map_skill("whip","riyue-bian");
map_skill("strike","banruo-zhang");
map_skill("parry","yizhi-chan");
  prepare_skill("finger", "yizhi-chan");
  prepare_skill("claw", "longzhua-gong");
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: exert_function, "jingang" :),
                (: perform_action, "claw.canyun" :),
                (: perform_action, "finger.qiankun" :),
                (: perform_action, "finger.wofo" :),
	}));
        create_family("少林派", 34, "弟子");   
	      set_temp("apply/damage", 50);
        set_temp("apply/dodge", 100);
        set_temp("apply/attack", 80);
        set_temp("apply/armor", 60);      
        setup();
        carry_object("/d/shaolin/obj/du-cloth")->wear();
}

void kill_ob(object me)
{
	command("yun jingang");
        ::kill_ob(me);
}
void init()
{
    object ob;  
    int i;     
    ::init();
    ob = this_object();
 	if(ob->query("setok")) return;
	ob->set("setok",1);
	i=400;	
   	ob->set("party","sl");  	  
	ob->copy_menpai(({ob->query("party")}),random(2),random(2),100);    //复制npc的门派武功，                                                   
	ob->copy_state();				//根据门派更新npc 的一些状态
	ob->set("max_qi", 25000);
	ob->set("eff_qi", 25000);
	ob->set("qi", 25000);
	ob->set("max_jing", 6000);
	ob->set("neili", 15000);
	ob->set("max_neili", 10000);
	ob->set("jiali", 200);
	ob->set("eff_jingli", 6000);
	ob->set("jingli", 6000);
	ob->set("combat_exp", 5800000);
	ob->set_skills_level(i);
	ob->set_skill("literate",ob->query("int")*10); 	 											//full literate
	ob->set_skill("wuxing-zhen",ob->query("int")*10); 	 									
}

