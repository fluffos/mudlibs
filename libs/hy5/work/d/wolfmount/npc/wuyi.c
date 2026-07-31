#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("常无意", ({ "chang wuyi","wuyi" }) );
        set("gender", "男性");
        set("title", "剥皮匠");
        set("age", 35);
        set("long","一个专门剥人皮的皮匠，他的眼睛如同刀锋一般锋利的。\n");
        set("combat_exp", 1000000);
        set("attitude", "heroism"); 
        set("con", 50);
        set("int", 20);
        set("agi", 20);
        set("cor", 40); 
        set("force", 900);
        set("max_neili",900);
        set("force_factor",20); 
        set_temp("apply/attack",  40);
        set_temp("apply/dodge", 40);
        set_temp("apply/parry", 40); 
	set("fengset",1);
	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 380);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 380);
	set_skill("zixia-shengong", 380);
	set_skill("zixia-shengong", 380);
	set_skill("ziyunyin", 380);
	set_skill("zhengqijue", 380);
	set_skill("fanliangyi-dao", 380);
	set_skill("huashan-sword", 380);
	set_skill("hunyuan-zhang", 380);
	set_skill("lonely-sword", 380);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 200);
        set_skill("zhengqijue",380);
        set_skill("hunyuan-zhang", 380);
        set_skill("poyu-quan", 380);        
        set_skill("huashan-neigong", 380);        
        set_skill("chongling-jian", 380);
        set("fengset",1);
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );
   
        setup();
        carry_object(__DIR__"obj/softsword")->wield();
        carry_object(__DIR__"obj/tigercloth")->wear(); 
} 
void die()
{
        object ob;
        object *enemy;
        ob = query_temp("last_damage_from");
        if(!ob)
        { 
                enemy = this_object()->query_enemy();
                if (sizeof(enemy)!=0)
                {
                        ob=enemy[0];
                }
        }
        if(userp(ob))   ob->set_temp("marks/wolf_killed_wuyi",1);
        ::die();
}                                      
