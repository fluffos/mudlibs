// zhu-changling.c 

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("Öì³¤Áä", ({"zhu changling", "zhu"}));
	set("title", HIR"ºìÃ·É½×¯×¯Ö÷"NOR);
	set("gender", "ÄÐÐÔ");
	set("age", 45);

       set("max_qi", 22500);
	set("max_jing", 21220);
	set("neili", 25000);
	set("max_neili", 25000);
	set("jiali", 100);
	set("combat_exp", 5000000);
	set("score", 300000);

        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 150);
        set_skill("cuff", 200);
        set_skill("strike", 150);
        set_skill("sword", 200);
        set_skill("staff", 150);
        set_skill("finger", 220);
        set_skill("finger", 280);
	set_skill("kurong-changong", 301);
        set_skill("tiannan-step", 280);
        set_skill("jinyu-quan", 280);
        set_skill("wuluo-zhang", 280);
        set_skill("duanjia-sword", 380);
        set_skill("yiyang-zhi", 280);
	set_skill("literate", 200);
	set_skill("wuluo-zhang", 200);
	set_skill("feifeng-whip", 300);
	map_skill("unarmed", "yiyang-zhi");
	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "yiyang-zhi");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "yiyang-zhi");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "finger.sandie" :),
                (: perform_action, "finger.dian" :),
                (: perform_action, "finger.jian" :),
                (: perform_action, "finger.qian" :),
                (: perform_action, "finger.sandie" :),
         
                (: perform_action, "dodge.huadie" :),
                
                (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );
	set("shen_type", -1);
	        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 2200);
        set_temp("apply/damage", 2200);
	setup();
	carry_object(__DIR__"obj/pao2")->wear();
	add_money("silver", 50);
}

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	
	who->set_temp("book1233",1);
	::die();
}