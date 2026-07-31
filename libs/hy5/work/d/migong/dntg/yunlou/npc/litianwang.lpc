//modified by vikee for xlqy-zq station
//2000-12-2 1:34

inherit NPC;
#include <ansi.h>


 
void create()
{
 
	set_name("李靖", ({ "li jing", "jing", "li" }) );
	set("gender", "男性" );
	set("long", "托塔李天王乃是天界元帅，麾下十万天兵天将，法力无边。\n");
	set("age",40);
	set("title", "托塔天王");
	set("str", 40);
	set("int", 30);
	set("con", 30);
	set("spi", 30);
	set("per", 30);
	set("class", "xian");
	set("attitude", "heroism");
	set("combat_exp", 4500000);
	set("daoxing", 8000000);
	set("max_qi", 4000);
	set("max_jing", 4000);
	set("neili",9000);
	set("max_neili",5000);
	set("force_factor", 500);
	set("mana", 9000);
	set("max_mana", 9000);
	set("mana_factor", 550);

	set("eff_dx", 600000);
	set("nkgain", 600);

	set("max_qi", 1000);
	set("max_jing", 1000);
        set("neili",800);
        set("max_neili",800);
	set("force_factor", 40);
	set("mana", 800);
	set("max_mana", 800);
	set("mana_factor", 40);
	set("qi", 39800);
	set("max_qi", 39800);
	set("jing", 38600);
	set("max_jing", 38600);
	set("neili", 54400);
	set("max_neili", 54400);
	set("jiali", 200);

	set("combat_exp", 95050000);
	set("score", 200000);

	set("fengset",1);
	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 1380);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 1380);
	set_skill("zixia-shengong", 1380);
	set_skill("zixia-shengong", 1380);
	set_skill("ziyunyin", 1380);
	set_skill("zhengqijue", 1380);
	set_skill("fanliangyi-dao", 1380);
	set_skill("huashan-sword", 1380);
	set_skill("hunyuan-zhang", 1380);
	set_skill("lonely-sword", 1380);
	set_skill("feiyan-huixiang",1380);
	set_skill("literate", 1200);
        set_skill("zhengqijue",1380);
        set_skill("hunyuan-zhang", 1380);
        set_skill("poyu-quan", 1380);        
        set_skill("huashan-neigong", 1380);        
        set_skill("chongling-jian", 1380);
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
	
        create_family("陷空山无底洞", 1, "弟子");
	set("chat_chance",1);
	set("chat_msg", ({
		    name()+"说道：哪位大仙可愿去下界灭妖？\n",
		    }));


	setup();
        carry_object("/clone/armor/yinjia")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
