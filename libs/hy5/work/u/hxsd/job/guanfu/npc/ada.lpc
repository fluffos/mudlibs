//  ada 阿大

#include <ansi.h> 
inherit NPC;
 
void create()
{
	set_name("阿大", ({ "a da", "a" }));
	set("nickname", "八臂神剑");
	set("long", 
        "原丐帮四大长老之首，剑术之精，名动江湖，据说出手极快。\n");
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
	set("combat_exp", 1800000); 
        set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "force.powerup" :)
         }));
         set_skill("force", 180);
         set_skill("canhe-zhi", 200);
         set_skill("dodge", 180);
         set_skill("murong-jianfa", 180);
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
 
        prepare_skill("finger", "canhe-zhi");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield(); 
        add_money("gold", 1);
}
#include "/quest/guanfu/npc/npc.h"
