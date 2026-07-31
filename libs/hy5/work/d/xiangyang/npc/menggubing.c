// menggubing.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("ÃÉ¹Å±ø", ({ "menggu bing", "bing", "menggu" }));
	set("long", 
"ÃÉ¹Å±ø³¤ÄêÔ¾ÂíºáÇ¹£¬Ê®·ÖæçÓÂ¡£\n");
	set("gender", "ÄÐÐÔ");
	set("title", "´óº¹Ç×±ø");
	set("age", 18);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 24);
	set("str", 20);
	set("int", 40);
	set("con", 20);
	set("dex", 20);
	
	set("max_qi", 5800);
	set("max_jing", 5800);
	set("neili", 3100);
	set("max_neili", 3100);
	set("combat_exp", 60000);

 set("combat_exp", 500000+random(2000000));
	set("bellicosity", 10000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.fanzhuan" :),
                (: perform_action, "club.huimaqiang" :),
               
        }) );


        set_skill("unarmed", 80+random(180));
        set_skill("club", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("zhong-qiang", 280+random(380));
        
	map_skill("club", "zhong-qiang");
	map_skill("parry", "zhong-qiang");
        set_temp("apply/attack", 120);
        set_temp("apply/defense",150);
        set_temp("apply/armor", 350);
        set_temp("apply/damage", 320);


	set_temp("is_riding", HIY"ÃÉ¹ÅÂí"NOR);
	set("env/wimpy", 40);

 	setup();
	carry_object("/d/city/obj/tiejia")->wear();
	carry_object("/clone/weapon/changqiang")->wield();
}

