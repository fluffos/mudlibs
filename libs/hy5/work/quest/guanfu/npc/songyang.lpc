//  songyang 宋扬
 
inherit NPC;
 
void create()
{
	set_name("宋扬", ({ "song yang", "song" }));
//	set("nickname", "");
	set("long", 
        "一个行走江湖的独角大盗，一身轻功有所造脂。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen", -1000);
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 6500);
	set("max_jing", 6200);
	set("neili", 6500);
	set("max_neili", 6500);
	set("jiali", 100);
	set("combat_exp", 500000); 
	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "strike.sanhua" :),
         }));
         set_skill("force", 120);
         set_skill("hunyuan-yiqi", 340);
         set_skill("dodge", 100 + random(28));
  

        set_skill("shaolin-shenfa", 120);
        set_skill("strike", 100 + random(20));
        set_skill("sanhua-zhang", 100 + random(20));
        set_skill("parry", 100 + random(20));
        set_skill("sword", 100 + random(20));
        set_skill("literate", 70);
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shnfa");
        map_skill("strike", "sanhua-zhang");
  	map_skill("parry", "sanhua-zhang");
  	prepare_skill("strike", "sanhua-zhang");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
