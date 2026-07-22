// gaiyiming.c 盖一鸣
// zly 7/6/99

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("盖一鸣", ({"gai yiming", "gai", "yiming"}));
	set("title", HIY"太岳四侠"NOR);
	set("nickname", "八步赶蝉、赛专诸、踏雪无痕、独脚水上飞、双刺盖七省");
        set("shen_type", 1);
	set("gender", "男性");
	set("age", 36);
	set("long", 
"这人看起来短小精悍，下巴尖削，手中拿着一对峨眉钢刺。\n"
	);

	set("attitude", "aggressive");
        set("vendetta/authority",1);
	
	set("max_qi", 500);
	set("qi", 500);
	set("jing",500);
	set("max_jing", 500);
        set("jingli", 600);
        set("eff_jingli", 600);        
	set("neili", 500);
	set("max_neili", 900);
	set("jiali", 1);
	
	set("combat_exp", 90000);
	
	set_skill("force", 60);		
	set_skill("huntian-qigong", 60);	
	set_skill("dodge", 60);	
	set_skill("sword", 90);		
	set_skill("parry", 60);			
		
	map_skill("force", "huntian-qigong");

        set("chat_chance", 3);
        set("chat_msg", ({
            "盖一鸣一摆峨嵋刺，细声细气地道：“你有什么宝贝，就给我们留下吧！”\n",
            "盖一鸣说道：“咱四兄弟义结金兰，行侠仗义，专门锄强扶弱，劫富
济贫，江湖上人称大名鼎鼎的‘太岳四侠’。”\n", 
     }) );

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/emeici")->wield();
        setup();

} 
