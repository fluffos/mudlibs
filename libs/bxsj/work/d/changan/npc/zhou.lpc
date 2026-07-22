// zhou.c 周威信
// modified by zly 6/6/99

#include <ansi.h>
#include <wanted.h>
inherit NPC;

#include "/d/zhiye/npc/biaotou.h"

void create()
{
        set_name("周虎威", ({"zhou huwei", "huwei", "zhou"}));
        set("title", YEL"虎威镖局"NOR);
        set("nickname", "铁鞭镇八方");
        set("shen_type", -1);
        set("gender", "男性");
        set("age", 58);
        set("long", 
                "这个老头，便是天下知名长安城虎威镖局的总镖头，但看起来一点都不显眼。\n"
                "他左手按着腰间铁鞭，紧惕地看着四周。\n"
        );

        set("attitude", "peaceful");
        
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 3500);
        set("max_qi", 3500);
        set("jing", 2000);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 60);
        
        set("combat_exp", 1500000);
        
        set_skill("force", 200); 
        set_skill("strike", 200);
        set_skill("lianhua-zhang", 200);
        set_skill("huntian-qigong", 200);       
	set_skill("dodge", 200);                        
        set_skill("xiaoyaoyou", 200);           
        set_skill("parry", 200);                        
        set_skill("whip", 200);         
        set_skill("huifeng-bian", 200);
                
        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "huifeng-bian");
        map_skill("whip","huifeng-bian");
        map_skill("strike", "lianhua-zhang");
        prepare_skill("strike", "lianhua-zhang");
        set("chat_chance", 3);
        set("chat_msg", ({
		"周威信轻声说：“江湖上有言道：忍得一时之气，可免百日之灾”。 \n",
		"周威信低声道: “江湖上有言道：容情不动手，动手不容情”。\n",
		"周威信小声道：“江湖上有言道：只要人手多，牌楼抬过河”。\n",
	}));   
	
	set("inquiry", ([
		"保镖"		: (: ask_guard :),
		"guard"		: (: ask_guard :),
		"保镖1"		: (: ask_guard1 :),
		"guard1"	: (: ask_guard1 :),
		"保镖2"		: (: ask_guard2 :),
		"guard2"	: (: ask_guard2 :),
		"保镖3"		: (: ask_guard3 :),
		"guard3"	: (: ask_guard3 :),
	]));
	
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(BINGQI_D("tiewhip"))->wield();
} 
