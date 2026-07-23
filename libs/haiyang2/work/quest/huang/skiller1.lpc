#include <ansi.h> 
inherit NPC;
 
void create()
{
	set_name("土匪", ({ "tu fei","fei"}));
	set("gender", "男性");
	set("age", 66);
	set("attitude", "peaceful");
	set("shen", -18000);
	set("str", 30);
	set("int", 30);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 2500);
	set("max_jing", 2500);
	set("neili", 3500);
	set("max_neili", 3500);
        set("jiali", 100);
	set("combat_exp", 10000);
        set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.kuangjian" :),
                (: perform_action, "sword.kuangjian" :),
                (: perform_action, "force.powerup" :)
         }));
 	set("chat_chance", 20);
	set("chat_msg", ({
		(: random_move :)
	}) );
        set_skill("force", 180);
         set_skill("canhe-zhi", 200);
         set_skill("dodge", 180);
         set_skill("murong-jianfa", 220);
         set_skill("parry", 180);
        set_skill("shaolin-shenfa", 180);
        set_skill("finger", 200);
        set_skill("shenyuan-gong", 180);
        set_skill("literate", 150);
        set_skill("sword", 190);

        map_skill("force", "shenyuan-gong");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("finger", "canhe-zhi");
        map_skill("sword", "murong-jianfa");
  	map_skill("parry", "murong-jianfa");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 220);
 
        prepare_skill("finger", "canhe-zhi");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield(); 
        add_money("gold", 1);
}
#include "killer.h"
