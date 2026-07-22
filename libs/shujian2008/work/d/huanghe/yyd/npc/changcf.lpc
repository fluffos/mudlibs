// changcf.c 常长风
// zly 7/6/99

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("常长风", ({"chang changfeng", "chang", "changfeng"}));
	set("title", HIY"太岳四侠"NOR);
	set("nickname", "双掌开碑");
        set("shen_type", 1);
	set("gender", "男性");
	set("age", 35);
	set("long", 
"这人看起来又高又肥，便如是一座铁塔摆在地下，他身前放着一
块大石碑，碑上写的是“先考黄府君诚本之墓”。\n"
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
	set_skill("hammer", 90);		
	set_skill("parry", 60);			
		
	map_skill("force", "huntian-qigong");

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/mubei")->wield();
} 
