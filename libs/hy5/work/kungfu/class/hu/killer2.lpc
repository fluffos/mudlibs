// caoyunqi.c 曹云奇

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("殷吉", ({ "yin ji", "yinji" }) );
	set("gender", "男性");
	set("title", "辽东天龙门南宗第六代掌门人");
	set("nickname", "威震天南");
	set("age", 43);
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
set("qi", 39800);
	set("max_qi", 39800);
	set("jing", 38600);
	set("max_jing", 38600);
	set("neili", 54400);
	set("max_neili", 54400);
	set("jiali", 200);

	set("combat_exp", 15050000);
	set("score", 200000);

	set("fengset",1);
	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 280);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 280);
	set_skill("zixia-shengong", 280);
	set_skill("zixia-shengong", 280);
	set_skill("ziyunyin", 280);
	set_skill("zhengqijue", 280);
	set_skill("fanliangyi-dao", 280);
	set_skill("huashan-sword", 280);
	set_skill("hunyuan-zhang", 280);
	set_skill("lonely-sword", 280);
	set_skill("feiyan-huixiang",280);
	set_skill("literate", 200);
        set_skill("zhengqijue",280);
        set_skill("hunyuan-zhang", 280);
        set_skill("poyu-quan", 280);        
        set_skill("huashan-neigong", 280);        
        set_skill("chongling-jian", 280);
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
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
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
              //me->add("score",1);        
        message_vision(RED"$N一声怒吼，浑身鲜血直流，逃了出去!\n"NOR,ob,me);
        


        me->set_temp("killtian1",1);


               destruct(ob);
        return;
}
