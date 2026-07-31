// zhu-jiuzhen.c 朱九真

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("武青婴", ({"wu qingying", "wu"}));
	set("long", "她长得极美，容貌娇媚，又白又腻。\n");
	set("title", HIW"雪岭双姝"NOR);
	set("gender", "女性");
	set("age", 17);
	set("per", 30);

set("max_qi", 8500);
	set("max_jing", 8220);
	set("neili", 15000);
	set("max_neili", 15000);
	set("jiali", 100);
	set("combat_exp", 2000000);
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
	set_skill("kurong-changong", 201);
        set_skill("tiannan-step", 250);
        set_skill("jinyu-quan", 250);
        set_skill("wuluo-zhang", 250);
        set_skill("duanjia-sword", 250);
        set_skill("yiyang-zhi", 250);
//        set_skill("sun-finger", 100);
	set_skill("literate", 200);
	set_skill("wuluo-zhang", 200);
	set_skill("feifeng-whip", 250);
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

                (: perform_action, "sword.fenglei" :),
                (: perform_action, "sword.jingtian" :),
                (: perform_action, "sword.feilong" :),   
                	(: perform_action, "sword.ailao" :),
                		(: perform_action, "sword.xswy" :) ,            
                (: perform_action, "dodge.huadie" :),
                
                (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );
	set("shen_type", -1);
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object(__DIR__"obj/baihu-qiu")->wear();
	carry_object(__DIR__"obj/necklace")->wear();
}
	
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	
	who->set_temp("book1232",1);
	::die();
}